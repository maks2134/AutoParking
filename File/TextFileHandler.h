#ifndef TEXTFILEHANDLER_H
#define TEXTFILEHANDLER_H

#include "../auth/User.h"
#include <fstream>
#include <vector>

class TextFileHandler {
private:
    std::string path;
    std::ifstream fileStream;

public:
    TextFileHandler(const std::string& path);
    std::vector<std::string> readAllLines();
    void writeLine(const std::string& line);
    std::string readAll();

    bool userExists(const User& user);
    void writeUser(const User& user);
    bool loadUserByLogin(const std::string& login, User& user);
};

#endif // TEXTFILEHANDLER_H
