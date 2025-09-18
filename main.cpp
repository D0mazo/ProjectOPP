// Įtraukiamos reikalingos bibliotekos
#include <iostream>
#include <memory>
#include <sstream>
#include <vector>
#include <cctype>

// SRP : Single Responsibility Principle – kiekviena įtraukta klasė atsakinga tik už vieną dalyką
#include "core/CSVLoader.h"       // CSV failo nuskaitymas
#include "analysis/Analysis.h"    // Abstrakti analizės klasė
#include "analysis/MinMaxAnalysis.h"
#include "analysis/MedianAnalysis.h"
#include "analysis/MeanAnalysis.h"
#include "analysis/ModeAnalysis.h"
#include "analysis/SumAnalysis.h"

// OOP principai
#include "core/Result.h"              // Enkapsuliacija – duomenys slepiami, prieiga tik per getter'us
#include "extra/Exporter.h"           // Abstrakcija – bendras eksportavimo interfeisas
#include "extra/TextExporter.h"       // Paveldėjimas ir Polimorfizmas – galima naudoti įvairius Exporter tipus
#include "extra/SimpleData.h"         // Klasė – duomenų struktūra su metodais

int main() {
    std::cout << "Iveskite CSV failo pavadinimA: ";
    std::string file;
    std::cin >> file;

    CSVLoader loader;
    // S – atsakingas tik už CSV duomenų užkrovimą
    if (!loader.load(file)) {
        std::cout << "Nepavyko atidaryti " << file << ". Sukurkite paprastą skaitmeninį CSV failą.\n";
        return 1;
    }
    loader.summary();

    while (true) {
        std::cout << "\nPasirinkite stulpelį (A, B, C ... arba 'sad' iseiti): ";
        std::string input;
        std::cin >> input;

        if (input == "sad") break;

        if (input.length() != 1 || !std::isalpha(input[0])) {
            std::cout << "Neteisingas stulpelis. Naudokite A, B, C ...\n";
            continue;
        }

        int col = std::toupper(input[0]) - 'A';
        if (static_cast<size_t>(col) >= loader.columns()) {
            std::cout << "Neteisingas stulpelis. Maksimalus stulpelis: "
                      << static_cast<char>('A' + loader.columns() - 1) << "\n";
            continue;
        }

        auto data = loader.getColumn(col);
        if (data.empty()) {
            std::cout << "Stulpelis tuscias.\n";
            continue;
        }
        // Liskov Substitution Principle  – naudojame abstrakcijas Analysis* vietoj konkrečių tipų
        std::vector<std::unique_ptr<Analysis>> analyses;
        analyses.push_back(std::make_unique<MinMaxAnalysis>());
        analyses.push_back(std::make_unique<MedianAnalysis>());
        analyses.push_back(std::make_unique<MeanAnalysis>());
        analyses.push_back(std::make_unique<ModeAnalysis>());
        analyses.push_back(std::make_unique<SumAnalysis>()); //Open/Coled principe


        std::cout << "\n--- Vykdoma analize stulpeliui " << char('A' + col) << " ---\n";
        std::ostringstream oss;
        oss << "Ataskaita stulpeliui " << char('A' + col) << "\n";

        // Polimorfizmas – visi analizės objektai naudojami per bendrą abstrakciją
        for (auto& analysis : analyses) {
            analysis->run(data);
        }

        // --------------------------
        // Visi OOP principai
        // 1. Klasė – SimpleData klasė saugo stulpelio duomenis ir metodus
        std::string colName = std::string("Column ") + char('A' + col);
        SimpleData demo(colName, data);
        ConsoleOutputStream consoleOutput;         // DIP-compliant srautas
        demo.print(consoleOutput);

        // 2. Enkapsuliacija – Result saugo analizės rezultatus su getter'iais
        std::vector<Result> results;
        for (auto& analysis : analyses) {
            results.emplace_back(analysis->name(), analysis->getFormattedResult());
        }

        // 3. Abstrakcija, Paveldėjimas, Polimorfizmas
        std::vector<std::unique_ptr<Exporter>> exporters;
        exporters.push_back(std::make_unique<TextExporter>(std::make_unique<ConsoleOutputStream>()));

        // Polimorfizmas – galima naudoti įvairius Exporter tipus per bendrą abstrakciją
        for (auto& e : exporters) {
            e->exportResults(results);
        }
    }

    std::cout << "Analizatorius baigia darbą.\n";
    return 0;
}