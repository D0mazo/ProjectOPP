#include "MedianAnalysis.h"
#include <algorithm>

// Enkapsuliacija ir SRP: run() metodas apskaičiuoja medianą ir saugo rezultatą privačiame naryje
void MedianAnalysis::run(const std::vector<double>& data) {
    if (data.empty()) {
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

}

// Polimorfizmas: Grąžina MedianAnalysis specifinį analizės pavadinimą
std::string MedianAnalysis::name() const {
    return "Mediana";
}

// ISP/DIP: Grąžina rezultatą kaip eilutę, galima naudoti vėliau
std::string MedianAnalysis::getFormattedResult() const {
    return std::to_string(result_);
}
