#include "VisitorException.h"

// Реализация конструктора
VisitorException::VisitorException(const std::string& msg)
        : ParkingException("Visitor Error: " + msg) {}
