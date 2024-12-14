#ifndef FILE_HANDLER_H
#define FILE_HANDLER_H

#include <string>
#include <fstream>

// Базовый класс для работы с файлами
class FileHandler {
protected:
    std::string filePath; // Путь к файлу
    std::fstream fileStream; // Поток для работы с файлом

public:
    explicit FileHandler(const std::string& path);
    virtual ~FileHandler();

    // Открытие файла
    virtual void open(std::ios::openmode mode);

    // Закрытие файла
    virtual void close();

    // Проверка, открыт ли файл
    bool isOpen() const;

    // Получение пути к файлу
    std::string getFilePath() const;
};

#endif // FILE_HANDLER_H
