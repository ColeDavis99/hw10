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

    //
    //Pre:
    //Post: Returns can_move. If true, call addToGrid(). Else, return false.
    bool move();

    //
    //pre:
    //Post:
    void setAliveState(const bool p_state);

    //
    //Pre:
    //Post:
    bool getAliveState()const;
};

#endif
