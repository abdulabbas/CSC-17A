/* 
 * File:   main.cpp
 * Author: Abdul Hakim Abbas
 * Purpose: Ch_10_Prob_3
 * Created on September 24, 2015, 11:01 PM
 */

//System Libraries
#include <cstdlib>
#include <iostream>
using namespace std;
//User Libraries
//Global Constants

//Function Prototypes
int wrdCntr(char *, int);

//Execution Starts Here
int main(int argc, char** argv) {
    //Variable Declaration
    int size=51;
    char entry[size];
    
    //Request sentence with a max of 50 characters
    cout<<"Enter a sentence that is no more than 50 characters: \n";
    cin.getline(entry, size);

    //Output results
    cout<<"There are ";
    cout<<wrdCntr(entry, size);
    cout<<" words in your sentence.\n";
   
    
    //Exit Stage Right
    return 0;
}

int wrdCntr(char *array, int size){
    int words=0;   //Set counter to zero;
    for(int count=0; count<size; count++){  //Run through the character array
        if(array[count]==' '){  //If character equals a space then
            words++;   //increment words
        }
    }
    
    words=words+1;
    
    return words;    
}
