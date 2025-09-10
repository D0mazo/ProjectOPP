#include "MeanAnalysis.h"
#include <iostream>
#include <numeric>

void MeanAnalysis::run(const std::vector<double>& data) {
    if (data.empty()) { std::cout << "No data.\n"; return; }
    double sum = std::accumulate(data.begin(), data.end(), 0.0);
    double mean = sum / data.size();
    std::cout << "Mean: " << mean << "\n";
}

std::string MeanAnalysis::name() const { return "Mean"; }
