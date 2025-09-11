#include "ModeAnalysis.h"
#include <iostream>
#include <map>

void ModeAnalysis::run(const std::vector<double>& data) {
    if (data.empty()) {
        std::cout << "No data.\n";
        result_.reset();
        frequency_ = 0;
        return;
    }

    std::map<double, int> freq;
    for (double x : data) freq[x]++;

    int maxCount = 0;
    double modeValue = data[0];
    for (auto& p : freq) {
        if (p.second > maxCount) {
            maxCount = p.second;
            modeValue = p.first;
        }
    }

    result_ = modeValue;
    frequency_ = maxCount;

    std::cout << "Mode: " << modeValue << " (appears " << maxCount << " times)\n";
}

std::string ModeAnalysis::name() const { return "Mode"; }

double ModeAnalysis::getResult() const {
    if (result_.has_value()) {
        return result_.value();
    } else {
        return 0.0; // or throw an exception if you prefer
    }
}
