#ifndef EGOR_EMPLOYEES_H
#define EGOR_EMPLOYEES_H
#include "../autoParking/AutoParking.h"

class Employees : public AutoParking {
protected:
    std::string position; // Должность (менеджер, охранник и т.д.)
    double salary;        // Зарплата

public:
    // Конструктор
    Employees(const std::string& name, int capacity, const std::string& position, double salary);

    // Виртуальный деструктор
    virtual ~Employees();

    // Чисто виртуальные методы
    virtual void work() const = 0; // Выполнение обязанностей
    virtual void showEmployeeInfo() const = 0; // Информация о сотруднике

    // Геттеры и сеттеры
    const std::string& getPosition() const;
    double getSalary() const;

    // Перегрузка оператора вывода
    friend std::ostream& operator<<(std::ostream& os, const Employees& employee);
};


#endif