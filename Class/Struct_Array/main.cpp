/* 
 * File:   main.cpp
 * Author: Abdul-Hakim
 * Purpose: Self Contained Array
 * Created on October 1, 2015, 12:11 PM
 */
//System Libraries
#include <cstdlib>
//User Libraries
#include "Array.h"
using namespace std;
//Global constructs
//Function Prototypes
Array *fillAry(int);
void prntAry(Array *);

int main(int argc, char** argv) {
    //set the random number seed and size
    srand(static_cast<unsigned int>(time(0)));
    
    
    
    return 0;
}

Array *fillAry(int n){
    //check n
    if (n<=1)n=2;
    //allocate memory
    Array *a=new Array;
    a -> size=n;
    a -> data=new int[a -> size];
    //loop to fill the array
    for(int indx=0;indx<a->size;indx++){
        
    }
        
}

