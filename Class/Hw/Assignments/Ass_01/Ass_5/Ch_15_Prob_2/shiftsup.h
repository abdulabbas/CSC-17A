/* 
 * File:   shiftsup.h
 * Author: Abdul-Hakim
 *
 * Created on September 28, 2015, 7:13 PM
 */

#ifndef SHIFTSUP_H
#define	SHIFTSUP_H

//System Libraries
#include <cstdlib>
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
//User Libraries
#include "employee.h"

class ShiftSupervisor : public Employee{
    private:
        float anSalry;
        float anBonus;
        
    public:
        ShiftSupervisor() : Employee(){
            anSalry=0.0;
            anBonus=0.0;
        }
        
        ShiftSupervisor(string name, int num, string hire, 
        float annualS, float annualB) : Employee(name, num, hire){
            anSalry=annualS;
            anBonus=annualB;
        }
        
        float getAnnualS()
            {return anSalry;}
        float getAnnualB()
            {return anBonus;}
        
};


#endif	/* SHIFTSUP_H */

