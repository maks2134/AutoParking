#ifndef PARKING_SPOT_EXCEPTION_H
#define PARKING_SPOT_EXCEPTION_H

#include "ParkingException.h"

// Исключение: ошибка назначения парковочного места
class ParkingSpotException : public ParkingException {
public:
    explicit ParkingSpotException(const std::string& msg);
};

#endif // PARKING_SPOT_EXCEPTION_H
