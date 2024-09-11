#include "EmployeeManagement.h"
#include <algorithm>
#include <vector>

using namespace std;

void EmployeeManagement::AddEmployee(const shared_ptr<Employee>& employee) {
    if (employee->GetFirstName().length() < 30 && employee->GetLastName().length() < 30 && (2024 - stoi(employee->GetBirthDate().substr(0, 4))) >= 18)
        employees.push_back(employee);
    else
        cout << "First name/last name and/or age do not meet the conditions.";
}

void EmployeeManagement::DisplayEmployees() {
    for (const auto& employee : employees) {
        employee->Display();
    }
}

shared_ptr<Employee> EmployeeManagement::FindEmployee(int id) {
    for (const auto& employee : employees) {
        if (employee->GetID() == id) {
            return employee;
        }
    }
    return nullptr;
}

void EmployeeManagement::EditEmployee(int id, const string& newFirstName, const string& newLastName, const string& newBirthDate, const string& newHireDate) {
    auto employee = FindEmployee(id);
    if (employee) {
        employee->SetFirstName(newFirstName);
        employee->SetLastName(newLastName);
        employee->SetBirthDate(newBirthDate);
        employee->SetHireDate(newHireDate);
    }
}

void EmployeeManagement::RemoveEmployee(int id) {
    employees.erase(remove_if(employees.begin(), employees.end(),
        [id](const shared_ptr<Employee>& employee) { return employee->GetID() == id; }),
        employees.end());
}

void EmployeeManagement::CalculateSalary(int id) {
    auto employee = FindEmployee(id);
    if (employee) {
        employee->CalculateSalary();
    }
}

