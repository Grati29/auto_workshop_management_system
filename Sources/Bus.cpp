#include "Bus.h"

Bus::Bus() = default;

Bus::Bus(int mileage, int manufactureYear, char engineType, int seatCount)
    : Car(mileage, manufactureYear, engineType), seatCount(seatCount) {}

void Bus::CalculateInsurance(bool discount) {
    int value = (2024 - manufactureYear) * 200;
    if (engineType == 'D')
        value += 1000;
    if (mileage > 200000)
        value += 1000;
    else if (mileage > 100000)
        value += 500;

    if (discount)
        value *= 0.90; // 10% discount for buses

    cout << "Bus Insurance: " << value << " lei" << endl;
}

void Bus::Display() {
    cout << "Bus: ";
    Car::Display();
    cout << "Seat count: " << seatCount << endl;
}

