#include "../include/lf_model.h"
#include <cmath>
#include <vector>
#include <algorithm>

namespace sparkng {
namespace lfmodel {

/**
 * Generate closing I2kn0 phase of LF waveform
 * Creates the I2kn0 component with nth-order characteristics
 * Translates MATLAB closeI2kn0.m logic to C++
 * @param t Time vector (std::vector<double>)
 * @param omega Angular frequency parameter (double)
 * @param n Order parameter (int)
 * @return Closing I2kn0 waveform values (std::vector<double>)
 */
std::vector<double> closeI2kn0(const std::vector<double>& t, double omega, int n) {
    std::vector<double> out(t.size());
    
    // Constants
    const double pi = M_PI;
    
    // Process each time sample
    for (size_t i = 0; i < t.size(); i++) {
        double t_val = t[i];
        double abs_t = std::abs(t_val);
        
        // Main computation based on MATLAB closeI2kn0.m logic:
        // out = Tw/k/pi*sin(k*pi*t.*(abs(t)<=td)).^n;
        // Adapting to C++ with omega parameter and n order
        
        if (abs_t > 0.0) {
            double sin_val = std::sin(omega * pi * t_val);
            // Apply nth power for order characteristics
            out[i] = std::pow(sin_val, n) / (omega * pi);
        } else {
            out[i] = 0.0;
        }
    }
    
    return out;
}

} // namespace lfmodel
} // namespace sparkng
