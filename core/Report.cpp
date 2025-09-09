// Įtraukiamas antraštės failas su Report klasės aprašymu
#include "Report.h"
// Biblioteka failų rašymui
#include <fstream>
// Biblioteka tekstinei išvestiai į konsolę
#include <iostream>

// Funkcija išsaugo ataskaitos tekstą į failą
void Report::save(const std::string& filename, const std::string& content) {
    // Atidaro failą rašymui
    std::ofstream file(filename);
    // Įrašo ataskaitos turinį į failą
    file << content;
    // Praneša, kad ataskaita sėkmingai išsaugota
    std::cout << "Report saved to " << filename << "\n";
}