#ifndef EGOR_WORKERS_H
#define EGOR_WORKERS_H
#include "../Employees.h"

class Workers : public Employees {
protected:
    int workHours; // Количество рабочих часов в день

public:
    // Конструктор
    Workers(const std::string& parkingName, int capacity, const std::string& position, double salary, int workHours = 8);

    // Виртуальный деструктор
    virtual ~Workers();

    // Методы
    int getWorkHours() const; // Получить рабочие часы
    void setWorkHours(int hours); // Установить рабочие часы

    // Чисто виртуальные методы остаются не изменены
    virtual void work() const override = 0;
    virtual void showEmployeeInfo() const override = 0;

    void showInfo() {
        std::cout << "Parking Manager: " << name
                  << ", Capacity: " << capacity
                  << ", Salary: $" << salary << std::endl;
    }

    void calculateIncome() {
        int income = capacity * 10; // Example calculation
        std::cout << "Estimated Income: $" << income << std::endl;
    }

    // Перегрузка оператора вывода для класса Workers
    friend std::ostream& operator<<(std::ostream& os, const Workers& worker);
};

#endif // EGOR_WORKERS_H
