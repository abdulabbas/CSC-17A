/* 
 * File:   Prob2Sort.h 
 * Author: Abdul-Hakim 
 * Created on December 18, 2015, 7:54 PM 
 */

#ifndef PROB2SORT_H
#define	PROB2SORT_H
#include <iostream>

using namespace std;

template<class T>
class Prob2Sort 
{
        private:
                int *index;                                 //Index that is utilized in the sort
        public:
		Prob2Sort(){index=NULL;};                   //Constructor
		~Prob2Sort(){delete []index;};              //Destructor
		//T *sortArray(const T*,int,bool);           //Sorts a single column array
		T *sortArray( T*,int,int,int,bool);   //Sorts a 2 dimensional array represented as a 1 dim array
};
#endif	/* PROB2SORT_H */


template<class T>
T *Prob2Sort<T>::sortArray(T *arr, int r, int c, int col, bool a)
{
    int temp;
    bool ascen = a;
    index = new int[r];
    for(int i = 0; i < r; i++)
    {
        index[i] = arr[(col-1)+(17*i)];
    }

    do{
        ascen = false;
        for(int i = 0; i < r-1; i++)
        {
            if(index[i] < index[i+1])
            {
                ascen = true;
                temp = index[i];
                index[i] = index[i+1];
                index[i+1] = temp;
                for(int j = 0; j < c-1; j++)
                {
                    temp = arr[j+(17*i)];
                    arr[j+(17*i)] = arr[j+(17*(i+1))];
                    arr[j+(17*(i+1))] = temp;
                }
            }
        }
    }while(ascen != false);
    
    return arr;
}
