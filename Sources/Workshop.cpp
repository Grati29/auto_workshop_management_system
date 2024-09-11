#include "Workshop.h"

Workshop::Workshop() = default;

void Workshop::AddEmployee(const shared_ptr<Employee>& employee) {
    employees.push_back(employee);
}

bool Workshop::IsOpen() const {
    return !employees.empty();
}

bool Workshop::CanAcceptCar(shared_ptr<Car> car) {
    // Check if the workshop can still accept cars of the given type
    if (dynamic_pointer_cast<Standard>(car) && standardCarsInWorkshop < 3) {
        return true;
    } else if (dynamic_pointer_cast<Bus>(car) && busesInWorkshop < 1) {
        return true;
    } else if (dynamic_pointer_cast<Truck>(car) && trucksInWorkshop < 1) {
        return true;
    }
    return false;
}

void Workshop::AddCar(shared_ptr<Car> car) {
    if (CanAcceptCar(car)) {
        carQueue.push(car);
        if (dynamic_pointer_cast<Standard>(car)) standardCarsInWorkshop++;
        if (dynamic_pointer_cast<Bus>(car)) busesInWorkshop++;
        if (dynamic_pointer_cast<Truck>(car)) trucksInWorkshop++;
        AllocateCar();
    } else {
        cout << "No space available for this type of car!" << endl;
    }
}

void Workshop::AllocateCar() {
    // Allocate the car to the first available employee
    for (auto& employee : employees) {
        if (employee->IsAvailable()) {
            if (!carQueue.empty()) {
                auto car = carQueue.front();
                carQueue.pop();
                employee->TakeCar(car);
                return;
            }
        }
    }
    cout << "All employees are busy. The car will be added to the queue." << endl;
}

void Workshop::CompleteRepair(int employeeId) {
    for (auto& employee : employees) {
        if (employee->GetID() == employeeId) {
            auto car = employee->FinishRepair();
            if (dynamic_pointer_cast<Standard>(car)) standardCarsInWorkshop--;
            if (dynamic_pointer_cast<Bus>(car)) busesInWorkshop--;
            if (dynamic_pointer_cast<Truck>(car)) trucksInWorkshop--;
            AllocateCar();
            return;
        }
    }
    cout << "Employee not found!" << endl;
}

void Workshop::DisplayStatus() {
    cout << "Workshop open: " << (IsOpen() ? "YES" : "NO") << endl;
    cout << "Cars in queue: " << carQueue.size() << endl;
    cout << "Standard cars in workshop: " << standardCarsInWorkshop << "/3" << endl;
    cout << "Buses in workshop: " << busesInWorkshop << "/1" << endl;
    cout << "Trucks in workshop: " << trucksInWorkshop << "/1" << endl;
}

