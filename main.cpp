#include <iostream>
#include <cstdlib>
#include <cmath>
#include <iomanip>
#include <string>
#include <vector>
#include <limits>
#include "header.h"
using namespace std;

int main(void)
{
  NazwaProgramu();
  do
  {
    menu();
    switch (wybor)
    {
    case 1:
      dzialanie(wybor);
      break;
    case 2:
      dzialanie(wybor);
      break;
    case 3:
      dzialanie(wybor);
      break;
    case 4:
      dzialanie(wybor);
      break;
    default:
      break;
    }
  } while (wybor != 0);
  return 0;
}
