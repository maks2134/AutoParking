#ifndef EGOR_MANAGER_H
#define EGOR_MANAGER_H
#include "../Employees.h"
#include <iostream>
#include <vector>

class Manager : public Employees {
private:
    double totalIncome;               // Общая прибыль
    std::vector<std::string> shifts; // Информация о сменах работников

public:
    // Конструктор
    Manager(const std::string& parkingName, int capacity, double salary);

    // Методы
    void work() const override;                 // Выполнение обязанностей менеджера
    void showEmployeeInfo() const override;     // Вывод информации о менеджере
    void calculateIncome(double income);        // Подсчет общей прибыли
    void logShift(const std::string& employee); // Учет смен работников
    void showShifts() const;                    // Вывод всех смен
};

#endif //EGOR_MANAGER_H
