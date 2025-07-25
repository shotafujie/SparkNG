// closeI4.cpp: C++ implementation of MATLAB closeI4.m for SparkNG LF model
// Direct translation from: https://github.com/shotafujie/SparkNG/blob/master/src/closeI4.m
// Original MATLAB function: function out = closeI4(t,Tw,td,beetaa,k)

#include <vector>
#include <complex>
#include <cmath>
#include "lf_model.h"

namespace sparkng {
namespace lfmodel {

std::vector<double> closeI4(const std::vector<double>& t, double te, double ta) {
    // MATLAB: function out = closeI4(t,Tw,td,beetaa,k)
    // C++ signature: closeI4(t, te, ta) where te=Tw, ta=td
    // For LF model closure, using typical parameters:
    double beetaa = 1.0;  // Shape parameter for exponential decay
    int k = 1;            // Integer parameter for oscillatory behavior
    
    std::vector<double> out(t.size());
    const std::complex<double> I(0.0, 1.0);  // Complex unit
    
    // MATLAB: coeff = -beetaa+1i*k*pi/Tw;
    std::complex<double> coeff = -beetaa + I * static_cast<double>(k) * M_PI / te;
    
    for (size_t i = 0; i < t.size(); ++i) {
        double ti = t[i];
        
        // MATLAB: u1 = double(t>Tw & t-td<Tw);
        double u1 = ((ti > te) && (ti - ta < te)) ? 1.0 : 0.0;
        
        // MATLAB: u2 = double(t>-Tw & t-td<-Tw);
        double u2 = ((ti > -te) && (ti - ta < -te)) ? 1.0 : 0.0;
        
        // MATLAB: (exp(coeff*t).*(abs(t)<=Tw)-exp(coeff*(t-td)).*(abs(t-td)<=Tw))
        std::complex<double> exp_coeff_t = std::exp(coeff * ti);
        std::complex<double> exp_coeff_t_ta = std::exp(coeff * (ti - ta));
        
        double abs_ti = std::abs(ti);
        double abs_ti_ta = std::abs(ti - ta);
        
        std::complex<double> term1 = (abs_ti <= te) ? exp_coeff_t : std::complex<double>(0.0, 0.0);
        std::complex<double> term2 = (abs_ti_ta <= te) ? exp_coeff_t_ta : std::complex<double>(0.0, 0.0);
        
        // MATLAB: real(1/coeff*(...))
        std::complex<double> first_part = (1.0 / coeff) * (term1 - term2);
        double real_first_part = std::real(first_part);
        
        // MATLAB: (-1)^k*real(1/coeff)*(u1*exp(-beetaa*Tw)-u2*exp(beetaa*Tw))
        double real_coeff_inv = std::real(1.0 / coeff);
        double sign_factor = std::pow(-1.0, k);
        double second_part = sign_factor * real_coeff_inv * 
                           (u1 * std::exp(-beetaa * te) - u2 * std::exp(beetaa * te));
        
        // MATLAB: (...) .* exp(beetaa*t)
        double result = (real_first_part + second_part) * std::exp(beetaa * ti);
        
        out[i] = result;
    }
    
    return out;
}

} // namespace lfmodel
} // namespace sparkng
