#include "Report.h"
#include <fstream>
#include <iostream>

void Report::save(const std::string& filename, const std::string& content) {
    std::ofstream file(filename);
    file << content;
    std::cout << "Report saved to " << filename << "\n";
}
