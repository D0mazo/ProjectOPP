#ifndef MINMAXANALYSIS_H
#define MINMAXANALYSIS_H

#include "Analysis.h"
#include <string>
#include <vector>

// Paveldėjimas: MinMaxAnalysis paveldi iš Analysis
class MinMaxAnalysis : public Analysis {
public:
    // Polimorfizmas: Perrašo run() iš Analysis
    void run(const std::vector<double>& data) override;
    // Polimorfizmas: Grąžina analizės pavadinimą
    std::string name() const override;
    // ISP/DIP: Formatuoja min/max kaip eilutę
    std::string getFormattedResult() const override;

private:
    // Enkapsuliacija: Privatūs nariai saugo min/max
    double min_ = 0.0;
    double max_ = 0.0;
};

#endif