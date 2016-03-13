/* 
 * File:   Employee.h 
 * Author: Abdul-Hakim
 * Created on November 17, 2015, 9:20 PM
 */

#ifndef EMPLOYEE_H
#define	EMPLOYEE_H
#include <string>

using namespace std;

class Employee 
{
    private:
        string name;         //Holds the name of the employee
        int idNumber;        //Holds the employee's ID number
        string department;   //Holds name of department where the employee works
        string position;     //Holds the employee's job title
    public:
        Employee(string, int, string, string);   //Constructor for all arguments
        Employee(string, int);                   //Constructor for name and ID
        Employee();                              //Default constructor
        void getName(string);             //Mutator that gets the name
        void getId(int);                  //Mutator that gets the ID
        void getDepartment(string);       //Mutator that gets the department
        void getPosition(string);         //Mutator that gets the position
        string printName() const;         //Accessor that prints the name
        int printId() const;              //Accessor that prints the ID
        string printDepartment() const;   //Accessor that prints the department
        string printPosition() const;     //Accessor that prints the position
};

#endif	/* EMPLOYEE_H */

