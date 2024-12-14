#ifndef INVALID_INPUT_EXCEPTION_H
#define INVALID_INPUT_EXCEPTION_H

#include "ParkingException.h"

// Исключение: некорректный ввод данных
class InvalidInputException : public ParkingException {
public:
    explicit InvalidInputException(const std::string& msg);
};

#endif // INVALID_INPUT_EXCEPTION_H
