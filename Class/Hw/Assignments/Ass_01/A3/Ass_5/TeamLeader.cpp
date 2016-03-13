/* 
 * File:   TeamLeader.cpp
 * Author: Abdul-Hakim
 *
 * Created on September 28, 2015, 10:41 AM
 */

#include "TeamLeader.h"

//Function to calculate the total payment
void TeamLeader::calcTotal()
{
    float payRate;   //Hourly pay rate
    
    //Calling getPayRate function from the ProductionWorker class
    payRate = getPayRate();
    
    if(attendHours >= reqHours)
    {
        total = (attendHours * payRate) + bonusAmount;
    }
    else
    {
        total = attendHours * payRate;
    }
}
