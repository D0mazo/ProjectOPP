#include "MeanAnalysis.h"
#include <numeric>
#include <iostream>

// Enkapsuliacija ir SRP: run() metodas apskaičiuoja vidurkį ir saugo rezultatą privačiame naryje
void MeanAnalysis::run(const std::vector<double>& data) {
    if (data.empty()) {
        std::cout << "Nėra duomenų\n";
        result_ = 0.0;
        return;
    }
    // Skaičiuoja vidurkį
    double sum = std::accumulate(data.begin(), data.end(), 0.0);
    result_ = sum / data.size();
    // Išveda rezultatą
    std::cout << "Vidurkis: " << result_ << "\n";
}

// Polimorfizmas: Grąžina MeanAnalysis specifinį analizės pavadinimą
std::string MeanAnalysis::name() const {
    return "Vidurkis";
}

// Enkapsuliacija: Kontroliuojama prieiga prie privataus nario
double MeanAnalysis::getResult() const {
    return result_;
}