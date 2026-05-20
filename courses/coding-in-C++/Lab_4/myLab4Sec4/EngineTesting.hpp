#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "TestProducts.hpp"

// Forward Declaration
class Product;

// Interface
class IReportable {
public:
    virtual ~IReportable() = default;
    virtual void printReport() const = 0; // Each Inspection has to be able to print a report
};

// ABSTRAKTE BASISKLASSE FÜR INSPEKTIONEN
class Inspection : public IReportable {
protected:
    std::string typeName;
    int totalChecks = 0;
    int passedChecks = 0;
public:
    Inspection(std::string name) : typeName(name) {}
    virtual ~Inspection() = default;

    // Jede Inspektion muss logisch prüfen können
    virtual bool execute(const Product& product) = 0;
};


// 1. KONKRETE INSPEKTION
class WeightCheck : public Inspection {
public:
    WeightCheck() : Inspection("Weight Check") {}

    bool execute(const Product& product) override {
        totalChecks++;
        //Gewicht zwischen 100 und 200 kg ist okay
        bool success = (product.getWeight() >= 100.0 && product.getWeight() <= 200.0);
        if (success) passedChecks++;
        return success;
    }

    void printReport() const override {
        std::cout << "Report [" << typeName << "]: Erfolgsquote: "
            << (totalChecks > 0 ? (passedChecks * 100 / totalChecks) : 0) << "%\n";
    }
};

// 2. KONKRETE INSPEKTION
class VisualTest : public Inspection
{
public:
    VisualTest() : Inspection("Visual Test") {}

    bool execute(const Product& product) override {
        totalChecks++;
        if (!product.hasVisualDefects())
        {
            passedChecks++;
            return true;
        }
        return false;
    }
    void printReport() const override {
        std::cout << "Report [" << typeName << "]: Erfolgsquote: "
            << (totalChecks > 0 ? (passedChecks * 100 / totalChecks) : 0) << "%\n";
    }
};
// 3. KONKRETE INSPEKTION


class TemperatureTest : public Inspection {
private:
    static constexpr double MAX_TEMPERATURE = 90.0;
public:
    TemperatureTest() : Inspection("Temperature Test") {}

    bool execute(const Product& product) override {
        totalChecks++;
        if (product.getTemperature() < MAX_TEMPERATURE)
        {
            passedChecks++;
            return true;
        }
        return false;
    }

    void printReport() const override {
        std::cout << "Report [" << typeName << "]: Erfolgsquote: "
            << (totalChecks > 0 ? (passedChecks * 100 / totalChecks) : 0) << "%\n";
    }
};