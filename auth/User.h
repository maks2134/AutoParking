#ifndef USER_H
#define USER_H

#include <string>

// Базовый класс для пользователя
class User {
protected:
    std::string login;
    std::string password;
    std::string role; // Роль пользователя

public:
    User(const std::string& login, const std::string& password, const std::string& role);
    virtual ~User() = default;

    std::string getLogin() const;
    std::string getRole() const;

    bool checkPassword(const std::string& inputPassword) const;

    virtual void displayInfo() const; // Виртуальный метод для отображения информации о пользователе
};

// Класс для менеджера
class Manager : public User {
public:
    Manager(const std::string& login, const std::string& password);

    void displayInfo() const override;
};

// Класс для работника
class Worker : public User {
public:
    Worker(const std::string& login, const std::string& password);

    void displayInfo() const override;
};

// Класс для посетителя
class Visitor : public User {
public:
    Visitor(const std::string& login, const std::string& password);

    void displayInfo() const override;
};

#endif // USER_H
