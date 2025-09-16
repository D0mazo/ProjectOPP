// extra/Exporter.h
#pragma once
#include <string>
#include <vector>
#include "../core/Result.h"

class Exporter {
public:
    virtual void exportResults(const std::vector<Result>& results) = 0;
    virtual ~Exporter() = default;
};
