#ifndef HW10FISH_H
#define HW10FISH_H
#include "hw10headder.h"

class Fish
{
private:
  short m_foodWorth;
  short m_posX;
  short m_posY;
  bool m_isAlive;

public:
  Fish();

  bool move();

  //
  //Pre:
  //Post:
  void setFishPos(const short posX, const short posY);


};

#endif
