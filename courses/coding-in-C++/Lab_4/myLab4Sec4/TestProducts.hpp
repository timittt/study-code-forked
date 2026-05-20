#pragma once
#include <string>

// DUMMY PRODUKT-KLASSE FÜR DEN STRUKTURTEST
class Product {
public:
    std::string id;
    std::string name;
public:
    Product(std::string id, std::string name)
        : id(id), name(name) {
    }
    std::string getName() const { return name; }
    virtual double getWeight() const { return 0.0; }
    virtual double getTemperature() const { return 0.0; }
    virtual double getVoltage() const { return 0.0; }
    virtual bool hasVisualDefects() const { return false; }
};

// VERBRENNERKLASSE
class CombustionEngine : public Product
{
private:
    double weight;
    double temperature;
    bool visualDefects;
public:
    CombustionEngine(std::string id, std::string name, double w, double t, bool def) : Product(id, name),
        weight(w), temperature(t), visualDefects(def) {
    }
    double getWeight() const override { return weight; }
    double getTemperature() const override { return temperature; }
    bool hasVisualDefects() const override { return visualDefects; }
};

// ELEKTROKLASSE
class ElectricEngine : public Product
{
private:
    double weight;
    double temperature;
    double voltage;
    bool visualDefects;
public:
    ElectricEngine(std::string id, std::string name, double w, double t, double v, bool def) : Product(id, name),
        weight(w), temperature(t), voltage(v), visualDefects(def) {
    }
    double getWeight() const override { return weight; }
    double getTemperature() const override { return temperature; }
    double getVoltage() const override { return voltage; }
    bool hasVisualDefects() const override { return visualDefects; }
};