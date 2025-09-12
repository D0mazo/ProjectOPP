// Apsaugo, kad šis failas nebūtų įtrauktas kelis kartus kompiliuojant
#ifndef ANALYSIS_H
#define ANALYSIS_H

// Įtraukiam bibliotekas
#include <string>   // Kad galėtume naudoti tekstą (eilutes)
#include <vector>   // Kad galėtume dirbti su kintamo dydžio skaičių sąrašais

// Klasė – abstrakti bazinė visoms analizėms
// ISP: Pridedamas segreguotas metodas getFormattedResult() – klientas (main) priklauso tik nuo jo rezultatams
// DIP: Visi metodai abstraktūs – main priklauso nuo abstrakcijos, ne konkrečių implementacijų
class Analysis {
public:
    // Išvalyti atmintį – virtualus destruktorius polimorfizmui
    virtual ~Analysis() = default;

    // Funkcija, kurią kiekviena paveldėta klasė turės įgyvendinti, kad apdorotų skaičių sąrašą
    // Gauna: vektorių su dvigubo tikslumo skaičiais (double)
    // (Šis metodas apskaičiuoja rezultatus viduje, bet slepia detales)
    virtual void run(const std::vector<double>& data) = 0;

    // Funkcija, kuri grąžina analizės pavadinimą
    // const reiškia, kad funkcija nieko nekeičia klasėje
    virtual std::string name() const = 0;

    // NAUJAS METODAS: Grąžina formatuotą rezultatą kaip eilutę (pvz., "2.5" arba "Min 1, Max 3")
    // ISP: Vienintelis metodas rezultatams – segreguotas, klientas nežino specifinių detalių (pvz., getMin())
    // DIP: Polimorfinis – kiekviena subclass įgyvendina savo formatą, bet main kviečia per bazę
    // const: Saugus, nekeičia būsenos
    virtual std::string getFormattedResult() const = 0;
};

// Baigiam antraštės apsaugą
#endif