/* 
 * File:   P1rnd.cpp
 * Author: Abdul-Hakim
 *
 * Created on December 12, 2015, 10:51 AM
 */

#include <cstdlib>
#include"P1rnd.h" 
using namespace std;
//Constructor
P1rnd::P1rnd(const char n, const char* s)
{
     nset = n;
    
    int size = (int)nset; 
    
    set = new char[size];
    for(int i = 0; i<size; i++)
    {
        set[i] = s[i];
    }
    freq = new int[size];
    for(int i = 0; i<size; i++)
    {
        freq[i]=0;
    }
    numRand = 0;
}
P1rnd::~P1rnd(void)
{
    delete [] set;
    delete [] freq;
}

//Returns a random number from the set
char P1rnd::randFromSet(void)
{
    int size = (int)nset; 
    int r = (rand() % size);
    
    freq[r] = freq[r]+1;
    numRand = numRand+1;
    
    return set[r];
}

//Returns the frequency histogram
int *P1rnd::getFreq(void) const
{
    return freq;
}

//Returns the set used
char *P1rnd::getSet(void) const
{
    return set;
}

//Gets the number of times randFromSet has been called
int P1rnd::getNumRand(void) const
{
    return numRand;
}   

