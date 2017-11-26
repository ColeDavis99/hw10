#ifndef HW10SEA_H
#define HW10SEA_H
#include "hw10headder.h"


class Sea
{
  private:
    char m_seaGrid[SEA_MAX][SEA_MAX];//Holds characters representing actors
    short m_seaSpace; //Represents area of seaGrid[][] that is actually used

  public:
    //Constructor (definition in hw10sea.cpp)
    Sea(const short seaspace = SEA_MAX);

    //Sets all elements of seaGrid[][] to space character
    //Pre: Sea object must be instanciated
    //Post: m_seaGrid[][] contains no junk data
    void clear();

    // Adds characters into m_seaGrid[][] representing actors
    //Pre: Actor objects & sea objects must be instanciated
    //Post: m_seaGrid[][] is populated with chars representing actors
    void populate();



    friend ostream & operator <<(ostream &os, const Sea &sea);
};

#endif
