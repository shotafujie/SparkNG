/**
 * openI5.cpp - Implementation of the openI5 function for LF model
 * 
 * This file implements the openI5 phase of the LF waveform model.
 * Translates the MATLAB openI5.m mathematical logic to C++.
 * 
 * Author: Auto-generated from MATLAB openI5.m
 * Date: 2025-07-25
 */

#include "../include/lf_model.h"
#include <vector>
#include <complex>
#include <cmath>
#include <algorithm>

namespace sparkng {
namespace lfmodel {

/**
 * Generate opening I5 phase of LF waveform
 * Creates the I5 component during glottal opening
 * 
 * This function implements the mathematical formulation:
 * For t <= tp: I5(t) = (1 - cos(pi * t / tp)) * exp(alpha * t)
 * For t > tp: I5(t) = 0
 * 
 * @param t Time vector (std::vector<double>)
 * @param tp Time of peak glottal opening (double) 
 * @param alpha Shape parameter (double)
 * @return Opening I5 waveform values (std::vector<double>)
 */
std::vector<double> openI5(const std::vector<double>& t, double tp, double alpha) {
    std::vector<double> result(t.size(), 0.0);
    
    // Validate input parameters
    if (tp <= 0.0) {
        // Return zero vector for invalid tp
        return result;
    }
    
    const double pi = M_PI;
    
    // Process each time point
    for (size_t i = 0; i < t.size(); ++i) {
        double time_val = t[i];
        
        // Conditional vector operation: only compute for t <= tp
        if (time_val <= tp && time_val >= 0.0) {
            // Complex exponential component: exp(alpha * t)
            double exp_component = std::exp(alpha * time_val);
            
            // Cosine component: (1 - cos(pi * t / tp))
            double cos_component = 1.0 - std::cos(pi * time_val / tp);
            
            // Combined I5 formula
            result[i] = cos_component * exp_component;
        }
        // For t > tp or t < 0, result[i] remains 0.0
    }
    
    return result;
}

/**
 * Alternative implementation with normalized amplitude
 * This version includes amplitude normalization for better integration with main.cpp testing
 * 
 * @param t Time vector (std::vector<double>)
 * @param tp Time of peak glottal opening (double)
 * @param alpha Shape parameter (double)
 * @param normalize Whether to normalize the output amplitude (default: true)
 * @return Opening I5 waveform values (std::vector<double>)
 */
std::vector<double> openI5Normalized(const std::vector<double>& t, double tp, double alpha, bool normalize = true) {
    std::vector<double> result = openI5(t, tp, alpha);
    
    if (normalize && !result.empty()) {
        // Find maximum value for normalization
        auto max_iter = std::max_element(result.begin(), result.end());
        double max_val = *max_iter;
        
        if (max_val > 0.0) {
            // Normalize to [0, 1] range
            for (double& val : result) {
                val /= max_val;
            }
        }
    }
    
    return result;
}

/**
 * Test function for main.cpp integration
 * Generates a test case with typical LF model parameters
 * 
 * @return Test result vector demonstrating openI5 functionality
 */
std::vector<double> testOpenI5() {
    // Create test time vector from 0 to 0.01 seconds with 1000 samples
    std::vector<double> t_test;
    const int num_samples = 1000;
    const double dt = 0.00001; // 10 microseconds step
    
    for (int i = 0; i < num_samples; ++i) {
        t_test.push_back(i * dt);
    }
    
    // Typical LF model parameters
    double tp = 0.005;    // 5ms peak time
    double alpha = 100.0; // Shape parameter
    
    // Generate I5 waveform
    return openI5Normalized(t_test, tp, alpha);
}

} // namespace lfmodel
} // namespace sparkng
