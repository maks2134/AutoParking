#ifndef PARKING_EXCEPTION_H
#define PARKING_EXCEPTION_H

#include <exception>
#include <string>

// Базовый класс для всех пользовательских исключений
class ParkingException : public std::exception {
protected:
    std::string message; // Сообщение об ошибке

public:
    // Конструктор с сообщением об ошибке
    explicit ParkingException(const std::string& msg);

    // Переопределение метода what()
    const char* what() const noexcept override;
};

#endif // PARKING_EXCEPTION_H
