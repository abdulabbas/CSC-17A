/* 
 * File:   main.cpp
 * Author: Abdul-Hakim
 * Purpose: Chapter_15_Prob_2 
 * Created on September 28, 2015, 7:02 PM
 */

//System Libraries
#include <cstdlib>
#include <iostream>
#include <iomanip>
//User libraries
#include "employee.h"
#include "productionworker.h"
#include "shiftsup.h"
using namespace std;
//Global constants
//Function Prototypes
//Execution begins here!
int main(int argc, char** argv) {
 //Variable Declaration
    
    //Create Employee
    ProductionWorker worker("Hector Mendoza", 101707, "09/16/13", 2, 25.80);
    
    //Display Employee Information
    cout<<setprecision(2)<<fixed<<showpoint;
    cout<<"Employee Name:         "<<worker.getName()<<endl;
    cout<<"Employee Number:       "<<worker.getNum()<<endl;
    cout<<"Employee's Hire Date:  "<<worker.getHire()<<endl;
    cout<<"Employee's Shift:      "<<worker.getShift()<<endl;
    cout<<"Employee's Pay Rate:   $"<<worker.getPayRate()<<endl;
    cout<<endl<<endl;
    
    //Create Shift Sup
    ShiftSupervisor sup("Mickey Mouse", 12345, "11/18/28", 100000, 2000);
    
    //Display Sup's Information
    cout<<"--->Shift Supervisor<---"<<endl;
    cout<<setprecision(2)<<showpoint<<fixed;
    cout<<"Employee's Name:      "<<sup.getName()<<endl;
    cout<<"Employee's Number:    "<<sup.getNum()<<endl;
    cout<<"Employee's Hire Date: "<<sup.getHire()<<endl;
    cout<<"Annual Salary:        $"<<sup.getAnnualS()<<endl;
    cout<<"Annual Bonus:         $"<<sup.getAnnualB()<<endl;
    
    //Exit Stage Right
    return 0;
}


