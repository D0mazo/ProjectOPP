
#include "CSVLoader.h"
#include <fstream>    // Failų skaitymui
#include <iostream>   // Išvesties srautui
#include <sstream>    // Eilučių apdorojimui


bool CSVLoader::load(const std::string& filename) {
    std::ifstream file(filename);
    if (!file) return false;


    data_.clear();
    std::string line;


    while (std::getline(file, line)) {
        // Sukuria srautą eilutės apdorojimui
        std::istringstream iss(line);
        std::string cell;
        //saugoti eilutės duomenis
        std::vector<double> row;
        // Skaito langelius, atskirtus kableliais
        while (std::getline(iss, cell, ',')) {
            try {
                // Konvertuoja langelio tekstą į skaičių ir prideda į eilutę
                row.push_back(std::stod(cell));
            } catch (...) {
                // Ignoruoja netinkamus skaičius
            }
        }
        // Jei eilutė nėra tuščia, prideda ją į duomenų masyvą
        if (!row.empty()) data_.push_back(row);
    }
    // Grąžina true, jei įkėlimas sėkmingas
    return true;
}

// Atvaizduoja duomenų santrauką
void CSVLoader::summary() const {
    // Spausdina eilučių skaičių
    std::cout << "Loaded dataset: " << data_.size() << " rows, ";
    // Jei yra duomenų, spausdina stulpelių skaičių, kitaip - 0
    if (!data_.empty()) std::cout << data_[0].size() << " columns.\n";
    else std::cout << "0 columns.\n";
}

// Grąžina nurodyto stulpelio duomenis
std::vector<double> CSVLoader::getColumn(size_t col) const {
    // Sukuria vektorių stulpelio duomenims
    std::vector<double> column;
    // Iteruoja per visas eilutes
    for (const auto& row : data_) {
        // Jei stulpelio indeksas galioja, prideda reikšmę
        if (col < row.size()) column.push_back(row[col]);
    }
    // Grąžina stulpelio duomenis
    return column;
}

// Grąžina stulpelių skaičių
size_t CSVLoader::columns() const {
    // Jei duomenys tušti, grąžina 0, kitaip - pirmos eilutės stulpelių skaičių
    return data_.empty() ? 0 : data_[0].size();
}