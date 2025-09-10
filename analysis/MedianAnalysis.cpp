#include "MedianAnalysis.h"
#include <iostream>
#include <algorithm>

void MedianAnalysis::run(const std::vector<double>& data) {
    if (data.empty()) { std::cout << "No data.\n"; return; }
    std::vector<double> sorted = data;
    std::sort(sorted.begin(), sorted.end());
    double median;
    size_t n = sorted.size();
    if (n % 2 == 0) median = (sorted[n/2 - 1] + sorted[n/2]) / 2.0;
    else median = sorted[n/2];
    std::cout << "Median: " << median << "\n";
}

std::string MedianAnalysis::name() const { return "Median"; }
