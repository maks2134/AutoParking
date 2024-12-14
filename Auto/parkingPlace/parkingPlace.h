
#ifndef EGOR_PARKINGPLACE_H
#define EGOR_PARKINGPLACE_H
#include "../Auto.h"

// Класс parkingPlace (описание парковочного места)
class parkingPlace : public Auto {
private:
    bool isOccupied; // Занято ли место

public:
    // Конструктор
    parkingPlace(const std::string& name, int capacity, const std::string& carType, int parkingSpot, bool isOccupied = false);

    // Методы
    void showCarInfo() const override;          // Показать информацию о парковочном месте
    void assignParkingSpot(int spotNumber) override; // Назначить номер парковочного места
    bool getOccupancyStatus() const;            // Получить статус занятости
    void setOccupancyStatus(bool status);       // Установить статус занятости
};

#endif //EGOR_PARKINGPLACE_H
