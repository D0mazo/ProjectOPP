// extra/Exporter.h
#pragma once
#include <string>
#include <vector>
#include "../core/Result.h"

// S (Single Responsibility Principle) – šis abstraktus Exporter interfeisas atsakingas tik už rezultatų eksportavimo kontraktą.

class Exporter {
public:
    // O (Open/Closed Principle) – interfeisas leidžia pridėti naujus eksportavimo tipus (pvz., TextExporter, CSVExporter)

    virtual void exportResults(const std::vector<Result>& results) = 0;

    // L (Liskov Substitution Principle) – galima naudoti Exporter* arba Exporter& su bet kuria paveldėta klase
    virtual ~Exporter() = default;

};
