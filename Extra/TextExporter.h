// extra/TextExporter.h
#pragma once
#include "Exporter.h"
#include <iostream>

// S (Single Responsibility Principle) – TextExporter atsakinga tik už rezultatų eksportavimą į tekstą.
class TextExporter : public Exporter {
public:
    // O (Open/Closed Principle) – metodas override‘ina abstraktų exportResults.
    // Galima pridėti naujus eksportavimo formatus paveldint Exporter, nekeisdami esamo kodo.
    void exportResults(const std::vector<Result>& results) override {
        std::cout << "\n=== Tekstine ataskaita ===\n";

        // S – atsakinga tik už rezultatų spausdinimą į konsolę.
        // L (Liskov Substitution Principle) – galima naudoti Exporter* pointerius su TextExporter
        for (const auto& r : results) {
            std::cout << r.getName() << ": " << r.getValue() << "\n";
        }

        // D (Dependency Inversion Principle) – šiuo metu tiesiogiai priklauso nuo std::cout.

    }
};
