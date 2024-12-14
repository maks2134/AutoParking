#include "parkingPlace.h"
#include <iostream>

parkingPlace::parkingPlace(const std::string& name, int capacity, const std::string& carType, int parkingSpot, bool isOccupied)
        : Auto(name, capacity, carType, parkingSpot), isOccupied(isOccupied) {}

void parkingPlace::showCarInfo() const {
    std::cout << "Место №" << parkingSpot
              << " для типа авто: " << carType
              << ", Статус: " << (isOccupied ? "Занято" : "Свободно")
              << ", Название парковки: " << AutoParking::name
              << ", Вместимость: " << AutoParking::capacity << std::endl;
}

void parkingPlace::assignParkingSpot(int spotNumber) {
    parkingSpot = spotNumber;
    std::cout << "Парковочному месту назначен номер: " << spotNumber << std::endl;
}

bool parkingPlace::getOccupancyStatus() const {
    return isOccupied;
}

void parkingPlace::setOccupancyStatus(bool status) {
    isOccupied = status;
    std::cout << "Статус парковочного места №" << parkingSpot << " изменен на: "
              << (isOccupied ? "Занято" : "Свободно") << std::endl;
}
