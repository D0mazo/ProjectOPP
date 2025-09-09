#ifndef STDDEV_ANALYSIS_H
#define STDDEV_ANALYSIS_H

#include "Analysis.h"

class StdDevAnalysis : public Analysis {
public:
    void run(const std::vector<double>& data) override;
    std::string name() const override;
};

#endif
