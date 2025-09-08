#ifndef ANALYSIS_H
#define ANALYSIS_H

#include <string>
#include <vector>

class Analysis {
public:
    virtual ~Analysis() = default;
    virtual void run(const std::vector<double>& data) = 0;
    virtual std::string name() const = 0;
};

#endif
