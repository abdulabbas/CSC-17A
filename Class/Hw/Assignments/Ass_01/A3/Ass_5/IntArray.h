/* 
 * File:   IntArray.h
 * Author: Abdul-Hakim
 *
 * Created on September 28, 2015, 9:58 AM
 */


#ifndef INTARRAY_H
#define	INTARRAY_H

class IntArray 
{
    private:
        int *aptr;                     // Pointer to the array
        int arraySize;                 // Holds the array size
    public:
        IntArray(int);                 // Constructor
        IntArray(const IntArray &);    // Copy constructor
        ~IntArray();                   // Destructor
   
        class subscriptError{};        // Exception
        
        int size() const               // Returns the array size
        { return arraySize; }

        int &operator[](const int &);  // Overloaded [] operator
};

#endif	/* INTARRAY_H */

