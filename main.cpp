// Įtraukiamos reikalingos bibliotekos
#include <iostream>
#include <memory>
#include <sstream>
#include <vector>
#include <cctype>

// SRP : Atsakingas už vieną : Single Responsibility Principle
#include "core/CSVLoader.h"
#include "analysis/Analysis.h"
#include "analysis/MinMaxAnalysis.h"
#include "analysis/MedianAnalysis.h"
#include "analysis/MeanAnalysis.h"
#include "analysis/ModeAnalysis.h"
#include "analysis/SumAnalysis.h"

// OPP principai
#include "core/Result.h"              // Enkapsuliacija
#include "extra/Exporter.h"           // Abstrakcija
#include "extra/TextExporter.h"       // Paveldėjimas ir Polimorfizmas
#include "extra/SimpleData.h"         // Klasė

int main() {

    std::cout << "Įveskite CSV failo pavadinimą: ";
    std::string file;
    std::cin >> file;

    CSVLoader loader;
    //std::string file = "data.csv";

    if (!loader.load(file)) {
        std::cout << "Nepavyko atidaryti " << file << ". Sukurkite paprastą skaitmeninį CSV failą.\n";
        return 1;
    }
    loader.summary();

    std::vector<std::unique_ptr<Analysis>> analyses;

    analyses.push_back(std::make_unique<MinMaxAnalysis>());
    analyses.push_back(std::make_unique<MedianAnalysis>());
    analyses.push_back(std::make_unique<MeanAnalysis>());
    analyses.push_back(std::make_unique<ModeAnalysis>());
    analyses.push_back(std::make_unique<SumAnalysis>());

    while (true) {
        std::cout << "\nPasirinkite stulpelį (A, B, C, D arba 'sad' iseiti): ";
        std::string input;
        std::cin >> input;

        if (input == "sad") break;

        if (input.length() != 1 || std::toupper(input[0]) < 'A' || std::toupper(input[0]) > 'D') {
            std::cout << "Neteisingas stulpelis. Naudokite A, B, C arba D.\n";
            continue;
        }

        int col = std::toupper(input[0]) - 'A';
        if (static_cast<size_t>(col) >= loader.columns()) {
            std::cout << "Neteisingas stulpelis.\n";
            continue;
        }

        auto data = loader.getColumn(col);
        if (data.empty()) {
            std::cout << "Stulpelis tuscias.\n";
            continue;
        }

        std::cout << "\n--- Vykdoma analize stulpeliui " << char('A' + col) << " ---\n";
        std::ostringstream oss;
        oss << "Ataskaita stulpeliui " << char('A' + col) << "\n";

        for (auto& analysis : analyses) {
                        analysis->run(data);
        }

        // Visi Principai
        // 1. Klasė
        std::string colName = std::string("Column ") + char('A' + col);
        SimpleData demo(colName, data);
        demo.print();

        // 2. Enkapsuliacija
        std::vector<Result> results;
        for (auto& analysis : analyses) {
            results.emplace_back(analysis->name(), analysis->getFormattedResult());
        }

        // Abstrakcija, Paveldėjimas, Polimorfizmas
        std::vector<std::unique_ptr<Exporter>> exporters;
        exporters.push_back(std::make_unique<TextExporter>());


        for (auto& e : exporters) {
            e->exportResults(results);
        }

    }


    std::cout << "Analizatorius baigia darbą.\n";
    return 0;
}
