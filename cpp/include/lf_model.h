#ifndef SPARKNG_LFMODEL_H
#define SPARKNG_LFMODEL_H

#include <vector>
#include <complex>

namespace sparkng {
namespace lfmodel {

/**
 * LFModelOutput structure containing LF waveform generation results
 * Stores various output parameters from LF model processing
 */
struct LFModelOutput {
    std::vector<double> source;              // Source signal vector
    std::vector<double> volumeVelocity;      // Volume velocity output
    std::vector<double> antiAliasedSource;   // Anti-aliased source signal
    double decayRate;                        // Signal decay rate parameter
    double growthRate;                       // Signal growth rate parameter
    
    // Default constructor
    LFModelOutput() : decayRate(0.0), growthRate(0.0) {}
};

/**
 * Generate opening terminal phase of LF waveform
 * Creates the initial opening portion of the glottal flow model
 * @param t Time vector (std::vector<double>)
 * @param tp Time of peak glottal opening (double)
 * @param te Time of glottal closure (double)
 * @return Opening terminal waveform values (std::vector<double>)
 */
std::vector<double> openTermk(const std::vector<double>& t, double tp, double te);

/**
 * Generate opening I5 phase of LF waveform
 * Creates the I5 component during glottal opening
 * @param t Time vector (std::vector<double>)
 * @param tp Time of peak glottal opening (double)
 * @param alpha Shape parameter (double)
 * @return Opening I5 waveform values (std::vector<double>)
 */
std::vector<double> openI5(const std::vector<double>& t, double tp, double alpha);

/**
 * Generate closing I4 phase of LF waveform
 * Creates the I4 component during glottal closure
 * @param t Time vector (std::vector<double>)
 * @param te Time of glottal closure (double)
 * @param ta Time of return phase start (double)
 * @return Closing I4 waveform values (std::vector<double>)
 */
std::vector<double> closeI4(const std::vector<double>& t, double te, double ta);

/**
 * Generate closing I2k0xi0 phase of LF waveform
 * Creates the I2k0xi0 component with zero damping during closure
 * @param t Time vector (std::vector<double>)
 * @param omega Angular frequency parameter (double)
 * @param phase Phase offset (double)
 * @return Closing I2k0xi0 waveform values (std::vector<double>)
 */
std::vector<double> closeI2k0xi0(const std::vector<double>& t, double omega, double phase);

/**
 * Generate closing I2kn0 phase of LF waveform
 * Creates the I2kn0 component with nth-order characteristics
 * @param t Time vector (std::vector<double>)
 * @param omega Angular frequency parameter (double)
 * @param n Order parameter (int)
 * @return Closing I2kn0 waveform values (std::vector<double>)
 */
std::vector<double> closeI2kn0(const std::vector<double>& t, double omega, int n);

/**
 * Generate closing I4k0 phase of LF waveform
 * Creates the I4k0 component with zero damping during closure
 * @param t Time vector (std::vector<double>)
 * @param omega Angular frequency parameter (double)
 * @param amplitude Amplitude scaling factor (double)
 * @return Closing I4k0 waveform values (std::vector<double>)
 */
std::vector<double> closeI4k0(const std::vector<double>& t, double omega, double amplitude);

} // namespace lfmodel
} // namespace sparkng

#endif // SPARKNG_LFMODEL_H
