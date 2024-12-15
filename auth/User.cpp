#include "User.h"

// Конструктор
User::User(const std::string& login, const std::string& password, Role role)
        : login(login), encryptedPassword(password), role(role) {}

// Геттеры и сеттеры
void User::setPassword(const std::string& password, const std::string& key) {
    Blowfish blowfish;
    blowfish.SetKey(reinterpret_cast<const unsigned char*>(key.c_str()), key.size());
    unsigned char encrypted[64] = {0};
    blowfish.Encrypt(encrypted, reinterpret_cast<const unsigned char*>(password.c_str()), password.size());
    encryptedPassword = std::string(reinterpret_cast<char*>(encrypted), password.size());
}

std::string User::getPassword(const std::string& key) const {
    Blowfish blowfish;
    blowfish.SetKey(reinterpret_cast<const unsigned char*>(key.c_str()), key.size());
    unsigned char decrypted[64] = {0};
    blowfish.Decrypt(decrypted, reinterpret_cast<const unsigned char*>(encryptedPassword.c_str()), encryptedPassword.size());
    return std::string(reinterpret_cast<char*>(decrypted));
}
Role User::getRole() const { return role; }
void User::setRole(Role role) { this->role = role; }

// Перегрузка оператора ввода
std::istream& operator>>(std::istream& is, User& user) {
    std::string login, password;
    int roleChoice;

    std::cout << "Введите логин: ";
    is >> login;

    std::cout << "Введите пароль: ";
    is >> password;

    std::cout << "Выберите роль (0 - Manager, 1 - Worker, 2 - Visitor): ";
    is >> roleChoice;

    if (roleChoice < 0 || roleChoice > 2) {
        throw std::invalid_argument("Некорректный выбор роли");
    }

    // Устанавливаем данные в объект User
    user = User(login, password, static_cast<Role>(roleChoice));

    return is;
}


// Перегрузка оператора вывода
std::ostream& operator<<(std::ostream& os, const User& user) {
    os << user.login << " " << user.encryptedPassword << " " << (user.role == Role::Manager ? "Manager" : (user.role == Role::Worker ? "Worker" : "Visitor"));
    return os;
}
