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
string mA = "A", mB = "B", wierszy_str = "wierszy", kolumn_str = "kolumn";
double wA = 0, kA = 0, wB = 0, kB = 0, wC = 0, kC = 0;

void menu()
{

  cout << " ________________  MENU  ________________ " << endl
       << "|                                        |"
       << endl;
  cout << "|  1 - Dodawanie macierzy                |" << endl;
  cout << "|  2 - Odejmowanie macierzy              |" << endl;
  cout << "|  3 - Mnozenie macierzy                 |" << endl;
  cout << "|  4 - Mnozenie macierzy przez liczbę    |" << endl
       << "|                                        |"
       << endl;
  cout << "|  0 - Zakoncz program                   |" << endl
       << "|________________________________________|"
       << endl
       << endl;
  cout << "Wybierz rodzaj dzialania: ";
  cin >> wybor;
  cout << endl;
  if (wybor < 0 || wybor > 4)
  {
    cout << "Brak podanego działania! Prosze wybrac inny:  ";
    cin >> wybor;
    cout << endl;
  }
}

void wielkoscMacierzy(int liczba_w_k, string wier_kol, string mA_mB)
{
  while (liczba_w_k < 2 || liczba_w_k > 10)
  {
    cout << "------------------------------------" << endl;
    cout << "Podałes nieprawidlowa liczbe " + wier_kol + " macierzy " + mA_mB + "!" << endl;
    cout << "Podaj liczbe " + wier_kol + " macierzy " + mA_mB + " od 2 do 10: ";
    cin >> liczba_w_k;
  }
}

void rozmiar_macierzy_A_B(string mA_mB)
{
  cout << "Podaj liczbe wierszy macierzy " + mA_mB + " od 2 do 10: ";
  if (mA_mB == mA)
  {
    cin >> wA;
    wielkoscMacierzy(wA, wierszy_str, mA);
  }
  else if (mA_mB == mB)
  {
    cin >> wB;
    wielkoscMacierzy(wB, wierszy_str, mB);
  }
  cout << "Podaj liczbe kolumn macierzy " + mA_mB + " od 2 do 10: ";
  if (mA_mB == mA)
  {
    cin >> kA;
    wielkoscMacierzy(kA, kolumn_str, mA);
  }
  else if (mA_mB == mB)
  {
    cin >> kB;
    wielkoscMacierzy(kB, kolumn_str, mB);
  }
}

void rozmiar_macierzy()
{
  rozmiar_macierzy_A_B(mA);
  rozmiar_macierzy_A_B(mB);
}

int main(void)
{
  cout << endl
       << endl;
  cout << "*****************************************" << endl;
  cout << "*          KALKULATOR MACIERZY          *" << endl;
  cout << "*****************************************" << endl;
  cout << endl;

  do
  {
    menu();
    switch (wybor)
    {
    case 1:
      rozmiar_macierzy();
      break;

    default:
      break;
    }
  } while (wybor != 0);
  return 0;
}