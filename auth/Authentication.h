#ifndef AUTHENTICATION_H
#define AUTHENTICATION_H

#include <string>
#include <unordered_map>
#include <memory>
#include "User.h"

class Authentication {
private:
    std::unordered_map<std::string, std::shared_ptr<User>> users;

public:
    bool registerUser(const std::string& login, const std::string& password, const std::string& role);
    bool authenticate(const std::string& login, const std::string& password) const;
    bool deleteUser(const std::string& login);
    void displayUsers() const;
};

#endif // AUTHENTICATION_H
