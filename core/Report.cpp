#include "Report.h"
// input
#include <fstream>
//console
#include <iostream>

// Funkcija išsaugo ataskaitos tekstą į failą
void Report::save(const std::string& filename, const std::string& content) {
    std::ofstream file(filename);
    file << content;

    std::cout << "Report saved to " << filename << "\n";
}