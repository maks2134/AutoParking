cmake_minimum_required(VERSION 3.28)
project(Egor)

set(CMAKE_CXX_STANDARD 23)

add_executable(Egor main.cpp
        autoParking/AutoParking.cpp
        autoParking/AutoParking.h
        Employees/Employees.cpp
        Employees/Employees.h
        Auto/Auto.cpp
        Auto/Auto.h
        visitors/Visitors.cpp
        visitors/Visitors.h
        Employees/Manager/Manager.cpp
        Employees/Manager/Manager.h
        Employees/Workers/Workers.cpp
        Employees/Workers/Workers.h
        Employees/Workers/Administarator/Administrator.cpp
        Employees/Workers/Administarator/Administrator.h
        Employees/Workers/Security/Security.cpp
        Employees/Workers/Security/Security.h
        Auto/parkingPlace/parkingPlace.cpp
        Auto/parkingPlace/parkingPlace.h
        Auto/Type/Type.cpp
        Auto/Type/Type.h
        visitors/Guests/Guests.cpp
        visitors/Guests/Guests.h
        visitors/Clients/Clients.cpp
        visitors/Clients/Clients.h
        Exception/ParkingException.cpp
        Exception/ParkingException.h
        Exception/InvalidInputException.cpp
        Exception/InvalidInputException.h
        Exception/CapacityExceededException.cpp
        Exception/CapacityExceededException.h
        Exception/ParkingSpotException.cpp
        Exception/ParkingSpotException.h
        Exception/VisitorException.cpp
        Exception/VisitorException.h
        File/FileHandler.cpp
        File/FileHandler.h
        File/TextFileHandler.cpp
        File/TextFileHandler.h
        File/BinaryFileHandler.cpp
        File/BinaryFileHandler.h
        algoritm/HashTable.h
        algoritm/QuickSort.h
        auth/User.cpp
        auth/User.h
        auth/Authentication.cpp
        auth/Authentication.h
)
