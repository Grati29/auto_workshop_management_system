#ifndef TRUCK_H
#define TRUCK_H

#include "Car.h"

class Truck : public Car {
    int tonnage; // Tonaj

public:
    Truck();
    Truck(int mileage, int manufactureYear, char engineType, int tonnage);

    void CalculateInsurance(bool discount = false) override;
    void Display() override;
};

#endif // TRUCK_H

