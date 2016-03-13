/* 
 * File:   P3table.h 
 * Author: Abdul-Hakim 
 * Created on December 11, 2015, 9:35 PM 
 */

#ifndef P3TABLE_H 
#define	P3TABLE_H
#include <cstdlib>
#include <iostream>
#include <fstream>
#include "Prob3table.h"
using namespace std;
template<class T>
class P3table:public Prob3table<T>
{
        protected:
		T *augTable;                                  //Augmented Table with sums
	public:
		P3table(char *,int,int);          //Constructor
		~P3table(){delete [] augTable;};  //Destructor
		const T *getAugTable(void){return augTable;}; 
};

template <class T>
P3table<T>::P3table(char *file, int r, int c) : Prob3table<T>(file, r, c)
{
    const T *tempTable = this->getTable();
    const T *tempRowSum = this->getRowSum();
    const T *tempColSum = this->getColSum();
    T tempTotal = this->getGrandTotal(); 
    int rowCount = c;
 
    augTable = new T[(r+1)*(c+1)];
    for(int i = 0; i < r; i++)
    {
	for(int j = 0;j < c; j++)
	{
            augTable[i*(c+1)+j] = tempTable[i*c+j];
	}
	augTable[rowCount+i] = tempRowSum[i];
        rowCount += c;
    }
    for(int i = 0; i < c; i++)
    {
        augTable[35+i] = tempColSum[i];
    }
    augTable[41] = tempTotal;
}


#endif	/* P3TABLE_H */
//This is for Problem 3 
//Which is the Inherited Table Question
