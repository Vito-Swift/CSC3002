/*
 * File: employee.h
 * ----------------
 * This file provides a skeletal interface for an Employee class with three
 * subclasses: HourlyEmployee, CommissionedEmployee, and SalariedEmployee.
 * Lines marked with // comments are excluded from the abbreviated listing.
 */

#ifndef _employee_h
#define _employee_h

#include <string>

/*
 * Class: Employee
 * ---------------
 * This class defines the root of the Employee hierarchy.  Employee is
 * an abstract class, which means that there are no objects whose primary
 * type is Employee.  Every object is constructed as one of the subclasses.
 * The getPay method is declared using the virtual keyword, which means
 * that it can be overridden by its subclasses.  The "= 0" notation at the
 * end of the prototype marks getPay as a "pure virtual" method, which
 * is implemented only in the subclasses.
 */

class Employee {

public:

/*
 * Constructor: Employee
 * Usage: Employee e("NAME");
 * --------------------------
 * Initializes a employee with given employee name.
 */

    Employee(std::string name) : employeeName(name) {}

/*
 * Method: getName
 * Usage: std::string name = e.getName();
 * --------------------------------------
 * Returns the employeeName of the object.
 */

    std::string getName();

/*
 * Method: getPay
 * Usage: double pay = e.getPay();
 * -------------------------------
 * Get the pay value of the object.
 * It is a pure virtual function and need to be implemented
 * by classes inherited from it.
 */

    virtual double getPay() const = 0;

/*
 * Destructor: ~Employee()
 * Usage: (usually implicit)
 */

    virtual ~Employee();

/* Protected section */

protected:

/* Instance variables*/

    std::string employeeName;           /* name of the employee */

};

/*
 * Class: HourlyEmployee
 * ---------------------
 * This class is inherited from class Employee and defines the methods
 * for hourly employee.
 */

class HourlyEmployee: public Employee {

public:

/*
 * Constructor: HourlyEmployee
 * Usage: HourlyEmployee e("NAME");
 * --------------------------
 * Inherited from its base class Employee.
 * Initializes a employee with given employee name.
 */

    HourlyEmployee(std::string name) : Employee(name) {}

/*
 * Destructor: ~HourlyEmployee()
 * Usage: (usually implicit)
 */

    ~HourlyEmployee() = default;

/*
 * Method: getPay
 * Usage: double pay = getPay();
 * -----------------------------
 * Returns the hourly rate times hours worked of the employee.
 */

    double getPay() const;

/*
 * Method: setHourlyRate
 * Usage: setHourlyRate(15.0);
 * ---------------------------
 * Set the hourly rate of the employee.
 */

    void setHourlyRate(double rate);

/*
 * Method: setHoursWorked
 * Usage: setHoursWorked(100);
 * ---------------------------
 * Set the hours worked of the employee.
 */

    void setHoursWorked(int hours);

/* Private section */

private:

/* Instance variables */

    double hourlyRate;
    int hoursWorked;

};

/*
 * Class: CommissionedEmployee
 * ---------------------------
 * This class is inherited from class Employee and defines the methods
 * for commissioned employee.
 */

class CommissionedEmployee: public Employee {

public:

/*
 * Constructor: CommissionedEmployee
 * Usage: CommissionedEmployee e("NAME");
 * --------------------------
 * Inherited from its base class Employee.
 * Initializes a employee with given employee name.
 */

    CommissionedEmployee(std::string name) : Employee(name) {}

/*
 * Destructor: ~CommissionedEmployee
 * Usage: (usually implicit)
 */

    ~CommissionedEmployee() = default;

/*
 * Method: getPay
 * Usage: double pay = getPay();
 * -----------------------------
 * Returns the pay value of employee based on formula
 *  pay = baseSalary + commissionRate * salesVolume
 */

    double getPay() const;

/*
 * Method: setBaseSalary
 * Usage: setBaseSalary(100);
 * --------------------------
 * Set the base salary of the employee.
 */

    void setBaseSalary(double salary);

/*
 * Method: setCommissionRate
 * Usage: setBaseSalary(50);
 * --------------------------
 * Set the commission rate of the employee.
 */

    void setCommissionRate(double rate);

/*
 * Method: setSalesVolume
 * Usage: setBaseSalary(1000);
 * --------------------------
 * Set the sales volume of the employee.
 */

    void setSalesVolume(double volume);

/* Private section */

private:

/* Instance variables */

    double baseSalary;
    double commissionRate;
    double salesVolume;

};

/*
 * Class: SalariedEmployee
 * ---------------------------
 * This class is inherited from class Employee and defines the methods
 * for salaried employee.
 */

class SalariedEmployee: public Employee {

public:

/*
 * Constructor: SalariedEmployee
 * Usage: SalariedEmployee e("NAME");
 * --------------------------
 * Inherited from its base class Employee.
 * Initializes a employee with given employee name.
 */

    SalariedEmployee(std::string name) : Employee(name) {}

/*
 * Destructor: ~SalariedEmployee
 * Usage: (usually implicit)
 */

    ~SalariedEmployee() = default;

/*
 * Method: getPay
 * Usage: double pay = getPay();
 * -----------------------------
 * Returns the salary of the employee.
 */

    double getPay() const;

/*
 * Method: setSalary
 * Usage: setSalary(1000);
 * -----------------------
 * Set the salary of the employee.
 */

    void setSalary(double salary);

/* Private section */

private:

/* Instance variables */

    double salary;

};

#endif
