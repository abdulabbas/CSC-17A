/* 
 * File:   main.cpp
 * Author: Abdul Hakim Abbas
 * Purpose: Homework for Array using the Mod operator_Problem_#'s_8 & 9 
 * Created on September 18, 2015, 9:43 AM
 */

//System libraries
#include <cstdlib>
#include <iostream>
#include <iomanip>
using namespace std;
//User Libraries

//Global Constant

//Function prototypes
float mean(int[], int);
float median(int[], int);
int *mode(int[], int);
void sort(int[], int);

//System Begins Here
int main(int argc, char** argv) {
    cout<<fixed<<showpoint<<setprecision(2);
    //Declare Variables
    
    int num;
    int *array;
    float avg;
    float med;
    int *mod;
    //input
    cout<<"Input the num of the array :";
    cin>>num;
    array = new int[num];
    cout<<"Input the numbers with space\n";
    for(int i=0;i<num;i++){
        cin>>array[i];
    }
    
    //sorting
    sort(array, num);
    
    //find mena median mode
    avg=mean(array, num);
    med=median(array, num);
    mod=mode(array, num);
    //output
    cout<<"avgerage = "<<avg<<endl;
    cout<<"median = "<<med<<endl;
    cout<<"mode array = {";
    for(int i=0; i<mod[0]+2;i++){
        cout<<" "<<*(mod+i);
    }
    cout<<" }\n";
    delete []array;
    delete mod;
    return 0;
}
void sort(int array[], int num){
    bool swap;
    do{
        int temp;
        swap=false;
        for(int i=0; i<num-1; i++){
            if(array[i]>array[i+1]){
                temp= array[i];
                array[i]=array[i+1];
                array[i+1]=temp;
                swap=true;
            }
        }
    }while(swap==true);
    for(int i=0;i<num;i++){
        cout<<array[i]<<endl;
    }
}
float mean(int array[], int num){
    float ttl=0;
    for(int i=0;i<num;i++){
        ttl+=array[i];
    }
    return ttl/num;
}
float median(int array[], int num){
    float mid=(static_cast<float>(num)+1)/2-1;
    cout<<"middle"<<mid<<endl;
    int imid=mid;
    if(mid==imid){
        return static_cast<float>(array[imid]);
    }
    else{
        float a=static_cast<float>(array[imid]);
        float b=static_cast<float>(array[imid+1]);
        return (a+b)/2;
    }
    
}
int *mode(int array[], int num){
    int nom;
    int *md;
    int inum=array[0];
    int mode;
    int cntmod=0;
    int count1=1, count2=0;
    
    
    for(int i=0; i<num-1;i++){
        if(array[i]==array[i+1]){
            count1++;
//            cout<<"i = "<<i<<endl;
//            cout<<"count = "<<count1<<endl;
//            cout<<"cntmod = "<<cntmod<<endl;
        }
        else if(count1>cntmod) {
//            cout<<"else if\n";
            cntmod = count1; // mode is the biggest ocurrences
            count1 = 1; // reset count for the new number
        }
        if(i==num-1 && count1>cntmod){
            cntmod = count1; // mode is the biggest ocurrences
        }
    }
    for(int i=0; i<num-1;i++){
        if(array[i]==array[i+1]){
            count1++;
            cout<<"i = "<<i<<endl;
            cout<<"count = "<<count1<<endl;
            cout<<"cntmod = "<<cntmod<<endl;
        }
        else if(count1==cntmod) {
            cout<<"else if\n";
            count2++;
        }
        if(i==num-1 && count1==cntmod){
            count2++;
        }
    }
    cout<<"count2(nom) = "<<count2<<endl;
    nom=count2;
    md = new int[nom+2];
    md[1]=cntmod;
    md[0]=nom;
    cout<<"nom"<<nom<<endl;
    count2=0;
    count1=1;
    
    for(int i=0;i<num-1;i++){
        if(array[i]==array[i+1]){
            count1++;
        }
        else if(count1==cntmod){
            md[count2+2]=array[i];
            count2++;
            count1=1;
        }
        if(count1==cntmod && i==num-1){
            md[count2+2]=array[i];
            count2++;
            count1=1;
        }
        
    }
    cout<<md[0]<<" "<<md[1]<<endl;
    
    return md;
}


