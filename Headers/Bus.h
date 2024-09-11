#ifndef BUS_H
#define BUS_H

#include "Car.h"

class Bus : public Car {
    int seatCount; // NumarLocuri

public:
    Bus();
    Bus(int mileage, int manufactureYear, char engineType, int seatCount);

    void CalculateInsurance(bool discount = false) override;
    void Display() override;
};

#endif // BUS_H

