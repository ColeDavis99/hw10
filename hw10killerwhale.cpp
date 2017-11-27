#include "hw10headder.h"
#include "hw10killerwhale.h"

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

short Whale::getWhalePosX()
{
  return m_posX;
}

short Whale::getWhalePosY()
{
  return m_posY;
}