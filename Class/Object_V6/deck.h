/* 
 * File:   deck.h
 * Author: Abdul-Hakim 
 * Purpose: Specification for the Deck Class
 * Created on November 8, 2015, 7:58 PM
 */

#ifndef DECK_H 
#define	DECK_H

#include "Card.h"

class Deck{
   private:
       int nCards;
       Card **card;
       char *indx;
       char dltCard;
   public:
       Deck();
       ~Deck();
       void shuffle(void);
       char deal();
       int getNCrd(void){return nCards;};
};

#endif	/* DECK_H */

