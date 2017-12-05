#ifndef HW10PENGUIN_H
#define HW10PENGUIN_H
#include "hw10fish.h"
#include "hw10killerwhale.h"

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

    //Penguin eats a fish
    //Pre: Penguin shares a space in m_seaGrid[][] with a fish
    //Post:Penguin gains health of fish and replaces fish character in seagrid
    bool eat(Sea & Arctic, Fish fishArr[]);

    //Penguin moves towards fish
    //Pre:fish must be within penguin's max vision range
    //Post: Penguin moves towards the fish target and eats if applicable
    bool move(short distToMove, Fish fishArr[], Sea & arctic,
                                        const bool hasTarget);

    //Change value of m_alive
    //pre: none
    //Post:m_alive is set to p_state
    void setPengAliveState(const bool p_state);

    //Change value of m_posX and m_posY
    //Pre: posX and posY must be within PLAYABLE_SPACE
    //Post:Change value of m_posX and m_posY
    void setPengPos(const short posX, const short posY);

    // Returns m_posX
    //pre: none
    // Returns m_posX
    //Post:
    short getPengPosX()const;

    //Returns m_posY
    //pre: none
    //Post:Returns m_posY
    short getPengPosY()const;


    // Returns m_alive
    //Pre: none
    //Post:Returns m_alive
    bool getAliveState()const;


    // Returns bool representing whether or not there is a fish to chase.
    // Also sets the targetX & targetY member vars = to target's x&y
    //Pre: none
    //Post: Returns true if there is a fish in range
    bool pengFoundTarget(const Sea S);

    //Increments penguin class's m_num_pengs_alive
    //Pre: none
    //Post: Increments penguin class's m_num_pengs_alive
    void incrementPengAlive();

    //Decrements penguin class's m_num_pengs_alive
    //Pre: none
    //Post: Decrements penguin class's m_num_pengs_alive
    void decramentPengAlive();

    // Returns penguin class's static variable m_num_pengs_alive
    //Pre: none
    //Post:Returns penguin class's static variable m_num_pengs_alive
    static short getm_num_pengs_alive();

    // Returns short representing number of spaces peng can move
    //Pre: none
    //Post: Returns short representing number of spaces peng can move
    short distToMove();




};

#endif
