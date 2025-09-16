// extra/TextExporter.h
#pragma once
#include "Exporter.h"
#include <iostream>

class TextExporter : public Exporter {
public:
    void exportResults(const std::vector<Result>& results) override {
        std::cout << "\n=== Tekstine ataskaita ===\n";
        for (const auto& r : results) {
            std::cout << r.getName() << ": " << r.getValue() << "\n";
        }
    }
};
