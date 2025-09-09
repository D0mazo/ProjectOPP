// Neleidžia daug kartų įtraukti šį antraštės failą
#ifndef REPORT_H
#define REPORT_H

// Įtraukiama biblioteka darbui su tekstinėmis eilutėmis
#include <string>

// Klasė ataskaitų išsaugojimui
class Report {
public:
    // Statinė funkcija, kuri išsaugo ataskaitą į failą
    // filename - failo pavadinimas, content - ataskaitos tekstas
    static void save(const std::string& filename, const std::string& content);
};

// Antraštės failo apsaugos pabaiga
#endif