#include "hw10headder.h"

short randomDirection()
{
  short range = (RAND_DIR_UPPR - RAND_DIR_LOWR + 1);
  return rand() % range + RAND_DIR_LOWR;
}
