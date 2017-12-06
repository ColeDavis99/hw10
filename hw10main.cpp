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
  short turn = 0;
  bool fishHasMoved = false;
  bool printSea = false;
  char answer = ' ';
  short fishNumAlive;
  short fishMoveAttempts; //counter

  //Penguin variables
  short pengNumAlive;
  bool pengAllDead = false;



  //Create arrays of all actors
  Penguin penguinArr[MAX_PENGUINS];
  Fish fishArr[MAX_FISH];
  Whale whaleArr[MAX_WHALES];
  Sea Arctic(penguinArr, fishArr, whaleArr, PLAYABLE_SPACE);


  //User Promped for Printing Sea to screen
  do
  {
    cout << "Do you want to Print the Sea? (1 for yes / 0 for no) : ";
    cin >> answer;
    if (answer != '1' && answer != '0')
      cout << "INVALID INPUT: ENTER 1 OR 0" << endl;
  } while (answer != '1' && answer != '0');

  if (answer == YES)
    printSea = true;
  else
    printSea = false;

  //for (short turn = 0; turn < SIMULATION_ITTERATIONS; turn++)

  while( turn < SIMULATION_ITTERATIONS && pengAllDead == false)
  {
    //sets the fish and penguin loops to only loop through the
    //objects that are still alive.
    fishNumAlive = fishArr[ZERO].getm_num_fish_alive();
    pengNumAlive = penguinArr[ZERO].getm_num_pengs_alive();

    for (short fish = 0; fish < fishNumAlive; fish++)
    {
      fishMoveAttempts = 0;
      fishHasMoved = false;
      do
      {
        fishHasMoved = fishArr[fish].move(Arctic);
        //
        fishMoveAttempts++;
      } while (fishHasMoved == false && fishMoveAttempts < FISH_MAX_MOVE_TRY);
    }

    for (short peng = 0; peng < pengNumAlive; peng++)
    {
      penguinArr[peng].move(fishArr, Arctic);
      //Pop a new penguin from the m_num_pengs_alive index,
      //THEN increment m_num_pengs_alive
      penguinArr[peng].reincarnatePeng(Arctic, penguinArr);
    }

    for (short whale = 0; whale < MAX_WHALES; whale++)
    {
      whaleArr[whale].move(fishArr, penguinArr, Arctic);
    }


    if (printSea == true)
    {
      usleep(200000);
      cout << Arctic;
    }

    if (pengNumAlive == 0)
    {
      pengAllDead = true;
    }


    /*======================================================
              OUTPUT AFTER SINGLE LOOP
    ======================================================*/
    cout<<"NUMBER OF PENGUINS ALIVE: "<<penguinArr[ZERO].getm_num_pengs_alive()<<endl;

    //Calling fish spawn
    fishArr[ZERO].reincarnateFish(Arctic, fishArr);
    turn++;

  }//End of While Loop





  /*======================================================
          OUTPUT AFTER SIMULATION TERMINATION
  ======================================================*/
  cout << "Simulation Made: " << turn << " cycles." << endl;
  if (pengAllDead == false)
  {
    cout << "Penguins Survived: " << pengNumAlive << endl;
  }
  else
  {
    cout << "All Penguins died on Simulation cycle: " << turn << endl;
  }
  cout << "Whale One Kill Count: " << whaleArr[0].getPenguinKillCount() << endl;
  cout << "Whale Two Kill Count: " << whaleArr[1].getPenguinKillCount() << endl;


  return 0;
}
