#ifndef
 SPARKNG_LFMODEL_H
#define
 SPARKNG_LFMODEL_H
#include
 <vector>
#include
 <complex>
namespace
 sparkng 
{
namespace
 lfmodel 
{
/**
 * LFModelOutput structure containing LF waveform generation results
 * Stores various output parameters from LF model processing
 */
struct
 LFModelOutput 
{
    std::vector<double>&gt;
 
source
;              
// Source signal vector
    std::vector<double>&gt;
 
volumeVelocity
;      
// Volume velocity output
    std::vector<double>&gt;
 
antiAliasedSource
;   
// Anti-aliased source signal
    double 
decayRate
;                        
// Signal decay rate parameter
    double 
growthRate
;                       
// Signal growth rate parameter
    
    
// Default constructor
    
LFModelOutput
(
)
 : 
decayRate
(
0.0
), 
growthRate
(
0.0
) 
{
}
}
;
/**
 * Generate opening terminal phase of LF waveform
 * Creates the initial opening portion of the glottal flow model
 * @param t Time vector (std::vector<double>)
 * @param tp Time of peak glottal opening (double)
 * @param te Time of glottal closure (double)
 * @return Opening terminal waveform values (std::vector<double>)
 */
std::vector<double>&gt;
 
openTermk
(
const
 std::vector<double>&gt;
& t, double tp, double te
);
/**
 * Generate opening I5 phase of LF waveform
 * Creates the I5 component during glottal opening
 * @param t Time vector (std::vector<double>)
 * @param tp Time of peak glottal opening (double)
 * @param alpha Shape parameter (double)
 * @return Opening I5 waveform values (std::vector<double>)
 */
std::vector<double>&gt;
 
openI5
(
const
 std::vector<double>&gt;
& t, double tp, double alpha
);
/**
 * Generate closing I4 phase of LF waveform
 * Creates the I4 component during glottal closure
 * @param t Time vector (std::vector<double>)
 * @param te Time of glottal closure (double)
 * @param ta Time of return phase start (double)
 * @return Closing I4 waveform values (std::vector<double>)
 */
std::vector<double>&gt;
 
closeI4
(
const
 std::vector<double>&gt;
& t, double te, double ta
);
/**
 * Generate closing I2k0xi0 phase of LF waveform
 * Creates the I2k0xi0 component with zero damping during closure
 * @param t Time vector (std::vector<double>)
 * @param omega Angular frequency parameter (double)
 * @param phase Phase offset (double)
 * @return Closing I2k0xi0 waveform values (std::vector<double>)
 */
std::vector<double>&gt;
 
closeI2k0xi0
(
const
 std::vector<double>&gt;
& t, double omega, double phase
);
/**
 * Generate closing I2kn0 phase of LF waveform
 * Creates the I2kn0 component with nth-order characteristics
 * @param t Time vector (std::vector<double>)
 * @param omega Angular frequency parameter (double)
 * @param n Order parameter (int)
 * @return Closing I2kn0 waveform values (std::vector<double>)
 */
std::vector<double>&gt;
 
closeI2kn0
(
const
 std::vector<double>&gt;
& t, double omega, int n
);
