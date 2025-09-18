// core/Result.h
#pragma once
#include <string>

// Klasė – Result saugo vieno analizės rezultato informaciją
// S (Single Responsibility Principle) – atsakinga tik už vieno analizės rezultato laikymą
class Result {
private:
    // Enkapsuliacija – duomenys slepiami, prieiga tik per getter ir setter metodus
    std::string analysisName;
    std::string value;

public:
    // Konstruktoriumi nustatome pavadinimą ir rezultatą
    Result(const std::string& name, const std::string& val)
        : analysisName(name), value(val) {}

    // Getter'iai – tik skaitymui
    // Enkapsuliacija užtikrina, kad duomenys negali būti keičiami tiesiogiai iš išorės
    std::string getName() const { return analysisName; }
    std::string getValue() const { return value; }

    // Setter – leidžia pakeisti rezultatą, jei reikia
    // Liskov Substitution Principle – galima paveldėti Result
    void setValue(const std::string& val) { value = val; }

    // I (Interface Segregation Principle) – klasė turi tik būtinus metodus, nereikia papildomų funkcijų
};
