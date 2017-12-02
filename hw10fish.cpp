#include "hw10headder.h"
#include "hw10fish.h"
#include "hw10sea.h"
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>


//Constructor
Fish::Fish()
{
  m_alive = false;

  short range = (FOOD_VAL_UPPR - FOOD_VAL_LOWR + 1);

  //Starting position of fish
  m_posX = FISH_START_X;
  m_posY = FISH_START_Y;

  //Sets random food value worth
  m_foodWorth = rand() % range + FOOD_VAL_LOWR;
}



bool Fish::move(const Sea & arctic)
{
  bool moveSuccessful = false;
  short direction;
  short moveToPosY;
  short moveToPosX;
  direction = randomDirection();

  switch (direction)
  {
  case: 0
    moveToPosX = m_posX;
    moveToPosY = m_posY + ADVANCE_FISH_MOVE_BY;

    if (moveToPosY >= MAX_MOVEABLE_BOUNDRY)
    {
      moveToPosY = MAX_MOVEABLE_BOUNDRY;
    }
    if (arctic.getActor(moveToPosX, moveToPosY) == ' ')
    {
      arctic.setActor(m_PosX, m_posY, CLEAR_LAST_POS);
      m_posX = moveToPosX;
      m_posY = moveToPosY;
      moveSuccessful = true;
    }
    break;
  case: 1
    break;
  case 2:
    break;
  case: 3
    break;
  case: 4
    break;
  case 5:
    break;
  case: 6
    break;
  case: 7
    break;
  default:
    break;
  }

  return moveSuccessful;
}


/*============
    GETTERS
============*/
short Fish::getFishPosX()const
{
  return m_posX;
}

short Fish::getFishPosY()const
{
  return m_posY;
}


/*============
    SETTERS
============*/

void Fish::setFishPos(const short posX, const short posY)
{
  m_posX = posX;
  m_posY = posY;
  return;
}


void Fish::setFishAliveState(const bool p_state)
{
  m_alive = p_state;
  return;
}
