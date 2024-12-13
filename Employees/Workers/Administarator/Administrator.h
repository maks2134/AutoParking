#ifndef EGOR_ADMINISTRATOR_H
#define EGOR_ADMINISTRATOR_H
#include "../Workers.h"

#include <vector>

// Класс Administrator
class Administrator : public Workers {
private:
    std::vector<std::string> recordedCars; // Список зарегистрированных автомобилей

public:
    // Конструктор
    Administrator(const std::string& parkingName, int capacity, double salary);

    // Методы
    void work() const override;                          // Выполнение обязанностей администратора
    void showEmployeeInfo() const override;              // Вывод информации об администраторе
    void recordCar(const std::string& plate);            // Записать автомобиль
    void showRecordedCars() const;                       // Показать все зарегистрированные автомобили
};


#endif