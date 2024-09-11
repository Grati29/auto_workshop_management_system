#ifndef WORKSHOP_H
#define WORKSHOP_H

#include <queue>
#include <vector>
#include <memory>
#include <iostream>
#include "Employee.h"
#include "Car.h"
#include "Manager.h"
#include "Employee.h"
#include "Mechanic.h"
#include "Assistant.h"
#include "Standard.h"
#include "Bus.h"
#include "Truck.h"

using namespace std;

class Workshop {
private:
    vector<shared_ptr<Employee>> employees;
    queue<shared_ptr<Car>> carQueue;
    int standardCarsInWorkshop = 0;
    int busesInWorkshop = 0;
    int trucksInWorkshop = 0;

public:
    Workshop();

    void AddEmployee(const shared_ptr<Employee>& employee);
    bool IsOpen() const;
    bool CanAcceptCar(shared_ptr<Car> car);
    void AddCar(shared_ptr<Car> car);
    void AllocateCar();
    void CompleteRepair(int employeeId);
    void DisplayStatus();
};

#endif // WORKSHOP_H

