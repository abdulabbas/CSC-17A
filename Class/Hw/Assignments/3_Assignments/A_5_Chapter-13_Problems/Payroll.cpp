/* 
 * File:   Payroll.cpp
 * Author: Abdul-Hakim
 * Created on November 17, 2015, 9:35 PM
 */

#include "Payroll.h"

//Declaring arguments to a default value
Payroll::Payroll()
{
    payRate = 0.0;     
    hoursWorked = 0.0;
    totalPay = 0.0;
}

//Mutator to get the payRate
void Payroll::getRate(float r) { payRate = r; }
//Mutator to get the hours worked
void Payroll::getHours(float h) { hoursWorked = h; }
//Accessor to print the total pay
float Payroll::printTotal()
{
    //Calculating the total pay
    totalPay = payRate * hoursWorked;
    
    //Returning total pay
    return totalPay;
}
