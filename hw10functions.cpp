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

short randQuad(const short directOne, const short directTwo, const short directThree)
{
  short direction;
  short quad;

  direction = randomNumberGen(RAND_QUAD_UPPER, RAND_QUAD_LOWER);

  switch (direction)
  {
    case 1:
      quad = directOne;
      break;
    case 2:
      quad = directTwo;
      break;
    case 3:
      quad = directThree;
      break;
    default:
      quad = randomNumberGen(RAND_DIR_UPPR_EGHT, RAND_DIR_LOWR_ONE);
  }

  return quad;
}


short superPosition(short sourcePosX, short sourcePosY,
  short targetPosX, short targetPosY)
{
  short superPosQuad = randomNumberGen(RAND_DIR_UPPR_EGHT, RAND_DIR_LOWR_ONE);

  if (targetPosX > sourcePosX && targetPosY > sourcePosY)
  {
    superPosQuad = QUAD_ONE; //Does not need to be constant as it will never change
  }
  else if (targetPosX < sourcePosX  && targetPosY > sourcePosX)
  {
    superPosQuad = QUAD_TWO;
  }
  else if (targetPosX < sourcePosX && targetPosY < sourcePosY)
  {
    superPosQuad = QUAD_THREE;
  }
  else if (targetPosX > sourcePosX && targetPosY < sourcePosX)
  {
    superPosQuad = QUAD_FOUR;
  }
  else if (targetPosX > sourcePosX && targetPosY == sourcePosY)
  {
    superPosQuad = QUAD_FIVE;
  }
  else if (targetPosX == sourcePosX && targetPosY > sourcePosY)
  {
    superPosQuad = QUAD_SIX;
  }
  else if (targetPosX < sourcePosX && targetPosY == sourcePosY)
  {
    superPosQuad = QUAD_SEVEN;
  }
  else if (targetPosX == sourcePosX && targetPosY < sourcePosY)
  {
    superPosQuad = QUAD_EIGHT;
  }

  return superPosQuad;
}

short avoidWhaleQuadAdjust(short quad)
{
  switch (quad)
  {
    case QUAD_ONE:
      quad = randQuad(QUAD_SEVEN, QUAD_THREE, QUAD_EIGHT);
      break;
    case QUAD_TWO:
      quad = randQuad(QUAD_FIVE, QUAD_FOUR, QUAD_EIGHT);
      break;
    case QUAD_THREE:
      quad = randQuad(QUAD_SIX, QUAD_ONE, QUAD_FIVE);
      break;
    case QUAD_FOUR:
      quad = randQuad(QUAD_SEVEN, QUAD_TWO, QUAD_SIX);
      break;
    case QUAD_FIVE:
      quad = randQuad(QUAD_TWO, QUAD_SEVEN, QUAD_THREE);
      break;
    case QUAD_SIX:
      quad = randQuad(QUAD_THREE, QUAD_EIGHT, QUAD_FOUR);
      break;
    case QUAD_SEVEN:
      quad = randQuad(QUAD_ONE, QUAD_FIVE, QUAD_FOUR);
      break;
    case QUAD_EIGHT:
      quad = randQuad(QUAD_TWO, QUAD_SIX, QUAD_ONE);
      break;
    default:
      quad = randomNumberGen(RAND_DIR_UPPR_EGHT, RAND_DIR_LOWR_ONE);
  }

  return quad;
}

