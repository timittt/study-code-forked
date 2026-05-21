#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // Notwendig für std::sort

class Professor
{
public:
    int id;
    std::string name;
    Professor(int p_id, std::string p_name) : id(p_id), name(p_name) {}

    // Operator-Überladung
    // -> ermöglicht std::sort ohne Lambda
    bool operator<(const Professor& other) const
    {
        return this->id < other.id; // aufsteigend nach ID
    }
};

// Vektor ausprinten
void printProfessors(const std::vector<Professor>& list)
{
    for (const auto& prof : list)
    {
        std::cout << "[ID: " << prof.id << "] " << prof.name << std::endl;
    }
}

int main()
{
    // Testdaten
    std::vector<Professor> profs = {
        { 104, "Prof. Dr. Christoph Nagel" },
        { 101, "Prof. Dr. Peter Pagirulo" },
        { 103, "Prof. Dr. Phil Hasselblad" },
        { 102, "Prof. Dr. Mario Baeumler" }
    };

    std::cout << "--- Unsortiert ---" << std::endl;
    printProfessors(profs);
    std::cout << "\n";

    // 1. Sort ohne Lambda (Nutzt < Operator)
    std::sort(profs.begin(), profs.end());
    std::cout << "--- Aufsteigend nach ID ---" << std::endl;
    printProfessors(profs);
    std::cout << "\n";

    // 2. Absteigend nach ID
    
    std::sort(profs.begin(), profs.end(), [](const Professor& profA, const Professor& profB) 
        {
            return profA.id > profB.id;
        });

    std::cout << "--- Absteigend nach ID ---" << std::endl;
    printProfessors(profs);
    std::cout << "\n";
    
    
    // 3. Alphabetisch nach Name
    std::sort(profs.begin(), profs.end(), [](const Professor& profA, const Professor& profB) 
        {
            return profA.name < profB.name; // C++ eigener String Vergleich
        });

    std::cout << "--- Alphabetisch nach Name ---" << std::endl;
    printProfessors(profs);
    
    return 0;
}