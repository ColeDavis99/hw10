#include "hw10headder.h"

short randomNumberGen(const short upperBound, const short lowerBound)
{
  short range = (upperBound - lowerBround + 1);
  return rand() % range + lowerBound;
}


float calcDist(const short x1, const short y1, const short x2, const short y2)
{
  float dist;
  dist = pow(x2-x1, 2) + pow(y2-y1, 2);       //calculating Euclidean distance
  dist = sqrt(dist);
  return dist;
}
