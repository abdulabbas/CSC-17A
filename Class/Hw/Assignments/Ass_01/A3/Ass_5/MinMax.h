/* 
 * File:   MinMax.h
 * Author: Abdul-Hakim
 *
 * Created on September 28, 2015, 10:18 AM
 */


#ifndef MINMAX_H
#define	MINMAX_H

template <class T>
class MinMax 
{
    private:
        T argument1;   //Argument 1 to compare with argument 2
        T argument2;   //Argument 2 to compare with argument 1
    public:
        //Constructors
        MinMax(){ argument1 = 0; argument2 =0;}
        MinMax(T a, T b){argument1 = a; argument2 = b;}
        
        //Mutators
        T minimum();
        T maximum();
};

//Function template
template <class T>
T MinMax<T>::minimum()
{
    T temp;
    
    if(argument1 < argument2)
        temp = argument1;
    else
        temp = argument2;
    
    return temp;
}       

//Function template
template <class T>
T MinMax<T>::maximum()
{
    T temp;
    
    if(argument1 > argument2)
        temp = argument1;
    else
        temp = argument2;
    
        return temp;
}

#endif	/* MINMAX_H */

