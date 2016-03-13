/* 
 * File:   hand.h
 * Author: Abdul-Hakim 
 * Purpose: Specification for the Hand Class
 * Created on November 8, 2015, 7:59 PM
 */


#ifndef HAND_H 
#define	HAND_H

#include "Card.h"

class Hand{
   private:
       int nCards;
       Card **card;
       char recCard;
   public:
       Hand();
       ~Hand();
       Hand& operator--();
       Hand operator--(int);
       char inspect(char);
       void receive(int);
       int getNCrd(void){return recCard;};
};

#endif	/* HAND_H */

