#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <sstream>


class SimpleData {
private:
    std::string columnName;
    std::vector<double> values;

public:
    // Default constructor
    SimpleData() : columnName(""), values() {}

    // Constructor to initialize with column name and values
    SimpleData(const std::string& colName, const std::vector<double>& vals, const std::string& ts = "")
        : columnName(colName), values(vals) {}

    // Getter methods (encapsulation)
    std::string getColumnName() const { return columnName; }
    const std::vector<double>& getValues() const { return values; }

    // Add a single value to the column data
    void addValue(double val) {
        values.push_back(val);
    }

    // Format data as a string for display
    std::string toString() const {
        std::ostringstream oss;
        oss << "Stulpelis: " << columnName << ", Reiksmes: [";
        for (size_t i = 0; i < values.size(); ++i) {
            oss << values[i];
            if (i < values.size() - 1) oss << ", ";
        }
        oss << "]";
        return oss.str(); // Return the formatted string
    }



    // Print method for debugging or display
    void print() const {
        std::cout << toString() << "\n";
    }
};