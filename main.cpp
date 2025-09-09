// Įtraukiamos reikalingos bibliotekos
#include <iostream>
#include <memory>
#include <sstream>
#include <vector>

// Įtraukiami projekto antraštės failai
#include "core/CSVLoader.h"
#include "core/Report.h"
#include "analysis/Analysis.h"
#include "analysis/StdDevAnalysis.h"

int main() {
    // Sukuria CSV įkėliklį
    CSVLoader loader;
    std::string file = "data.csv";

    // Bando įkelti CSV failą
    if (!loader.load(file)) {
        std::cout << "Nepavyko atidaryti " << file << ". Sukurkite paprastą skaitmeninį CSV failą.\n";
        return 1;
    }

    // Rodo duomenų santrauką
    loader.summary();

    // Sukuria analizės objektų vektorių (tik StdDevAnalysis)
    std::vector<std::unique_ptr<Analysis>> analyses;
    analyses.push_back(std::make_unique<StdDevAnalysis>());

    while (true) {
        // Prašo vartotojo pasirinkti stulpelį
        std::cout << "\nPasirinkite stulpelį (0.." << loader.columns()-1 << ", -1 išeiti): ";
        int col;
        std::cin >> col;
        if (col < 0) break;
        if (static_cast<size_t>(col) >= loader.columns()) {
            std::cout << "Neteisingas stulpelis.\n";
            continue;
        }

        // Gauna stulpelio duomenis
        auto data = loader.getColumn(col);
        if (data.empty()) {
            std::cout << "Stulpelis tuščias.\n";
            continue;
        }

        // Vykdo analizę
        std::cout << "\n--- Vykdoma analizė stulpeliui " << col << " ---\n";
        std::ostringstream oss;
        oss << "Ataskaita stulpeliui " << col << "\n";

        for (auto& analysis : analyses) {
            std::cout << analysis->name() << ": ";
            analysis->run(data);
            // Įtraukia rezultatą į ataskaitą
            auto* stdDevAnalysis = dynamic_cast<StdDevAnalysis*>(analysis.get());
            if (stdDevAnalysis) {
                oss << analysis->name() << ": " << stdDevAnalysis->getResult() << "\n";
            }
        }

        // Klausia, ar išsaugoti ataskaitą
        std::cout << "Išsaugoti ataskaitą? (t/n): ";
        char yn;
        std::cin >> yn;
        if (yn == 't' || yn == 'T') {
            Report::save("report.txt", oss.str());
        }
    }

    // Praneša apie programos pabaigą
    std::cout << "Analizatorius baigia darbą.\n";
    return 0;
}