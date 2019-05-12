/*
 * File: employee.cpp
 * ------------------
 * This file provides a stub implementation of the employee.h interface.
 */

#include <string>
#include "employee.h"
#include "strlib.h"
using namespace std;

/*
 * Implementation notes: getName
 * -----------------------------
 * This method returns the employeeName of the instance.
 */

std::string Employee::getName() {
    return employeeName;
}

Employee::~Employee() {}

/*
 * Implementation notes: getPay, setHourlyRate, setHoursWorked
 * -----------------------------------------------------------
 * These methods define the interfaces of hourly employee based
 * on corresponding mechanisms.
 */

double HourlyEmployee::getPay() const {
    return hourlyRate * hoursWorked;
}

void HourlyEmployee::setHourlyRate(double rate) {
    hourlyRate = rate;
}

void HourlyEmployee::setHoursWorked(int hours) {
    hoursWorked = hours;
}

/*
 * Implementation notes: getPay, setBaseSalary, setCommissionRate, setSalesVolume
 * ------------------------------------------------------------------------------
 * These methods define the interfaces of commissioned employee
 * based on corresponding mechanisms.
 */

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

/*
 * Implementation notes: getPay, setSalary
 * ---------------------------------------
 * These methods define the interfaces of salaried employee based
 * on corresponding mechanisms.
 */

double SalariedEmployee::getPay() const {
    return salary;
}

void SalariedEmployee::setSalary(double salary) {
    this->salary = salary;
}
