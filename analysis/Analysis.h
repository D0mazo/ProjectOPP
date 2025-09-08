// Apsauga nuo daugkartinio antraštės failo įtraukimo
#ifndef ANALYSIS_H
#define ANALYSIS_H

// Įtraukiamos reikalingos bibliotekos
#include <string>   // Darbui su eilutėmis
#include <vector>   // Darbui su dinaminių masyvų vektoriais

// Abstrakti bazinė klasė analizės operacijoms
class Analysis {
public:
    // Virtualusis destruktorius, užtikrinantis tinkamą paveldinčių klasių išvalymą
    virtual ~Analysis() = default;

    // Grynoji virtualioji funkcija, skirta duomenų analizei atlikti
    // Parametras: const std::vector<double>& data - nuoroda į konstantinį dvigubo tikslumo skaičių vektorių
    virtual void run(const std::vector<double>& data) = 0;

    // Grynoji virtualioji funkcija, grąžinanti analizės pavadinimą
    // Grąžina: std::string - analizės pavadinimas
    // const žymi, kad funkcija nekeičia objekto būsenos
    virtual std::string name() const = 0;
};

// Antraštės apsaugos pabaiga
#endif