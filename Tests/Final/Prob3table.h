/* 
 * File:   Prob3table.h 
 * Author: Abdul-Hakim 
 * Created on December 12, 2015, 11:08 AM 
 */

#ifndef PROB3TABLE_H 
#define	PROB3TABLE_H
#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace std;

template<class T>
class Prob3table 
{
        protected:
		int rows;                                 //Number of rows in the table
		int cols;                                 //Number of cols in the table
		T *rowSum;                                //RowSum array
		T *colSum;                                //ColSum array
		T *table;                                 //Table array
		T grandTotal;                             //Grand total
		void calcTable(void);                     //Calculate all the sums
	public:
		Prob3table(char *,int,int);               //Constructor then Destructor
		~Prob3table(){delete [] table;delete [] rowSum;delete [] colSum;};
		const T *getTable(void){return table;};
		const T *getRowSum(void){return rowSum;};
		const T *getColSum(void){return colSum;};
		T getGrandTotal(void){return grandTotal;};
};

template <class T>
Prob3table<T>::Prob3table(char *file, int r, int c)
{
    rows = r;
    cols = c;
    grandTotal = 0;
    
    int count = 0;
    table = new T[r*c];
    T temp;
    fstream infile(file, ios_base::in);
    while (infile >> temp)
    {
        table[count] = temp;
        count++;
    }
    infile.close();
    
    calcTable();
    
}

template <class T>
void Prob3table<T>::calcTable()
{
    int countSum = 0;
    int countEl = 0;
    rowSum = new T[rows];
    while(countSum < rows)
    {
        rowSum[countSum] = table[countEl+0]+table[countEl+1]+table[countEl+2]+table[countEl+3]+table[countEl+4]+table[countEl+5];
        grandTotal += rowSum[countSum];
        countSum++;
        countEl += cols;
    }
    
    countSum = 0;
    countEl = 0;
    colSum = new T[cols];
    while(countSum < cols)
    {
        colSum[countSum] = table[countEl+0]+table[countEl+6]+table[countEl+12]+table[countEl+18]+table[countEl+24];
        countSum++;
        countEl++;;
    }
}  

#endif	/* PROB3TABLE_H */

