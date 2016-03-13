/* 
 * File:   main.cpp
 * Author: Abdul Hakim Abbas
 * Purpose: Ch_9_Problem_1 
 * Created on September 24, 2015, 9:02 PM
 */
//System Libraries
#include <cstdlib>
#include <iostream>
using namespace std;
//User Libraries

//Global Constants

//Function Prototypes
int *getNum();

//Execution Starts Here
int main(int argc, char** argv) {
//Variable Declaration
    int *numbers=NULL;
    
    //Function call
    numbers=getNum();
    
    //Free the memory
    delete [] numbers;
    numbers=0;
    //Exit Stage Right
    return 0;
}

int *getNum(){
   
    int *array = NULL; //Array to hold the numbers
    int size;
    
    cout<<"Enter the size of the array: ";
    cin>>size;
    cout<<endl;
    cout<<"Your array will be filled with ";
    cout<<size;
    cout<<" integers.";
    cout<<endl<<endl;
    
    if(size<=0){
        return NULL; //Return a null pointer if num is zero or negative
    }
    
    array=new int[size]; //Dynamically allocate the array
    
    //Fill Array with integers entered by user
    for(int count=0; count<size; count++){
        cout<<"Enter an integer number: ";
        cin>>array[count];
    }
     
        cout<<endl;
        cout<<"Your array is filled with the following integers: ";
        cout<<endl;
        for(int count=0; count<size; count++){
            cout<<array[count];
            cout<<endl;
        }
    
    //Return a pointer to the array
    return array;
    
}


