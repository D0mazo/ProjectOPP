#ifndef REPORT_H
#define REPORT_H


#include <string>

// Klasė
class Report {
public:
    static void save(const std::string& filename, const std::string& content);
};


#endif