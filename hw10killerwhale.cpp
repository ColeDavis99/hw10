#include "hw10headder.h"
#include "hw10killerwhale.h"
#include "hw10sea.h"


Whale::Whale()
{
  m_penguinKilledCount = 0;
  m_energy = WHALE_MOVE_PER_TURN;
}


short Whale::getPenguinKillCount()
{
  return m_penguinKilledCount;
}


bool Whale::eat(Sea & Arctic, Fish fishArr[], Penguin pengArr[])
{
  bool pengInArrFound = false;
  short counter = 0;
  short pengAlive;
  short pengPosX;
  short pengPosY;

  if (Arctic.getActor(m_posX, m_posY) == PENG_CHAR || Arctic.getActor(m_posX, m_posY) == FISH_CHAR)
  {
    while (pengInArrFound == false)
    {
      pengPosX = pengArr[counter].getPengPosX();
      pengPosY = pengArr[counter].getPengPosY();
      if (m_posX == pengPosX && m_posY == pengPosY)
      {
        pengArr[counter].decramentPengAlive();
        pengArr[counter].setPengAliveState(DEAD);
        pengAlive = pengArr[counter].getm_num_pengs_alive();
        pengArr[counter].setPengPos(PENG_START_X, PENG_START_Y);
        swap(pengArr[counter], pengArr[pengAlive]);
        pengInArrFound = true;
        m_penguinKilledCount++;
      }
      counter++;
    }
  }
  return pengInArrFound;
}

