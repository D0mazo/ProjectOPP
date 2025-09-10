// Apsaugo, kad šis failas nebūtų įtrauktas kelis kartus kompiliuojant
#ifndef MEDIANANALYSIS_H
#define MEDIANANALYSIS_H

#include "Analysis.h"
#include <string>
#include <vector>

// Paveldėjimas: MedianAnalysis paveldi iš Analysis
class MedianAnalysis : public Analysis {
public:
    // Polimorfizmas: Perrašo virtualias funkcijas iš Analysis
    void run(const std::vector<double>& data) override;
    std::string name() const override;
    // Enkapsuliacija: Viešasis metodas prieigai prie privataus nario
    double getResult() const;

private:
    // Enkapsuliacija: Privatus narys saugo analizės rezultatą
    double result_ = 0.0; // Saugo medianos rezultatą
};

// Baigia antraštės apsaugą
#endif