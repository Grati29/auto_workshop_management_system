#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include "Workshop.h"

using namespace std;

int main() {
    Workshop workshop;

    int option;
    do {
        cout << "\nAuto Workshop Menu:\n";
        cout << "1. Add employee\n";
        cout << "2. Add car\n";
        cout << "3. Complete repair\n";
        cout << "4. Display workshop status\n";
        cout << "0. Exit\n";
        cout << "Choose an option: ";
        cin >> option;

        switch (option) {
            case 1: {
                // Adding an employee
                int employeeType;
                string firstName, lastName, birthDate, hireDate;

                cout << "Employee type (1 = Manager, 2 = Mechanic, 3 = Assistant): ";
                cin >> employeeType;
                cout << "First name: ";
                cin >> firstName;
                cout << "Last name: ";
                cin >> lastName;
                cout << "Birth date (YYYY-MM-DD): ";
                cin >> birthDate;
                cout << "Hire date (YYYY-MM-DD): ";
                cin >> hireDate;

                shared_ptr<Employee> employee;
                if (employeeType == 1) {
                    employee = make_shared<Manager>(firstName, lastName, birthDate, hireDate);
                } else if (employeeType == 2) {
                    employee = make_shared<Mechanic>(firstName, lastName, birthDate, hireDate);
                } else if (employeeType == 3) {
                    employee = make_shared<Assistant>(firstName, lastName, birthDate, hireDate);
                }

                workshop.AddEmployee(employee);
                cout << "Employee added successfully!" << endl;
                break;
            }
            case 2: {
                // Adding a car
                int carType;
                int mileage, manufactureYear;
                char engineType;

                cout << "Car type (1 = Standard, 2 = Bus, 3 = Truck): ";
                cin >> carType;
                cout << "Mileage: ";
                cin >> mileage;
                cout << "Manufacture year: ";
                cin >> manufactureYear;
                cout << "Diesel engine? (D = yes, B = no): ";
                cin >> engineType;

                shared_ptr<Car> car;
                if (carType == 1) {
                    string transmissionType;
                    cout << "Transmission type (Manual/Automatic): ";
                    cin >> transmissionType;
                    car = make_shared<Standard>(mileage, manufactureYear, engineType, transmissionType);
                } else if (carType == 2) {
                    int seatCount;
                    cout << "Seat count: ";
                    cin >> seatCount;
                    car = make_shared<Bus>(mileage, manufactureYear, engineType, seatCount);
                } else if (carType == 3) {
                    int tonnage;
                    cout << "Tonnage: ";
                    cin >> tonnage;
                    car = make_shared<Truck>(mileage, manufactureYear, engineType, tonnage);
                }

                workshop.AddCar(car);
                cout << "Car added successfully!" << endl;
                break;
            }
            case 3: {
                // Completing a repair
                int employeeId;
                cout << "ID of the employee completing the repair: ";
                cin >> employeeId;
                workshop.CompleteRepair(employeeId);
                break;
            }
            case 4: {
                // Displaying workshop status
                workshop.DisplayStatus();
                break;
            }
            case 0:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid option! Please choose again." << endl;
                break;
        }
    } while (option != 0);

    return 0;
}
