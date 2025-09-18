OOP principai

Klasės (Class) ✅
Visi pagrindiniai komponentai (CSVLoader, SimpleData, Result, Analysis, Exporter) yra klasės.
Jos turi savo duomenis ir funkcijas.

Enkapsuliacija (Encapsulation) ✅
Result saugo analysisName ir value kaip private.
SimpleData slepia stulpelio duomenis (values) ir pavadinimą (columnName) su getter/setter metodais.
CSVLoader saugo data_ kaip private.

Abstrakcija (Abstraction) ✅
Exporter ir Analysis yra abstraktūs interfeisai.
Aukšto lygio modulis (main) bendrauja su abstrakcijomis, o ne konkrečiomis implementacijomis.

Paveldėjimas (Inheritance) ✅
TextExporter paveldi Exporter.
Analizės klasės (MinMaxAnalysis, MedianAnalysis, ...) paveldi Analysis.

Polimorfizmas (Polymorphism) ✅
main naudoja vektorius std::unique_ptr<Analysis> ir std::unique_ptr<Exporter> – polimorfinė sąsaja.
Galima pridėti naujus analizės ar eksportavimo tipus be esamo kodo keitimo.

SOLID principai
S – Single Responsibility Principle ✅
CSVLoader – tik CSV užkrovimas.
Analysis klasės – tik analizė.
Result – tik rezultatų saugojimas.
TextExporter – tik eksportas į tekstą.

O – Open/Closed Principle ✅ (su sąlyga)
Galima pridėti naujų analizės ar eksportavimo tipų per paveldėjimą, nekeičiant esamų klasės implementacijų.


L – Liskov Substitution Principle ✅
Visi paveldėti objektai (TextExporter, analizės klasės) gali būti naudojami per bazinę abstrakciją be netikėtų klaidų.

I – Interface Segregation Principle ✅
Exporter ir Analysis interfeisai turi tik būtinus metodus.
Paveldėtos klasės nėra priverstos implementuoti nereikalingų funkcijų.

D – Dependency Inversion Principle ✅ 
main priklauso nuo abstrakcijų (Analysis, Exporter, TextExporter) ✅


