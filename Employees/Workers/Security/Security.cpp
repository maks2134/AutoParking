#include "Security.h"
#include <iostream>

Security::Security(const std::string& parkingName, int capacity, double salary)
        : Workers(parkingName, capacity, "Security", salary) {}

void Security::work() const {
    std::cout << "Security is ensuring all cars are in place." << std::endl;
    checkCars();
}

void Security::showEmployeeInfo() const {
    std::cout << "Security Info: " << std::endl;
    std::cout << *this << std::endl; // Используем перегруженный оператор
}

void Security::addCarToCheck(const std::string& plate) {
    carPlates.push_back(plate);
    std::cout << "Car added to check list: " << plate << std::endl;
}

void Security::checkCars() const {
    std::cout << "Checking cars:" << std::endl;
    for (const auto& plate : carPlates) {
        std::cout << " - Car " << plate << " is in place." << std::endl;
    }
}