#ifndef USERMANAGER_H
#define USERMANAGER_H

#include "User.h"
#include "../File/TextFileHandler.h"
#include <iostream>

class UserManager {
private:
    TextFileHandler& textHandler;

public:
    // Конструктор, принимающий ссылку на объект TextFileHandler
    UserManager(TextFileHandler& handler);

    // Регистрация нового пользователя
    void registerUser(User& user);

    // Авторизация пользователя
    bool loginUser(const std::string& login, const std::string& password);
};

#endif // USERMANAGER_H
