#include "StdDevAnalysis.h"
#include <cmath>
#include <numeric>
#include <iostream>

// Vykdo standartinio nuokrypio analizę
void StdDevAnalysis::run(const std::vector<double>& data) {
    if (data.empty()) {
        std::cout << "Nėra duomenų\n";
        result_ = 0.0;
        return;
    }
    // Skaičiuoja vidurkį
    double sum = std::accumulate(data.begin(), data.end(), 0.0);
    double mean = sum / data.size();
    // Skaičiuoja dispersiją
    double sq_sum = std::accumulate(data.begin(), data.end(), 0.0,
        [mean](double a, double b) { return a + (b - mean) * (b - mean); });
    result_ = std::sqrt(sq_sum / data.size());
    // Išveda rezultatą
    std::cout << result_ << "\n";
}

// Grąžina analizės pavadinimą
std::string StdDevAnalysis::name() const {
    return "Standartinis nuokrypis";
}

// ISP/DIP: Formatuoja rezultatą kaip eilutę (vietoj specifinio getResult())
std::string StdDevAnalysis::getFormattedResult() const {
    return std::to_string(result_);
}