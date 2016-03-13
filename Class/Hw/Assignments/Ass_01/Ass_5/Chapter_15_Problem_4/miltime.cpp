/* 
 * File:   miltime.cpp
 * Author: Abdul-Hakim
 *
 * Created on September 28, 2015, 7:50 PM
 */

#include <cstdlib>
#include "miltime.h"

void MilTime::setTime(int mH, int mS){
    
    milHour=mH;
    milSeconds=mS;
    hour=(milHour/100);
    min=milHour%100;
    sec=milSeconds;
    
    
}

