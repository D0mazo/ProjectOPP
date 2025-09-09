// Itinukiamos reikalingos bibliotekos
#include <iostream>
#include <memory>
#include <sstream>
#include <vector>

// Itinukiami projekto antrastes failai
#include "core/CSVLoader.h"
#include "core/Report.h"
#include "analysis/Analysis.h"
#include "analysis/StdDevAnalysis.h"

int main() {
    // Sukuria CSV ikelikli
    CSVLoader loader;
    std::string file = "data.csv";

    // Bando ikelti CSV faila
    if (!loader.load(file)) {
        std::cout << "Nepavyko atidaryti " << file << ". Sukurkite paprasta skaitmenini CSV faila.\n";
        return 1;
    }

    // Rodo duomenu santrauka
    loader.summary();

    // Sukuria analizes objektu vektoriu (tik StdDevAnalysis)
    std::vector<std::unique_ptr<Analysis>> analyses;
    analyses.push_back(std::make_unique<StdDevAnalysis>());

    while (true) {
        // Praso vartotojo pasirinkti stulpeli
        std::cout << "\nPasirinkite stulpeli (0.." << loader.columns()-1 << ", -1 iseiti): ";
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
            std::cout << "Stulpelis tuscias.\n";
            continue;
        }

        // Vykdo analize
        std::cout << "\n--- Vykdoma analize stulpeliui " << col << " ---\n";
        std::ostringstream oss;
        oss << "Ataskaita stulpeliui " << col << "\n";

        for (auto& analysis : analyses) {
            std::cout << analysis->name() << ": ";
            analysis->run(data);
            // Itraukia rezultata i ataskaita
            auto* stdDevAnalysis = dynamic_cast<StdDevAnalysis*>(analysis.get());
            if (stdDevAnalysis) {
                oss << analysis->name() << ": " << stdDevAnalysis->getResult() << "\n";
            }
        }

        // Klausia, ar issaugoti ataskaita
        std::cout << "Issaugoti ataskaita? (t/n): ";
        char yn;
        std::cin >> yn;
        if (yn == 't' || yn == 'T') {
            Report::save("report.txt", oss.str());
        }
    }

    // Pranesa apie programos pabaiga
    std::cout << "Analizatorius baigia darba.\n";
    return 0;
}