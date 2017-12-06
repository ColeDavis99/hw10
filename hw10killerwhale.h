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

  //Eat the penguin
  //Pre: none
  //Post:Penguin is removed from m_seaGrid[][] and set to dead.
  bool eat(Sea & Arctic, Penguin pengArr[]);

  // Sets the targetX & targetY member vars = to target's x&y
  //Pre: none
  //Post:Sets the targetX & targetY member vars = to target's x&y
  bool whaleFindTarget(const Sea & S);

public:

  //Creates Whale Object
  //Pre: none
  //Post: Whale Object is Created
  Whale();

  //Returns m_penguinKilledCount
  //Pre: none
  //Post:Returns m_penguinKilledCount
  short getPenguinKillCount()const;

  //Move the killer whale towards penguin and call eat()
  //Pre: none
  //Post: killer whale moves towards penguin
  bool move(Penguin pengArr[], Sea & arctic);

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

};

#endif
