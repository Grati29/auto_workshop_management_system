#include "Manager.h"

Manager::Manager() = default;

Manager::Manager(string firstName, string lastName, string birthDate, string hireDate)
    : Employee(firstName, lastName, birthDate, hireDate, 2.0) {}

void Manager::Display() const {
    cout << "Manager " << firstName << " " << lastName
         << " (ID: " << id << ") - Salary Coefficient: "
         << salaryCoefficient << endl;
}

