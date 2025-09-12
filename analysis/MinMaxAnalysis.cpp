#include "MinMaxAnalysis.h"
#include <algorithm>

// Vykdo min/max analizę (be spausdinimo – SRP)
void MinMaxAnalysis::run(const std::vector<double>& data) {
    if (data.empty()) {
        min_ = 0.0;
        max_ = 0.0;
        return;
    }
    // Naudoja std::minmax_element efektyvumui
    auto [minIt, maxIt] = std::minmax_element(data.begin(), data.end());
    min_ = *minIt;
    max_ = *maxIt;
}

// Grąžina analizės pavadinimą
std::string MinMaxAnalysis::name() const {
    return "Min/Max";
}

// ISP/DIP: Formatuoja min/max kaip eilutę (vietoj specifinių getMin()/getMax())
std::string MinMaxAnalysis::getFormattedResult() const {
    return "Min " + std::to_string(min_) + ", Max " + std::to_string(max_);
}