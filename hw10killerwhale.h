#ifndef HW10KILLERWHALE_H
#define HW10KILLERWHALE_H

class Whale
{
  private:
    //Position in grid
    short m_posX;
    short m_posY;
    
    //Kill tally
    short m_penguinKillCount;

  public:

    //
    //Pre:
    //Post:
    Whale();

    //
    //Pre:
    //Post:
    bool whaleMove();

    //
    //Pre:
    //Post:
    short getPenguinKillCount();

    //
    //Pre:
    //Post:
    void setWhalePos(const short posX, const short posY);

    //
    //Pre:
    //Post:
    short getWhalePosX()const;

    //
    //Pre:
    //Post:
    short getWhalePosY()const;

};

#endif
