#include "Standard.h"

Standard::Standard() = default;

Standard::Standard(int mileage, int manufactureYear, char engineType, string transmissionType)
    : Car(mileage, manufactureYear, engineType), transmissionType(transmissionType) {}

void Standard::CalculateInsurance(bool discount) {
    int value = (2024 - manufactureYear) * 100;
    if (engineType == 'D')
        value += 500;
    if (mileage > 200000)
        value += 500;

    if (discount)
        value *= 0.95; // 5% discount for standard cars

    cout << "Standard Car Insurance: " << value << " lei" << endl;
}

void Standard::Display() {
    cout << "Standard: ";
    Car::Display();
    cout << "Transmission type: " << transmissionType << endl;
}

