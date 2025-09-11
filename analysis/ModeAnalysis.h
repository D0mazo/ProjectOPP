#ifndef MODE_ANALYSIS_H
#define MODE_ANALYSIS_H

#include "Analysis.h"
#include <optional>

class ModeAnalysis : public Analysis {
public:
    void run(const std::vector<double>& data) override;
    std::string name() const override;

    // Getter for the computed result
    double getResult() const;

private:
    std::optional<double> result_;   // stores the computed mode
    int frequency_ = 0;              // frequency of mode
};

#endif
