#include "hello.h"
#include "lfmodel.h"
#include <iostream>
#include <vector>

int main() {
    say_hello();
    
    // LFModel test parameters (textbook representative values)
    double tp = 0.2;    // Peak time
    double te = 0.6;    // End time
    double ta = 0.05;   // Attack time
    double tc = 1.0;    // Cycle time
    double Twor = 0.01; // World reference time
    
    // Create time axis from 0 to 1 with 0.01 step
    std::vector<double> time_values;
    for (double t = 0.0; t <= 1.0; t += 0.01) {
        time_values.push_back(t);
    }
    
    std::cout << "\nLFModel openTermk test results:\n";
    std::cout << "Parameters: tp=" << tp << ", te=" << te << ", ta=" << ta 
              << ", tc=" << tc << ", Twor=" << Twor << "\n\n";
    
    // Output approximately 10 values (every 10th value from 101 total)
    for (int i = 0; i < time_values.size(); i += 10) {
        double t = time_values[i];
        double result = openTermk(t, tp, te, ta, tc, Twor);
        std::cout << "LFModel openTermk value: t=" << t 
                  << ", result=" << result << std::endl;
    }
    
    return 0;
}
