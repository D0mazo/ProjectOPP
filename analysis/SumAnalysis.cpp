#include "SumAnalysis.h"
#include <numeric>

void SumAnalysis::run(const std::vector<double>& data) {
    if (data.empty()) {
        result_.reset();
        return;
    }
    result_ = std::accumulate(data.begin(), data.end(), 0.0);
}

std::string SumAnalysis::name() const {
    return "Sum";
}

std::string SumAnalysis::getFormattedResult() const {
    return result_.has_value() ? std::to_string(result_.value()) : "N/A";
}