#include "CapacityExceededException.h"

// Реализация конструктора
CapacityExceededException::CapacityExceededException(const std::string& msg)
        : ParkingException("Capacity Exceeded: " + msg) {}
