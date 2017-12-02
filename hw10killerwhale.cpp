#include "hw10headder.h"
#include "hw10killerwhale.h"
#include "hw10sea.h"


Whale::Whale()
{
  m_penguinKillCount = 0;
}

bool whaleMove()
{



}

short Whale::getPenguinKillCount()
{
  return m_penguinKillCount;
}

void Whale::setWhalePos(const short posX, const short posY)
{
  m_posX = posX;
  m_posY = posY;
  return;
}

short Whale::getWhalePosX()const
{
  return m_posX;
}

short Whale::getWhalePosY()const
{
  return m_posY;
}
