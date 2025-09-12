#include "MeanAnalysis.h"
#include <numeric>

// Enkapsuliacija ir SRP: run() apskaičiuoja vidurkį privačiame naryje (be spausdinimo)
void MeanAnalysis::run(const std::vector<double>& data) {
    if (data.empty()) {
        result_ = 0.0;
        return;
    }
    // Skaičiuoja vidurkį su std::accumulate
    double sum = std::accumulate(data.begin(), data.end(), 0.0);
    result_ = sum / data.size();
}

// Polimorfizmas: Grąžina analizės pavadinimą
std::string MeanAnalysis::name() const {
    return "Vidurkis";
}

// ISP/DIP:
std::string MeanAnalysis::getFormattedResult() const {
    return std::to_string(result_);
}