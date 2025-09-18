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
    // S (Single Responsibility Principle) – SimpleData atsakinga tik už vienos stulpelio duomenų laikymą ir manipuliavimą jais.
    // Kostruktorius
    SimpleData() : columnName(""), values() {}

    // vertės
    SimpleData(const std::string& colName, const std::vector<double>& vals, const std::string& ts = "")
        : columnName(colName), values(vals) {}

    // Pasiima, Enkasuliacija
    // S – šie metodai tik suteikia prieigą prie duomenų
    std::string getColumnName() const { return columnName; }
    const std::vector<double>& getValues() const { return values; }

    // S – metodas daro tik vieną dalyką: prideda reikšmę prie duomenų vektoriaus.
    void addValue(double val) {
        values.push_back(val);
    }


    // O (Open/Closed Principle) – galima plėsti toString, pvz., pridėti naują formatą, nekeičiant esamo metodo.
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

    // D (Dependency Inversion Principle) – tiesiogiai priklauso nuo std::cout
    // Jei norime DIP pilnai, galima perduoti abstraktų Output interfeisą.
    void print() const {
        std::cout << toString() << "\n";
    }

    // L (Liskov Substitution Principle) – jei kada nors paveldėtume SimpleData, override metodai turėtų išlaikyti
    // I (Interface Segregation Principle) – klasė neturi nereikalingų metodų; tik tie, kurie būtini stulpelio duomenims manipuliuoti ir parodyti.
};
