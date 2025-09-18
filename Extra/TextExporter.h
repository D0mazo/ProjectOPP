#pragma once
#include "Exporter.h"
#include "OutputStream.h"
#include <memory>
#include <string>
#include <iostream>


// S (Single Responsibility Principle) – TextExporter atsakinga tik už rezultatų eksportavimą į tekstą.
class TextExporter : public Exporter {
public:
    // Constructor injection for the output stream (DIP)
    explicit TextExporter(std::unique_ptr<OutputStream> output)
        : outputStream(std::move(output)) {}

    // O (Open/Closed Principle) – metodas override‘ina abstraktų exportResults.
    // Galima pridėti naujus eksportavimo formatus paveldint Exporter, nekeisdami esamo kodo.
    void exportResults(const std::vector<Result>& results) override {
        outputStream->write("\n=== Tekstine ataskaita ===\n");

        // S – atsakinga tik už rezultatų spausdinimą į abstraktų srautą.
        // L (Liskov Substitution Principle) – galima naudoti Exporter* pointerius su TextExporter
        for (const auto& r : results) {
            outputStream->write(r.getName() + ": " + r.getValue() + "\n");
        }
    }

private:
    std::unique_ptr<OutputStream> outputStream;
};