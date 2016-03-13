/* 
 * File:   main.cpp
 * Author: Abdul-Hakim
 *
 * Created on September 28, 2015, 11:01 AM
 */

//System Libraries
#include <cstdlib>
#include <iostream>
#include <iomanip>
//User Libraries
#include "employee.h"
#include "productionworker.h"
using namespace std;

//Global Constants

//Function Prototypes

//Execution Starts Here
int main(int argc, char** argv) {
    //Variable Declaration
    
    //Create Employee
    ProductionWorker worker("Hector Vice", 101707, "09/16/13", 2, 28.50);
    
    //Display Employee Information
    cout<<setprecision(4)<<showpoint;
    cout<<"Employee Name:         "<<worker.getName()<<endl;
    cout<<"Employee Number:       "<<worker.getNum()<<endl;
    cout<<"Employee's Hire Date:  "<<worker.getHire()<<endl;
    cout<<"Employee's Shift:      "<<worker.getShift()<<endl;
    cout<<"Employee's Pay Rate:   $"<<worker.getPayRate()<<endl;
    
    //Exit Stage Right
    return 0;
}

