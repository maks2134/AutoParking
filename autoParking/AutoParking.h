#ifndef EGOR_AUTOPARKING_H
#define EGOR_AUTOPARKING_H

#include <string>
#include <iostream>

// Абстрактный класс AutoParking
class AutoParking {
protected:
    std::string name; // Название парковки
    int capacity;     // Вместимость парковки

public:
    // Конструктор
    AutoParking(const std::string& name = "Default", int capacity = 0);

    // Виртуальный деструктор
    virtual ~AutoParking();

    virtual void showInfo() const = 0; // Вывод информации о парковке
    virtual void calculateIncome() const = 0; // Расчет доходов от парковки

    // Перегрузка оператора вывода
    friend std::ostream& operator<<(std::ostream& os, const AutoParking& parking);
};

#endif