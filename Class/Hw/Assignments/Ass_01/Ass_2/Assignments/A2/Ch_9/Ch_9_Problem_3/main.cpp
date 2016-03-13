/* 
 * File:   main.cpp
 * Author: Abdul Hakim Abbas
 * Purpose: Chap_9_Prob_3 
 * Created on September 24, 2015, 9:32 PM
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;
//User Libraries

//Global constants

//Function Prototypes
float *getScore(int);
void selSort(float *, int);
void prntArr(const float *, int);
void arrAvg(float *, int);

//Execution Begins Here!
int main(int argc, char** argv) {
//Variable Declaration and initialization
    int size;
    float *scores=NULL;
    
    cout<<"How many test score would you like to enter?: ";
    cin>>size;
    cout<<endl;

 
    scores=getScore(size);
    selSort(scores, size);
    cout<<endl;
    cout<<"You entered the following scores: ";
    cout<<endl;
    prntArr(scores, size);
    cout<<endl;
    arrAvg(scores, size);
    
    //Free the memory
    delete [] scores;
    //Exit Stage Right
    return 0;
}

float *getScore(int size){
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
        cout<<"Enter test score ";
        cout<<count+1<<": ";
        cin>>array[count];
        }while(array[count]<0);
    }
        //cout<<endl;
        // cout<<"You entered the following test scores: ";
        // cout<<endl;
        // for(int count=0; count<size; count++){
        //    cout<<array[count];
        //     cout<<endl;
        // }
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
        cout<<"Score "<<count+1<<": ";
        cout<<array[count]<<" ";
        cout<<endl;
    }
}

void arrAvg(float *array, int size){
    float total=0,avg=0;
    for(int count=0; count<size; count++){
        total+=array[count];
    }
    if (size==1){
        cout<<"You cannot average with only one test score.";
        cout<<endl;
    }else
    total-=array[0];
    size-=1;
    avg=total/size;
    cout<<"After dropping your lowest test score your test score average is ";
    cout<<fixed<<showpoint<<setprecision(2)<<avg;
    cout<<endl;
}

