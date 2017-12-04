#include "hw10headder.h"
#include "hw10penguin.h"
#include "hw10sea.h"

short Penguin::m_num_pengs_alive = 0;//Represent number of pengs in grid


/*==================
    CONSTRUCTOR
==================*/
Penguin::Penguin()
{
  //Calculate starting energy level;
  m_energy = randomNumberGen(PENG_HEALTH_MAX, PENG_HEALTH_MIN);


  //Penguins spawn "dead" (Instructions said to)
  m_alive = false;

  //Set starting X and Y values
  m_posX = PENG_START_X;
  m_posY = PENG_START_Y;

}

bool Penguin::eat(Sea & Arctic, Fish fishArr[])
{
  bool fishInArrFound = false;
  short counter = 0;
  short fishAlive;
  short fishPosX;
  short fishPosY;

  if (Arctic.getActor(m_posX, m_posY) == FISH_CHAR)
  {
    while (fishInArrFound == false)
    {
      fishPosX = fishArr[counter].getFishPosX();
      fishPosY = fishArr[counter].getFishPosY();
      if (m_posX == fishPosX && m_posY == fishPosY)
      {
        m_energy = fishArr[counter].getFoodWorth();
        fishArr[counter].decramentFishAlive();
        fishAlive = fishArr[counter].getm_num_fish_alive();
        swap(fishArr[counter], fishArr[fishAlive]);
        fishInArrFound = true;
      }
      counter++;
    }
  }
  return fishInArrFound;
}

