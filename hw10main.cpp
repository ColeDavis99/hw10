/*========================================================================
 *Programmers: Cole Davis & Matthew Stroble
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

  bool fishHasMoved = false;
  short fishNumAlive;
  short fishMoveAttempts; //counter


  //Create arrays of all actors
  Penguin penguinArr[MAX_PENGUINS];
  Fish fishArr[MAX_FISH];
  Whale whaleArr[MAX_WHALES];

  Sea Arctic(penguinArr, fishArr, whaleArr, PLAYABLE_SPACE);

  cout<<"Fish alive: "<<fishArr[4].getm_num_fish_alive()<<endl<<endl;

  for (short turn = 0; turn < SIMULATION_ITTERATIONS; turn++)
  {
    fishNumAlive = fishArr[0].getm_num_fish_alive();

    for (short fish = 0; fish < fishNumAlive; fish++)
    {
      fishMoveAttempts = 0;
      do
      {
        fishHasMoved = fishArr[fish].move(Arctic);
        fishMoveAttempts++;
      } while (fishHasMoved == false && fishMoveAttempts < FISH_MAX_MOVE_TRY);
    }
    usleep(200000);
    cout << Arctic;
  }


  return 0;
}
