#include "CSVLoader.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <filesystem> // C++17+

// Single Responsibility Principle – ši klasė atsakinga tik už CSV failo užkrovimą ir duomenų laikymą.

bool CSVLoader::load(const std::string& filename) {
    namespace fs = std::filesystem;

    fs::path path = filename;
    std::ifstream file(path);

    // O (Open/Closed Principle) – kodas leidžia plėsti paieškos logiką (pvz., kelių direktorijų palaikymas),

    if (!file && fs::exists(fs::current_path().parent_path() / path)) {
        path = fs::current_path().parent_path() / path;
        file.open(path);
    }

    data_.clear();
    std::string line;

    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string cell;
        std::vector<double> row;

        // SIngle – atsakinga tik už eilučių konvertavimą į skaičius.
        while (std::getline(iss, cell, ',')) {
            try {
                row.push_back(std::stod(cell));
            } catch (...) {
                // L (Liskov Substitution Principle) – jei ateityje būtų paveldėta klasė,
                // ji neturėtų sulaužyti šio elgesio (pvz., kita implementacija galėtų loginti klaidas, bet neturėtų mesti nevaldomų išimčių).
            }
        }

        if (!row.empty()) {
            data_.push_back(row);
        }
    }
    return true;
}

// S – ši funkcija tik parodo duomenų suvestinę (output), o ne atlieka analizę.
// D (Dependency Inversion Principle) – ši funkcija tiesiogiai naudoja std::cout (aukšto lygio priklausomybė).
// Jei reikėtų atitikti DIP pilnai, reikėtų iškelti "output" priklausomybę į interfeisą.
void CSVLoader::summary() const {
    std::cout << "Loaded dataset: " << data_.size() << " rows, ";
    if (!data_.empty())
        std::cout << data_[0].size() << " columns.\n";
    else
        std::cout << "0 columns.\n";
}

// I (Interface Segregation Principle) – klasė pateikia atskirą metodą tik stulpeliui gauti,

std::vector<double> CSVLoader::getColumn(size_t col) const {
    std::vector<double> column;
    for (const auto& row : data_) {
        if (col < row.size()) {
            column.push_back(row[col]);
        }
    }
    return column;
}

// Single – vienintelis tikslas: gauti stulpelių skaičių.

size_t CSVLoader::columns() const {
    return data_.empty() ? 0 : data_[0].size();
}
