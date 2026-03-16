#include <iostream>
#include <string>
#include <vector>
#define N 10
using namespace std;

void dodajOsobe(string *tabNazwisko, string nazwisko, int &licznik, bool obecnosc, bool *tabObecnosc){
    if (licznik < N) {
        cout << "Wpisz nazwisko: ";
        cin >> nazwisko;
        tabNazwisko[licznik] = nazwisko;
        obecnosc = 0;
        tabObecnosc[licznik] = obecnosc;
        licznik++;
        //tabNazwisko.push_back;
    }
    else {
        cout << "Lista jest pelna, nie mozna dodac wiecej osob." << endl;
    }
}

void ustawObecnosc(string *tabNazwisko, bool *tabObecnosc, bool obecnosc, int licznik){
    if (licznik == 0)
        cout << "Lista jest pusta." << endl;
    for (int i = 0; i < licznik; i++){
        cout << "Ustaw obecnosc dla " << tabNazwisko[i] << " : ";
        cin >> obecnosc;
        tabObecnosc[i] = obecnosc;
    }
}

void drukujListe(string *tabNazwisko, bool *tabObecnosc, int licznik){
    if (licznik == 0)
        cout << "Lista jest pusta." << endl;
    for (int i = 0; i < licznik; i++){
        cout << i + 1 << ". " << tabNazwisko[i] << " - " << (tabObecnosc[i]==1?"obecny":"nie obecny") << endl;
    }
} 

void menu(int &wybor){
    cout << endl;
    cout << "========MENU========" << endl;
    cout << "1. Dodac osobe" << endl;
    cout << "2. Ustawic obecnosc" << endl;
    cout << "3. Drukowac liste" << endl;
    cout << "0. Zakoncz program" << endl;
    cout << "Twoj wybor: ";
    cin >> wybor;
    cout << endl;
}

int main(){
    int wybor, licznik = 0;
    string nazwisko;
    bool obecnosc;
    string tabNazwisko[N];
    bool tabObecnosc[N];
    //vector<string> tabNazwisko;
    //vector<bool> tabObecnosc;
    
    while (1){
        menu(wybor);

        switch (wybor){
            case 1:
                dodajOsobe(tabNazwisko, nazwisko, licznik, obecnosc, tabObecnosc);
                break;
            case 2:
                ustawObecnosc(tabNazwisko, tabObecnosc, obecnosc, licznik);
                break;
            case 3:
                drukujListe(tabNazwisko, tabObecnosc, licznik);
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