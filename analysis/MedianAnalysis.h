#ifndef MEDIANANALYSIS_H
#define MEDIANANALYSIS_H

#include "Analysis.h"
#include <string>
#include <vector>

// Paveldėjimas: MedianAnalysis paveldi iš Analysis
class MedianAnalysis : public Analysis {
public:
    // Polimorfizmas: Perrašo run() iš Analysis
    void run(const std::vector<double>& data) override;
    // Polimorfizmas: Grąžina analizės pavadinimą
    std::string name() const override;
    // ISP/DIP: Formatuoja rezultatą kaip eilutę
    std::string getFormattedResult() const override;

private:
    // Enkapsuliacija: Privatus narys saugo medianą
    double result_ = 0.0;
};

#endif