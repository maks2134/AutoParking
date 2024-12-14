#include "TextFileHandler.h"
#include <sstream>

TextFileHandler::TextFileHandler(const std::string& path) : FileHandler(path) {}

std::vector<std::string> TextFileHandler::readAllLines() {
    if (!fileStream.is_open()) {
        throw std::runtime_error("File is not open for reading.");
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
        throw std::runtime_error("File is not open for writing.");
    }

    fileStream << line << "\n";
}

std::string TextFileHandler::readAll() {
    if (!fileStream.is_open()) {
        throw std::runtime_error("File is not open for reading.");
    }

    std::ostringstream buffer;
    buffer << fileStream.rdbuf();
    return buffer.str();
}
