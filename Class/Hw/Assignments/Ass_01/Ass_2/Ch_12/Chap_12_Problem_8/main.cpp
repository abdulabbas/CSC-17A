/* 
 * File:   main.cpp
 * Author: Abdul-Hakim
 *
 * Created on September 25, 2015, 1:18 AM
 */
//System Libraries
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;
//User Libraries

//Global Constants

//Function Prototypes
//With Pointer
void arrayToFile2(fstream &, int [], int);
void fileToArray2(fstream &, int [], int);


//Execution Starts Here
int main(int argc, char** argv) {
    //Variable Declaration
    srand(static_cast<unsigned int>(time(0)));
    const int size=10;
    int array[size]={1,2,3,4,5,6,7,8,9,10};
    fstream file;
    int *ptr=NULL;
    ptr=array;
    
    arrayToFile2(file, ptr, size);
    fileToArray2(file, ptr, size);
   
    //Exit Stage Right
    return 0;
}

//Functions are done here 

//With Pointers

void arrayToFile2(fstream &file, int *array, int size){
    
    file.open("file.dat", ios::out | ios::binary);
    //cout<<"Writing data to the file...";
    file.write(reinterpret_cast<char *>(array), sizeof(array));
    cout<<endl;
    file.close();
}

void fileToArray2(fstream &file, int *array, int size){
    file.open("file.dat", ios::in | ios::binary);
    file.read(reinterpret_cast<char *>(array), sizeof(array));
    cout<<"The following data was read by the program."<<endl;
    for(int count=0; count<size; count++){
        cout<<array[count]<<" ";
    }
    cout<<endl;
  //Close file
    file.close();
}
