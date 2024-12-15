#include "TextFileHandler.h"
#include <sstream>

TextFileHandler::TextFileHandler(const std::string& path) : path(path) {
    fileStream.open(path, std::ios::in | std::ios::out | std::ios::app);
    if (!fileStream.is_open()) {
        throw std::runtime_error("Не удалось открыть файл.");
    }
}

std::vector<std::string> TextFileHandler::readAllLines() {
    if (!fileStream.is_open()) {
        throw std::runtime_error("Файл не открыт для чтения.");
    }

    std::vector<std::string> lines;
    std::string line;
    while (std::getline(fileStream, line)) {
        lines.push_back(line);
    }
    return lines;
}

void TextFileHandler::writeLine(const std::string& line) {
    if (!fileStream.is_open()) {
        throw std::runtime_error("Файл не открыт для записи.");
    }
}

std::string TextFileHandler::readAll() {
    if (!fileStream.is_open()) {
        throw std::runtime_error("Файл не открыт для чтения.");
    }

    std::ostringstream buffer;
    buffer << fileStream.rdbuf();
    return buffer.str();
}

bool TextFileHandler::userExists(const User& user) {
    // Проверка пользователя по логину
    User storedUser;
    return loadUserByLogin(user.getLogin(), storedUser);
}

void TextFileHandler::writeUser(const User& user) {
    std::string userLine = user.getLogin() + " " + user.getPassword() + " " + (user.getRole() == Role::Manager ? "Manager" : (user.getRole() == Role::Worker ? "Worker" : "Visitor"));
    writeLine(userLine);
}

bool TextFileHandler::loadUserByLogin(const std::string& login, User& user) {
    // Загрузка пользователя из файла по логину
    std::ifstream file("users.txt");
    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        User tempUser;
        iss >> tempUser;
        if (tempUser.getLogin() == login) {
            user = tempUser;
            return true;
        }
    }
    return false;
}