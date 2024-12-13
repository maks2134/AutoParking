#include "Employees.h"

Employees::Employees(const std::string& name, int capacity, const std::string& position, double salary)
        : AutoParking(name, capacity), position(position), salary(salary) {}

Employees::~Employees() {}

const std::string& Employees::getPosition() const {
    return position;
}

double Employees::getSalary() const {
    return salary;
}

std::ostream& operator<<(std::ostream& os, const Employees& employee) {
    os << "Позиция: " << employee.position << ", Зарплата: " << employee.salary;
    return os;
}