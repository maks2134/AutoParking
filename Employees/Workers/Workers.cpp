#include "Workers.h"

// Конструктор
Workers::Workers(const std::string& parkingName, int capacity, const std::string& position, double salary, int workHours)
        : Employees(parkingName, capacity, position, salary), workHours(workHours) {}

// Виртуальный деструктор
Workers::~Workers() {}

// Получить рабочие часы
int Workers::getWorkHours() const {
    return workHours;
}

// Установить рабочие часы
void Workers::setWorkHours(int hours) {
    workHours = hours;
}

// Перегрузка оператора вывода
std::ostream& operator<<(std::ostream& os, const Workers& worker) {
    os << "Позиция: " << worker.position
       << ", Зарплата: " << worker.salary
       << ", Рабочие часы: " << worker.workHours;
    return os;
}
