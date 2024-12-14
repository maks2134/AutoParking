#ifndef TEXT_FILE_HANDLER_H
#define TEXT_FILE_HANDLER_H

#include "FileHandler.h"
#include <vector>

// Класс для работы с текстовыми файлами
class TextFileHandler : public FileHandler {
public:
    explicit TextFileHandler(const std::string& path);

    // Чтение всех строк из файла
    std::vector<std::string> readAllLines();

    // Запись строки в файл
    void writeLine(const std::string& line);

    // Чтение содержимого файла в виде одной строки
    std::string readAll();
};

#endif // TEXT_FILE_HANDLER_H
