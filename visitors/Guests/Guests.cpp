#include "Guests.h"
#include <iostream>

Guests::Guests(const std::string& parkingName, int capacity, const std::string& name, const std::string& licensePlate, double rate, int minutes)
        : Visitors(parkingName, capacity, "Гость", name, licensePlate), minuteRate(rate), minutesParked(minutes) {}

void Guests::showVisitorInfo() const {
    std::cout << "Гость: " << name
              << ", Номер авто: " << licensePlate
              << ", Время на парковке: " << minutesParked << " минут"
              << ", Поминутная ставка: " << minuteRate << " руб/мин\n";
}

void Guests::assignParkingSpot(int spotNumber) {
    std::cout << "Гостю " << name << " назначено временное парковочное место №" << spotNumber << std::endl;
}

double Guests::calculateParkingCost() const {
    return minuteRate * minutesParked; // Гости платят поминутно
}
