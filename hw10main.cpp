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

  bool pengHasMoved = false;
  bool pengFoundTarget = false;
  short pengNumAlive;
  short pengDistToMove;
  short pengMoveAttempts;


  //Create arrays of all actors
  Penguin penguinArr[MAX_PENGUINS];
  Fish fishArr[MAX_FISH];
  Whale whaleArr[MAX_WHALES];

  Sea Arctic(penguinArr, fishArr, whaleArr, PLAYABLE_SPACE);

  cout<<"Fish alive: "<<fishArr[4].getm_num_fish_alive()<<endl<<endl;

  for (short turn = 0; turn < SIMULATION_ITTERATIONS; turn++)
  {
    fishNumAlive = fishArr[0].getm_num_fish_alive();
    pengNumAlive = penguinArr[0].getm_num_pengs_alive();

    for (short fish = 0; fish < fishNumAlive; fish++)
    {
      fishMoveAttempts = 0;
      fishHasMoved = false;
      do
      {
        fishHasMoved = fishArr[fish].move(Arctic);
        fishMoveAttempts++;
      } while (fishHasMoved == false && fishMoveAttempts < FISH_MAX_MOVE_TRY);

    }

    for (short peng = 0; peng < pengNumAlive; peng++)
    {
      pengMoveAttempts = 0;
      pengHasMoved = false;
      pengFoundTarget = false;
      pengDistToMove = penguinArr[peng].distToMove();

      pengFoundTarget = penguinArr[peng].pengFoundTarget(Arctic);

      do
      {
        pengHasMoved = penguinArr[peng].move(pengDistToMove, fishArr, Arctic, pengFoundTarget);
        pengMoveAttempts++;
      } while ( pengHasMoved == false && pengMoveAttempts < PENG_MAX_MOVE_TRY);

      //fall back on sequance logic
      if (pengHasMoved == false)
      {

      }
    }


    usleep(200000);
    cout << Arctic;
  }


  return 0;
}
