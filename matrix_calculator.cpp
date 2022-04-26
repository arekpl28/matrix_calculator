#include <iostream>
#include <cstdlib>
#include <cmath>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

#define SMAX 10

vector<vector<int>> macierzA;
vector<vector<int>> macierzB;
vector<vector<int>> macierzC;

int wybor;
string mA = "A", mB = "B", wierszy_str = "wierszy", kolumn_str = "kolumn";
int wA = 0, kA = 0, wB = 0, kB = 0, wC = 0, kC = 0;

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

void wielkoscMacierzy(int liczba_w_k, string wier_kol)
{
  while (liczba_w_k < 2 || liczba_w_k > 10)
  {
    cout << "------------------------------------" << endl;
    cout << "Podałes nieprawidlowa liczbe " + wier_kol + "!" << endl;
    cout << "Podaj liczbe " + wier_kol + " macierzy od 2 do 10: ";
    cin >> liczba_w_k;
    wA = liczba_w_k;
    wB = liczba_w_k;
  }
}

void rozmiar_macierzy_A_B()
{
  cout << "Podaj liczbe wierszy macierzy A i B od 2 do 10: ";
  cin >> wA;
  wB = wA;
  wielkoscMacierzy(wA, wierszy_str);
  cout << "Podaj liczbe kolumn macierzy A i B od 2 do 10: ";
  cin >> kA;
  kB = kA;
  wielkoscMacierzy(kA, kolumn_str);
}

void rozmiar_macierzy(int wybor_dzialanie)
{
  if (wybor_dzialanie == 1 || wybor_dzialanie == 2)
  {
    rozmiar_macierzy_A_B();
  }
}

void uzupelnianie_macierzy(vector<vector<int>> &vec, int liczba_wierszy, int liczba_kolumn)
{
  cout << "Uzupełnij macierz liczbami: " << endl;
  vector<int> temp;
  temp.clear();
  vec.clear();
  for (int i = 0; i < liczba_wierszy; i++)
  {
    int liczba;
    for (int j = 0; j < liczba_kolumn; j++)
    {
      cin >> liczba;
      temp.push_back(liczba);
    }
    vec.push_back(temp);
    temp.clear();
  }
}

void wyswietlanie_macierzy(vector<vector<int>> &vec)
{
  for (int i = 0; i < vec.size(); i++)
  {
    for (int j = 0; j < vec[i].size(); j++)
    {
      cout << vec[i][j] << " ";
    }
    cout << endl;
  }
}

void dodawanie(vector<vector<int>> &vec_A, vector<vector<int>> &vec_B, int liczba_wierszy, int liczba_kolumn)
{
  cout << "Suma macierzy: " << endl;
  int suma = 0;
  vector<int> temp;
  macierzC.clear();
  temp.clear();
  for (int i = 0; i < liczba_wierszy; i++)
  {
    for (int j = 0; j < liczba_kolumn; j++)
    {
      suma = vec_A[i][j] + vec_B[i][j];

      temp.push_back(suma);
    }
    macierzC.push_back(temp);
    temp.clear();
  }
}
void odejmowanie(vector<vector<int>> &vec_A, vector<vector<int>> &vec_B, int liczba_wierszy, int liczba_kolumn)
{
  cout << "Roznica macierzy: " << endl;
  int suma = 0;
  vector<int> temp;
  macierzC.clear();
  temp.clear();
  for (int i = 0; i < liczba_wierszy; i++)
  {
    for (int j = 0; j < liczba_kolumn; j++)
    {
      suma = vec_A[i][j] - vec_B[i][j];

      temp.push_back(suma);
    }
    macierzC.push_back(temp);
    temp.clear();
  }
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
      rozmiar_macierzy(wybor);
      uzupelnianie_macierzy(macierzA, wA, kA);
      wyswietlanie_macierzy(macierzA);
      uzupelnianie_macierzy(macierzB, wB, kB);
      wyswietlanie_macierzy(macierzB);
      dodawanie(macierzA, macierzB, wA, kA);
      wyswietlanie_macierzy(macierzC);
      break;
    case 2:
      rozmiar_macierzy(wybor);
      uzupelnianie_macierzy(macierzA, wA, kA);
      wyswietlanie_macierzy(macierzA);
      uzupelnianie_macierzy(macierzB, wB, kB);
      wyswietlanie_macierzy(macierzB);
      odejmowanie(macierzA, macierzB, wA, kA);
      wyswietlanie_macierzy(macierzC);
      break;

    default:
      break;
    }
  } while (wybor != 0);
  return 0;
}