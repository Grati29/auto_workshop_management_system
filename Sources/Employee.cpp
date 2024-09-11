#include "Employee.h"

int Employee::nextID = 1;

Employee::Employee() = default;

Employee::Employee(string firstName, string lastName, string birthDate, string hireDate, double salaryCoefficient)
    : id(nextID++), firstName(firstName), lastName(lastName), birthDate(birthDate), hireDate(hireDate), salaryCoefficient(salaryCoefficient) {}

void Employee::Display() const {
    cout << "Employee " << firstName << " " << lastName
         << " (ID: " << id << ") - Salary Coefficient: "
         << salaryCoefficient << endl;
}

void Employee::CalculateSalary() {
    int currentYear = 2024;
    int hireYear = stoi(hireDate.substr(0, 4));
    int yearsOfExperience = currentYear - hireYear;
    double salary = yearsOfExperience * salaryCoefficient * 1000;
    cout << "Salary for " << firstName << " " << lastName
         << " (ID: " << id << ") is: "
         << salary << " lei." << endl;
}

bool Employee::IsAvailable() const {
    return available;
}

void Employee::TakeCar(shared_ptr<Car> car) {
    if (available) {
        currentCar = car;
        available = false;
        cout << "Employee " << id << " took the car with ID " << currentCar->GetID() << endl;
    } else {
        cout << "Employee " << id << " is already busy." << endl;
    }
}

shared_ptr<Car> Employee::FinishRepair() {
    if (!available) {
        cout << "Employee " << id << " finished repairing the car with ID " << currentCar->GetID() << endl;
        available = true;
        auto finishedCar = currentCar;
        currentCar = nullptr;
        return finishedCar;
    }
    return nullptr;
}

void Employee::SetFirstName(const string& fn) { firstName = fn; }
void Employee::SetLastName(const string& ln) { lastName = ln; }
void Employee::SetBirthDate(const string& date) { birthDate = date; }
void Employee::SetHireDate(const string& date) { hireDate = date; }
void Employee::SetSalaryCoefficient(double coef) { salaryCoefficient = coef; }
int Employee::GetID() const { return id; }
string Employee::GetFirstName() const { return firstName; }
string Employee::GetLastName() const { return lastName; }
string Employee::GetBirthDate() const { return birthDate; }
double Employee::GetSalaryCoefficient() const { return salaryCoefficient; }

Employee::~Employee() {}
