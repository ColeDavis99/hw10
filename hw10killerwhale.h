#ifndef HW10KILLERWHALE_H
#define HW10KILLERWHALE_H

class Penguin;
class Fish;
class Sea;
class Whale
{
  private:
    bool m_alive;
    short m_energy;
    short m_posX;
    short m_posY;
    short m_targetX;
    short m_targetY;
    static short m_num_whale_alive;

    //Kill tally
    short m_penguinKilledCount;

  public:

    //Creates Whale Object
    //Pre: none
    //Post: Whale Object is Created
    Whale();

    //Returns m_penguinKilledCount
    //Pre: none
    //Post:Returns m_penguinKilledCount
    short getPenguinKillCount();

    //Eat the penguin
    //Pre: none
    //Post:Penguin is removed from m_seaGrid[][] and set to dead.
    bool eat(Sea & Arctic, Fish fishArr[], Penguin pengArr[]);

    //Move the killer whale towards penguin and call eat()
    //Pre: none
    //Post: killer whale moves towards penguin
    bool move(short distToMove, Fish fishArr[], Penguin pengArr[],
              Sea & arctic, const bool hasTarget);

    //Sets whale's m_posX and m_posY variable
    //Pre: none
    //Post:Sets whale's m_posX and m_posY variable
    void setWhalePos(const short posX, const short posY);

    //Returns whale's m_posX variable
    //pre: none
    //Post:Returns whale's m_posX variable
    short getWhalePosX()const;

    //Returns whale's m_posY variable
    //pre: none
    //Post:Returns whale's m_posY variable
    short getWhalePosY()const;

    // Sets the targetX & targetY member vars = to target's x&y
    //Pre: none
    //Post:Sets the targetX & targetY member vars = to target's x&y
    bool whaleFoundTarget(const Sea & S);


    //
    //Pre:
    //Post:
    short distToMove();
};

#endif
