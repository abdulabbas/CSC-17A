/* 
 * File:   Employee.cpp
 * Author: Abdul-Hakim
 * Created on September 28, 2015, 9:16 AM
 */

#include "Employee.h"

using namespace std;

//Constructor for objects with all arguments
Employee::Employee(string n, int i, string d, string p)
{
    name = n;
    idNumber = i;
    department = d;
    position = p;
}
//Constructor for objects with only the name and ID
Employee::Employee(string n, int i)
{
    name = n;
    idNumber = i;
    department = " ";
    position = " ";
}
//Default constructor
Employee::Employee()
{
    name = " ";
    idNumber = 0;
    department = " ";
    position = " ";
}

//Mutator for the name
void Employee::getName(string n){ name = n; }
//Mutator for the ID
void Employee::getId(int i){ idNumber = i; }
//Mutator for the department
void Employee::getDepartment(string d){ department = d; }
//Mutator for the position
void Employee::getPosition(string p){ position = p; }

//Accessor to print the name
string Employee::printName() const{ return name; }
//Accessor to print the ID
int Employee::printId() const{ return idNumber; }
//Accessor to print the department
string Employee::printDepartment() const{ return department; }
//Accessor to print the position
string Employee::printPosition() const { return position; }

