#ifndef HW10HEADDER_H
#define HW10HEADDER_H

/*========================
      IMPORTS
========================*/
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>
using namespace std;

/*========================
    GLOBAL CONSTANTS
========================*/
const short SEA_PLAYABLE_MAX = 25;
const short PLAYABLE_SPACE = 17;
const short SIMULATION_ITTERATIONS = 10000;
const short RAND_DIR_UPPR = 7;
const short RAND_DIR_LOWR = 0;
const char SPACE_EMPTY = ' ';

//DO NOT CHANGE THIS!!! I WILL HUNT YOU DOWN IF YOU DO!!!!
const short BORDERS_OF_PLAY_SPACE = PLAYABLE_SPACE + 2;
const short SEA_MAX = SEA_PLAYABLE_MAX + 2;

//For "out of border" prevention
const short MIN_MOVABLE_BOUNDARY = 1;
const short MAX_MOVABLE_BOUNDARY = PLAYABLE_SPACE;
const short DOUBLE_VISION = 2;


//Penguins
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

const short PENG_VISION_RANGE = 8;
const short PENG_TARGET_DEF = PENG_VISION_RANGE + 1;
const char PENG_CHAR = 'p';


//Fishes
const short MAX_FISH = 200;
const short FISH_SPAWN_NUM = 35;
const short FOOD_VAL_LOWR = 1;
const short FOOD_VAL_UPPR = 10;
const short FISH_START_X = -1;
const short FISH_START_Y = -1;
const char FISH_CHAR = 'f';
const short ADVANCE_FISH_MOVE_BY = 1;


//Whales
const short MAX_WHALES = 2;
const short WHALE_SPAWN_NUM = 2;
const char WHALE_CHAR = 'W';




//Functions

//
//Pre:
//Post:
short randomDirection();

//
//Pre:
//Post:
float calcDist(const short x1, const short y1, const short x2, const short y2);

#endif
