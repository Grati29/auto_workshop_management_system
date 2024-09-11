# auto_workshop_management_system - C++ - OOP

## Project Overview

The Auto Workshop Management System is a console-based application developed in C++. It is designed to manage an auto workshop by handling operations related to both the workshop's personnel and the vehicles.

The project is structured into several classes that handle different aspects of the workshop's operations, including employees and vehicles. The application provides a user-friendly console menu for interacting with the system.

## Project Structure

The project is organized into the following files:

### Source Files

- `main.cpp`: Contains the main function and the user menu for interacting with the workshop management system.
- `Workshop.cpp`: Implements the Workshop class responsible for managing the overall operations of the workshop, including managing employees and vehicles.
- `Employee.cpp`: Implements the base Employee class.
- `Manager.cpp`, `Mechanic.cpp`, `Assistant.cpp`: Implements Employee derived classes such as Manager, Mechanic, and Assistant.
- `EmployeeManagement.cpp`: Implements the EmployeeManagement class that handles adding, editing, deleting, and calculating the salaries of employees.
- `Car.cpp`: Implements the base Car class.
- `Standard.cpp`, `Bus.cpp`, `Truck.cpp`: Implement specific behaviors and characteristics for each type of vehicle.

### Header Files

- `Workshop.h`: Declares the Workshop class.
- `Employee.h`: Declares the Employee class.
- `Manager.cpp`, `Mechanic.cpp`, `Assistant.cpp`: Declare the Employee derivated classes.
- `EmployeeManagement.h`: Declares the EmployeeManagement class.
- `Car.h`: Declares the Car class.
- `Standard.h`, `Bus.h`, `Truck.h`: Declare the Car derivated classes.

## Functional Requirements

### I. Employees

There are three types of employees: Manager, Mechanic, and Assistant. All employees have the following attributes:

- ID
- First Name
- Last Name
- Birth Date
- Hire Date
- Salary Coefficient

#### Implemented Functionalities:

- Display employees
- Add employee
- Delete employee
- Edit employee
- Calculate employee salary

#### Additional Observations:

- The ID should automatically increment for each added employee.
- The salary coefficient is not set manually. The coefficients are as follows:
  - Manager: 2.0
  - Mechanic: 1.5
  - Assistant: 1.0
- First and last names should not exceed 30 characters each.
- Employees must be at least 18 years old on the day of hiring.
- The hire date cannot be a future date.
- Deleting, editing, and calculating an employee's salary is done based on the employee's ID, entered via the console. If the ID does not match any employee, an appropriate message is displayed, and the system prompts the user to re-enter the ID.
- The salary is calculated using the formula: Years of Experience * Coefficient * 1000 lei


### II. Vehicles

There are three types of vehicles: Standard, Bus, and Truck. All vehicles share the following attributes:

- ID
- Mileage
- Year of Manufacture
- Engine Type (Diesel or Gasoline)

#### Specific Attributes and Calculations:

1. **Standard Cars**: 
 - Additional Attribute: Transmission Mode (Manual or Automatic)
 - Insurance Calculation:
   - Age (in years) multiplied by 100, plus:
   - +500 if the engine is Diesel
   - +500 if mileage exceeds 200,000 km
 - A discount of 5% can be applied.

2. **Buses**:
 - Additional Attribute: Number of Seats
 - Insurance Calculation:
   - Age (in years) multiplied by 200, plus:
   - +1000 if the engine is Diesel
   - +1000 if mileage exceeds 200,000 km
   - +500 if mileage exceeds 100,000 km but is below 200,000 km
 - A discount of 10% can be applied.

3. **Trucks**:
 - Additional Attribute: Tonnage
 - Insurance Calculation:
   - Age (in years) multiplied by 300, plus:
   - +1000 if the engine is Diesel
   - +700 if mileage exceeds 800,000 km
 - A discount of 15% can be applied.

### III. Workshop Operations

The workshop can employ multiple employees and repair multiple types of vehicles, with the following restrictions:

1. There must be at least one employee for the workshop to be considered open.
2. Employees cannot be overburdened: the workshop can accept up to 3 standard cars, 1 bus, and 1 truck at any time.
3. Employees must provide an estimated time for repairing a vehicle and are responsible for ensuring this estimate is accurate.
4. As an employee completes the repair of a vehicle, they can take on new vehicles, adhering to the restrictions above.
5. A new vehicle arriving for repair can be assigned to the first available employee or a specific requested employee. If the requested employee is unavailable, the vehicle can be either placed in a queue or assigned to another employee.
6. When all employees are occupied, a vehicle can either wait or its owner can choose to leave.

## User Menu

The console menu allows the user to:

1. Add an employee
2. Add a vehicle
3. Complete a repair
4. Display the workshop status
5. Exit the application
