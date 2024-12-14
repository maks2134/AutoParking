#ifndef BINARY_FILE_HANDLER_H
#define BINARY_FILE_HANDLER_H

#include "FileHandler.h"
#include <vector>

// Класс для работы с бинарными файлами
class BinaryFileHandler : public FileHandler {
public:
    explicit BinaryFileHandler(const std::string& path);

    // Чтение данных в вектор байтов
    std::vector<char> readAll();

    // Запись данных из вектора байтов
    void writeAll(const std::vector<char>& data);
};

#endif // BINARY_FILE_HANDLER_H
