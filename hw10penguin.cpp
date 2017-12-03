#include "hw10headder.h"
#include "hw10penguin.h"
#include "hw10sea.h"


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
bool Penguin::move()
{

  short moveAmmount = 0;
  bool can_move = false;// Assume penguin is going to move to an invalid
                        // location (either occupied or out of bounds)

  if(m_energy > PENG_HEALTH_4)
  {
    //Move 5 spaces
  }
  else if(m_energy > PENG_HEALTH_3)
  {
    //Move 4 spaces
  }
  else if(m_energy > PENG_HEALTH_2)
  {
    //Move 3 Spaces
  }
  else if(m_energy > PENG_HEALTH_1)
  {
    //Move 2 spaces
  }
  else if(m_energy >= PENG_HEALTH_0)
  {
    //Move 1 space
  }
  else
  {
    //The penguin doesn't move, no energy.
  }

  return can_move;
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
