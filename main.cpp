// Įtraukiamos reikalingos bibliotekos
#include <iostream>
#include <memory>
#include <sstream>
#include <vector>
#include <cctype> // Dėl std::toupper funkcijos, kad galėtume apdoroti didžiąsias ir mažąsias raides

// Įtraukiami projekto antraštės failai
#include "core/CSVLoader.h"
#include "core/Report.h"
#include "analysis/Analysis.h"
#include "analysis/StdDevAnalysis.h"
#include "analysis/MinMaxAnalysis.h"
#include "analysis/MedianAnalysis.h"
#include "analysis/MeanAnalysis.h"
#include "analysis/ModeAnalysis.h"

int main() {
    // Enkapsuliacija ir SRP: CSVLoader klasė užkapsuliuoja CSV duomenų tvarkymą (įkėlimą, stulpelių gavimą) ir atsako tik už duomenų valdymą
    CSVLoader loader;
    std::string file = "data.csv";

    // Bando įkelti CSV failą
    if (!loader.load(file)) {
        std::cout << "Nepavyko atidaryti " << file << ". Sukurkite paprastą skaitmeninį CSV faila.\n";
        return 1;
    }

    // Enkapsuliacija: summary() metodas suteikia kontroliuojamą prieigą prie duomenų santraukos
    loader.summary();

    // Paveldėjimas ir Polimorfizmas: Analysis rodyklių vektorius leidžia skirtingus analizės tipus traktuoti vienodai
    // LSP: StdDevAnalysis, MinMaxAnalysis, MedianAnalysis, MeanAnalysis gali būti pakeisti Analysis be programos veikimo pažeidimo
    // DIP: Main priklauso nuo Analysis abstrakcijos, o ne nuo konkrečių implementacijų
    // OCP: Nauji analizės tipai gali būti pridėti prie analyses vektoriaus be kilpos keitimo
    std::vector<std::unique_ptr<Analysis>> analyses;
    analyses.push_back(std::make_unique<StdDevAnalysis>());
    analyses.push_back(std::make_unique<MinMaxAnalysis>());
    analyses.push_back(std::make_unique<MedianAnalysis>());
    analyses.push_back(std::make_unique<MeanAnalysis>());
    analyses.push_back(std::make_unique<ModeAnalysis>());

    while (true) {
        // Prašo vartotojo pasirinkti stulpelį arba išeiti
        std::cout << "\nPasirinkite stulpelį (A, B, C, D arba 'sad' iseiti): ";
        std::string input;
        std::cin >> input;

        // Tikrina išėjimo sąlygą
        if (input == "sad") break;

        // Validuoja įvestį: turi būti viena raidė (A, B, C, D)
        if (input.length() != 1 || std::toupper(input[0]) < 'A' || std::toupper(input[0]) > 'D') {
            std::cout << "Neteisingas stulpelis. Naudokite A, B, C arba D.\n";
            continue;
        }

        // Konvertuoja įvestą raidę į stulpelio indeksą (A=0, B=1, C=2, D=3)
        int col = std::toupper(input[0]) - 'A';
        if (static_cast<size_t>(col) >= loader.columns()) {
            std::cout << "Neteisingas stulpelis.\n";
            continue;
        }

        // Enkapsuliacija: getColumn() metodas suteikia kontroliuojamą prieigą prie CSV duomenų
        auto data = loader.getColumn(col);
        if (data.empty()) {
            std::cout << "Stulpelis tuscias.\n";
            continue;
        }

        // Vykdo analizę
        std::cout << "\n--- Vykdoma analize stulpeliui " << char('A' + col) << " ---\n";
        std::ostringstream oss;
        oss << "Ataskaita stulpeliui " << char('A' + col) << "\n";

        // Polimorfizmas: run() ir name() metodai kviečiami per Analysis rodykles, iškviečiant tinkamą paveldėtos klasės metodą
        // ISP (Pažeidimas): dynamic_cast priverčia priklausomybę nuo specifinių paveldėtų klasių metodų
        // DIP (Pažeidimas): dynamic_cast įveda priklausomybę nuo konkrečių klasių
        for (auto& analysis : analyses) {
            std::cout << analysis->name() << ": ";
            analysis->run(data);
            // Įtraukia rezultatą į ataskaitą
            if (auto* stdDevAnalysis = dynamic_cast<StdDevAnalysis*>(analysis.get())) {
                oss << analysis->name() << ": " << stdDevAnalysis->getResult() << "\n";
            } else if (auto* minMaxAnalysis = dynamic_cast<MinMaxAnalysis*>(analysis.get())) {
                oss << analysis->name() << ": Min " << minMaxAnalysis->getMin() << ", Max " << minMaxAnalysis->getMax() << "\n";
            } else if (auto* medianAnalysis = dynamic_cast<MedianAnalysis*>(analysis.get())) {
                oss << analysis->name() << ": " << medianAnalysis->getResult() << "\n";
            } else if (auto* meanAnalysis = dynamic_cast<MeanAnalysis*>(analysis.get())) {
                oss << analysis->name() << ": " << meanAnalysis->getResult() << "\n";
            } else if (auto* modeAnalysis = dynamic_cast<ModeAnalysis*>(analysis.get())) {
                oss << analysis->name() << ": " << modeAnalysis->getResult() << "\n";
            }

            // SRP: Report klasė atsakinga tik už ataskaitų išsaugojimą
            std::cout << "Issaugoti ataskaita? (t/n): ";
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
}