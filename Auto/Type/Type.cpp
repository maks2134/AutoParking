#include "Type.h"
#include <iostream>

Type::Type(const std::string& name, int capacity, const std::string& carType, int parkingSpot)
        : Auto(name, capacity, carType, parkingSpot) {}

void Type::showCarInfo() const {
    std::cout << "Тип машины: " << carType
              << ", Парковочное место: " << parkingSpot
              << ", Название парковки: " << AutoParking::name
              << ", Вместимость парковки: " << AutoParking::capacity << std::endl;
}

void Type::assignParkingSpot(int spotNumber) {
    parkingSpot = spotNumber;
    std::cout << "Типу машины \"" << carType << "\" назначено парковочное место №" << spotNumber << std::endl;


}
