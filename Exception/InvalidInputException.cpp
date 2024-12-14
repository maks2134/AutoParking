#include "InvalidInputException.h"

// Реализация конструктора
InvalidInputException::InvalidInputException(const std::string& msg)
        : ParkingException("Invalid Input: " + msg) {}
