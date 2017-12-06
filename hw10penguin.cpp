/*========================================================================
*Programmers: Matthew Stroble & Cole Davis
*Date: 12-7-2017
*Class: CS1570 Section A
*File: hw10penguin.cpp
*Purpose: Definition file for class Penguin
========================================================================*/
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
        m_energy += fishArr[counter].getFoodWorth();
        fishArr[counter].setFishAliveState(DEAD);
        fishArr[counter].decramentFishAlive();
        fishAlive = fishArr[counter].getm_num_fish_alive();
        fishArr[counter].setFishPos(FISH_START_X, FISH_START_Y);
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
bool Penguin::move(Fish fishArr[], Sea & arctic)
{
  bool moveSuccessful = false;// Assume penguin isn't going to be able to move
  bool caughtFish = false;
  bool hasFishTarget = false;
  bool hasWhaleTarget = false;
  short turns;
  short counter = 0;
  short moveAttemptsThisMove = 0;
  short quad;
  short lastPosX;
  short lastPosY;
  short moveToPosX;
  short moveToPosY;

  //Gathering needed information for moving the penguin
  turns = distToMove();

  if (PENG_DEBUG)
  {
    cout << "\nAttempting to move: " << turns << endl;
    cout << "My Helth: " << getPengEnergy() << endl;
    usleep(500000);
  }

  //Number of times can move
  while (counter < turns && caughtFish == false
    && moveAttemptsThisMove < MAX_MOVE_ATTMPTS)
  {
    lastPosX = m_posX;
    lastPosY = m_posY;

    hasFishTarget = pengFindTarget(arctic, FISH_CHAR);
    if (hasFishTarget == false)
    {
      hasWhaleTarget = pengFindTarget(arctic, WHALE_CHAR);
    }
    //Get the quadrant the target is in. quad is used in the switch case below
    if (hasFishTarget == true && hasWhaleTarget == false)
    {
      quad = superPosition(m_posX, m_posY, m_targetX, m_targetY);
    }
    else if (hasFishTarget == false && hasWhaleTarget == true)
    {
      quad = superPosition(m_posX, m_posY, m_targetX, m_targetY);
      quad = avoidWhaleQuadAdjust(quad);
    }
    else
    {
      quad = randomNumberGen(RAND_DIR_UPPR_EGHT, RAND_DIR_LOWR_ONE);
    }


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
        if (arctic.getActor(moveToPosX, moveToPosY) == SPACE_EMPTY
          || arctic.getActor(moveToPosX, moveToPosY) == FISH_CHAR)
        {
          m_posX = moveToPosX;
          m_posY = moveToPosY;
          caughtFish = eat(arctic, fishArr);
          arctic.setActor(m_posX, m_posY, PENG_CHAR,
            lastPosX, lastPosY, SPACE_EMPTY);
          m_energy -= PENG_MOVE_COST;
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
        if (arctic.getActor(moveToPosX, moveToPosY) == SPACE_EMPTY
          || arctic.getActor(moveToPosX, moveToPosY) == FISH_CHAR)
        {
          m_posX = moveToPosX;
          m_posY = moveToPosY;
          caughtFish = eat(arctic, fishArr);
          arctic.setActor(m_posX, m_posY, PENG_CHAR,
            lastPosX, lastPosY, SPACE_EMPTY);
          m_energy -= PENG_MOVE_COST;
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
        if (arctic.getActor(moveToPosX, moveToPosY) == SPACE_EMPTY
          || arctic.getActor(moveToPosX, moveToPosY) == FISH_CHAR)
        {
          m_posX = moveToPosX;
          m_posY = moveToPosY;
          caughtFish = eat(arctic, fishArr);
          arctic.setActor(m_posX, m_posY, PENG_CHAR,
            lastPosX, lastPosY, SPACE_EMPTY);
          m_energy -= PENG_MOVE_COST;
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
        if (arctic.getActor(moveToPosX, moveToPosY) == SPACE_EMPTY
          || arctic.getActor(moveToPosX, moveToPosY) == FISH_CHAR)
        {
          m_posX = moveToPosX;
          m_posY = moveToPosY;
          caughtFish = eat(arctic, fishArr);
          arctic.setActor(m_posX, m_posY, PENG_CHAR,
            lastPosX, lastPosY, SPACE_EMPTY);
          m_energy -= PENG_MOVE_COST;
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
        if (arctic.getActor(moveToPosX, moveToPosY) == SPACE_EMPTY
          || arctic.getActor(moveToPosX, moveToPosY) == FISH_CHAR)
        {
          m_posX = moveToPosX;
          m_posY = moveToPosY;
          caughtFish = eat(arctic, fishArr);
          arctic.setActor(m_posX, m_posY, PENG_CHAR,
            lastPosX, lastPosY, SPACE_EMPTY);
          m_energy -= PENG_MOVE_COST;
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
        if (arctic.getActor(moveToPosX, moveToPosY) == SPACE_EMPTY
          || arctic.getActor(moveToPosX, moveToPosY) == FISH_CHAR)
        {
          m_posX = moveToPosX;
          m_posY = moveToPosY;
          caughtFish = eat(arctic, fishArr);
          arctic.setActor(m_posX, m_posY, PENG_CHAR,
            lastPosX, lastPosY, SPACE_EMPTY);
          m_energy -= PENG_MOVE_COST;
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
        if (arctic.getActor(moveToPosX, moveToPosY) == SPACE_EMPTY
          || arctic.getActor(moveToPosX, moveToPosY) == FISH_CHAR)
        {
          m_posX = moveToPosX;
          m_posY = moveToPosY;
          caughtFish = eat(arctic, fishArr);
          arctic.setActor(m_posX, m_posY, PENG_CHAR,
            lastPosX, lastPosY, SPACE_EMPTY);
          m_energy -= PENG_MOVE_COST;
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
        if (arctic.getActor(moveToPosX, moveToPosY) == SPACE_EMPTY
          || arctic.getActor(moveToPosX, moveToPosY) == FISH_CHAR)
        {
          m_posX = moveToPosX;
          m_posY = moveToPosY;
          caughtFish = eat(arctic, fishArr);
          arctic.setActor(m_posX, m_posY, PENG_CHAR,
            lastPosX, lastPosY, SPACE_EMPTY);
          m_energy -= PENG_MOVE_COST;
          moveSuccessful = true;
        }
        break;
      default:
        quad = randomNumberGen(RAND_DIR_UPPR_EGHT, RAND_DIR_LOWR_ONE);
        break;
    }//End of switch

    if (moveSuccessful == true)
    {
      counter++;
      moveAttemptsThisMove = 0;
    }
    else
    {
      moveAttemptsThisMove++;
      quad = randomNumberGen(RAND_DIR_UPPR_EGHT, RAND_DIR_LOWR_ONE);
    }

    if (PENG_DEBUG == true)
    {
      cout << arctic;
      usleep(500000);
    }
  }//End of While Loop


  if (PENG_DEBUG == true)
  {
    cout << "I moved: " << counter << endl;
    cout << "Caught fish: " << caughtFish << endl;
    cout << arctic;
    usleep(500000);
  }


  return moveSuccessful;
}//End of Penguin::move()



void Penguin::reincarnatePeng(Sea & S, Penguin penguinArr[])
{
  static short num_calls = 0;
  if (m_energy > PENG_HEALTH_SPAWN_MIN && m_num_pengs_alive < MAX_PENGUINS)
  {
    num_calls++;
    bool is_space;
    is_space = false;
    short new_x;
    short new_y;
    short counter = 0;
    //Parent's health is cut in half.
    m_energy = static_cast<short>(static_cast<float>(m_energy) / 2);
    do
    {
      //Generate random number between 1 & 17 inclusive
      new_x = rand() % PLAYABLE_SPACE;
      new_y = rand() % PLAYABLE_SPACE;

      if (S.getActor(new_x, new_y) == SPACE_EMPTY)
      {
        is_space = true;

        //Update m_seaGrid[][]
        S.addActor(new_x, new_y, PENG_CHAR);

        //Set member x&y variables
        penguinArr[m_num_pengs_alive].setPengPos(new_x, new_y);

        //Generate penguin's health anywhere between 100 and 0
        penguinArr[m_num_pengs_alive].setPengEnergy
        (randomNumberGen(PENG_HEALTH_MAX, PENG_HEALTH_MIN));


        //penguinArr[m_num_pengs_alive].setPengEnergy(spawnedHealth);
        //Make member 'alive' variable to true
        penguinArr[m_num_pengs_alive].setPengAliveState(true);

        penguinArr[m_num_pengs_alive].incrementPengAlive();
        //cout << "Penguin Alive: " << m_num_pengs_alive << endl;
        counter++;
      }
    } while (!is_space && counter < ATTEMPTS_CTR);
  }
}




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


bool Penguin::pengFindTarget(const Sea & S, const char targetType)
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

  if (targetType == FISH_CHAR)
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

  if (targetType == WHALE_CHAR)
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

void Penguin::setPengEnergy(const short energy)
{
  m_energy = energy;
  return;
}





void Penguin::incrementPengAlive()
{
  m_num_pengs_alive++;
  if (PENG_DEBUG == true)
  {
    cout << "NUMBER OF PENGUINS ALIVE: ";
    cout << m_num_pengs_alive << endl;
  }
  return;
}

void Penguin::decramentPengAlive()
{
  m_num_pengs_alive--;
  return;
}

short Penguin::getm_num_pengs_alive()
{
  return m_num_pengs_alive;
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
