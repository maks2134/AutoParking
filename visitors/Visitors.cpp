#include "Visitors.h"

Visitors::Visitors(const std::string& parkingName, int capacity, const std::string& visitorType,
                   const std::string& name, const std::string& licensePlate)
        : AutoParking(parkingName, capacity), visitorType(visitorType), name(name), licensePlate(licensePlate) {}

Visitors::~Visitors() {}

const std::string& Visitors::getVisitorType() const {
    return visitorType;
}

const std::string& Visitors::getName() const {
    return name;
}

const std::string& Visitors::getLicensePlate() const {
    return licensePlate;
}

void Visitors::setLicensePlate(const std::string& licensePlate) {
    this->licensePlate = licensePlate;
}

std::ostream& operator<<(std::ostream& os, const Visitors& visitor) {
    os << "Тип посетителя: " << visitor.visitorType
       << ", Имя: " << visitor.name
       << ", Номер авто: " << visitor.licensePlate;
    return os;
}