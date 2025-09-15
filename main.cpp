// Įtraukiamos reikalingos bibliotekos
#include <iostream>  // Naudojama standartiniam įvesties/išvesties tvarkymui (std::cout, std::cin)
#include <memory>    // Naudojama išmaniems rodyklėms (std::unique_ptr) – užtikrina atminties valdymą be nutekėjimų (RAII principas)
#include <sstream>   // Naudojama std::ostringstream rezultatų kaupimui į stringą (efektyvus buferis ataskaitoms)
#include <vector>    // Naudojama std::vector analizės objektams laikyti – dinamiškas masyvas su polimorfiniais objektais
#include <cctype>    // Dėl std::toupper funkcijos, kad galėtume apdoroti didžiąsias ir mažąsias raides (įvesties normalizavimas)

//SRP : Single Responsibility Principle
#include "core/CSVLoader.h"      // Klasė duomenų įkėlimui iš CSV – enkapsuliuoja failo skaitymą
#include "core/Report.h"         // Klasė ataskaitų išsaugojimui – atsakinga tik už failo rašymą (SRP)
#include "analysis/Analysis.h"   // Bazinė abstrakcijos klasė analizėms – apibrėžia bendrą interfeisą (Abstrakcija, DIP)
#include "analysis/StdDevAnalysis.h"  // Konkretus analizės tipas (standartinis nuokrypis) – paveldi iš Analysis (Paveldėjimas)
#include "analysis/MinMaxAnalysis.h"  // Min/Max analizė – paveldi, leidžia polimorfizmą
#include "analysis/MedianAnalysis.h"  // Mediana – paveldi, užtikrina LSP (gali pakeisti bazę be klaidų)
#include "analysis/MeanAnalysis.h"    // Vidurkis – paveldi
#include "analysis/ModeAnalysis.h"    // Moda – paveldi
#include "analysis/SumAnalysis.h"

int main() {
    // Enkapsuliacija ir SRP: CSVLoader klasė užkapsuliuoja CSV duomenų tvarkymą (įkėlimą, stulpelių gavimą)
    CSVLoader loader;  // enkapsuliuoja visą CSV logiką
    std::string file = "data.csv";  // SRP

    // įkelia CSV failą, Abstrakcija
    if (!loader.load(file)) {
        std::cout << "Nepavyko atidaryti " << file << ". Sukurkite paprastą skaitmeninį CSV failą.\n";
        return 1;
    }
    // Enkapsuliacija
    loader.summary(); // kiek ko

    // Paveldėjimas ir Polimorfizmas: Analysis rodyklių vektorius leidžia skirtingus analizės tipus traktuoti vienodai
    // DIP: Main priklauso nuo Analysis abstrakcijos, o ne nuo konkrečių implementacijų
    std::vector<std::unique_ptr<Analysis>> analyses;  // polimorfizmas + atminties saugumas (neprivaloma išvalyti)
    analyses.push_back(std::make_unique<StdDevAnalysis>());  // Standartinis nuokrypis - paveldėjimas
    analyses.push_back(std::make_unique<MinMaxAnalysis>());  // Min/Max – polimorfiškai kviečiamas run()
    analyses.push_back(std::make_unique<MedianAnalysis>());  // Mediana
    analyses.push_back(std::make_unique<MeanAnalysis>());    // Vidurkis
    analyses.push_back(std::make_unique<ModeAnalysis>());    // Moda

    // OCP: Nauji analizės tipai gali būti pridėti, plėtra be modifikacijos – pridėti push_back ir viskas veikia
    // LSP: StdDevAnalysis, MinMaxAnalysis, MedianAnalysis, MeanAnalysis gali būti pakeisti Analysis be programos veikimo pažeidimo
    analyses.push_back(std::make_unique<SumAnalysis>());

    // kilpa opcijoms (SRP: main() atsakingas už ciklą ir įvestį)
    while (true) {
        // Prašo vartotojo pasirinkti stulpelį arba išeiti – sad
        std::cout << "\nPasirinkite stulpelį (A, B, C, D arba 'sad' iseiti): ";
        std::string input;
        std::cin >> input;  // Skaito įvestį

        // Tikrina išėjimo sąlygą
        if (input == "sad") break;  //nutraukia

        //įvesties validacija
        // SRP
        if (input.length() != 1 || std::toupper(input[0]) < 'A' || std::toupper(input[0]) > 'D') { //std::toupper – case-insensitive
            std::cout << "Neteisingas stulpelis. Naudokite A, B, C arba D.\n";
            continue;  // grįžta be vykdymo
        }


        // (Konvertuoja įvestą raidę į stulpelio indeksą, Abstrakcija: slepia, kad viduje stulpeliai indeksuojami nuo 0)
        int col = std::toupper(input[0]) - 'A';  // Raidę paverčia skaičiumi (pvz., 'B' -> 1)
        // tikrina ribas
        if (static_cast<size_t>(col) >= loader.columns()) {
            std::cout << "Neteisingas stulpelis.\n"; // jei nėra, klaida
            continue;
        }

        // Enkapsuliacija: getColumn() metodas suteikia kontroliuojamą prieigą prie CSV duomenų
        auto data = loader.getColumn(col);
        if (data.empty()) {
            std::cout << "Stulpelis tuscias.\n";
            continue;
        }

        // Vykdo analizę – pranešimas vartotojui
        std::cout << "\n--- Vykdoma analize stulpeliui " << char('A' + col) << " ---\n";  // Išveda stulpelio raidę
        std::ostringstream oss;
        oss << "Ataskaita stulpeliui " << char('A' + col) << "\n";  // Pradeda ataskaitą

        // Polimorfizmas: run() ir name() metodai kviečiami per Analysis rodykles, iškviečiant tinkamą paveldėtos klasės metodą
        //ISP ir DIP pažeistas
        for (auto& analysis : analyses) {  // Ciklas per visas analizes – OCP
            std::cout << analysis->name() << ": ";  // Polimorfizmas: name() per bazę
            analysis->run(data);  // Vykdo analizę – virtualus metodas, polimorfiškas
            std::string result = analysis->getFormattedResult();  // DIP/ISP: Rezultatas per abstrakciją (be dynamic_cast)
            std::cout << result << "\n";  // Spausdina formatuotą rezultatą
            oss << analysis->name() << ": " << result << "\n";  // Įtraukia į ataskaitą (vieningai visoms)
        }  // Pastaba: Nauja analizė veiks automatiškai – atitinka OCP/LSP

        // SRP: Report klasė atsakinga tik už ataskaitų išsaugojimą
        std::cout << "Issaugoti ataskaita? (t/n): ";
        char yn;  //
        std::cin >> yn;
        if (yn == 't' || yn == 'T') {
            Report::save("report.txt", oss.str());  // Enkapsuliacija - įrašo
        }

    }  // Ciklo pabaiga

       std::cout << "Analizatorius baigia darbą.\n";
    return 0;
}
