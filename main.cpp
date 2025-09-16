// Įtraukiamos reikalingos bibliotekos
#include <iostream>
#include <memory>
#include <sstream>
#include <vector>
#include <cctype>

// SRP : Single Responsibility Principle
#include "core/CSVLoader.h"
#include "core/Report.h"
#include "analysis/Analysis.h"

#include "analysis/MinMaxAnalysis.h"
#include "analysis/MedianAnalysis.h"
#include "analysis/MeanAnalysis.h"
#include "analysis/ModeAnalysis.h"
#include "analysis/SumAnalysis.h"

// --- OOP Demo Includes ---
#include "core/Result.h"              // Encapsulation
#include "extra/Exporter.h"           // Abstraction
#include "extra/TextExporter.h"       // Inheritance + Polymorphism
#include "extra/ConsoleExporter.h"    // Inheritance + Polymorphism
#include "extra/SimpleData.h"         // Class

int main() {
    CSVLoader loader;
    std::string file = "data.csv";

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
            std::cout << analysis->name() << ": ";
            analysis->run(data);
            std::string result = analysis->getFormattedResult();
            std::cout << result << "\n";
            oss << analysis->name() << ": " << result << "\n";
        }

        std::cout << "Issaugoti ataskaita? (t/n): ";
        char yn;
        std::cin >> yn;
        if (yn == 't' || yn == 'T') {
            Report::save("report.txt", oss.str());
        }

        // --- OOP DEMO: All Five Principles ---
        // 1. Class
        SimpleData demo("DemoColumn", 123);
        demo.print();

        // 2. Encapsulation
        std::vector<Result> results;
        for (auto& analysis : analyses) {
            results.emplace_back(analysis->name(), analysis->getFormattedResult());
        }

        // 3-5. Abstraction + Inheritance + Polymorphism
        std::vector<std::unique_ptr<Exporter>> exporters;
        exporters.push_back(std::make_unique<TextExporter>());
        exporters.push_back(std::make_unique<ConsoleExporter>());

        for (auto& e : exporters) {
            e->exportResults(results);  // Polymorphic call via abstract Exporter
        }
        // --- End OOP Demo ---
    }

    std::cout << "Analizatorius baigia darbą.\n";
    return 0;
}
