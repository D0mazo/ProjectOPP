#include "StdDevAnalysis.h"
#include <iostream>
#include <numeric>
#include <cmath>

void StdDevAnalysis::run(const std::vector<double>& data) {
    if (data.empty()) { std::cout << "No data.\n"; return; }
    double mean = std::accumulate(data.begin(), data.end(), 0.0) / data.size();
    double sq_sum = 0.0;
    for (double x : data) sq_sum += (x - mean) * (x - mean);
    double stdev = std::sqrt(sq_sum / data.size());
    std::cout << "Standard Deviation: " << stdev << "\n";
}

std::string StdDevAnalysis::name() const { return "Standard Deviation"; }
