// Apsauga nuo daugkartinio failo įtraukimo
#ifndef CSVLOADER_H
#define CSVLOADER_H

#include <string>   // Eilutėms
#include <vector>   // Vektoriams

// Klasė CSV failų įkėlimui ir tvarkymui
class CSVLoader {
public:
    // Įkelia duomenis iš CSV failo, grąžina true, jei sėkmingai
    bool load(const std::string& filename);

    // Rodo duomenų santrauką
    void summary() const;

    // Grąžina nurodyto stulpelio duomenis
    std::vector<double> getColumn(size_t col) const;

    // Grąžina stulpelių skaičių
    size_t columns() const;

private:
    // Duomenys: vektorius su eilutėmis iš dvigubo tikslumo skaičių
    std::vector<std::vector<double>> data_;
};

// Apsaugos pabaiga
#endif