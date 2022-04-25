#include <iostream>
#include <cstdlib>
#include <cmath>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

#define SMAX 10

int wA = 0, kA = 0, wB = 0, kB = 0, wC = 0, kC = 0, koniec = 0, wybor;
double A[SMAX][SMAX], B[SMAX][SMAX], C[SMAX][SMAX];

int main(void)
{
  do
  {
    cout << endl
         << endl;
    cout << "*****************************************" << endl;
    cout << "*          KALKULATOR MACIERZY          *" << endl;
    cout << "*****************************************" << endl
         << endl;
    cout << "-----------------  MENU  ----------------" << endl
         << endl;
    cout << "Wybierz rodzaj dzialania" << endl;
    cout << "1 - Dodawanie macierzy" << endl;
    cout << "2 - Odejmowanie macierzy" << endl;
    cout << "3 - Mnozenie macierzy" << endl;
    cout << "4 - Mnozenie macierzy przez liczbę" << endl;
  } while (koniec != 0);
  return 0;
}