#ifndef STDDEVANALYSIS_H
#define STDDEVANALYSIS_H

#include "Analysis.h"
#include <string>
#include <vector>

// Paveldėjimas: StdDevAnalysis paveldi iš Analysis
class StdDevAnalysis : public Analysis {
public:
    // Polimorfizmas: Perrašo run() iš Analysis
    void run(const std::vector<double>& data) override;
    // Polimorfizmas: Grąžina analizės pavadinimą
    std::string name() const override;
    // ISP/DIP: Formatuoja std. nuokrypį kaip eilutę
    std::string getFormattedResult() const override;

private:
    // Enkapsuliacija: Privatus narys saugo std. nuokrypį
    double result_ = 0.0;
};

#endif