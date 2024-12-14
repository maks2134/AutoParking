#include "Clients.h"
#include <iostream>

Clients::Clients(const std::string& parkingName, int capacity, const std::string& name, const std::string& licensePlate, double rate)
        : Visitors(parkingName, capacity, "Клиент", name, licensePlate), parkingSpot(-1), monthlyRate(rate) {}

void Clients::showVisitorInfo() const {
    std::cout << "Клиент: " << name
              << ", Номер авто: " << licensePlate
              << ", Парковочное место: " << (parkingSpot == -1 ? "Не назначено" : std::to_string(parkingSpot))
              << ", Месячная ставка: " << monthlyRate << " руб.\n";
}

void Clients::assignParkingSpot(int spotNumber) {
    parkingSpot = spotNumber;
    std::cout << "Клиенту " << name << " назначено парковочное место №" << spotNumber << std::endl;
}

double Clients::calculateParkingCost() const {
    return monthlyRate; // Клиенты платят фиксированную ставку за месяц
}

int Clients::getParkingSpot() const {
    return parkingSpot;
}
