#ifndef HW10FISH_H
#define HW10FISH_H
#include "hw10killerwhale.h"

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

  //Allows the fish to move inside the sea grid
  //Pre: none
  //Post: The calling objects location variables will have been changed
  bool move(Sea & artic);

  //Updates fish's x&y member variables
  //Pre: x&y must be within PLAYABLE_SPACE
  //Post:Updates fish's x&y member variables are updated
  void setFishPos(const short posX, const short posY);

  //Sets the m_foodWorth variable
  //Pre: none
  //Post: m_foodWorth is equal to foodworth
  void setm_foodworth(const short foodworth);

  //Adds fish into Sea.m_seaGrid[][]
  //Pre: none
  //Post: Adds fish to seagrid
  void reincarnateFish(Sea & S, Fish fishArr[]);

  //Returns fish's m_posX member variable
  //Pre: Fish must exist
  //Post: Returns fish's m_posX member variable
  short getFishPosX()const;

  //Returns fish's m_posY member variable
  //Pre: none
  //Post: Returns fish's m_posY member variable
  short getFishPosY()const;

  //Sets fish's m_alive variable to p_state
  //Pre: none
  //Post: fish's m_alive is set to p_state
  void setFishAliveState(const bool p_state);

  //Increases Fish class's static m_num_fish_alive variable by 1
  //Pre: none
  //Post: Fish class's static m_num_fish_alive variable increased by 1
  void incrementFishAlive();

  //Decreases Fish class's static m_num_fish_alive variable by 1
  //Pre: none
  //Post: Fish class's static m_num_fish_alive variable decreased by 1
  void decramentFishAlive();

  //Returns fish object's m_num_fish_alive variable
  //Pre: none
  //Post: REturns fish object's m_num_fish_alive variable
  static short getm_num_fish_alive() { return m_num_fish_alive; }

  // returns m_foodWorth
  //Pre: none
  //Post: returns m_foodWorth
  short getFoodWorth()const { return m_foodWorth; }

};

#endif
