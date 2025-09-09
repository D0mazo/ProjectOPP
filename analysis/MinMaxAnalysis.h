#ifndef MINMAX_ANALYSIS_H
#define MINMAX_ANALYSIS_H

#include "Analysis.h"

class MinMaxAnalysis : public Analysis {
public:
    void run(const std::vector<double>& data) override;
    std::string name() const override;
};

#endif
