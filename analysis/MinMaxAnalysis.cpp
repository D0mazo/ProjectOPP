#include "MinMaxAnalysis.h"
#include <iostream>
#include <algorithm>

void MinMaxAnalysis::run(const std::vector<double>& data) {
    if (data.empty()) { std::cout << "No data.\n"; return; }
    auto [minIt, maxIt] = std::minmax_element(data.begin(), data.end());
    std::cout << "Min: " << *minIt << ", Max: " << *maxIt << "\n";
}

std::string MinMaxAnalysis::name() const { return "Min/Max"; }
