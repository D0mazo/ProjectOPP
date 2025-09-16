// core/Result.h
#pragma once
#include <string>

//Klasė
class Result {
private:
    std::string analysisName;
    std::string value;

public:
    Result(const std::string& name, const std::string& val)
        : analysisName(name), value(val) {}

    std::string getName() const { return analysisName; }
    std::string getValue() const { return value; }

    void setValue(const std::string& val) { value = val; }
};
