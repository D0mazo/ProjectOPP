#ifndef MEAN_ANALYSIS_H
#define MEAN_ANALYSIS_H

#include "Analysis.h"

class MeanAnalysis : public Analysis {
public:
    void run(const std::vector<double>& data) override;
    std::string name() const override;
};

#endif
