#include "Truck.h"

Truck::Truck() = default;

Truck::Truck(int mileage, int manufactureYear, char engineType, int tonnage)
    : Car(mileage, manufactureYear, engineType), tonnage(tonnage) {}

void Truck::CalculateInsurance(bool discount) {
    int value = (2024 - manufactureYear) * 300;
    if (mileage > 800000)
        value += 700;
    if (engineType == 'D')
        value += 1000; // adjustment for Diesel engines in trucks

    if (discount)
        value *= 0.85; // 15% discount for trucks

    cout << "Truck Insurance: " << value << " lei" << endl;
}

void Truck::Display() {
    cout << "Truck: ";
    Car::Display();
    cout << "Tonnage: " << tonnage << endl;
}

