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


/*==================
    FUNCTIONALITY
==================*/
bool Penguin::move(short distToMove, Fish fishArr[], Sea S, const bool hasTarget)
{
  bool did_move = false;// Assume penguin isn't going to be able to move
  short quad;

  //Get the quadrant the target is in. quad is used in the switch case below
  if(hasTarget == true)
    quad = superPosition(m_posX, m_posY, m_targetX, m_targetY);

  else
    quad = 9;


  //Number of times can move
  for (short cycle = distToMove; cycle > 0; cycle--)
  {
    switch (quad)
    {
      case 1:
      {
        if(S.getActor(m_posX + ADVANCE_ACTOR_MOVE, m_posY + ADVANCE_ACTOR_MOVE
          == SPACE_EMPTY) || S.getActor(m_posX + ADVANCE_ACTOR_MOVE, m_posY
            + ADVANCE_ACTOR_MOVE == FISH_CHAR))
        {
          m_posX += ADVANCE_ACTOR_MOVE;
          m_posY += ADVANCE_ACTOR_MOVE;
        }

        else if(S.getActor(m_posX + ADVANCE_ACTOR_MOVE, m_posY) == SPACE_EMPTY
          || S.getActor(m_posX + ADVANCE_ACTOR_MOVE, m_posY) == FISH_CHAR)
            m_posX += ADVANCE_ACTOR_MOVE;

        else if(S.getActor(m_posX, m_posY + ADVANCE_ACTOR_MOVE) == SPACE_EMPTY
          || S.getActor(m_posX, m_posY + ADVANCE_ACTOR_MOVE) == FISH_CHAR)
            m_posY += ADVANCE_ACTOR_MOVE;

        break;
      }

      case 2:
      {

        break;
      }
      case 3:
      {

        break;
      }
      case 4:
      {

        break;
      }
      case 5:
      {

        break;
      }
      case 6:
      {

        break;
      }
      case 7:
      {

        break;
      }
      case 8:
      {

        break;
      }
      default:
      {

      }
    }//End of switch
  }
  return did_move;
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
  if(startX < MIN_MOVABLE_BOUNDARY)
     startX = MIN_MOVABLE_BOUNDARY;

  short endX = m_posX + PENG_VISION_RANGE;      //Ending X
  if(endX > MAX_MOVABLE_BOUNDARY)
    endX = MAX_MOVABLE_BOUNDARY;


  short startY = m_posY + PENG_VISION_RANGE;    //Starting Y
  if(startY > MAX_MOVABLE_BOUNDARY)
     startY = MAX_MOVABLE_BOUNDARY;

  short endY = m_posY - PENG_VISION_RANGE;      //Ending Y
   if(endY < MIN_MOVABLE_BOUNDARY)
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
     for ( short x = startX; x <= endX; x++)
     {
       temp = S.getActor(x,y);//Get character in grid.
       if(temp == FISH_CHAR)
       {
         dist = calcDist(m_posX, m_posY, x, y);
         if(dist < target_dist)
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
  cout<<"NUMBER OF PENGUINS ALIVE: ";
  cout<<m_num_pengs_alive<<endl;
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
    distToMove = PENG_MOVE_Max0;
  }

  return distToMove;
}
