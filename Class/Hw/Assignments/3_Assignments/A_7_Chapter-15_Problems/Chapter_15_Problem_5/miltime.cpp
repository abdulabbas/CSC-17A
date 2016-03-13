/* 
 * File:   miltime.cpp
 * Author: Abdul-Hakim
 *
 * Created on September 28, 2015, 7:59 PM
 */

#include <cstdlib>
#include "miltime.h"
using namespace std;


void MilTime::setTime(int mH, int mS){
    
    milHour=mH;
    milSeconds=mS;
    hour=(milHour/100);
    min=milHour%100;
    sec=milSeconds;
    
}


