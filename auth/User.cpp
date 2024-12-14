#include "User.h"
#include <iostream>

// Реализация базового класса User
User::User(const std::string& login, const std::string& password, const std::string& role)
        : login(login), password(password), role(role) {}

std::string User::getLogin() const {
    return login;
}

std::string User::getRole() const {
    return role;
}

bool User::checkPassword(const std::string& inputPassword) const {
    return password == inputPassword;
}

void User::displayInfo() const {
    std::cout << "Логин: " << login << ", Роль: " << role << "\n";
}

// Реализация класса Manager
Manager::Manager(const std::string& login, const std::string& password)
        : User(login, password, "менеджер") {}

void Manager::displayInfo() const {
    std::cout << "Менеджер: " << login << "\n";
}

// Реализация класса Worker
Worker::Worker(const std::string& login, const std::string& password)
        : User(login, password, "работник") {}

void Worker::displayInfo() const {
    std::cout << "Работник: " << login << "\n";
}

// Реализация класса Visitor
Visitor::Visitor(const std::string& login, const std::string& password)
        : User(login, password, "посетитель") {}

void Visitor::displayInfo() const {
    std::cout << "Посетитель: " << login << "\n";
}
