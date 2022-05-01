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

int wybor, max_liczba_A_B = 0, min_liczba_A_B = 0, mnoznik = 0;
string mA = "A", mB = "B", wierszy_str = "wierszy", kolumn_str = "kolumn";
int wA = 0, kA = 0, wB = 0, kB = 0, wC = 0, kC = 0;

void blad_wybory()
{
  cout << "Brak podanego działania! Prosze wybrac inny:  ";
  cin >> wybor;
  if (wybor < 0 || wybor > 4)
  {
    blad_wybory();
  }

  cout << endl;
}

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
    blad_wybory();
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

void rozmiar_macierzy_A_B(int &wybor)
{
  if (wybor == 1 || wybor == 2)
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
  else if (wybor == 3)
  {
    cout << "Podaj liczbe wierszy macierzy A od 2 do 10: ";
    cin >> wA;
    wielkoscMacierzy(wA, wierszy_str);
    cout << "Podaj liczbe kolumn macierzy A oraz wierszy macierzy B od 2 do 10: ";
    cin >> kA;
    wB = kA;
    wielkoscMacierzy(kA, kolumn_str);
    cout << "Podaj liczbe kolumn macierzy B od 2 do 10: ";
    cin >> kB;
    wielkoscMacierzy(kB, kolumn_str);
  }
  else if (wybor == 4)
  {
    cout << "Podaj liczbe wierszy macierzy A od 2 do 10: ";
    cin >> wA;
    wielkoscMacierzy(wA, wierszy_str);
    cout << "Podaj liczbe kolumn macierzy A od 2 do 10: ";
    cin >> kA;
    wielkoscMacierzy(kA, kolumn_str);
    cout << "Podaj liczbe przez ktora chcesz pomozyc macierz: ";
    cin >> mnoznik;
  }
}

void rozmiar_macierzy(int wybor_dzialanie)
{
  if (wybor_dzialanie == 1 || wybor_dzialanie == 2)
  {
    rozmiar_macierzy_A_B(wybor);
  }
  else if (wybor_dzialanie == 3)
  {
    rozmiar_macierzy_A_B(wybor);
  }
  else if (wybor_dzialanie == 4)
  {
    rozmiar_macierzy_A_B(wybor);
  }
}

void uzupelnianie_macierzy(vector<vector<int>> &vec, int liczba_wierszy, int liczba_kolumn, string nazwa_macierzy)
{
  cout << "Uzupełnij macierz " << nazwa_macierzy << " liczbami: " << endl;
  vector<int> temp;
  temp.clear();
  vec.clear();
  for (int i = 0; i < liczba_wierszy; i++)
  {
    int liczba;
    for (int j = 0; j < liczba_kolumn; j++)
    {
      cin >> liczba;
      if (max_liczba_A_B < liczba)
      {
        max_liczba_A_B = liczba;
      }
      temp.push_back(liczba);
    }
    vec.push_back(temp);
    temp.clear();
  }
}

void wyswietlanie_macierzy(vector<vector<int>> &vec)
{
  cout << endl;
  for (int i = 0; i < vec.size(); i++)
  {
    for (int j = 0; j < vec[i].size(); j++)
    {
      if (vec[i][j] < 0)
      {
        cout << vec[i][j] << " ";
      }

      else if (max_liczba_A_B < 10 && max_liczba_A_B > 0)
      {
        if (min_liczba_A_B < 0)
        {
          cout << " ";
        }
        cout << vec[i][j] << "  ";
      }
      else if (max_liczba_A_B > 9 && max_liczba_A_B < 100 && vec[i][j] < 10)
      {
        cout << vec[i][j] << "   ";
      }
      else if (max_liczba_A_B > 9 && max_liczba_A_B < 100 && vec[i][j] > 9)
      {
        cout << vec[i][j] << "  ";
      }
      else if (max_liczba_A_B > 99 && max_liczba_A_B < 1000 && vec[i][j] < 10)
      {
        cout << vec[i][j] << "    ";
      }
      else if (max_liczba_A_B > 99 && max_liczba_A_B < 1000 && vec[i][j] > 9 && vec[i][j] < 100)
      {
        cout << vec[i][j] << "   ";
      }
      else if (max_liczba_A_B > 99 && max_liczba_A_B < 1000 && vec[i][j] > 99 && vec[i][j] < 1000)
      {
        cout << vec[i][j] << "  ";
      }
    }
    cout << endl;
  }
  max_liczba_A_B = 0;
  cout << endl;
}

void dodawanie(int liczba_wierszy, int liczba_kolumn)
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
      suma = macierzA[i][j] + macierzB[i][j];
      if (max_liczba_A_B < suma)
      {
        max_liczba_A_B = suma;
      }
      temp.push_back(suma);
    }
    macierzC.push_back(temp);
    temp.clear();
  }
}
void odejmowanie(int liczba_wierszy, int liczba_kolumn)
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
      suma = macierzA[i][j] - macierzB[i][j];
      if (max_liczba_A_B < suma)
      {
        max_liczba_A_B = suma;
      }
      else if (min_liczba_A_B > suma)
      {
        min_liczba_A_B = suma;
      }
      temp.push_back(suma);
    }
    macierzC.push_back(temp);
    temp.clear();
  }
}
void mnozenie_macierzy(int liczba_wierszy_A, int liczba_kolumn_A, int liczba_wierszy_B, int liczba_kolumn_B)
{
  cout << "Iloczyn macierzy: " << endl;
  int suma = 0;
  vector<int> temp;
  macierzC.clear();
  temp.clear();
  for (int i = 0; i < liczba_wierszy_A; i++)
  {
    for (int j = 0; j < liczba_kolumn_B; j++)
    {
      suma = 0;
      for (int k = 0; k < liczba_wierszy_B; k++)
      {
        suma += macierzA[i][k] * macierzB[k][j];
        if (max_liczba_A_B < suma)
        {
          max_liczba_A_B = suma;
        }
      }
      temp.push_back(suma);
    }
    macierzC.push_back(temp);
    temp.clear();
  }
}
void mnozenie_przez_liczbe(int liczba_wierszy, int liczba_kolumn)
{
  cout << "Macierz pomnozona przez liczbe: " << mnoznik << endl;
  int suma = 0;
  vector<int> temp;
  macierzC.clear();
  temp.clear();
  for (int i = 0; i < liczba_wierszy; i++)
  {
    for (int j = 0; j < liczba_kolumn; j++)
    {
      suma = 0;
      suma = macierzA[i][j] * mnoznik;
      temp.push_back(suma);
      if (max_liczba_A_B < suma)
      {
        max_liczba_A_B = suma;
      }
    }
    macierzC.push_back(temp);
    temp.clear();
  }
}
void dzialanie(int rodzaj_dzialania)
{
  rozmiar_macierzy(rodzaj_dzialania);
  uzupelnianie_macierzy(macierzA, wA, kA, mA);
  wyswietlanie_macierzy(macierzA);
  if (rodzaj_dzialania != 4)
  {
    uzupelnianie_macierzy(macierzB, wB, kB, mB);
    wyswietlanie_macierzy(macierzB);
  }
  if (rodzaj_dzialania == 1)
  {
    dodawanie(wA, kA);
  }
  else if (rodzaj_dzialania == 2)
  {
    odejmowanie(wA, kA);
  }
  else if (rodzaj_dzialania == 3)
  {
    mnozenie_macierzy(wA, kA, wB, kB);
  }
  else if (rodzaj_dzialania == 4)
  {
    mnozenie_przez_liczbe(wA, kA);
  }
  wyswietlanie_macierzy(macierzC);
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