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
    Employee(std::string name) : employeeName(name) {}
    std::string getName();
    virtual double getPay() const = 0;
    virtual ~Employee();
protected:
    std::string employeeName;
};

class HourlyEmployee: public Employee {
public:
    HourlyEmployee(std::string name) : Employee(name) {}
    ~HourlyEmployee() = default;
    double getPay() const;
    void setHourlyRate(double rate);
    void setHoursWorked(int hours);
private:
    double hourlyRate;
    int hoursWorked;
};

class CommissionedEmployee: public Employee {
public:
    CommissionedEmployee(std::string name) : Employee(name) {}
    ~CommissionedEmployee() = default;
    double getPay() const;
    void setBaseSalary(double salary);
    void setCommissionRate(double rate);
    void setSalesVolume(double volume);
private:
    double baseSalary;
    double commissionRate;
    double salesVolume;
};

class SalariedEmployee: public Employee {
public:
    SalariedEmployee(std::string name) : Employee(name) {}
    ~SalariedEmployee() = default;
    double getPay() const;
    void setSalary(double salary);
private:
    double salary;
};

#endif
