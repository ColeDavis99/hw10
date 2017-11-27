#include "hw10headder.h"
#include "hw10fish.h"
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>


//Constructor
Fish::Fish()
{
  m_isAlive = false;

  short range = (FOOD_VAL_UPPR - FOOD_VAL_LOWR + 1);

  //Starting position of fish
  m_posX = FISH_START_X;
  m_posY = FISH_START_Y;

  //Sets random food value worth
  m_foodWorth = rand() % range + FOOD_VAL_LOWR;
}

bool Fish::move()
{



}


void Fish::setFishPos(const short posX, const short posY)
{
  m_posX = posX;
  m_posY = posY;
  return;
}

short Fish::getFishPosX()const
{
  return m_posX;
}

short Fish::getFishPosY()const
{
  return m_posY;
}