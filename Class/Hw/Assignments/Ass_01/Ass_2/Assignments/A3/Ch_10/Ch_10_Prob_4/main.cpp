/* 
 * File:   main.cpp
 * Author: Abdul Hakim Abbas
 * Purpose: Problem_4_Ch_10 
 * Created on September 25, 2015, 12:04 AM
 */
//System Libraries
#include <cstdlib>
#include <iostream>
#include <iomanip>
using namespace std;
//User Libraries

//Global Constants

//Function Prototypes
int wrdCntr(char *, int);
int totLttr(char *, int);

//Execution Starts Here
int main(int argc, char** argv) {
    //Variable Declaration
    int size=51;
    char entry[size];
    float letters, words, average=0;
    

    
    //Request sentence with a max of 50 characters
    cout<<"Enter a sentence that is no more than 50 characters: \n";
    cin.getline(entry, size);
    cout<<"\n";
    
    //Output word results
    cout<<"There are ";
    cout<<wrdCntr(entry, size);
    cout<<" words in your sentence.\n";
    cout<<"\n";
    
    
    
    //Output letter results
    cout<<"There are ";
    cout<<totLttr(entry, size);
    cout<<" letters in your sentence.\n";
    
    
    words=wrdCntr(entry, size);
    letters=totLttr(entry, size);
    average=letters/words;
    
    
    cout<<"\nThe average number of letters per word in your sentence is: ";
    cout<<setprecision(1)<<fixed<<showpoint;
    cout<<average;
    cout<<"\n";
    
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
    
    return words;    
}

int totLttr(char *array, int size){
    int letters=0;
    int count=0;
    
    while (array[count] != '\0'){ //Runs through the array stopping and terminator
        count++; //while not terminator increment count
        letters++; //and increment letter count
    
        if (array[count]==' ' ){  //Excludes spaces
            letters--;
        }else if (array[count]=='?'){ //Excludes question mark
            letters--;
        }else if (array[count]=='!'){ //Excludes exclamation mark
            letters--;
        }else if (array[count]=='.'){ // Excludes period
            letters--;
        }
    }
    return letters;  
}

