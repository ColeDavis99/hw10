#include "hw10headder.h"
#include "hw10fish.h"
#include "hw10sea.h"


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



bool Fish::move(Sea & arctic)
{
  bool moveSuccessful = false;
  short direction;
  short moveToPosY;
  short moveToPosX;
  short lastPosY;
  short lastPosX;

  direction = randomDirection();

  lastPosY = m_posY;
  lastPosX = m_posX;

  switch (direction)
  {
  case 0:
    moveToPosX = m_posX;
    moveToPosY = m_posY + ADVANCE_FISH_MOVE_BY;

    if (moveToPosY >= MAX_MOVABLE_BOUNDARY)
    {
      moveToPosY = MAX_MOVABLE_BOUNDARY;
    }
    if (arctic.getActor(moveToPosX, moveToPosY) == SPACE_EMPTY)
    {
      m_posX = moveToPosX;
      m_posY = moveToPosY;
      arctic.setActor(m_posX, m_posY, FISH_CHAR, lastPosX, lastPosY, SPACE_EMPTY);
      moveSuccessful = true;
    }
    break;
  case 1:
    moveToPosX = m_posX + ADVANCE_FISH_MOVE_BY;
    moveToPosY = m_posY + ADVANCE_FISH_MOVE_BY;

    if (moveToPosY >= MAX_MOVABLE_BOUNDARY)
    {
      moveToPosY = MAX_MOVABLE_BOUNDARY;
    }
    if (moveToPosX >= MAX_MOVABLE_BOUNDARY)
    {
      moveToPosX = MAX_MOVABLE_BOUNDARY;
    }
    if (arctic.getActor(moveToPosX, moveToPosY) == SPACE_EMPTY)
    {
      m_posX = moveToPosX;
      m_posY = moveToPosY;
      arctic.setActor(m_posX, m_posY, FISH_CHAR, lastPosX, lastPosY, SPACE_EMPTY);
      moveSuccessful = true;
    }
    break;
  case 2:
    moveToPosX = m_posX + ADVANCE_FISH_MOVE_BY;
    moveToPosY = m_posY;

    if (moveToPosX >= MAX_MOVABLE_BOUNDARY)
    {
      moveToPosX = MAX_MOVABLE_BOUNDARY;
    }
    if (arctic.getActor(moveToPosX, moveToPosY) == SPACE_EMPTY)
    {
      m_posX = moveToPosX;
      m_posY = moveToPosY;
      arctic.setActor(m_posX, m_posY, FISH_CHAR, lastPosX, lastPosY, SPACE_EMPTY);
      moveSuccessful = true;
    }
    break;
  case 3:
    moveToPosX = m_posX + ADVANCE_FISH_MOVE_BY;
    moveToPosY = m_posY - ADVANCE_FISH_MOVE_BY;

    if (moveToPosY <= MIN_MOVABLE_BOUNDARY)
    {
      moveToPosY = MIN_MOVABLE_BOUNDARY;
    }
    if (moveToPosX >= MAX_MOVABLE_BOUNDARY)
    {
      moveToPosX = MAX_MOVABLE_BOUNDARY;
    }
    if (arctic.getActor(moveToPosX, moveToPosY) == SPACE_EMPTY)
    {
      m_posX = moveToPosX;
      m_posY = moveToPosY;
      arctic.setActor(m_posX, m_posY, FISH_CHAR, lastPosX, lastPosY, SPACE_EMPTY);
      moveSuccessful = true;
    }
    break;
  case 4:
    moveToPosX = m_posX;
    moveToPosY = m_posY - ADVANCE_FISH_MOVE_BY;

    if (moveToPosY <= MIN_MOVABLE_BOUNDARY)
    {
      moveToPosY = MIN_MOVABLE_BOUNDARY;
    }
    if (arctic.getActor(moveToPosX, moveToPosY) == SPACE_EMPTY)
    {
      m_posX = moveToPosX;
      m_posY = moveToPosY;
      arctic.setActor(m_posX, m_posY, FISH_CHAR, lastPosX, lastPosY, SPACE_EMPTY);
      moveSuccessful = true;
    }
    break;
  case 5:
    moveToPosX = m_posX - ADVANCE_FISH_MOVE_BY;
    moveToPosY = m_posY - ADVANCE_FISH_MOVE_BY;

    if (moveToPosY <= MIN_MOVABLE_BOUNDARY)
    {
      moveToPosY = MIN_MOVABLE_BOUNDARY;
    }
    if (moveToPosX <= MIN_MOVABLE_BOUNDARY)
    {
      moveToPosX = MIN_MOVABLE_BOUNDARY;
    }
    if (arctic.getActor(moveToPosX, moveToPosY) == SPACE_EMPTY)
    {
      m_posX = moveToPosX;
      m_posY = moveToPosY;
      arctic.setActor(m_posX, m_posY, FISH_CHAR, lastPosX, lastPosY, SPACE_EMPTY);
      moveSuccessful = true;
    }
    break;
  case 6:
    moveToPosX = m_posX - ADVANCE_FISH_MOVE_BY;
    moveToPosY = m_posY;

    if (moveToPosX <= MIN_MOVABLE_BOUNDARY)
    {
      moveToPosX = MIN_MOVABLE_BOUNDARY;
    }
    if (arctic.getActor(moveToPosX, moveToPosY) == SPACE_EMPTY)
    {
      m_posX = moveToPosX;
      m_posY = moveToPosY;
      arctic.setActor(m_posX, m_posY, FISH_CHAR, lastPosX, lastPosY, SPACE_EMPTY);
      moveSuccessful = true;
    }
    break;
  case 7:
    moveToPosX = m_posX - ADVANCE_FISH_MOVE_BY;
    moveToPosY = m_posY + ADVANCE_FISH_MOVE_BY;

    if (moveToPosY <= MAX_MOVABLE_BOUNDARY)
    {
      moveToPosY = MAX_MOVABLE_BOUNDARY;
    }
    if (moveToPosX <= MIN_MOVABLE_BOUNDARY)
    {
      moveToPosX = MIN_MOVABLE_BOUNDARY;
    }
    if (arctic.getActor(moveToPosX, moveToPosY) == SPACE_EMPTY)
    {
      m_posX = moveToPosX;
      m_posY = moveToPosY;
      arctic.setActor(m_posX, m_posY, FISH_CHAR, lastPosX, lastPosY, SPACE_EMPTY);
      moveSuccessful = true;
    }
    break;
  default:
    cout << "Fish not moving" << endl;
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
