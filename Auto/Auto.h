#ifndef EGOR_AUTO_H
#define EGOR_AUTO_H
#include "../autoParking/AutoParking.h"

// Абстрактный класс Auto
class Auto : public AutoParking {
protected:
    std::string carType; // Тип автомобиля (легковой, грузовой и т.д.)
    int parkingSpot;     // Номер парковочного места

public:
    // Конструктор
    Auto(const std::string& name, int capacity, const std::string& carType, int parkingSpot);

    // Виртуальный деструктор
    virtual ~Auto();

    // Чисто виртуальные методы
    virtual void showCarInfo() const = 0; // Показать информацию о машине
    virtual void assignParkingSpot(int spotNumber) = 0; // Назначить парковочное место

    // Геттеры и сеттеры
    const std::string& getCarType() const;
    int getParkingSpot() const;

    // Перегрузка оператора вывода
    friend std::ostream& operator<<(std::ostream& os, const Auto& car);
};

#endif