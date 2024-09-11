#ifndef ASSISTANT_H
#define ASSISTANT_H

#include "Employee.h"

class Assistant : public Employee {
public:
    Assistant();
    Assistant(string firstName, string lastName, string birthDate, string hireDate);

    void Display() const override;
};

#endif // ASSISTANT_H

