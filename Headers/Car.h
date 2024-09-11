#ifndef CAR_H
#define CAR_H

#include <iostream>
#include <string>

using namespace std;

class Car {
protected:
    static int nextID;
    int id;
    int mileage; // NumarKm
    int manufactureYear; // AnFabricatie
    char engineType; // 'D' for Diesel, 'B' for Gasoline

public:
    Car();
    Car(int mileage, int manufactureYear, char engineType);

    virtual void CalculateInsurance(bool discount = false) = 0;
    virtual void Display();
    virtual int GetID() const;

    virtual ~Car();
};

#endif // CAR_H

