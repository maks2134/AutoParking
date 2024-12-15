#ifndef USER_H
#define USER_H
#include "../algoritm/blowfish.h"
#include <string>
#include <unordered_map>
#include <iostream>

// Перечисление для ролей
enum class Role {
    Manager,
    Worker,
    Visitor
};

class User {
private:
    std::string login;
    std::string encryptedPassword;
    Role role;

public:
    User(const std::string& login = "", const std::string& password = "", Role role = Role::Visitor);

    std::string getLogin() const;
    std::string getEncryptedPassword() const;
    Role getRole() const;
    void setRole(Role role);
    void setPassword(const std::string& password, const std::string& key);
    std::string getPassword(const std::string& key) const;

    // Перегрузка оператора ввода
    friend std::istream& operator>>(std::istream& is, User& user);

    // Перегрузка оператора вывода
    friend std::ostream& operator<<(std::ostream& os, const User& user);
};

#endif // USER_H
