/* 
 * File:   main.cpp
 * Author: Abdul Hakim Abbas
 * Purpose: Ch_9_Problem_6 
 * Created on September 24, 2015, 10:28 PM
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//Global Constants

//Function Prototypes
float *getDonat(int);
void selSort(float *, int);
void prntArr(const float *, int);

//Execution Starts Here
int main(int argc, char** argv) {
    //Variable Declaration and initialization
    int size;
    float *money=NULL;
    
    cout<<"How many donations would you like to enter?: ";
    cin>>size;
    cout<<endl;

    cout<<"Please enter all donations in whole dollar amounts.";
    cout<<endl;
    money=getDonat(size);
    selSort(money, size);
    cout<<endl;
    
    cout<<"You entered the following donation amounts: ";
    cout<<endl;
    prntArr(money, size);
   
    
    //Free the memory
    delete [] money;
    //Exit Stage Right
    return 0;
}

float *getDonat(int size){
    //Array to hold the numbers
    float *array = NULL; 
    if(size<=0){
        return NULL; //Return a null pointer if num is zero or negative
    }
    
    //Dynamically allocate the array
    array=new float[size];
    //Fill Array with integers entered by user
    
    for(int count=0; count<size; count++){
        do{
        cout<<"Enter donation amount ";
        cout<<count+1<<": $";
        cin>>array[count];
        }while(array[count]<0);
    }
        return array;
}

void selSort(float *array, int size){
    int startScan, minIndex;
    float minElem;
    
    for(startScan=0; startScan<(size-1); startScan++){
        minIndex=startScan;
        minElem=array[startScan];
        for(int index=startScan+1; index<size; index++){
            if(array[index]<minElem){
                minElem=array[index];
                minIndex=index;
            }
        }
        array[minIndex]=array[startScan];
        array[startScan]=minElem;
    }

}

void prntArr(const float *array, int size){
    for(int count=0; count<size; count++){
        cout<<"Donation "<<count+1<<": $";
        cout<<array[count]<<" ";
        cout<<endl;
    }
}


