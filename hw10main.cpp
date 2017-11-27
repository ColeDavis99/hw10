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

  Penguin penguinArr[MAX_PENGUINS];
  Fish fishArr[MAX_FISH];

  Sea Arctic(penguinArr, fishArr, PLAYABLE_SPACE);

  cout<<Arctic;








  for (short turn = 0; turn < SIMULATION_ITTERATIONS; turn++)
  {


  }


  return 0;
}
