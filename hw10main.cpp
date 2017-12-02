/*========================================================================
 *Programmers: Cole Davis & Matthew (Last Name)
 *Date: 12-7-2017
 *Class: CS1570 Section A
 *Purpose: Simulate Antarctic Waters
========================================================================*/
#include "hw10headder.h"
#include "hw10sea.h"
#include "hw10fish.h"
#include "hw10penguin.h"
#include "hw10killerwhale.h"
#include <iostream>
#include <unistd.h>


int main()
{
  srand(time(NULL));

  //Create arrays of all actors
  Penguin penguinArr[MAX_PENGUINS];
  Fish fishArr[MAX_FISH];
  Whale whaleArr[MAX_WHALES];

  Sea Arctic(penguinArr, fishArr, whaleArr, PLAYABLE_SPACE);
  //cout<<Arctic;

  penguinArr[5].pengFoundTarget(Arctic);






  for (short turn = 0; turn < SIMULATION_ITTERATIONS; turn++)
  {
    for (short fish = 0; fish < 35; fish++)

    fishArr[fish].move(Arctic);
    usleep(200000);
    cout << Arctic;
  }


  return 0;
}