/*==================
    FUNCTIONALITY
==================*/
bool Penguin::move(short distToMove, Fish fishArr[], Sea & arctic, const bool hasTarget)
{
  bool moveSuccessful = false;// Assume penguin isn't going to be able to move
  bool caughtFish = false;
  bool searchNewTarget = !hasTarget;
  short counter = 0;
  short moveAttemptsThisMove = 0;
  short quad;
  short lastPosX;
  short lastPosY;
  short moveToPosX;
  short moveToPosY;
  short randDirection;

 
  //Get the quadrant the target is in. quad is used in the switch case below
  if (searchNewTarget == false)
  {
    quad = superPosition(m_posX, m_posY, m_targetX, m_targetY);
  }
  else
  {
    quad = randomNumberGen(RAND_DIR_UPPR_EGHT, RAND_DIR_LOWR_ONE);
  }

  //Number of times can move
  while (distToMove > counter && caughtFish == false)
  {
    lastPosX = m_posX;
    lastPosY = m_posY;


      switch (quad)
      {
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
        if (arctic.getActor(moveToPosX, moveToPosY) == SPACE_EMPTY || arctic.getActor(moveToPosX, moveToPosY) == FISH_CHAR)
        {
          m_posX = moveToPosX;
          m_posY = moveToPosY;
          caughtFish = eat(arctic, fishArr);
          arctic.setActor(m_posX, m_posY, PENG_CHAR, lastPosX, lastPosY, SPACE_EMPTY);
          //m_energy -= PENG_MOVE_COST;
          moveSuccessful = true;
        }
        break;
      case 2:
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
        if (arctic.getActor(moveToPosX, moveToPosY) == SPACE_EMPTY || arctic.getActor(moveToPosX, moveToPosY) == FISH_CHAR)
        {
          m_posX = moveToPosX;
          m_posY = moveToPosY;
          caughtFish = this->eat(arctic, fishArr);
          arctic.setActor(m_posX, m_posY, PENG_CHAR, lastPosX, lastPosY, SPACE_EMPTY);
          //m_energy -= PENG_MOVE_COST;
          moveSuccessful = true;
        }
        break;
      case 3:
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
        if (arctic.getActor(moveToPosX, moveToPosY) == SPACE_EMPTY || arctic.getActor(moveToPosX, moveToPosY) == FISH_CHAR)
        {
          m_posX = moveToPosX;
          m_posY = moveToPosY;
          caughtFish = this->eat(arctic, fishArr);
          arctic.setActor(m_posX, m_posY, PENG_CHAR, lastPosX, lastPosY, SPACE_EMPTY);
          //m_energy -= PENG_MOVE_COST;
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
        if (arctic.getActor(moveToPosX, moveToPosY) == SPACE_EMPTY || arctic.getActor(moveToPosX, moveToPosY) == FISH_CHAR)
        {
          m_posX = moveToPosX;
          m_posY = moveToPosY;
          caughtFish = this->eat(arctic, fishArr);
          arctic.setActor(m_posX, m_posY, PENG_CHAR, lastPosX, lastPosY, SPACE_EMPTY);
          //m_energy -= PENG_MOVE_COST;
          moveSuccessful = true;
        }
        break;
      case 5:
        moveToPosX = m_posX + ADVANCE_ACTOR_MOVE;
        moveToPosY = m_posY;

        if (moveToPosX >= MAX_MOVABLE_BOUNDARY)
        {
          moveToPosX = MAX_MOVABLE_BOUNDARY;
        }
        if (arctic.getActor(moveToPosX, moveToPosY) == SPACE_EMPTY || arctic.getActor(moveToPosX, moveToPosY) == FISH_CHAR)
        {
          m_posX = moveToPosX;
          m_posY = moveToPosY;
          caughtFish = this->eat(arctic, fishArr);
          arctic.setActor(m_posX, m_posY, PENG_CHAR, lastPosX, lastPosY, SPACE_EMPTY);
          //m_energy -= PENG_MOVE_COST;
          moveSuccessful = true;
        }
        break;
      case 6:
        moveToPosX = m_posX;
        moveToPosY = m_posY + ADVANCE_ACTOR_MOVE;

        if (moveToPosY >= MAX_MOVABLE_BOUNDARY)
        {
          moveToPosY = MAX_MOVABLE_BOUNDARY;
        }
        if (arctic.getActor(moveToPosX, moveToPosY) == SPACE_EMPTY || arctic.getActor(moveToPosX, moveToPosY) == FISH_CHAR)
        {
          m_posX = moveToPosX;
          m_posY = moveToPosY;
          caughtFish = this->eat(arctic, fishArr);
          arctic.setActor(m_posX, m_posY, PENG_CHAR, lastPosX, lastPosY, SPACE_EMPTY);
          //m_energy -= PENG_MOVE_COST;
          moveSuccessful = true;
        }
        break;
      case 7:
        moveToPosX = m_posX - ADVANCE_ACTOR_MOVE;
        moveToPosY = m_posY;

        if (moveToPosX <= MIN_MOVABLE_BOUNDARY)
        {
          moveToPosX = MIN_MOVABLE_BOUNDARY;
        }
        if (arctic.getActor(moveToPosX, moveToPosY) == SPACE_EMPTY || arctic.getActor(moveToPosX, moveToPosY) == FISH_CHAR)
        {
          m_posX = moveToPosX;
          m_posY = moveToPosY;
          caughtFish = this->eat(arctic, fishArr);
          arctic.setActor(m_posX, m_posY, PENG_CHAR, lastPosX, lastPosY, SPACE_EMPTY);
          //m_energy -= PENG_MOVE_COST;
          moveSuccessful = true;
        }
        break;
      case 8:
        moveToPosX = m_posX;
        moveToPosY = m_posY - ADVANCE_ACTOR_MOVE;

        if (moveToPosY <= MIN_MOVABLE_BOUNDARY)
        {
          moveToPosY = MIN_MOVABLE_BOUNDARY;
        }
        if (arctic.getActor(moveToPosX, moveToPosY) == SPACE_EMPTY || arctic.getActor(moveToPosX, moveToPosY) == FISH_CHAR)
        {
          m_posX = moveToPosX;
          m_posY = moveToPosY;
          caughtFish = this->eat(arctic, fishArr);
          arctic.setActor(m_posX, m_posY, PENG_CHAR, lastPosX, lastPosY, SPACE_EMPTY);
          //m_energy -= PENG_MOVE_COST;
          moveSuccessful = true;
        }
        break;
      default:
        cout << "ERROR IN PENGUIN DIRECTION LOGIC !!!!!" << endl;
        break;
      }//End of switch

      if (moveSuccessful == true)
      {
        counter++;
      }
      else
      {
        quad = randomNumberGen(RAND_DIR_UPPR_EGHT, RAND_DIR_LOWR_ONE);
      }
 
  }//End of While Loop

  return moveSuccessful;
}//End of Penguin::move()



/*================
     GETTERS
================*/
short Penguin::getPengPosX()const
{
  return m_posX;
}

short Penguin::getPengPosY()const
{
  return m_posY;
}

bool Penguin::getAliveState()const
{
  return m_alive;
}


bool Penguin::pengFoundTarget(const Sea S)
{
  /*
    Make sure looping doesn't start outside of the array
    (start X&Y, end X&Y variables are set to acceptable values)
  */
  short startX = m_posX - PENG_VISION_RANGE;    //Starting X
  if (startX < MIN_MOVABLE_BOUNDARY)
    startX = MIN_MOVABLE_BOUNDARY;

  short endX = m_posX + PENG_VISION_RANGE;      //Ending X
  if (endX > MAX_MOVABLE_BOUNDARY)
    endX = MAX_MOVABLE_BOUNDARY;


  short startY = m_posY + PENG_VISION_RANGE;    //Starting Y
  if (startY > MAX_MOVABLE_BOUNDARY)
    startY = MAX_MOVABLE_BOUNDARY;

  short endY = m_posY - PENG_VISION_RANGE;      //Ending Y
  if (endY < MIN_MOVABLE_BOUNDARY)
    endY = MIN_MOVABLE_BOUNDARY;


  /*
    Loop through the penguin's view and set a fish as target if there is one
  */
  bool found_target = false;
  char temp;
  float dist;
  float target_dist = PENG_TARGET_DEF;//One larger than Penguin's vision range

  for (short y = startY; y >= endY; y--)
  {
    for (short x = startX; x <= endX; x++)
    {
      temp = S.getActor(x, y);//Get character in grid.
      if (temp == FISH_CHAR)
      {
        dist = calcDist(m_posX, m_posY, x, y);
        if (dist < target_dist)
        {
          found_target = true;
          target_dist = dist;
          m_targetX = x;
          m_targetY = y;
        }
      }
    }
  }
  return found_target;
}//End of pengFoundTarget()






/*================
     SETTERS
================*/
void Penguin::setPengAliveState(const bool p_state)
{
  m_alive = p_state;
  return;
}

void Penguin::setPengPos(const short posX, const short posY)
{
  m_posX = posX;
  m_posY = posY;
  return;
}

void Penguin::incrementPengAlive()
{
  m_num_pengs_alive++;
  cout << "NUMBER OF PENGUINS ALIVE: ";
  cout << m_num_pengs_alive << endl;
  return;
}

short Penguin::distToMove()
{
  short distToMove = 0;

  if (m_energy > PENG_HEALTH_4)
  {
    //Move 5 spaces
    distToMove = PENG_MOVE_MAX5;
  }
  else if (m_energy > PENG_HEALTH_3)
  {
    //Move 4 spaces
    distToMove = PENG_MOVE_MAX4;
  }
  else if (m_energy > PENG_HEALTH_2)
  {
    //Move 3 Spaces
    distToMove = PENG_MOVE_MAX3;
  }
  else if (m_energy > PENG_HEALTH_1)
  {
    //Move 2 spaces
    distToMove = PENG_MOVE_MAX2;
  }
  else if (m_energy >= PENG_HEALTH_0)
  {
    //Move 1 space
    distToMove = PENG_MOVE_MAX1;
  }
  else
  {
    //The penguin doesn't move, no energy.
    distToMove = PENG_MOVE_MAX0;
  }

  return distToMove;
}

