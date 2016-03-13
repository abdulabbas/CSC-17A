/* 
 * File:   Employee.h
 * Author: Abdul-Hakim
 *
 * Created on September 28, 2015, 9:50 AM
 */

#ifndef EMPLOYEE_H
#define	EMPLOYEE_H

//Libraries
#include <string>

using namespace std;

class Employee 
{
    private:
        string empName;   //Holds employee name
        int empId;        //Holds employee ID number
        string empHire;   //Holds employee hire date
    public:
        //Constructor
        Employee();                    //Default constructor
        Employee(string,int,string);   //Constructor using input
        
        //Accessors
        string getName() const;
        int getId() const;
        string getHire() const;
};

#endif	/* EMPLOYEE_H */

