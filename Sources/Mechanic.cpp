#include "Mechanic.h"

Mechanic::Mechanic() = default;

Mechanic::Mechanic(string firstName, string lastName, string birthDate, string hireDate)
    : Employee(firstName, lastName, birthDate, hireDate, 1.5) {}

void Mechanic::Display() const {
    cout << "Mechanic " << firstName << " " << lastName
         << " (ID: " << id << ") - Salary Coefficient: "
         << salaryCoefficient << std::endl;
}

