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

    Whale();
    bool whaleMove();
    short getPenguinKillCount();

};

#endif