/*==================
FUNCTIONALITY
==================*/
bool Whale::move(Fish fishArr[], Penguin pengArr[], Sea & arctic)
{
  bool moveSuccessful = false;// Assume whale isn't going to be able to move
  bool caughtPeng = false;
  bool hasPengTarget = false;
  short counter = 0;
  short moveAttemptsThisMove = 0;
  short quad;
  short lastPosX;
  short lastPosY;
  short moveToPosX;
  short moveToPosY;


  //Number of times can move
  while (counter < WHALE_MOVE_PER_TURN && caughtPeng == false && moveAttemptsThisMove < MAX_MOVE_ATTMPTS)
  {

    lastPosX = m_posX;
    lastPosY = m_posY;

    hasPengTarget = whaleFindTarget(arctic);

    if (hasPengTarget == true)
    {
      quad = superPosition(m_posX, m_posY, m_targetX, m_targetY);
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
        if (arctic.getActor(moveToPosX, moveToPosY) == SPACE_EMPTY || arctic.getActor(moveToPosX, moveToPosY) == PENG_CHAR)
        {
          m_posX = moveToPosX;
          m_posY = moveToPosY;
          caughtPeng = eat(arctic, fishArr, pengArr);
          arctic.setActor(m_posX, m_posY, WHALE_CHAR, lastPosX, lastPosY, SPACE_EMPTY);
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
        if (arctic.getActor(moveToPosX, moveToPosY) == SPACE_EMPTY || arctic.getActor(moveToPosX, moveToPosY) == PENG_CHAR)
        {
          m_posX = moveToPosX;
          m_posY = moveToPosY;
          caughtPeng = eat(arctic, fishArr, pengArr);
          arctic.setActor(m_posX, m_posY, WHALE_CHAR, lastPosX, lastPosY, SPACE_EMPTY);
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
        if (arctic.getActor(moveToPosX, moveToPosY) == SPACE_EMPTY || arctic.getActor(moveToPosX, moveToPosY) == PENG_CHAR)
        {
          m_posX = moveToPosX;
          m_posY = moveToPosY;
          caughtPeng = eat(arctic, fishArr, pengArr);
          arctic.setActor(m_posX, m_posY, WHALE_CHAR, lastPosX, lastPosY, SPACE_EMPTY);
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
        if (arctic.getActor(moveToPosX, moveToPosY) == SPACE_EMPTY || arctic.getActor(moveToPosX, moveToPosY) == PENG_CHAR)
        {
          m_posX = moveToPosX;
          m_posY = moveToPosY;
          caughtPeng = eat(arctic, fishArr, pengArr);
          arctic.setActor(m_posX, m_posY, WHALE_CHAR, lastPosX, lastPosY, SPACE_EMPTY);
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
        if (arctic.getActor(moveToPosX, moveToPosY) == SPACE_EMPTY || arctic.getActor(moveToPosX, moveToPosY) == PENG_CHAR)
        {
          m_posX = moveToPosX;
          m_posY = moveToPosY;
          caughtPeng = eat(arctic, fishArr, pengArr);
          arctic.setActor(m_posX, m_posY, WHALE_CHAR, lastPosX, lastPosY, SPACE_EMPTY);
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
        if (arctic.getActor(moveToPosX, moveToPosY) == SPACE_EMPTY || arctic.getActor(moveToPosX, moveToPosY) == PENG_CHAR)
        {
          m_posX = moveToPosX;
          m_posY = moveToPosY;
          caughtPeng = eat(arctic, fishArr, pengArr);
          arctic.setActor(m_posX, m_posY, WHALE_CHAR, lastPosX, lastPosY, SPACE_EMPTY);
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
        if (arctic.getActor(moveToPosX, moveToPosY) == SPACE_EMPTY || arctic.getActor(moveToPosX, moveToPosY) == PENG_CHAR)
        {
          m_posX = moveToPosX;
          m_posY = moveToPosY;
          caughtPeng = eat(arctic, fishArr, pengArr);
          arctic.setActor(m_posX, m_posY, WHALE_CHAR, lastPosX, lastPosY, SPACE_EMPTY);
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
        if (arctic.getActor(moveToPosX, moveToPosY) == SPACE_EMPTY || arctic.getActor(moveToPosX, moveToPosY) == PENG_CHAR)
        {
          m_posX = moveToPosX;
          m_posY = moveToPosY;
          caughtPeng = eat(arctic, fishArr, pengArr);
          arctic.setActor(m_posX, m_posY, WHALE_CHAR, lastPosX, lastPosY, SPACE_EMPTY);
          //m_energy -= PENG_MOVE_COST;
          moveSuccessful = true;
        }
        break;
      default:
        cout << "ERROR IN WHALE DIRECTION LOGIC !!!!!" << endl;
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

  }//End of While Loop
  if (WHALE_DEBUG)
  {
    usleep(200000);
    cout << arctic;
  }
  return moveSuccessful;
}//End of Whale::move()



 /*================
 GETTERS
 ================*/
short Whale::getWhalePosX()const
{
  return m_posX;
}

short Whale::getWhalePosY()const
{
  return m_posY;
}


bool Whale::whaleFindTarget(const Sea & S)
{
  /*
  Make sure looping doesn't start outside of the array
  (start X&Y, end X&Y variables are set to acceptable values)
  */
  short startX = m_posX - WHALE_VISION_RANGE;    //Starting X
  if (startX < MIN_MOVABLE_BOUNDARY)
    startX = MIN_MOVABLE_BOUNDARY;

  short endX = m_posX + WHALE_VISION_RANGE;      //Ending X
  if (endX > MAX_MOVABLE_BOUNDARY)
    endX = MAX_MOVABLE_BOUNDARY;


  short startY = m_posY + WHALE_VISION_RANGE;    //Starting Y
  if (startY > MAX_MOVABLE_BOUNDARY)
    startY = MAX_MOVABLE_BOUNDARY;

  short endY = m_posY - WHALE_VISION_RANGE;      //Ending Y
  if (endY < MIN_MOVABLE_BOUNDARY)
    endY = MIN_MOVABLE_BOUNDARY;


  /*
  Loop through the penguin's view and set a fish as target if there is one
  */
  bool found_target = false;
  char temp;
  float dist;
  float target_dist = WHALE_VISION_RANGE;

  for (short y = startY; y >= endY; y--)
  {
    for (short x = startX; x <= endX; x++)
    {
      temp = S.getActor(x, y);//Get character in grid.
      if (temp == PENG_CHAR)
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
}//End of whaleFoundTarget()






 /*================
    SETTERS
 ================*/

void Whale::setWhalePos(const short posX, const short posY)
{
  m_posX = posX;
  m_posY = posY;
  return;
}
