#include "MedianAnalysis.h"
#include <algorithm>
#include <iostream>

// Enkapsuliacija ir SRP: run() metodas apskaičiuoja medianą ir saugo rezultatą privačiame naryje
void MedianAnalysis::run(const std::vector<double>& data) {
    if (data.empty()) {
        std::cout << "Nėra duomenų.\n";
        result_ = 0.0;
        return;
    }
    // Sukuria kopiją, kad galėtų rūšiuoti
    std::vector<double> sorted_data = data;
    std::sort(sorted_data.begin(), sorted_data.end());
    size_t n = sorted_data.size();
    if (n % 2 == 0) {
        // Jei lyginis skaičius, mediana yra dviejų vidurinių elementų vidurkis
        result_ = (sorted_data[n / 2 - 1] + sorted_data[n / 2]) / 2.0;
    } else {
        // Jei nelyginis skaičius, mediana yra vidurinis elementas
        result_ = sorted_data[n / 2];
    }
    // Išveda rezultatą
    std::cout << "Mediana: " << result_ << "\n";
}

// Polimorfizmas: Grąžina MedianAnalysis specifinį analizės pavadinimą
std::string MedianAnalysis::name() const {
    return "Mediana";
}

// Enkapsuliacija: Kontroliuojama prieiga prie privataus nario
double MedianAnalysis::getResult() const {
    return result_;
}