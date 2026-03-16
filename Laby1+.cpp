#include <iostream>
#include <string>
#include <vector>
#define N 10
using namespace std;

void dodajOsobe(int *tabIndex, string *tabImie, string *tabNazwisko, bool *tabObecnosc, int &licznik){
    if (licznik < N){
        cout << "Wpisz index: ";
        cin >> tabIndex[licznik];
        cout << "Wpisz imie: ";
        cin >> tabImie[licznik];
        tabObecnosc[licznik] = 0;
        cout << "Wpisz nazwisko: ";
        cin >> tabNazwisko[licznik];
        licznik++;
        //tabNazwisko.push_back;
    }
    else
        cout << "Lista jest pelna, nie mozna dodac wiecej osob." << endl;
}

void ustawObecnosc(int *tabIndex, string *tabImie, string *tabNazwisko, bool *tabObecnosc, int licznik){
    if (licznik != 0){
        for (int i = 0; i < licznik; i++){
            cout << "Ustaw obecnosc dla " << tabIndex[i] << " " << tabImie[i] << " " << tabNazwisko[i] << ": ";
            cin >> tabObecnosc[i];
        }
    }
    else
        cout << "Lista jest pusta." << endl;
}

void zmienDane(int *tabIndex, string *tabImie, string *tabNazwisko, int licznik){
    int index, licznik1 = -1;
    if (licznik != 0){
        cout << "Wpisz index osoby dane ktorej chcesz zmienic: ";
        cin >> index;
        for (int i = 0; i < licznik; i++){
            if (index == tabIndex[i]){
                licznik1 = i;
                break;
            }
        }
        if (licznik1 != -1){
            cout << "Wpisz nowy index: ";
            cin >> tabIndex[licznik1];
            cout << "Wpisz nowe imie: ";
            cin >> tabImie[licznik1];
            cout << "Wpisz nowe nazwisko: ";
            cin >> tabNazwisko[licznik1];
        }
        else
            cout << "Nieprawidlowy index." << endl;
    }
    else
        cout << "Lista jest pusta." << endl;
}

void drukujListe(int *tabIndex, string *tabImie, string *tabNazwisko, bool *tabObecnosc, int licznik){
    if (licznik != 0)
        for (int i = 0; i < licznik; i++)
            cout << i + 1 << ". " << tabIndex[i] << " " << tabImie[i] << " "  << tabNazwisko[i] << " - " << (tabObecnosc[i]==1?"obecny":"nie obecny") << endl;
    else
        cout << "Lista jest pusta." << endl;
}

void usunOsobe(int *tabIndex, string *tabImie, string *tabNazwisko, bool *tabObecnosc, int &licznik){
    int index, licznik1 = -1;
    if (licznik != 0){
        cout << "Wpisz index osoby ktora chcesz usunac: ";
        cin >> index;
        for (int i = 0; i < licznik; i++){
            if (index == tabIndex[i]){
                licznik1 = i;
                break;
            }
        }
        if (licznik1 != -1){
            for (int i = licznik1; i < licznik - 1; i++){
                tabIndex[i] = tabIndex[i + 1];
                tabImie[i] = tabImie[i + 1];
                tabNazwisko[i] = tabNazwisko[i + 1];
                tabObecnosc[i] = tabObecnosc[i + 1];
            }
            licznik--;
        }
        else
            cout << "Nieprawidlowy index." << endl;
    }
    else
        cout << "Lista jest pusta." << endl;
}

void menu(int &wybor){
    cout << endl;
    cout << "========MENU========" << endl;
    cout << "1. Dodac osobe." << endl;
    cout << "2. Ustawic obecnosc." << endl;
    cout << "3. Zmienic dane." << endl;
    cout << "4. Drukowac liste." << endl;
    cout << "5. Usunac osobe." << endl;
    cout << "0. Zakoncz program." << endl;
    cout << "Twoj wybor: ";
    cin >> wybor;
    cout << endl;
}

int main(){
    int wybor, licznik = 0;
    int tabIndex[N];
    string tabImie[N], tabNazwisko[N];
    bool tabObecnosc[N];
    //vector<string> tabNazwisko;
    //vector<bool> tabObecnosc;
    
    while (1){
        menu(wybor);

        switch (wybor){
            case 1:
                dodajOsobe(tabIndex, tabImie, tabNazwisko, tabObecnosc, licznik);
                break;
            case 2:
                ustawObecnosc(tabIndex, tabImie, tabNazwisko, tabObecnosc, licznik);
                break;
            case 3:
                zmienDane(tabIndex, tabImie, tabNazwisko, licznik);
                break;
            case 4:
                drukujListe(tabIndex, tabImie, tabNazwisko, tabObecnosc, licznik);
                break;
            case 5:
                usunOsobe(tabIndex, tabImie, tabNazwisko, tabObecnosc, licznik);
                break;
            case 0: 
                return 0;
                break;
            default:
                cout << "Wystapil blad!" << endl;
                break;
        }
    }
    return 0;
}