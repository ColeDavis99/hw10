#ifndef HW10SEA_H
#define HW10SEA_H
#include "hw10headder.h"
#include "hw10fish.h"
#include "hw10penguin.h"


class Sea
{
  private:
    char m_seaGrid[SEA_MAX][SEA_MAX];//Holds characters representing actors
    short m_seaSpace; //Represents area of seaGrid[][] that is actually used

  public:
    //Constructor (definition in hw10sea.cpp)
    Sea(Penguin penguinArr[],
        Fish fishArr[],
        const short seaspace = SEA_MAX);


    //Sets all elements of seaGrid[][] to 'x' character
    //Pre: Sea object must be instanciated
    //Post: m_seaGrid[][] contains all 'x'
    void drawBorder();


    //Sets all indeces of m_seaGrid[][] except borders == ' '
    //Pre: Sea object must be instanciated
    //Post: m_seaGrid[][] contains no junk data
    void clear();


    // Adds characters into m_seaGrid[][] representing actors
    //Pre: Actor objects & sea objects must be instanciated
    //Post: m_seaGrid[][] is populated with chars representing actors
    void populate(Penguin penguinArr[],
                  Fish fishArr[]);

    // Adds Representative character to m_seaGrid[][] at correct X&Y coord
    // Pre: Passed Object's X&Y coordinates are valid
    // Post: m_seaGrid[][] is updated with proper character.
    template <typename T>
    void addToGrid(T actor);

    friend ostream & operator <<(ostream &os, const Sea &sea);
};

#endif
