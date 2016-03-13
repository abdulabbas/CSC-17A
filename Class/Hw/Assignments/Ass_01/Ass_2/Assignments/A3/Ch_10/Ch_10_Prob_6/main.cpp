/* 
 * File:   main.cpp
 * Author: Abdul Hakim Abbas
 * Purpose: Ch_10_Prob_6 
 * Created on September 25, 2015, 12:16 AM
 */
//System Libraries
#include <cstdlib>
#include <iostream>
#include <iomanip>
using namespace std;
//User Libraries

//Global Constants

//Function Prototypes
int vowels(char *, int);
int conso(char *, int);
char *getStr(int);
int getN();
void Menu();
void def(int);


//Execution Starts Here
int main(int argc, char** argv) {
    //Variable Declaration
    int size=51;
    char *array=NULL;
    int inN;
    
    do{
      array=getStr(size);
      
        do{ 
            Menu();
            inN=getN();
            switch(inN){
                case 1:{
                    //Output number of vowels results
                    cout<<"There are ";
                    cout<<vowels(array, size);
                    cout<<" vowels in your string.\n";
                    break;
                }
                case 2: {   
                    //Output number of consonants results
                    cout<<"There are ";
                    cout<<conso(array, size);
                    cout<<" consonants in your string.\n";
                    break;
                }
                case 3: {   

                    //Output number of vowels results
                    cout<<"There are ";
                    cout<<vowels(array, size);
                    cout<<" vowels in your string.\n";

                    //Output number of consonants results
                    cout<<"There are ";
                    cout<<conso(array, size);
                    cout<<" consonants in your string.\n";
                    break;
                }
                case 4:{    
                   array=getStr(size); 
                    
                   break;
                }
                case 5:{
                    def(inN);
                   break;
                }
            }
        }while(inN>=1&&inN<=3); 

}while(inN==4);
    
     delete [] array;
    //Exit Stage Right
    return 0;

}

void def(int inN){
    char ch;
    if(inN==1){
       ch='A'; 
    }else if(inN==2){
        ch='B';
    }else if(inN==3){
        ch='C';
    }else if(inN==4){
        ch='D';
    }else if(inN==5){
        ch='E';
    }    
    cout<<"You typed "<<ch<<" to exit the program"<<endl;
}

void Menu(){
    cout<<endl;
    cout<<"What would you like to do?"<<endl;
    cout<<"Type A to count the number of vowels in your string."<<endl;
    cout<<"Type B to count the number of consonants in your string."<<endl;
    cout<<"Type C to count the number of both vowels and consonants in your string."<<endl;
    cout<<"Type D to type a new string."<<endl;
    cout<<"Type E to exit the program."<<endl;
}
int getN(){
        char inCh;
        int inN;
        cout<<"Selection: ";
        cin>>inCh;
        
        if(inCh=='a' || inCh=='A'){
            inN=1;
        }else if(inCh=='b' || inCh=='B'){
            inN=2;
        }else if(inCh=='c' || inCh=='C'){
            inN=3;
        }else if(inCh=='d' || inCh=='D'){
            inN=4;
        }else if(inCh=='e' || inCh=='E'){
            inN=5;
        }
        
        return inN;
}


char *getStr(int size){
    char *array=NULL;
    
    array=new char[size];
    
    //Request sentence with a max of 50 characters
    cout<<"Enter a sentence that is no more than 50 characters: \n";
    cin.getline(array, size);
    //cout<<"\n";
 
    return array;
}

int vowels(char *array, int size){
    int vowels=0;
    int count=0;
    
    while (array[count] != '\0'){ //Runs through the array stopping and terminator
        count++; //while not terminator increment count
        
        static_cast<int>(array[count]);
        
        if(array[count]==65 || array[count]==97){
            vowels++;
        }else if(array[count]==69 || array[count]==101){
            vowels++;
        }else if(array[count]==73 || array[count]==105){
            vowels++;
        }else if(array[count]==79 || array[count]==111){
            vowels++;
        }else if(array[count]==85 || array[count]==117){
            vowels++;
        }
        
    }
    return vowels;  
}

int conso(char *array, int size){
    int conso=0;
    int count=0;
    
    while (array[count] != '\0'){ //Runs through the array stopping and terminator
        count++; //while not terminator increment count
        
        static_cast<int>(array[count]);
        
        conso++; // Increment consonant count first
        
        //Subtract from consonant count if the following are found.
        if(array[count]==65 || array[count]==97){
            conso--;
        }else if(array[count]==69 || array[count]==101){
            conso--;
        }else if(array[count]==73 || array[count]==105){
            conso--;
        }else if(array[count]==79 || array[count]==111){
            conso--;
        }else if(array[count]==85 || array[count]==117){
            conso--;
        }else if (array[count]>=32 && array[count]<=64){
            conso--;
        }else if (array[count]>=91 && array[count]<=96){
            conso--;
        }else if (array[count]>=123 && array[count]<=126){
            conso--;
        }
            
        
    }
    return conso;  
}

