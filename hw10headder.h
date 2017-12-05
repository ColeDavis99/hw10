#ifndef HW10HEADDER_H
#define HW10HEADDER_H

/*========================
      IMPORTS
========================*/
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <unistd.h>
using namespace std;



/*========================
PLEASE ONLY EDIT THE SETTINGS
ANYTHING CHANGED BELOW THE DO
NOT EDIT LINE WILL CAUSE
ISSUES WITH THE PROGRAM.
========================*/


/*========================
       SEA SETTINGS
========================*/
const short SEA_PLAYABLE_MAX = 25;
const short PLAYABLE_SPACE = 17;
const short SIMULATION_ITTERATIONS = 10000;


/*========================
     PENGUINS SETTINGS
========================*/
const short MAX_PENGUINS = 50;
const short PENG_SPAWN_NUM = 20;
const short PENG_HEALTH_MIN = 70;
const short PENG_HEALTH_MAX = 80;
const short PENG_START_X = -1;
const short PENG_START_Y = -1;
const short PENG_HEALTH_0 = 1;
const short PENG_HEALTH_1 = 20;
const short PENG_HEALTH_2 = 40;
const short PENG_HEALTH_3 = 60;
const short PENG_HEALTH_4 = 80;
const short PENG_MOVE_MAX5 = 5;
const short PENG_MOVE_MAX4 = 4;
const short PENG_MOVE_MAX3 = 3;
const short PENG_MOVE_MAX2 = 2;
const short PENG_MOVE_MAX1 = 1;
const short PENG_MOVE_MAX0 = 0;
const short PENG_MOVE_COST = 1;

const short PENG_VISION_RANGE = 8;
const short PENG_TARGET_DEF = PENG_VISION_RANGE + 1;
const char PENG_CHAR = 'p';

/*========================
     FISH SETTINGS
========================*/
const short MAX_FISH = 200; //Default to 200
const short FISH_SPAWN_NUM = 35; //Default to 35
const short FOOD_VAL_LOWR = 1;
const short FOOD_VAL_UPPR = 10;
const short FISH_START_X = -1;
const short FISH_START_Y = -1;
const char FISH_CHAR = 'f';

const short FISH_MAX_MOVE_TRY = 7;
const bool SET_FISH_LIVING = false;

/*========================
     WHALE SETTINGS
========================*/
const short MAX_WHALES = 2;
const short WHALE_SPAWN_NUM = 2;
const short WHALE_MOVE_PER_TURN = 3;
const char WHALE_CHAR = 'w';
const short WHALE_VISION_RANGE = PLAYABLE_SPACE;


/*========================
     DEBUG PRINTING
========================*/
const bool FISH_DEBUG = false;
const bool PENG_DEBUG = false;
const bool WHALE_DEBUG = false;


//DO NOT CHANGE ANYTHING BELOW THIS LINE!!! I WILL HUNT YOU DOWN IF YOU DO!!!!

/*========================
    GLOBAL CONSTANTS
========================*/
const short RAND_DIR_UPPR = 7;
const short RAND_DIR_UPPR_EGHT = 8;
const short RAND_DIR_LOWR = 0;
const short RAND_DIR_LOWR_ONE = 1;
const short ZERO = 0;
const char SPACE_EMPTY = ' ';
const short ADVANCE_ACTOR_MOVE = 1;
const short MAX_MOVE_ATTMPTS = 7;
const short RAND_QUAD_UPPER = 3;
const short RAND_QUAD_LOWER = 1;

const short QUAD_ONE = 1;
const short QUAD_TWO = 2;
const short QUAD_THREE = 3;
const short QUAD_FOUR = 4;
const short QUAD_FIVE = 5;
const short QUAD_SIX = 6;
const short QUAD_SEVEN = 7;
const short QUAD_EIGHT = 8;

const short BORDERS_OF_PLAY_SPACE = PLAYABLE_SPACE + 2;
const short SEA_MAX = SEA_PLAYABLE_MAX + 2;

//For "out of border" prevention
const short MIN_MOVABLE_BOUNDARY = 1;
const short MAX_MOVABLE_BOUNDARY = PLAYABLE_SPACE;
const short DOUBLE_VISION = 2;

const char YES = '1';
const char NO = '0';


/*========================
        FUNCTIONS
========================*/

//Generates a random number between the upper and lower boundry thats
//passed to it
//Pre: None
//Post: Returns a random generated number.
short randomNumberGen(const short upperBound, const short lowerBound);

//calculated the distance between the calling object and targets location
//Pre: All arguments are within bounds of PLAYABLE_SPACE
//Post: returns the distance to target.
float calcDist(const short x1, const short y1, const short x2, const short y2);


/*
Description: Randomly select between three possable directions to move
Pre: Must have at the three directions to select between
Post: returns a quadrent to move to.
*/
short randQuad(const short directOne, const short directTwo,
  const short directThree);

/*
Determins the Quadrent of the target by the super possition of the
source object.
Pre: Source and Target  object must exist in SeaGrid
Post: Returns what Quadrent the target is in.
*/
short superPosition(short sourcePosX, short sourcePosY,
  short targetPosX, short targetPosY);


/*
Description: Flips target direction to avoid the target
//Pre: Must have fount a target to avoid
//Post: Returns a random direction away from the target
*/
short avoidWhaleQuadAdjust(short quad);


#endif
