#include "Auto.h"

Auto::Auto(const std::string& name, int capacity, const std::string& carType, int parkingSpot)
        : AutoParking(name, capacity), carType(carType), parkingSpot(parkingSpot) {}

Auto::~Auto() = default;

const std::string& Auto::getCarType() const {
    return carType;
}

int Auto::getParkingSpot() const {
    return parkingSpot;
}

std::ostream& operator<<(std::ostream& os, const Auto& car) {
    os << "Car Type: " << car.carType << ", Parking Spot: " << car.parkingSpot;
    return os;
}