#include "hw10headder.h"

short randomDirection()
{
  short range = (RAND_DIR_UPPR - RAND_DIR_LOWR + 1);
  return rand() % range + RAND_DIR_LOWR;
}


float calcDist(const short x1, const short y1, const short x2, const short y2)
{
  float dist;
  dist = pow(x2-x1, 2) + pow(y2-y1, 2);       //calculating Euclidean distance
  dist = sqrt(dist);
  return dist;
}
