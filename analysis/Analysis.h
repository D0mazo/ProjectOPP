// Apsaugo, kad šis failas nebūtų įtrauktas kelis kartus kompiliuojant
#ifndef ANALYSIS_H
#define ANALYSIS_H

// Įtraukiam bibliotekas
#include <string>   // Kad galėtume naudoti tekstą (eilutes)
#include <vector>   // Kad galėtume dirbti su kintamo dydžio skaičių sąrašais

// Klasė
class Analysis {
public:
    //išvalyti atminį
    virtual ~Analysis() = default;

    // Funkcija, kurią kiekviena paveldėta klasė turės įgyvendinti, kad apdorotų skaičių sąrašą
    // Gauna: vektorių su dvigubo tikslumo skaičiais (double)
    virtual void run(const std::vector<double>& data) = 0;

    // Funkcija, kuri grąžina analizės pavadinimą
    // const reiškia, kad funkcija nieko nekeičia klasėje
    virtual std::string name() const = 0;
};

// Baigiam antraštės apsaugą
#endif