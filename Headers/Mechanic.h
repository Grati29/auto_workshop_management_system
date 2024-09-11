#ifndef MECHANIC_H
#define MECHANIC_H

#include "Employee.h"

class Mechanic : public Employee {
public:
    Mechanic();
    Mechanic(string firstName, string lastName, string birthDate, string hireDate);

    void Display() const override;
};

#endif // MECHANIC_H

