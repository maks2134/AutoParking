#ifndef EGOR_GUESTS_H
#define EGOR_GUESTS_H
#include "../Visitors.h"

class Guests : public Visitors {
private:
    double minuteRate; // Поминутная ставка
    int minutesParked; // Количество минут на парковке

public:
    // Конструктор
    Guests(const std::string& parkingName, int capacity, const std::string& name, const std::string& licensePlate, double rate, int minutes);

    // Переопределение виртуальных методов
    void showVisitorInfo() const override;
    void assignParkingSpot(int spotNumber) override;

    // Метод расчета стоимости
    double calculateParkingCost() const;

    void showInfo() override {
        std::cout << "Parking Manager: " << name
                  << ", Capacity: " << capacity << std::endl;
    }

    void calculateIncome() override {
        int income = capacity * 10; // Example calculation
        std::cout << "Estimated Income: $" << income << std::endl;
    }
};

#endif //EGOR_GUESTS_H
