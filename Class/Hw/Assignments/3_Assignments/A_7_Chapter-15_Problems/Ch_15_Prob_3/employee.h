/* 
 * File:   employee.h
 * Author: Abdul-Hakim
 *
 * Created on September 28, 2015, 7:30 PM
 */

#ifndef EMPLOYEE_H
#define	EMPLOYEE_H

//System Libraries
#include <cstdlib>
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;


class Employee{
protected:
    string empName; //Employee Name
    int empNum;     //Employee Number
    string empHire; //Employee Hire Date
    
public:
    Employee(){
        empName="";
        empNum=0;
        empHire="";
    }
    
    Employee (string n, int num, string h){
        empName=n;
        empNum=num;
        empHire=h;
    }
    
    void setName(string n)
        {empName=n;}
    void setNum(int num)
        {empNum=num;}
    void setHire(string h)
        {empHire=h;}
    
    string getName() const
        {return empName;}
    int getNum() const
        {return empNum;}
    string getHire() const
        {return empHire;}
    
};

#endif	/* EMPLOYEE_H */


