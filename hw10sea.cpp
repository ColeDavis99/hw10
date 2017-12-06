/*========================================================================
 *Programmers: Matthew Stroble & Cole Davis
 *Date: 12-7-2017
 *Class: CS1570 Section A
 *File: hw10sea.cpp
 *Purpose: Implementation file for class Sea
========================================================================*/

#include "hw10sea.h"
#include "hw10penguin.h"
#include "hw10fish.h"



/*==================
    CONSTRUCTOR
==================*/
Sea::Sea(Penguin penguinArr[],
  Fish fishArr[],
  Whale whaleArr[],
  const short seaspace)
{
  m_seaSpace = seaspace;//Default argument of SEA_MAX

  // Fill m_seaGrid[][] with x's
  drawBorder();

  // Clear m_seaGrid[][]
  clear();

  // Place fish, pengs, and killers into m_seaGrid[][]
  populate(penguinArr, fishArr, whaleArr);
}


/*==================
    FUNCTIONALITY
==================*/

void Sea::drawBorder()
{
  for (short i = m_seaSpace + 1; i >= 0; i--)
  {
    for (short q = 0; q <= m_seaSpace + 1; q++)
    {
      m_seaGrid[i][q] = 'x';
    }
  }
}


void Sea::clear()
{
  for (short i = m_seaSpace; i > 0; i--)
  {
    for (short q = 1; q <= m_seaSpace; q++)
    {
      m_seaGrid[i][q] = SPACE_EMPTY;
    }
  }
}



void Sea::populate(Penguin penguinArr[],
  Fish fishArr[],
  Whale whaleArr[])
{
  //Randomly generate penguin's valid x&y values and set their member vars.
  bool is_space;
  short new_x;
  short new_y;


  //loop 1 of 3
  for (short i = 0; i < FISH_SPAWN_NUM; i++)
  {
    is_space = false;
    do
    {
      //Generate random number between 1 & 17 inclusive
      new_x = rand() % m_seaSpace + 1;
      new_y = rand() % m_seaSpace + 1;
      if (FISH_DEBUG == true)
      {
        cout << "Fish's Random X: " << new_x << endl;
        cout << "Fish's Random Y: " << new_y << endl << endl;
      }

      if (m_seaGrid[new_y][new_x] == SPACE_EMPTY)
      {
        is_space = true;

        fishArr[i].incrementFishAlive();

        m_seaGrid[new_y][new_x] = FISH_CHAR;

        //Set member x&y variables
        fishArr[i].setFishPos(new_x, new_y);

        //Make member 'alive' variable to true
        fishArr[i].setFishAliveState(true);
      }
      else {
        if (FISH_DEBUG == true)
        {
          cout << "^CONFLICT^" << endl << endl << endl;
        }
      }
    } while (!is_space);
  }//End of fish Loop

  //loop 2 of 3
  for (short i = 0; i < PENG_SPAWN_NUM; i++)
  {
    is_space = false;
    do
    {
      //Generate random number between 1 & 17 inclusive
      new_x = rand() % m_seaSpace + 1;
      new_y = rand() % m_seaSpace + 1;
      if (PENG_DEBUG == true)
      {
        cout << "Penguin's Random X: " << new_x << endl;
        cout << "Penguin's Random Y: " << new_y << endl;
        cout << "My Health: " << penguinArr[i].getPengEnergy() << endl<< endl;
      }

      if (m_seaGrid[new_y][new_x] == SPACE_EMPTY)
      {
        is_space = true;
        penguinArr[i].incrementPengAlive();

        //Update m_seaGrid[][]
        m_seaGrid[new_y][new_x] = PENG_CHAR;

        //Set member x&y variables
        penguinArr[i].setPengPos(new_x, new_y);

        //Make member 'alive' variable to true
        penguinArr[i].setPengAliveState(true);
      }
      else {
        if (PENG_DEBUG == true)
        {
          cout << "^CONFLICT^" << endl << endl << endl;
        }
      }
    } while (!is_space);
  }//End of Penguin Loop

   //loop 3 of 3
  for (short i = 0; i < WHALE_SPAWN_NUM; i++)
  {
    is_space = false;
    do
    {
      //Generate random number between 1 & 17 inclusive
      new_x = rand() % m_seaSpace + 1;
      new_y = rand() % m_seaSpace + 1;
      if (WHALE_DEBUG == true)
      {
        cout << "Whale's Random X: " << new_x << endl;
        cout << "Whale's Random Y: " << new_y << endl << endl;
      }

      if (m_seaGrid[new_y][new_x] == SPACE_EMPTY)
      {
        is_space = true;
        m_seaGrid[new_y][new_x] = WHALE_CHAR;

        //Set member x&y variables
        whaleArr[i].setWhalePos(new_x, new_y);
      }
      else {
        if (WHALE_DEBUG == true)
        {
          cout << "^CONFLICT^" << endl << endl << endl;
        }
      }
    } while (!is_space);
  }//End of Whale Loop

}//End of Sea::populate()







template <typename T>
void Sea::addToGrid(T actor)
{
  char actor_type;
  //Template function that takes a fish, penguin, or killer whale
  // object and adds it to m_seaGrid[][].


  //Ignore 'true', it's just here so everything compiles
  if (/*is a penguin*/true)
    actor_type = 'P';
  else if (/*is a killer whale*/true)
    actor_type = 'K';
  else if (/*is a fish*/true)
    actor_type = 'F';


  // m_seaGrid[actor.getX()][actor.getY()] = actor_type;
}




/*================================
    INSERTION OPERATOR OVERLOAD
================================*/

ostream & operator <<(ostream &os, const Sea &sea)
{
  for (short i = sea.m_seaSpace + 1; i >= 0; i--)
  {
    for (short q = 0; q <= sea.m_seaSpace + 1; q++)
    {
      os << ' ' << sea.m_seaGrid[i][q] << ' ';
    }
    os << endl;
  }
  return os;
}


char Sea::getActor(const short posX, const short posY)const
{
  return m_seaGrid[posY][posX];
}



void Sea::setActor(const short newPosX, const short newPosY,
  char newActor, short lastPosX, short lastPosY, char clearActor)
{
  m_seaGrid[lastPosY][lastPosX] = clearActor;
  m_seaGrid[newPosY][newPosX] = newActor;
  return;
}


void Sea::addActor(const short x, const short y, const char actor_char)
{
  m_seaGrid[y][x] = actor_char;
  return;
}
