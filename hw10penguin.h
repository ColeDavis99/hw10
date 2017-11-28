#ifndef HW10PENGUIN_H
#define HW10PENGUIN_H
#include "hw10headder.h"

class Penguin
{
  private:
    short m_energy;
    bool m_alive;
    short m_posX;
    short m_posY;


  public:
    Penguin();

    //
    //Pre:
    //Post: Returns can_move. If true, call addToGrid(). Else, return false.
    bool move();

    //
    //pre:
    //Post:
    void setPengAliveState(const bool p_state);

    //
    //Pre:
    //Post:
    void setPengPos(const short posX, const short posY);

    //
    //pre:
    //Post:
    short getPengPosX()const;

    //
    //pre:
    //Post:
    short getPengPosY()const;


    //
    //Pre:
    //Post:
    bool getAliveState()const;
};

#endif
