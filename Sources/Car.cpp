#include "Car.h"

int Car::nextID = 1;

Car::Car() = default;

Car::Car(int mileage, int manufactureYear, char engineType)
    : id(nextID++), mileage(mileage), manufactureYear(manufactureYear), engineType(engineType) {}

void Car::Display() {
    cout << "Car: " << id << " " << mileage << " km, manufactured in " << manufactureYear << ", engine type: " << engineType << endl;
}

int Car::GetID() const {
    return id;
}

Car::~Car() {}

