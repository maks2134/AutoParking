#include <iostream>
#include <vector>
#include "autoParking/AutoParking.h"
#include "Auto/Auto.h"
#include "Employees/Employees.h"
#include "visitors/Visitors.h"
#include "Employees/Workers/Workers.h"
#include "visitors/Clients/Clients.h"
#include "visitors/Guests/Guests.h"
#include "Auto/Type/Type.h"
#include "windows.h"

using namespace std;

// Функция для показа главного меню
void showMenu() {
    cout << "\nГлавное меню:\n";
    cout << "1. Создать парковку\n";
    cout << "2. Создать машину\n";
    cout << "3. Добавить сотрудника\n";
    cout << "4. Добавить посетителя\n";
    cout << "5. Вывести информацию о парковке\n";
    cout << "6. Вывести информацию о сотрудниках\n";
    cout << "7. Выход\n";
    cout << "Выберите опцию: ";
}

// Главная функция
int main() {
    SetConsoleOutputCP(CP_UTF8);
    vector<AutoParking*> parkings;
    vector<Auto*> cars;
    vector<Employees*> employees;
    vector<Visitors*> visitors;

    int option = 0;
    while (true) {
        showMenu();
        cin >> option;

        switch (option) {
            case 1: {
                string name;
                int capacity;
                cout << "Введите название парковки: ";
                cin >> name;
                cout << "Введите вместимость парковки: ";
                cin >> capacity;
                cout << "Парковка создана!\n";
                break;
            }

            case 2: {
                string name, carType;
                int capacity, parkingSpot;
                cout << "Введите название парковки: ";
                cin >> name;
                cout << "Введите вместимость парковки: ";
                cin >> capacity;
                cout << "Введите тип автомобиля: ";
                cin >> carType;
                cout << "Введите номер парковочного места: ";
                cin >> parkingSpot;

                Auto* car = new Type(name, capacity, carType, parkingSpot);
                cars.push_back(car);
                cout << "Машина добавлена!\n";
                break;
            }


            case 4: {
                string visitorType, name, licensePlate;
                cout << "Введите тип посетителя (гость/клиент): ";
                cin >> visitorType;
                cout << "Введите имя посетителя: ";
                cin >> name;
                cout << "Введите номер автомобиля посетителя: ";
                cin >> licensePlate;

                if (visitorType == "Гость") {
                    double rate;
                    int minutes;
                    cout << "Введите поминутную ставку: ";
                    cin >> rate;
                    cout << "Введите количество минут на парковке: ";
                    cin >> minutes;

                    Visitors* guest = new Guests("Default", 0, name, licensePlate, rate, minutes);
                    visitors.push_back(guest);
                    cout << "Гость добавлен!\n";
                } else if (visitorType == "Клиент") {
                    double monthlyRate;
                    cout << "Введите месячную ставку: ";
                    cin >> monthlyRate;

                    Visitors* client = new Clients("Default", 0, name, licensePlate, monthlyRate);
                    visitors.push_back(client);
                    cout << "Клиент добавлен!\n";
                } else {
                    cout << "Неверный тип посетителя!\n";
                }
                break;
            }

            case 5: {
                for (const auto& parking : parkings) {
                    parking->showInfo();
                }
                break;
            }

            case 6: {
                for (const auto& employee : employees) {
                    employee->showEmployeeInfo();
                }
                break;
            }

            case 7: {
                cout << "Выход...\n";
                return 0;
            }

            default:
                cout << "Неверный выбор, попробуйте снова.\n";
                break;
        }
    }
}
