#include "AutoParking.h"

AutoParking::AutoParking(const std::string& name, int capacity)
        : name(name), capacity(capacity) {}

AutoParking::~AutoParking() = default;

std::ostream& operator<<(std::ostream& os, const AutoParking& parking) {
    os << "Parking: " << parking.name << ", Capacity: " << parking.capacity;
    return os;
}
