#ifndef HW10SEA_H
#define HW10SEA_H
#include "hw10headder.h"
#include "hw10fish.h"
#include "hw10penguin.h"
#include "hw10killerwhale.h" //TEST COMMENT


class Sea
{
  private:
    char m_seaGrid[SEA_MAX][SEA_MAX];//Holds characters representing actors
    short m_seaSpace; //Represents area of seaGrid[][] that is actually used

  public:
    //Constructor (definition in hw10sea.cpp)
    Sea(Penguin penguinArr[],
        Fish fishArr[],
        Whale whaleArr[],
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
                  Fish fishArr[],
                  Whale whaleArr[]);

    // Adds Representative character to m_seaGrid[][] at correct X&Y coord
    // Pre: Passed Object's X&Y coordinates are valid
    // Post: m_seaGrid[][] is updated with proper character.
    template <typename T>
    void addToGrid(T actor);

    //
    //Pre:
    //Post:
    friend ostream & operator <<(ostream &os, const Sea &sea);

    //
    //Pre:
    //Post:
    char getActor(const short posX, const short posY)const;

    //
    //Pre:
    //Post:
    void setActor(const short newPosX, const short newPosY, char newActor, short lastPosX, short lastPosY, char clearActor);
};

#endif
