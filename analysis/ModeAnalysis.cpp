#include "ModeAnalysis.h"
#include <map>

// Vykdo modą analizę (be spausdinimo – SRP)
void ModeAnalysis::run(const std::vector<double>& data) {
    if (data.empty()) {
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
}

// Grąžina analizės pavadinimą
std::string ModeAnalysis::name() const {
    return "Mode";
}

// ISP/DIP: Formatuoja modą ir dažnį kaip eilutę (tvarko optional)
std::string ModeAnalysis::getFormattedResult() const {
    if (result_.has_value()) {
        return std::to_string(result_.value()) + " (appears " + std::to_string(frequency_) + " times)";
    } else {
        return "No mode";
    }
}