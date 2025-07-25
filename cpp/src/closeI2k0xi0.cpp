// closeI2k0xi0.cpp: C++ implementation of MATLAB closeI2k0xi0.m for SparkNG LF model
// Direct translation of: https://github.com/shotafujie/SparkNG/blob/master/src/closeI2k0xi0.m
// Original MATLAB function: function out = closeI2k0xi0(t,Tw,td)
#include <vector>
#include "lf_model.h"

namespace sparkng {
namespace lfmodel {

/**
 * Generate closing I2k0xi0 phase of LF waveform
 * C++ implementation of MATLAB closeI2k0xi0.m
 * MATLAB logic: out = -r(t-Tw)+r(t+Tw)+r(t-td-Tw)-r(t-td+Tw)
 * where r(x) = double(x.*(x>0)) - returns x if x > 0, else 0
 *
 * @param t Time vector (std::vector<double>)
 * @param omega Angular frequency parameter (corresponds to Tw in MATLAB)
 * @param phase Phase offset (corresponds to td in MATLAB)
 * @return Closing I2k0xi0 waveform values (std::vector<double>)
 */
std::vector<double> closeI2k0xi0(const std::vector<double>& t, double omega, double phase) {
    std::vector<double> out(t.size());
    
    // Helper function: r(x) = x if x > 0, else 0
    // This is the MATLAB equivalent of double(x.*(x>0))
    auto r = [](double x) -> double {
        return (x > 0.0) ? x : 0.0;
    };
    
    // Map parameters to MATLAB variable names for clarity
    double Tw = omega;  // Angular frequency parameter
    double td = phase;  // Phase offset parameter
    
    // Apply MATLAB formula: out = -r(t-Tw)+r(t+Tw)+r(t-td-Tw)-r(t-td+Tw)
    for (size_t i = 0; i < t.size(); ++i) {
        double ti = t[i];
        out[i] = -r(ti - Tw) + r(ti + Tw) + r(ti - td - Tw) - r(ti - td + Tw);
    }
    
    return out;
}

} // namespace lfmodel
} // namespace sparkng
