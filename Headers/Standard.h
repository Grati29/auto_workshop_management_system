#ifndef STANDARD_H
#define STANDARD_H

#include "Car.h"

class Standard : public Car {
    string transmissionType; // ModTransmisie

public:
    Standard();
    Standard(int mileage, int manufactureYear, char engineType, string transmissionType);

    void CalculateInsurance(bool discount = false) override;
    void Display() override;
};

#endif // STANDARD_H

