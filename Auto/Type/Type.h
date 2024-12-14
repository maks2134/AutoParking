#ifndef EGOR_TYPE_H
#define EGOR_TYPE_H
#include "../Auto.h"
#include <string>
#include <iostream>

// Класс Type (описание типа автомобиля)
class Type : public Auto {
public:
    // Конструктор
    Type(const std::string& name, int capacity, const std::string& carType, int parkingSpot);

    // Методы
    void showCarInfo() const override;          // Показать информацию о типе машины
    void assignParkingSpot(int spotNumber) override; // Назначить парковочное место

    void showInfo() override {
        std::cout << "Parking Manager: " << name
                  << ", Capacity: " << capacity
                  << ", Salary: $" << std::endl;
    }

    void calculateIncome() override {
        int income = capacity * 10; // Example calculation
        std::cout << "Estimated Income: $" << income << std::endl;
    }
};

#endif // EGOR_TYPE_H

