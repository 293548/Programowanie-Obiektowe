#include <iostream>
#include <string>
#include <vector>
#define N 10
using namespace std;

struct Student{
    int index;
    string imie; 
    string nazwisko;
    bool obecnosc;
};

void dodajOsobe(Student *baza, int &licznik){
    if (licznik < N){
        cout << "Wpisz index: ";
        cin >> baza[licznik].index;
        cout << "Wpisz imie: ";
        cin >> baza[licznik].imie;
        baza[licznik].obecnosc = 0;
        cout << "Wpisz nazwisko: ";
        cin >> baza[licznik].nazwisko;
        licznik++;
        //tabNazwisko.push_back;
    }
    else
        cout << "Lista jest pelna, nie mozna dodac wiecej osob." << endl;
}

void ustawObecnosc(Student *baza, int licznik){
    if (licznik != 0){
        for (int i = 0; i < licznik; i++){
            cout << "Ustaw obecnosc dla " << baza[i].index << " " << baza[i].imie << " " << baza[i].nazwisko << ": ";
            cin >> baza[i].obecnosc;
        }
    }
    else
        cout << "Lista jest pusta." << endl;
}

void zmienDane(Student *baza, int licznik){
    int index, licznik1 = -1;
    if (licznik != 0){
        cout << "Wpisz index osoby dane ktorej chcesz zmienic: ";
        cin >> index;
        for (int i = 0; i < licznik; i++){
            if (index == baza[i].index){
                licznik1 = i;
                break;
            }
        }
        if (licznik1 != -1){
            cout << "Wpisz nowy index: ";
            cin >> baza[licznik1].index;
            cout << "Wpisz nowe imie: ";
            cin >> baza[licznik1].imie;
            cout << "Wpisz nowe nazwisko: ";
            cin >> baza[licznik1].nazwisko;
        }
        else
            cout << "Nieprawidlowy index." << endl;
    }
    else
        cout << "Lista jest pusta." << endl;
}

void drukujListe(Student *baza, int licznik){
    if (licznik != 0)
        for (int i = 0; i < licznik; i++)
            cout << i + 1 << ". " << baza[i].index << " " << baza[i].imie << " "  << baza[i].nazwisko << " - " << (baza[i].obecnosc == 1 ? "obecny" : "nie obecny") << endl;
    else
        cout << "Lista jest pusta." << endl;
}

void usunOsobe(Student *baza, int &licznik){
    int index, licznik1 = -1;
    if (licznik != 0){
        cout << "Wpisz index osoby ktora chcesz usunac: ";
        cin >> index;
        for (int i = 0; i < licznik; i++){
            if (index == baza[i].index){
                licznik1 = i;
                break;
            }
        }
        if (licznik1 != -1){
            for (int i = licznik1; i < licznik - 1; i++)
                baza[i] = baza[i + 1];
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
    Student baza[N];
    //vector<string> tabNazwisko;
    //vector<bool> tabObecnosc;
    
    while (1){
        menu(wybor);

        switch (wybor){
            case 1:
                dodajOsobe(baza, licznik);
                break;
            case 2:
                ustawObecnosc(baza, licznik);
                break;
            case 3:
                zmienDane(baza, licznik);
                break;
            case 4:
                drukujListe(baza, licznik);
                break;
            case 5:
                usunOsobe(baza, licznik);
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