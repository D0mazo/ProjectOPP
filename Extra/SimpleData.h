#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include "OutputStream.h"


class SimpleData {
private:
    std::string columnName;
    std::vector<double> values;

public:
    // S (Single Responsibility Principle) – SimpleData atsakinga tik už vienos stulpelio duomenų laikymą ir manipuliavimą jais.
    // Kostruktorius
    SimpleData() : columnName(""), values() {}

    // vertės
    SimpleData(const std::string& colName, const std::vector<double>& vals, const std::string& ts = "")
        : columnName(colName), values(vals) {}

    // Pasiima, Enkasuliacija
    std::string getColumnName() const { return columnName; }
    const std::vector<double>& getValues() const { return values; }

    void addValue(double val) {
        values.push_back(val);
    }


    // O (Open/Closed Principle)
    std::string toString() const {
        std::ostringstream oss;
        oss << "Stulpelis: " << columnName << ", Reiksmes: [";
        for (size_t i = 0; i < values.size(); ++i) {
            oss << values[i];
            if (i < values.size() - 1) oss << ", ";
        }
        oss << "]";
        return oss.str();
    }

    // DIP
    void print(OutputStream& output) const {
        output.write(toString());
    }

};
