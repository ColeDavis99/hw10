#ifndef HW10PENGUIN_H
#define HW10PENGUIN_H
#include "hw10headder.h"

class Penguin
{
  private:
    short m_energy;
    bool m_alive;
    short m_X;
    short m_Y;


  public:
    Penguin();

    bool move();
};

#endif
