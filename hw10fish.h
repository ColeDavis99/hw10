#ifndef HW10FISH_H
#define HW10FISH_H

class Sea;
class Fish
{
private:
  short m_foodWorth;
  short m_posX;
  short m_posY;
  bool m_alive;
  static short m_num_fish_alive;


public:
  Fish();

  //
  //Pre:
  //Post:
  bool move(Sea & artic);

  //
  //Pre:
  //Post:
  void setFishPos(const short posX, const short posY);

  //
  //Pre:
  //Post:
  short getFishPosX()const;

  //
  //Pre:
  //Post:
  short getFishPosY()const;

  //
  //Pre:
  //Post:
  void setFishAliveState(const bool p_state);

  //
  //Pre:
  //Post:
  void incrementFishAlive();

};

#endif
