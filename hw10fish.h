#ifndef HW10FISH_H
#define HW10FISH_H
#include "hw10headder.h"

class fish
{
private:
  short m_foodWorth;
  short m_posX;
  short m_posY;
  bool m_isAlive;

public:
  fish();

  bool move();


};

#endif
