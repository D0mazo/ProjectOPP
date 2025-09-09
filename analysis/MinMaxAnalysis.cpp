#include "MinMaxAnalysis.h"
#include <iostream>
#include <algorithm>

// Vykdo minimalios ir maksimalios reiksmes analize
void MinMaxAnalysis::run(const std::vector<double>& data) {
    if (data.empty()) {
        std::cout << "Nera duomenu.\n";
        min_ = 0.0;
        max_ = 0.0;
        return;
    }
    auto [minIt, maxIt] = std::minmax_element(data.begin(), data.end());
    min_ = *minIt;
    max_ = *maxIt;
    std::cout << "Min: " << min_ << ", Max: " << max_ << "\n";
}

// Grazina analizes pavadinima
std::string MinMaxAnalysis::name() const {
    return "Min/Max";
}

// Grazina minimalia reiksme
double MinMaxAnalysis::getMin() const {
    return min_;
}

// Grazina maksimalia reiksme
double MinMaxAnalysis::getMax() const {
    return max_;
}