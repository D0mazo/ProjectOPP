// Apsauga nuo daugkartinio failo įtraukimo
#ifndef CSVLOADER_H
#define CSVLOADER_H

#include <string>
#include <vector>


//Klasė
class CSVLoader {
public:
    bool load(const std::string& filename);
    void summary() const;

    // Grąžina nurodyto stulpelio duomenis
    std::vector<double> getColumn(size_t col) const;
    // Grąžina stulpelių skaičių
    size_t columns() const;

private:
    std::vector<std::vector<double>> data_;
};

#endif