/* 
 * File:   SearchableVector.h
 * Author: Abdul-Hakim
 *
 * Created on September 28, 2015, 9:59 AM
 */

#ifndef SEARCHABLEVECTOR_H
#define	SEARCHABLEVECTOR_H

#include "SimpleVector.h"

template <class T>
class SearchableVector : public SimpleVector<T>
{
public:
   // Default constructor
   SearchableVector() : SimpleVector<T>()
      {}
   
   // Constructor
   SearchableVector(int size) : SimpleVector<T>(size)
      { }
   
   // Copy constructor
   SearchableVector(const SearchableVector &);

   // Accessor to find an item
   int findItem(const T);
};

// Copy constructor                                     
template <class T>
SearchableVector<T>::SearchableVector(const SearchableVector &obj) :
                     SimpleVector<T>(obj.size())
{
   for(int count = 0; count < this->size(); count++)
      this->operator[](count) = obj[count];
}


// findItem function                                    
template <class T>
int SearchableVector<T>::findItem(const T item)
{
    /*
   for (int count = 0; count <= this->size(); count++)
   {
      if (this->getElementAt(count) == item)
         return count;
   }
   return -1;
   */
   
    int first = 0;
    int	last = this->size() - 1;
    int	middle;
    int	position = -1;
    bool found = false;

    while (!found && first <= last)
    {
	middle = (first + last) / 2;
        if (this->getElementAt(middle) == item)
	{
            found = true;
            position = middle;
	}
        else if (this->getElementAt(middle) > item)
            last = middle - 1;
        else
	    first = middle + 1;
    }
    
    return position;
}

#endif	/* SEARCHABLEVECTOR_H */

