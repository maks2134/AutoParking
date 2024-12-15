#include "UserManager.h"
#include <iostream>
#include <stdexcept>

// Конструктор
UserManager::UserManager(TextFileHandler& handler) : textHandler(handler) {}

// Регистрация нового пользователя
void UserManager::registerUser(User& user) {
    std::string login, password;
    int roleChoice;

    std::cout << "Введите логин: ";
    std::cin >> login;

    std::cout << "Введите пароль: ";
    std::cin >> password;

    std::cout << "Выберите роль (0 - Manager, 1 - Worker, 2 - Visitor): ";
    std::cin >> roleChoice;

    if (roleChoice < 0 || roleChoice > 2) {
        throw std::invalid_argument("Некорректный выбор роли");
    }

    // Генерация ключа для шифрования (можно заменить на собственный ключ)
    std::string encryptionKey = "MySecretKey123";

    // Устанавливаем данные пользователя через сеттеры
    user = User(login, "", static_cast<Role>(roleChoice));
    user.setPassword(password, encryptionKey); // Шифруем пароль

    // Проверка, существует ли пользователь
    if (textHandler.userExists(user)) {
        std::cout << "Пользователь с таким логином уже существует.\n";
    } else {
        textHandler.writeUser(user);  // Добавляем нового пользователя
        std::cout << "Пользователь успешно зарегистрирован.\n";
    }
}

bool UserManager::loginUser(const std::string& login, const std::string& password) {
    // Генерация ключа для шифрования
    std::string encryptionKey = "MySecretKey123";

    // Проверка наличия пользователя
    User storedUser;
    if (textHandler.loadUserByLogin(login, storedUser)) {
        // Расшифровка пароля и проверка
        if (storedUser.getPassword(encryptionKey) == password) {
            std::cout << "Авторизация успешна.\n";
            return true;
        }
    }

    std::cout << "Неверные логин или пароль.\n";
    return false;
}
