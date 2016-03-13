/* 
 * File:   main.cpp
 * Author: Abdul-Hakim 
 * Created on December 8, 2015, 12:02 PM
 */

//System Libraries
#include <cstdlib>
#include <iostream>
using namespace std;

//User Libraries
#include "Simple_vector.h"

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Instantiate a vector
    int size=5;
    SimpleVector<int> vec(size);
    cout<<"The vector size = "<<vec.size()<<endl;
    cout<<"The vector max size = "<<vec.mSize()<<endl;
    //Fill the vector with values
    for(int i=0;i<size;i++){
        vec[i]=i;
    }
    //Print the result
    for(int i=0;i<size;i++){
        cout<<i<<" = "<<vec[i]<<endl;
    }
    //Add a new element
    vec.push_back(500);
    cout<<"The vector size = "<<vec.size()<<endl;
    cout<<"The vector max size = "<<vec.mSize()<<endl;
    for(int i=0;i<vec.size();i++){
        cout<<i<<" = "<<vec[i]<<endl;
    }
    //Add a new element
    vec.push_back(1000);
    cout<<"The vector size = "<<vec.size()<<endl;
    cout<<"The vector max size = "<<vec.mSize()<<endl;
    for(int i=0;i<vec.size();i++){
        cout<<i<<" = "<<vec[i]<<endl;
    }
    //Delete 3 elements
    vec.pop();
    vec.pop();
    vec.pop();
    cout<<"The vector size = "<<vec.size()<<endl;
    cout<<"The vector max size = "<<vec.mSize()<<endl;
    for(int i=0;i<vec.size();i++){
        cout<<i<<" = "<<vec[i]<<endl;
    }
    //Exit stage right
    return 0;
}


