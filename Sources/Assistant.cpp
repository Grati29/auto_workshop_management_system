#include "Assistant.h"

Assistant::Assistant() = default;

Assistant::Assistant(string firstName, string lastName, string birthDate, string hireDate)
    : Employee(firstName, lastName, birthDate, hireDate, 1) {}

void Assistant::Display() const {
    cout << "Assistant " << firstName << " " << lastName
         << " (ID: " << id << ") - Salary Coefficient: "
         << salaryCoefficient << std::endl;
}

