#ifndef MEDIAN_ANALYSIS_H
#define MEDIAN_ANALYSIS_H

#include "Analysis.h"

class MedianAnalysis : public Analysis {
public:
    void run(const std::vector<double>& data) override;
    std::string name() const override;
};

#endif
