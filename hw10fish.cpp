#include "hw10headder.h"
#include "hw10fish.h"
#include "hw10sea.h"


short Fish::m_num_fish_alive = 0;    //Represent number of fish in grid

/*==================
    CONSTRUCTOR
==================*/
Fish::Fish()
{
  m_alive = false;
  //Starting position of fish
  m_posX = FISH_START_X;
  m_posY = FISH_START_Y;

  //Sets random food value worth
  m_foodWorth = randomNumberGen(FOOD_VAL_UPPR, FOOD_VAL_LOWR);
}



bool Fish::move(Sea & arctic)
{
  bool moveSuccessful = false;
  short direction;
  short moveToPosY;
  short moveToPosX;
  short lastPosY;
  short lastPosX;

  direction = randomNumberGen(RAND_DIR_UPPR, RAND_DIR_LOWR);

  lastPosY = m_posY;
  lastPosX = m_posX;

  switch (direction)
  {
  case 0:
    moveToPosX = m_posX;
    moveToPosY = m_posY + ADVANCE_ACTOR_MOVE;

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
    moveToPosX = m_posX + ADVANCE_ACTOR_MOVE;
    moveToPosY = m_posY + ADVANCE_ACTOR_MOVE;

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
    moveToPosX = m_posX + ADVANCE_ACTOR_MOVE;
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
    moveToPosX = m_posX + ADVANCE_ACTOR_MOVE;
    moveToPosY = m_posY - ADVANCE_ACTOR_MOVE;

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
    moveToPosY = m_posY - ADVANCE_ACTOR_MOVE;

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
    moveToPosX = m_posX - ADVANCE_ACTOR_MOVE;
    moveToPosY = m_posY - ADVANCE_ACTOR_MOVE;

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
    moveToPosX = m_posX - ADVANCE_ACTOR_MOVE;
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
    moveToPosX = m_posX - ADVANCE_ACTOR_MOVE;
    moveToPosY = m_posY + ADVANCE_ACTOR_MOVE;

    if (moveToPosY >= MAX_MOVABLE_BOUNDARY)
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
    //cout << "Fish not moving" << endl;
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


void Fish::incrementFishAlive()
{
  m_num_fish_alive++;
  cout<<"NUMBER OF FISH ALIVE: ";
  cout<<m_num_fish_alive<<endl;
  return;
}

void Fish::decramentFishAlive()
{
  m_num_fish_alive--;
  return;
}


short Fish::getm_num_fish_alive()
{
  return m_num_fish_alive;
}


