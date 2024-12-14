#include "ParkingSpotException.h"

// Реализация конструктора
ParkingSpotException::ParkingSpotException(const std::string& msg)
        : ParkingException("Parking Spot Error: " + msg) {}
