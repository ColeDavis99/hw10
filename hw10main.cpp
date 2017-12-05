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
  bool printSea = false;
  short fishNumAlive;
  short fishMoveAttempts; //counter

  bool pengHasMoved = false;
  bool pengFoundTarget = false;
  short pengNumAlive;
  short pengDistToMove;
  short pengMoveAttempts;

  bool whaleHasMoved = false;
  bool whaleFoundTarget;
  short whaleDistToMove;
  short whaleMoveAttempts;


  //Create arrays of all actors
  Penguin penguinArr[MAX_PENGUINS];
  Fish fishArr[MAX_FISH];
  Whale whaleArr[MAX_WHALES];

  Sea Arctic(penguinArr, fishArr, whaleArr, PLAYABLE_SPACE);

  cout<<"Fish alive: "<<fishArr[4].getm_num_fish_alive()<<endl<<endl;

  cout << "Do you want to Print the Sea? (1 for yes / 0 for no) : ";
  cin >> printSea;
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
      pengHasMoved = penguinArr[peng].move(pengDistToMove, fishArr, Arctic, pengFoundTarget);
    }

    for (short whale = 0; whale < MAX_WHALES; whale++)
    {
      whaleMoveAttempts = 0;
      whaleHasMoved = false;
      whaleFoundTarget = false;
      whaleDistToMove = whaleArr[whale].distToMove();

      whaleFoundTarget = whaleArr[whale].whaleFoundTarget(Arctic);
      whaleHasMoved = whaleArr[whale].move(whaleDistToMove, fishArr, penguinArr, Arctic, whaleFoundTarget);
    }

    usleep(200000);
    if (printSea == true)
    {
      cout << Arctic;
    }
  }


  return 0;
}
