// extra/ConsoleExporter.h
#pragma once
#include "Exporter.h"
#include <iostream>

class ConsoleExporter : public Exporter {
public:
    void exportResults(const std::vector<Result>& results) override {
        std::cout << "\n=== Konsoles ataskaita ===\n";
        for (const auto& r : results) {
            std::cout << "[RESULT] " << r.getName() << " -> " << r.getValue() << "\n";
        }
    }
};
