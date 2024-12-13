#ifndef EGOR_VISITORS_H
#define EGOR_VISITORS_H
#include "../autoParking/AutoParking.h"

class Visitors : public AutoParking {
protected:
    std::string visitorType; // Тип посетителя (гость или клиент)
    std::string name;        // Имя посетителя
    std::string licensePlate; // Номер автомобиля

public:
    // Конструктор
    Visitors(const std::string& parkingName, int capacity, const std::string& visitorType,
             const std::string& name, const std::string& licensePlate);

    // Виртуальный деструктор
    virtual ~Visitors();

    // Чисто виртуальные методы
    virtual void showVisitorInfo() const = 0; // Показать информацию о посетителе
    virtual void assignParkingSpot(int spotNumber) = 0; // Назначить парковочное место

    // Геттеры и сеттеры
    const std::string& getVisitorType() const;
    const std::string& getName() const;
    const std::string& getLicensePlate() const;

    void setLicensePlate(const std::string& licensePlate);

    // Перегрузка оператора вывода
    friend std::ostream& operator<<(std::ostream& os, const Visitors& visitor);
};


#endif