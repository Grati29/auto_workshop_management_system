#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include <string>
#include <memory>
#include "Car.h"

using namespace std;

class Employee {
protected:
    static int nextID;
    int id;
    string firstName;
    string lastName;
    string birthDate;
    string hireDate;
    double salaryCoefficient;
    bool available = true;
    shared_ptr<Car> currentCar;

public:
    Employee();
    Employee(string firstName, string lastName, string birthDate, string hireDate, double salaryCoefficient);

    virtual void Display() const;
    virtual void CalculateSalary();

    bool IsAvailable() const;
    void TakeCar(shared_ptr<Car> car);
    shared_ptr<Car> FinishRepair();

    void SetFirstName(const string& fn);
    void SetLastName(const string& ln);
    void SetBirthDate(const string& date);
    void SetHireDate(const string& date);
    void SetSalaryCoefficient(double coef);

    int GetID() const;
    string GetFirstName() const;
    string GetLastName() const;
    string GetBirthDate() const;
    double GetSalaryCoefficient() const;

    virtual ~Employee();
};

#endif // EMPLOYEE_H
