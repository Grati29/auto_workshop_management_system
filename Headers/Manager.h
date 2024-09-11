#ifndef MANAGER_H
#define MANAGER_H

#include "Employee.h"

class Manager : public Employee {
public:
    Manager();
    Manager(string firstName, string lastName, string birthDate, string hireDate);

    void Display() const override;
};

#endif // MANAGER_H

