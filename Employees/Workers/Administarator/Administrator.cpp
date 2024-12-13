#include "Administrator.h"
#include <iostream>

Administrator::Administrator(const std::string& parkingName, int capacity, double salary)
        : Workers(parkingName, capacity, "Administrator", salary) {}

void Administrator::work() const {
    std::cout << "Administrator is registering cars." << std::endl;
    showRecordedCars();
}

void Administrator::showEmployeeInfo() const {
    std::cout << "Administrator Info: " << std::endl;
    std::cout << *this << std::endl; // Используем перегруженный оператор
}

void Administrator::recordCar(const std::string& plate) {
    recordedCars.push_back(plate);
    std::cout << "Car registered: " << plate << std::endl;
}

void Administrator::showRecordedCars() const {
    std::cout << "Registered cars:" << std::endl;
    for (const auto& plate : recordedCars) {
        std::cout << " - " << plate << std::endl;
    }
}