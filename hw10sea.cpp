#include "hw10headder.h"
#include "hw10sea.h"

/*==================
    CONSTRUCTOR
==================*/
Sea::Sea(const short seaspace)
{
  m_seaSpace = seaspace;//Default argument of SEA_MAX

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
   for(int i=0; i<SEA_MAX; i++)
   {
     for(int q=0; q<SEA_MAX; q++)
     {
       m_seaGrid[i][q] = 'S';
     }
   }
}



void Sea::populate()
{
  //Code goes here for m_seaGrid[][] population
}






/*================================
    INSERTION OPERATOR OVERLOAD
================================*/

ostream & operator <<(ostream &os, const Sea &sea)
{
  for(int i=0; i<SEA_MAX; i++)
  {
    for(int q=0; q<SEA_MAX; q++)
    {
      os<<sea.m_seaGrid[i][q];
    }
    os<<endl;
  }
  return os;
}
