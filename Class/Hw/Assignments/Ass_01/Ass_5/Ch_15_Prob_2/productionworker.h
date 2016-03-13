/* 
 * File:   productionworker.h
 * Author: Abdul-Hakim
 *
 * Created on September 28, 2015, 7:12 PM
 */


#ifndef PRODUCTIONWORKER_H
#define	PRODUCTIONWORKER_H

//System Libraries
#include <cstdlib>
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
//User Libraries
#include "employee.h"

class ProductionWorker : public Employee{
    private:
        int shift;
        float payRate;
        
    public:
        ProductionWorker():Employee(){
            shift=0;
            payRate=0.0;
        }
        
        ProductionWorker(string name, int num, string hire, 
                int s, float pay) : Employee(name, num, hire){
            
            shift=s;
            payRate=pay;
        }
        
        int getShift()
            {return shift;}
        float getPayRate()
            {return payRate;}
};

#endif	/* PRODUCTIONWORKER_H */

