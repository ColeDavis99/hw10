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

    //
    //Pre:
    //Post:
    Whale();

    //
    //Pre:
    //Post:
    short getPenguinKillCount();

    bool eat(Sea & Arctic, Fish fishArr[], Penguin pengArr[]);

    //
    //Pre:
    //Post:
    bool move(short distToMove, Fish fishArr[], Penguin pengArr[], Sea & arctic, const bool hasTarget);

    //
    //pre:
    //Post:
    void setWhaleAliveState(const bool p_state);



    //
    //Pre:
    //Post:
    void setWhalePos(const short posX, const short posY);

    //
    //pre:
    //Post:
    short getWhalePosX()const;

    //
    //pre:
    //Post:
    short getWhalePosY()const;


    //
    //Pre:
    //Post:
    bool getAliveState()const;


    // Returns bool representing whether or not there is a fish to chase.
    // Also sets the targetX & targetY member vars = to target's x&y
    //Pre:
    //Post:
    bool whaleFoundTarget(const Sea & S);


    ////
    ////Pre:
    ////Post:
    //void incrementWhaleAlive();

  

    //
    //Pre:
    //Post:
    short distToMove();
};

#endif
