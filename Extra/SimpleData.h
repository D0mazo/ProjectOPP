#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>

class SimpleData {
private:
    std::string columnName;      // Name of the column (e.g., "Column A")
    std::vector<double> values;  // All values in the column
    std::string timestamp;       // Optional metadata (e.g., when data was loaded)
    bool isValid;                // Flag to indicate data validity

public:
    SimpleData()
         : columnName(""), values{}, timestamp(""), isValid(false) {}

    // Constructor to initialize with column name and values
    SimpleData(const std::string& colName, const std::vector<double>& vals, const std::string& ts = "")
        : columnName(colName), values(vals), timestamp(ts), isValid(!colName.empty() && !vals.empty()) {}

    // Getter methods (encapsulation)
    std::string getColumnName() const { return columnName; }
    const std::vector<double>& getValues() const { return values; }
    std::string getTimestamp() const { return timestamp; }
    bool isDataValid() const { return isValid; }

    // Add a single value to the column data
    void addValue(double val) {
        values.push_back(val);
        isValid = !values.empty();
    }

    // Format data as a string for display
    std::string toString() const {
        std::ostringstream oss;
        oss << "Column: " << columnName << ", Values: [";
        for (size_t i = 0; i < values.size(); ++i) {
            oss << values[i];
            if (i < values.size() - 1) oss << ", ";
        }
        oss << "]";
        if (!timestamp.empty()) {
            oss << ", Timestamp: " << timestamp;
        }
        return oss.str();
    }

    // Format data as CSV for exporting
    std::string toCSV() const {
        std::ostringstream oss;
        oss << columnName;
        for (const auto& val : values) {
            oss << "," << val;
        }
        if (!timestamp.empty()) {
            oss << "," << timestamp;
        }
        return oss.str();
    }

    // Compute basic statistics (e.g., sum) for the column
    double computeSum() const {
        double sum = 0.0;
        for (const auto& val : values) {
            sum += val;
        }
        return sum;
    }

    // Compute number of values
    size_t count() const {
        return values.size();
    }

    // Print method for debugging or display
    void print() const {
        std::cout << toString() << "\n";
    }
};