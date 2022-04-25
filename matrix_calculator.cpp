#include <iostream>
#include <cstdlib>
#include <cmath>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

#define SMAX 10

vector<vector<double>> macierzA;
vector<double> jeden;

int wybor;
double liczba;
string mA = "A", mB = "B", wierszy = "wierszy", kolumn = "kolumn";
double wA = 0, kA = 0, wB = 0, kB = 0, wC = 0, kC = 0;

void wielkoscMacierzy(int liczba_wierszy, string wier_kol, string mA_mB)
{
  while (liczba_wierszy < 2 || liczba_wierszy > 10)
  {
    cout << "Podałes nieprawidlowa liczbe " + wier_kol + " macierzy " + mA_mB + "!" << endl;
    cout << "Podaj liczbe " + wier_kol + " macierzy " + mA_mB + " od 2 do 10: ";
    cin >> liczba_wierszy;
  }
}

int main(void)
{
  cout << endl
       << endl;
  cout << "*****************************************" << endl;
  cout << "*          KALKULATOR MACIERZY          *" << endl;
  cout << "*****************************************" << endl;
  do
  {
    cout << endl;
    cout << "-----------------  MENU  ----------------" << endl
         << endl;
    cout << "Wybierz rodzaj dzialania" << endl;
    cout << "1 - Dodawanie macierzy" << endl;
    cout << "2 - Odejmowanie macierzy" << endl;
    cout << "3 - Mnozenie macierzy" << endl;
    cout << "4 - Mnozenie macierzy przez liczbę" << endl
         << endl;
    cout << "0 - Zakoncz program" << endl
         << endl;

    ///////////////////////////////////////////////////////////////
    cin >> wybor;
    switch (wybor)
    {
    case 1:
      cout << "Podaj liczbe wierszy macierzy A od 2 do 10: ";
      cin >> wA;
      wielkoscMacierzy(wA, wierszy, mA);
      cout << "Podaj liczbe kolumn macierzy A od 2 do 10: ";
      cin >> kA;
      wielkoscMacierzy(kA, kolumn, mA);
      cout << "Podaj liczbe wierszy macierzy B od 2 do 10: ";
      cin >> wB;
      wielkoscMacierzy(wB, wierszy, mB);
      cout << "Podaj liczbe kolumn macierzy A od 2 do 10: ";
      cin >> kB;
      wielkoscMacierzy(kB, kolumn, mB);
      break;

    default:
      break;
    }
  } while (wybor != 0);
  return 0;
}