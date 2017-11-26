/*========================================================================
 *Programmers: Cole Davis & Matthew (Last Name)
 *Date: 12-7-2017
 *Class: CS1570 Section A
 *Purpose: Simulate Antarctic Waters
========================================================================*/

#include "hw10headder.h"
#include "hw10fish.h"
#include "hw10killerwhale.h"
#include "hw10penguin.h"
#include "hw10sea.h"



int main()
{
  srand(time(NULL));

  cout<<"I'm filling Arctic.m_seaGrid[][] with an 'S'.This can easily be"<<endl
  <<"switched with a space in order to 'clear' the grid."<<endl<<endl;
  Sea Arctic(17);
  cout<<Arctic;



  Penguin Mumble;
  Mumble.move();// move() is incomplete

  //Testing fish movement
  fish frank;



  return 0;
}
