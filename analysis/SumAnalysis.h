#ifndef SUM_ANALYSIS_H
#define SUM_ANALYSIS_H

#include "Analysis.h"
#include <optional>
#include <vector>

class SumAnalysis : public Analysis {
private:
    std::optional<double> result_; // Store the sum result
public:
    // Override virtual methods from Analysis
    void run(const std::vector<double>& data) override;
    std::string name() const override;
    std::string getFormattedResult() const override;
};

#endif