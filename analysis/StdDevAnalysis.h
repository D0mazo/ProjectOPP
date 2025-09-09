// Neleidžia daug kartų įtraukti šį antraštės failą
#ifndef STDDEVANALYSIS_H
#define STDDEVANALYSIS_H

#include "Analysis.h"
#include <string>
#include <vector>

// Klasė standartinio nuokrypio skaičiavimui
class StdDevAnalysis : public Analysis {
public:
    // Vykdo standartinio nuokrypio analizę
    void run(const std::vector<double>& data) override;
    // Grąžina analizės pavadinimą
    std::string name() const override;
    // Grąžina paskutinės analizės rezultatą
    double getResult() const;

private:
    double result_ = 0.0; // Saugo standartinio nuokrypio rezultatą
};

// Antraštės apsaugos pabaiga
#endif