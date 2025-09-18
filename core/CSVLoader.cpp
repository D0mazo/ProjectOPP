#include "CSVLoader.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <filesystem> // C++17+

bool CSVLoader::load(const std::string& filename) {
    //duomenų pasiėmimas
    namespace fs = std::filesystem;

    fs::path path = filename;
    std::ifstream file(path);
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

        // Skaito langelius, atskirtus kableliais
        while (std::getline(iss, cell, ',')) {
            try {
                row.push_back(std::stod(cell));
            } catch (...) {
                // Ignoruoja netinkamus skaičius
            }
        }

        if (!row.empty()) {
            data_.push_back(row);
        }
    }
    return true;
}
//outputas consolėje
void CSVLoader::summary() const {
    std::cout << "Loaded dataset: " << data_.size() << " rows, ";
    if (!data_.empty())
        std::cout << data_[0].size() << " columns.\n";
    else
        std::cout << "0 columns.\n";
}

std::vector<double> CSVLoader::getColumn(size_t col) const {
    std::vector<double> column;
    for (const auto& row : data_) {
        if (col < row.size()) {
            column.push_back(row[col]);
        }
    }
    return column;
}

size_t CSVLoader::columns() const {
    return data_.empty() ? 0 : data_[0].size();
}
