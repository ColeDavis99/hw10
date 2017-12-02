#include "hw10headder.h"
#include "hw10penguin.h"
#include "hw10sea.h"


/*==================
    CONSTRUCTOR
==================*/
Penguin::Penguin()
{
  //Calculate starting energy level;
  short range = (PENG_HEALTH_MAX - PENG_HEALTH_MIN + 1);
  m_energy = rand() % range + PENG_HEALTH_MIN;


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



  /*determine what direction the penguin should move
   (look for fish)


  /*Determine whether or not moving X amt of spaces in X direction
    is a valid move or not. bool can_move represents this.*/



  /*
    Note about move():
    -----------------

    Should we call call move() again if the penguin's first move wasn't
    valid? I think we should call it a maximum of 3 times to represent the
    amount of time the penguin would have to make a decision (I assume a
    penguin being chased by a killer whale  would have enough time to
    plot 3 different escape routes?) Having a limit of times move() is
    called will also prevent an infinite loop of
    "can't move" from occuring.
  */

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

  short startX = m_posX - PENG_VISION_RANGE;
  if(startX < MIN_MOVABLE_BOUNDARY)
     startX = MIN_MOVABLE_BOUNDARY;

  short endX = m_posX + PENG_VISION_RANGE;
  if(endX > MAX_MOVABLE_BOUNDARY)
    endX = MAX_MOVABLE_BOUNDARY;


  short startY = m_posY + PENG_VISION_RANGE;
  if(startY > MAX_MOVABLE_BOUNDARY)
     startY = MAX_MOVABLE_BOUNDARY;

  short endY = m_posY - PENG_VISION_RANGE;
   if(endY < MIN_MOVABLE_BOUNDARY)
      endY = MIN_MOVABLE_BOUNDARY;

  for (short y = startY; y >= endY; y--)
  {
     for ( short x = startX; x <= endX; x++)
     {
      //Loop through S.m_seaGrid[][] using these x & y values
      //And set the penguin's targetx&y values equal to the fish's
      // x & y values
      // (Look at picture on phone, black pseudocode on whiteboard)
     }
  }
}






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
