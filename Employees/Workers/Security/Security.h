#ifndef EGOR_SECURITY_H
#define EGOR_SECURITY_H
#include "../Workers.h"
#include <vector>

// Класс Security
class Security : public Workers {
private:
    std::vector<std::string> carPlates; // Номера автомобилей для проверки

public:
    // Конструктор
    Security(const std::string& parkingName, int capacity, double salary);

    // Методы
    void work() const override;                        // Выполнение обязанностей охранника
    void showEmployeeInfo() const override;            // Вывод информации об охраннике
    void addCarToCheck(const std::string& plate);      // Добавить автомобиль в список для проверки
    void checkCars() const;                            // Проверить все автомобили
};

#endif //EGOR_SECURITY_H
