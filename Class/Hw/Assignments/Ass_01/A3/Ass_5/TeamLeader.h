/* 
 * File:   TeamLeader.h
 * Author: Abdul-Hakim
 *
 * Created on September 28, 2015, 9:55 AM
 */

#ifndef TEAMLEADER_H
#define	TEAMLEADER_H

//Libraries
#include "ProductionWorker.h"
#include <string>

using namespace std;

class TeamLeader : public ProductionWorker
{
    private:
        float bonusAmount;   //Bonus amount employee gets if completed hours
        float reqHours;      //Required hours to get the bonus
        float attendHours;   //Hours attended by the employee
        float total;         //Total pay for the employee
    public:
        //Default Constructor
        TeamLeader() : ProductionWorker()
        { 
            bonusAmount = 0;
            reqHours = 0.0;
            attendHours = 0.0;
            total = 0.0;
        }
        //Constructor with user inputs
        TeamLeader(string n, int i, string h, int s, float p, float b, float r, float a) : ProductionWorker(n, i, h, s, p)
        {
            bonusAmount = b;
            reqHours = r;
            attendHours = a;
            total = 0.0;
        }
        
        //Accessors
        int getBonusAmount() const { return bonusAmount; }
        float getReqHours() const { return reqHours; } 
        float getAttendHours() const { return attendHours;}
        float getTotal() const { return total;}
        
        //Function to calculate the total pay of the employee
        void calcTotal();
};

#endif	/* TEAMLEADER_H */

