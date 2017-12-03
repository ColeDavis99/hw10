#ifndef HW10PENGUIN_H
#define HW10PENGUIN_H
#include "hw10fish.h"

class Sea;
class Penguin
{
  private:
    short m_energy;
    bool m_alive;
    short m_posX;
    short m_posY;
    short m_targetX;
    short m_targetY;
    static short m_num_pengs_alive;


  public:
    Penguin();

    //
    //Pre:
    //Post: Returns
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


    // Returns bool representing whether or not there is a fish to chase.
    // Also sets the targetX & targetY member vars = to target's x&y
    //Pre:
    //Post:
    bool pengFoundTarget(const Sea S);

    //
    //Pre:
    //Post:
    static short getm_num_pengs_alive(){return m_num_pengs_alive;}

    //
    //Pre:
    //Post:
    void incrementPengAlive();


};

#endif
