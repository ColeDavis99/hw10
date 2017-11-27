#include "hw10headder.h"
#include "hw10sea.h"

/*==================
    CONSTRUCTOR
==================*/
Sea::Sea(const short seaspace)
{
  m_seaSpace = seaspace;//Default argument of SEA_MAX


  //Border Drawing
  for(short i = m_seaSpace+1; i >= 0; i--)
  {
    for(short q = 0; q <=m_seaSpace+1; q++)
    {
      m_seaGrid[i][q] = 'x';
    }
  }

  // Clear m_seaGrid[][]
   clear();

  // Place fish, pengs, and killers into m_seaGrid[][]
  populate();
}


/*==================
    FUNCTIONALITY
==================*/
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



void Sea::populate()
{
  //Code goes here for m_seaGrid[][] population
  m_seaGrid[1][1] = 'A';
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
      os<<sea.m_seaGrid[i][q];
    }
    os<<endl;
  }
  return os;
}
