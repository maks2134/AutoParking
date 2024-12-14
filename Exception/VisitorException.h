#ifndef VISITOR_EXCEPTION_H
#define VISITOR_EXCEPTION_H

#include "ParkingException.h"

// Исключение: ошибка обработки посетителя
class VisitorException : public ParkingException {
public:
    explicit VisitorException(const std::string& msg);
};

#endif // VISITOR_EXCEPTION_H
