#include "hw10headder.h"
#include "hw10sea.h"
#include "hw10killerwhale.h"

/*==================
    CONSTRUCTOR
==================*/
Sea::Sea(Penguin penguinArr[],
         Fish fishArr[],
         const short seaspace)
{
  m_seaSpace = seaspace;//Default argument of SEA_MAX

  // Fill m_seaGrid[][] with x's
  drawBorder();


  // Clear m_seaGrid[][]
   clear();


  // Place fish, pengs, and killers into m_seaGrid[][]
  populate(penguinArr, fishArr);
}


/*==================
    FUNCTIONALITY
==================*/

void Sea::drawBorder()
{
  for(short i = m_seaSpace+1; i >= 0; i--)
  {
    for(short q = 0; q <=m_seaSpace+1; q++)
    {
      m_seaGrid[i][q] = 'x';
    }
  }
}


void Sea::clear()
{
  for(short i = m_seaSpace; i > 0; i--)
  {
    for(short q = 1; q <=m_seaSpace; q++)
    {
      m_seaGrid[i][q] = ' ';
    }
  }
}



//Eventually will pass whale array as well
void Sea::populate(Penguin penguinArr[],
                   Fish fishArr[])
{
  //Randomly generate penguin's valid x&y values and set their member vars.
  short peng_x;
  short peng_y;

  for(short i=0; i<PENG_SPAWN_NUM; i++)
  {
    //Generate random number between 1 & 17 inclusive
    peng_x = rand() % m_seaSpace + 1;
    peng_y = rand() % m_seaSpace + 1;
    cout<<"Penguin's Random X: "<<peng_x<<endl;
    cout<<"Penguin's Random Y: "<<peng_y<<endl;

  }
}







template <typename T>
void Sea::addToGrid(T actor)
{
  char actor_type;
  //Template function that takes a fish, penguin, or killer whale
  // object and adds it to m_seaGrid[][].


  //Ignore 'true', it's just here so everything compiles
  if(/*is a penguin*/true)
    actor_type = 'P';
  else if(/*is a killer whale*/true)
    actor_type = 'K';
  else if(/*is a fish*/true)
    actor_type = 'F';


  // m_seaGrid[actor.getX()][actor.getY()] = actor_type;
}




/*================================
    INSERTION OPERATOR OVERLOAD
================================*/

ostream & operator <<(ostream &os, const Sea &sea)
{
  for(short i = sea.m_seaSpace+1; i >= 0; i--)
  {
    for(short q = 0; q <=sea.m_seaSpace+1; q++)
    {
      os<<' '<<sea.m_seaGrid[i][q]<<' ';
    }
    os<<endl;
  }
  return os;
}
