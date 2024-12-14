#include "ParkingException.h"

// Реализация конструктора
ParkingException::ParkingException(const std::string& msg) : message(msg) {}

// Реализация метода what()
const char* ParkingException::what() const noexcept {
    return message.c_str();
}
