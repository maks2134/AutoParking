#include "Manager.h"

Manager::Manager(const std::string& parkingName, int capacity, double salary)
        : Employees(parkingName, capacity, "Manager", salary), totalIncome(0) {}

void Manager::work() const {
    std::cout << "Manager is calculating income and monitoring workers." << std::endl;
}

void Manager::showEmployeeInfo() const {
    std::cout << "Manager Info: " << std::endl;
    std::cout << *this << std::endl; // Используем перегруженный оператор
}

void Manager::calculateIncome(double income) {
    totalIncome += income;
    std::cout << "Income added: " << income << ". Total income: " << totalIncome << std::endl;
}

void Manager::logShift(const std::string& employee) {
    shifts.push_back(employee);
    std::cout << "Shift logged for: " << employee << std::endl;
}

void Manager::showShifts() const {
    std::cout << "Shifts logged: " << std::endl;
    for (const auto& shift : shifts) {
        std::cout << "- " << shift << std::endl;
    }
}

