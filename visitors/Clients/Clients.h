#ifndef EGOR_CLIENTS_H
#define EGOR_CLIENTS_H
#include "../Visitors.h"

class Clients : public Visitors {
private:
    int parkingSpot;   // Номер парковочного места
    double monthlyRate; // Месячная ставка со скидкой

public:
    // Конструктор
    Clients(const std::string& parkingName, int capacity, const std::string& name, const std::string& licensePlate, double rate);

    // Переопределение виртуальных методов
    void showVisitorInfo() const override;
    void assignParkingSpot(int spotNumber) override;

    // Метод расчета стоимости
    double calculateParkingCost() const;

    // Геттер парковочного места
    int getParkingSpot() const;

    void showInfo() override {
        std::cout << "Parking Manager: " << name
                  << ", Capacity: " << capacity
                  << ", Salary: $" <<std::endl;
    }

    void calculateIncome() override {
        int income = capacity * 10; // Example calculation
        std::cout << "Estimated Income: $" << income << std::endl;
    }
};

#endif //EGOR_CLIENTS_H
