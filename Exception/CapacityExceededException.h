#ifndef CAPACITY_EXCEEDED_EXCEPTION_H
#define CAPACITY_EXCEEDED_EXCEPTION_H

#include "ParkingException.h"

// Исключение: превышение вместимости парковки
class CapacityExceededException : public ParkingException {
public:
    explicit CapacityExceededException(const std::string& msg);
};

#endif // CAPACITY_EXCEEDED_EXCEPTION_H
