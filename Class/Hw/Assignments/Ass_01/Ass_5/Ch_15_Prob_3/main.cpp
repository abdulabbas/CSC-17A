/* 
 * File:   main.cpp
 * Author: Abdul-Hakim
 * Purpose: Chapter_15_Prob_3 
 * Created on September 28, 2015, 7:21 PM
 */

//System Libraries
#include <cstdlib>
#include <iostream>
//User Libraries
#include "employee.h"
#include "productionworker.h"
#include "teamleader.h"
using namespace std;
//Global constants
//Function Prototypes
//Execution begins here!
int main(int argc, char** argv) {
    //Variable Declaration
    
    //Create Employee
     ProductionWorker worker("Cindy Guijosa", 101707, "09/16/13", 2, 45.50);
    
    //Display Employee Information
    cout<<setprecision(2)<<showpoint<<fixed;
    cout<<"Employee Name:         "<<worker.getName()<<endl;
    cout<<"Employee Number:       "<<worker.getNum()<<endl;
    cout<<"Employee's Hire Date:  "<<worker.getHire()<<endl;
    cout<<"Employee's Shift:      "<<worker.getShift()<<endl;
    cout<<"Employee's Pay Rate:   $"<<worker.getPayRate()<<endl;
    cout<<endl<<endl;
    
    //Create Team Leader
    TeamLeader lead("Big Boss", 101000, "01/01/1900", 2, 35.00, 200.00, 30, 9);
    cout<<setprecision(2)<<showpoint<<fixed;
    cout<<"--> Shift Team Leader <--"<<endl;
    cout<<"Employee Name:           "<<lead.getName()<<endl;
    cout<<"Employee's Number:       "<<lead.getNum()<<endl;
    cout<<"Employee's Hire Date:    "<<lead.getHire()<<endl;
    cout<<"Employee's Shift:        "<<lead.getShift()<<endl;
    cout<<"Employee's Pay Rate:     $"<<lead.getPayRate()<<endl;
    cout<<"Team Lead Monthly Bonus: $"<<lead.getMoBonus()<<endl;
    cout<<"Required Training Hours: "<<lead.getReqHours()<<endl;
    cout<<"Attended Training Hours: "<<lead.getAttHours()<<endl;
    
    //Exit Stage Right
    return 0;
}

