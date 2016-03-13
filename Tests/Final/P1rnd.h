/* 
 * File:   P1rnd.h 
 * Author: Abdul-Hakim 
 * Created on December 11, 2015, 9:30 PM 
 */

#ifndef P1RND_H 
#define	P1RND_H
class P1rnd {
        private:
		char *set;      //The set of numbers to draw random numbers from 
		char  nset;     //The number of variables in the sequence 
		int  *freq;     //Frequency of all the random numbers returned 
		int   numRand;  //The total number of times the random number function is called 
    public:
		P1rnd(const char,const char *);     //Constructor 
		~P1rnd(void);                       //Destructor 
		char randFromSet(void);                   //Returns a random number from the set 
		int *getFreq(void) const;                 //Returns the frequency histogram 
		char *getSet(void) const;                 //Returns the set used 
		int getNumRand(void) const;               //Gets the number of times random from the set 
		                                          //Has been called 
};


#endif	/* P1RND_H */
//This is used for Problem 1 
//It is used to solve the Random Looping Question 
