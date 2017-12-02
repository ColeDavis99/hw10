#include "hw10headder.h"
#include "hw10sea.h"
#include "hw10killerwhale.h"
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
                   Fish fishArr[],
                   Whale whaleArr[])
{
  //Randomly generate penguin's valid x&y values and set their member vars.
  bool is_space;
  short new_x;
  short new_y;

  //loop 1 of 3
  for(short i=0; i<PENG_SPAWN_NUM; i++)
  {
    is_space = false;
    do
    {
      //Generate random number between 1 & 17 inclusive
      new_x = rand() % m_seaSpace + 1;
      new_y = rand() % m_seaSpace + 1;
      cout<<"Penguin's Random X: "<<new_x<<endl;
      cout<<"Penguin's Random Y: "<<new_y<<endl<<endl;


      if(m_seaGrid[new_x][new_y] == ' ')
      {
        is_space = true;
        m_seaGrid[new_x][new_y] = PENG_CHAR;

        //Set member x&y variables
        penguinArr[i].setPengPos(new_x, new_y);

        //Make member 'alive' variable to true
        penguinArr[i].setPengAliveState(true);
      }
      else{
        cout<<"^CONFLICT^"<<endl<<endl<<endl;
      }
    } while(!is_space);
  }//End of Penguin Loop

  //loop 2 of 3
  for(short i=0; i<FISH_SPAWN_NUM; i++)
  {
    is_space = false;
    do
    {
      //Generate random number between 1 & 17 inclusive
      new_x = rand() % m_seaSpace + 1;
      new_y = rand() % m_seaSpace + 1;
      cout<<"Fish's Random X: "<<new_x<<endl;
      cout<<"Fish's Random Y: "<<new_y<<endl<<endl;


      if(m_seaGrid[new_x][new_y] == ' ')
      {
        is_space = true;
        m_seaGrid[new_x][new_y] = FISH_CHAR;

        //Set member x&y variables
        fishArr[i].setFishPos(new_x, new_y);

        //Make member 'alive' variable to true
        fishArr[i].setFishAliveState(true);
      }
      else{
        cout<<"^CONFLICT^"<<endl<<endl<<endl;
      }
    } while(!is_space);
  }//End of fish Loop


  //loop 3 of 3
  for(short i=0; i<WHALE_SPAWN_NUM; i++)
  {
    is_space = false;
    do
    {
      //Generate random number between 1 & 17 inclusive
      new_x = rand() % m_seaSpace + 1;
      new_y = rand() % m_seaSpace + 1;
      cout<<"Whale's Random X: "<<new_x<<endl;
      cout<<"Whale's Random Y: "<<new_y<<endl<<endl;


      if(m_seaGrid[new_x][new_y] == ' ')
      {
        is_space = true;
        m_seaGrid[new_x][new_y] = WHALE_CHAR;

        //Set member x&y variables
        whaleArr[i].setWhalePos(new_x, new_y);
      }
      else{
        cout<<"^CONFLICT^"<<endl<<endl<<endl;
      }
    } while(!is_space);
  }//End of fish Loop

}//End of Sea::populate()







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


char getActor(const short posX, const short posY)const
{
  return m_seaGrid[posY][posX];
}

void setActor(const short & posX, const short & posY, char actor)
{
  m_seaGrid[posY][posX] = actor;
}
