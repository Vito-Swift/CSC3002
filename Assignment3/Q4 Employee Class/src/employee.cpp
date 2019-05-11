/*
 * File: employee.cpp
 * ------------------
 * This file provides a stub implementation of the employee.h interface.
 */

#include <string>
#include "employee.h"
#include "strlib.h"
using namespace std;

std::string Employee::getName() {
    return employeeName;
}

Employee::~Employee() {}

double HourlyEmployee::getPay() const {
    return hourlyRate * hoursWorked;
}

void HourlyEmployee::setHourlyRate(double rate) {
    hourlyRate = rate;
}

void HourlyEmployee::setHoursWorked(int hours) {
    hoursWorked = hours;
}

double CommissionedEmployee::getPay() const {
    return baseSalary + commissionRate * salesVolume;
}

void CommissionedEmployee::setBaseSalary(double salary) {
    baseSalary = salary;
}

void CommissionedEmployee::setCommissionRate(double rate) {
    commissionRate = rate;
}

void CommissionedEmployee::setSalesVolume(double volume) {
    salesVolume = volume;
}

double SalariedEmployee::getPay() const {
    return salary;
}

void SalariedEmployee::setSalary(double salary) {
    this->salary = salary;
}
