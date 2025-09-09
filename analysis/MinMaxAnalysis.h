// Neleidzia daug kartu itinukti si antrastes faila
#ifndef MINMAXANALYSIS_H
#define MINMAXANALYSIS_H

#include "Analysis.h"
#include <string>
#include <vector>

// Klase minimalios ir maksimalios reiksmes skaiciavimui
class MinMaxAnalysis : public Analysis {
public:
    // Vykdo minimalios ir maksimalios reiksmes analize
    void run(const std::vector<double>& data) override;
    // Grazina analizes pavadinima
    std::string name() const override;
    // Grazina minimalia reiksme
    double getMin() const;
    // Grazina maksimalia reiksme
    double getMax() const;

private:
    double min_ = 0.0; // Saugo minimalia reiksme
    double max_ = 0.0; // Saugo maksimalia reiksme
};

// Antrastes apsaugos pabaiga
#endif