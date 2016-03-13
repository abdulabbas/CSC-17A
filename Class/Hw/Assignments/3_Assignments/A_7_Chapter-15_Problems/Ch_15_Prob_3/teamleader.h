/* 
 * File:   teamleader.h
 * Author: Abdul-Hakim
 *
 * Created on September 28, 2015, 7:32 PM
 */

#ifndef TEAMLEADER_H
#define	TEAMLEADER_H

//System Libraries
#include <cstdlib>
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
//User Libraries
#include "productionworker.h"

class TeamLeader : public ProductionWorker{
    private:
        float moBonus;
        int reqHours;
        int attHours;
    public:
        TeamLeader() : ProductionWorker(){
            moBonus=0.0;
            reqHours=0;
            attHours=0;
        }
        
        TeamLeader(string name, int num, string hire, int s, float pay, 
            float moBo, int rHr, int atHr) : ProductionWorker(name, num, hire, s, pay){
            moBonus=moBo;
            reqHours=rHr;
            attHours=atHr;
        }
        
        //Mutator Functions
        void setMoBonus(float moBo)
            {moBonus=moBo;}
        void setReqHours(int rHr)
            {reqHours=rHr;}
        void setAttHours(int atHr)
            {attHours=atHr;}
        
        //Accessor Functions
        float getMoBonus()
            {return moBonus;}
        
        int getReqHours() const
            {return reqHours;}
        
        int getAttHours() const
            {return attHours;}
        
};


#endif	/* TEAMLEADER_H */


