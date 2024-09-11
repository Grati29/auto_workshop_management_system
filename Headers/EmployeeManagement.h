#ifndef EMPLOYEEMANAGEMENT_H
#define EMPLOYEEMANAGEMENT_H

#include <vector>
#include <memory>
#include "Employee.h"

class EmployeeManagement {
private:
    vector<shared_ptr<Employee>> employees;

public:
    void AddEmployee(const shared_ptr<Employee>& employee);
    void DisplayEmployees();
    shared_ptr<Employee> FindEmployee(int id);
    void EditEmployee(int id, const string& newFirstName, const string& newLastName, const string& newBirthDate, const string& newHireDate);
    void RemoveEmployee(int id);
    void CalculateSalary(int id);
};

#endif // EMPLOYEEMANAGEMENT_H

