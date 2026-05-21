#include "EngineTesting.hpp"

int main() {
    // 1. Pipeline erstellen (Nutzt Smart Pointer statt roher Pointer)
    std::vector<std::shared_ptr<Inspection>> qualityPipeline;
    qualityPipeline.push_back(std::make_shared<WeightCheck>());
    qualityPipeline.push_back(std::make_shared<VisualTest>());
    qualityPipeline.push_back(std::make_shared<TemperatureTest>());

    // 2. Test-Produkte erstellen
    CombustionEngine motor1("ID001", "Verbrennungsmotor v1", 190.0, 85.0, true); // Good Path
    ElectricEngine motor2("ID002", "Elektromotor v1", 80.0, 110.0, 400.0, false);   // Zu leicht & zu heiß

    std::vector<std::shared_ptr<Product>> productionLine;

    std::shared_ptr<Product> m1_shPtr = std::make_shared<CombustionEngine>(motor1);
    std::shared_ptr<Product> m2_shPtr = std::make_shared<ElectricEngine>(motor2);

    productionLine.push_back(m1_shPtr);
    productionLine.push_back(m2_shPtr);

    // 3. PIPELINE BEIDE PRODUKTE DURCHLAUFEN LASSEN
    std::cout << "--- STARTE QUALITAETSKONTROLLE ---\n";
    for (const auto& productPtr : productionLine) {
        std::cout << "\nPruefe Produkt: " << productPtr->getName() << "\n\n";
        bool productPassedEntirePipeline = true;

        // Iteration über die generische Pipeline via STL
        for (const auto& inspection : qualityPipeline) {
            bool stepResult = inspection->execute(*productPtr);
            std::cout << inspection->getName() << ": ";
            // Hier nutzen wir das Interface, um den Typ auszugeben
            if (stepResult) {
                std::cout << "PASS\n";
            }
            else {
                std::cout << "FAIL\n";
                productPassedEntirePipeline = false;
            }
        }

        std::cout << "Endergebnis: " << (productPassedEntirePipeline ? "AKZEPTIERT" : "ABGELEHNT") << "\n";
    }

    // 4. VERTRAG AUSNUTZEN: Inspektion-Reports am Ende drucken
    std::cout << "\n--- GLOBALE INSPEKTIONS-REPORTS (VERTRAGSERFUELLUNG) ---\n";
    for (const auto& inspection : qualityPipeline) {
        inspection->printReport(); // Garantiert durch das Interface IReportable
    }

    return 0;
}