#ifndef MEANANALYSIS_H
#define MEANANALYSIS_H

#include "Analysis.h"
#include <string>
#include <vector>

// Paveldėjimas: MeanAnalysis paveldi iš Analysis
class MeanAnalysis : public Analysis {
public:
    // Polimorfizmas: Perrašo run() iš Analysis
    void run(const std::vector<double>& data) override;
    // Polimorfizmas: Grąžina analizės pavadinimą
    std::string name() const override;
    // ISP/DIP: Formatuoja rezultatą kaip eilutę
    std::string getFormattedResult() const override;

private:
    // Enkapsuliacija: Privatus narys saugo vidurkį
    double result_ = 0.0;
};

#endif