#include "hw10headder.h"

short randomNumberGen(const short upperBound, const short lowerBound)
{
  short range = (upperBound - lowerBound + 1);
  return rand() % range + lowerBound;
}


float calcDist(const short x1, const short y1, const short x2, const short y2)
{
  float dist;
  dist = pow(x2 - x1, 2) + pow(y2 - y1, 2);       //calculating Euclidean distance
  dist = sqrt(dist);
  return dist;
}

short superPosition(short sourcePosX, short sourcePosY,
  short targetPosX, short targetPosY)
{
  short superPosQuad;

  if (targetPosX > sourcePosX && targetPosY > sourcePosY)
  {
    superPosQuad = 1; //Does not need to be constant as it will never change
  }
  else if (targetPosX < sourcePosX  && targetPosY > sourcePosX)
  {
    superPosQuad = 2;
  }
  else if (targetPosX < sourcePosX && targetPosY < sourcePosY)
  {
    superPosQuad = 3;
  }
  else if (targetPosX > sourcePosX && targetPosY < sourcePosX)
  {
    superPosQuad = 4;
  }
  else if (targetPosx > sourcePosX && targetPosY == sourcePosY)
  {
    superPosQuad = 5;
  }
  else if (targetPosX == sourcePosX && targetPosY > sourcePosY)
  {
    superPosQuad = 6;
  }
  else if (targetPosX < sourcePosX && targetPosY == sourcePosY)
  {
    superPosQuad = 7;
  }
  else if (targetPosX == sourcePosX && targetPosY < sourcePosY)
  {
    superPosQuad = 8;
  }

  return superPosQuad;
}
