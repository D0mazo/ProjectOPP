#ifndef MODE_ANALYSIS_H
#define MODE_ANALYSIS_H

#include "Analysis.h"
#include <optional>
#include <string>
#include <vector>

// Paveldėjimas: ModeAnalysis paveldi iš Analysis
class ModeAnalysis : public Analysis {
public:
    // Polimorfizmas: Perrašo run() iš Analysis
    void run(const std::vector<double>& data) override;
    // Polimorfizmas: Grąžina analizės pavadinimą
    std::string name() const override;
    // ISP/DIP: Formatuoja modą kaip eilutę
    std::string getFormattedResult() const override;

private:
    // Enkapsuliacija: Privatus narys saugo modą
    std::optional<double> result_;
    // Saugo dažnį (vidinis skaičiavimas)
    int frequency_ = 0;
};

#endif