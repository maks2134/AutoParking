#include "Authentication.h"
#include <iostream>

// Метод для регистрации пользователя
bool Authentication::registerUser(const std::string& login, const std::string& password, const std::string& role) {
    if (users.find(login) != users.end()) {
        std::cout << "Ошибка: Пользователь с таким логином уже существует.\n";
        return false;
    }

    if (role == "менеджер") {
        users[login] = std::make_shared<Manager>(login, password);
    } else if (role == "работник") {
        users[login] = std::make_shared<Worker>(login, password);
    } else if (role == "посетитель") {
        users[login] = std::make_shared<Visitor>(login, password);
    } else {
        std::cout << "Ошибка: Некорректный статус. Используйте 'менеджер', 'работник' или 'посетитель'.\n";
        return false;
    }

    std::cout << "Пользователь успешно зарегистрирован.\n";
    return true;
}

// Метод для аутентификации пользователя
bool Authentication::authenticate(const std::string& login, const std::string& password) const {
    auto it = users.find(login);
    if (it == users.end()) {
        std::cout << "Ошибка: Пользователь с таким логином не найден.\n";
        return false;
    }

    if (!it->second->checkPassword(password)) {
        std::cout << "Ошибка: Неверный пароль.\n";
        return false;
    }

    std::cout << "Аутентификация успешна. Ваш статус: " << it->second->getRole() << "\n";
    return true;
}

// Метод для удаления пользователя
bool Authentication::deleteUser(const std::string& login) {
    if (users.erase(login)) {
        std::cout << "Пользователь успешно удален.\n";
        return true;
    } else {
        std::cout << "Ошибка: Пользователь с таким логином не найден.\n";
        return false;
    }
}

// Метод для отображения всех пользователей
void Authentication::displayUsers() const {
    if (users.empty()) {
        std::cout << "Нет зарегистрированных пользователей.\n";
        return;
    }

    std::cout << "Список пользователей:\n";
    for (const auto& [login, user] : users) {
        user->displayInfo();
    }
}
