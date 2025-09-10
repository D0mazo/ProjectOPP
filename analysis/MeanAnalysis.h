// Apsaugo, kad šis failas nebūtų įtrauktas kelis kartus kompiliuojant
#ifndef MEANANALYSIS_H
#define MEANANALYSIS_H

#include "Analysis.h"
#include <string>
#include <vector>

// Paveldėjimas: MeanAnalysis paveldi iš Analysis
class MeanAnalysis : public Analysis {
public:
    // Polimorfizmas: Perrašo virtualias funkcijas iš Analysis
    void run(const std::vector<double>& data) override;
    std::string name() const override;
    // Enkapsuliacija: Viešasis metodas prieigai prie privataus nario
    double getResult() const;

private:
    // Enkapsuliacija: Privatus narys saugo analizės rezultatą
    double result_ = 0.0; // Saugo vidurkio rezultatą
};

// Baigia antraštės apsaugą
#endif