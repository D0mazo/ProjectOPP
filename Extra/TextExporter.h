#pragma once
#include "Exporter.h"
#include "OutputStream.h"
#include <memory>
#include <string>
#include <iostream>


// S (Single Responsibility Principle) – TextExporter atsakinga tik už rezultatų eksportavimą į tekstą.
class TextExporter : public Exporter {
public:
    //DIP
    explicit TextExporter(std::unique_ptr<OutputStream> output)
        : outputStream(std::move(output)) {}

    void exportResults(const std::vector<Result>& results) override {
        outputStream->write("\n=== Tekstine ataskaita ===\n");

        for (const auto& r : results) {
            outputStream->write(r.getName() + ": " + r.getValue() + "\n");
        }
    }

private:
    std::unique_ptr<OutputStream> outputStream;
};