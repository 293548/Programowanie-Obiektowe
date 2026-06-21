#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <iomanip>
#define N 10
using namespace std;

class Student{
    private:
        int index = -1;
        string imie;
        string nazwisko;
    public:
        void setIndex(int);
        void setImie(string);
        void setNazwisko(string);
        int getIndex();
        string getImie();
        string getNazwisko();
};

void Student::setIndex(int nowyIndex){
    if (nowyIndex >= 0 && nowyIndex <= 999999){
        index = nowyIndex;
    }
}
void Student::setImie(string noweImie){
    bool prawidloweImie = 1;
    for (int i = 0; i < noweImie.length(); i++){
        if (!isalpha(noweImie[i])){
            prawidloweImie = 0;
            break;
        }
    }
    if (prawidloweImie)
        imie = noweImie;
}
void Student::setNazwisko(string noweNazwisko){
    bool prawidloweNazwisko = 1;
    for (int i = 0; i < noweNazwisko.length(); i++){
        if (!isalpha(noweNazwisko[i])){
            prawidloweNazwisko = 0;
            break;
        }
    }
    if (prawidloweNazwisko)
        nazwisko = noweNazwisko;
}

int Student::getIndex(){
    return index;
}
string Student::getImie(){
    return imie;
}
string Student::getNazwisko(){
    return nazwisko;
}

void dodajOsobe(Student *baza, bool *obecnosc, int &licznik){
    if (licznik < N){
        Student nowaOsoba;
        int tymczasowyIndex = -1;
        string tymczasoweImie, tymczasoweNazwisko;

        do{
            cout << "Wpisz index: ";
            cin >> tymczasowyIndex;
            nowaOsoba.setIndex(tymczasowyIndex);
        }
        while (nowaOsoba.getIndex() == -1);

        do{
            cout << "Wpisz imie: ";
            cin >> tymczasoweImie;
            nowaOsoba.setImie(tymczasoweImie);
        }
        while (nowaOsoba.getImie() == "");

        do{
            cout << "Wpisz nazwisko: ";
            cin >> tymczasoweNazwisko;
            nowaOsoba.setNazwisko(tymczasoweNazwisko);
        }
        while (nowaOsoba.getNazwisko() == "");
        
        baza[licznik] = nowaOsoba;
        obecnosc[licznik] = 0;
        licznik++;
    }
    else
        cout << "Lista jest pelna, nie mozna dodac wiecej osob." << endl;
}

void ustawObecnosc(Student *baza, bool *obecnosc, int &licznik){
    bool tymczasowaObecnosc;
    if (licznik != 0){
        for (int i = 0; i < licznik; i++){
            cout << "Ustaw obecnosc dla " << setfill('0') << setw(6) << baza[i].getIndex() << " " << baza[i].getImie() << " " << baza[i].getNazwisko() << ": ";
            cin >> tymczasowaObecnosc;
            obecnosc[i] = tymczasowaObecnosc;
        }
    }
    else
        cout << "Lista jest pusta." << endl;
}

void zmienDane(Student *baza, int &licznik){
    int index, licznik1 = -1, tymczasowyIndex = -1;
    string tymczasoweImie, tymczasoweNazwisko;

    if (licznik != 0){
        cout << "Wpisz index osoby dane ktorej chcesz zmienic: ";
        cin >> index;
        for (int i = 0; i < licznik; i++){
            if (index == baza[i].getIndex()){
                licznik1 = i;
                break;
            }
        }
        if (licznik1 != -1){

            do{
                cout << "Wpisz nowy index: ";
                cin >> tymczasowyIndex;
                baza[licznik1].setIndex(tymczasowyIndex);
            }
            while (baza[licznik1].getIndex() == -1);
            
            do{
                cout << "Wpisz nowe imie: ";
                cin >> tymczasoweImie;
                baza[licznik1].setImie(tymczasoweImie);
            }
            while (baza[licznik1].getImie() == "");

            do{
                cout << "Wpisz nowe nazwisko: ";
                cin >> tymczasoweNazwisko;
                baza[licznik1].setNazwisko(tymczasoweNazwisko);
            }
            while (baza[licznik1].getNazwisko() == "");
        }
        else
            cout << "Nieprawidlowy index." << endl;
    }
    else
        cout << "Lista jest pusta." << endl;
}

void drukujListe(Student *baza, bool *obecnosc, int &licznik){
    if (licznik != 0)
        for (int i = 0; i < licznik; i++)
            cout << i + 1 << ". " << setfill('0') << setw(6) << baza[i].getIndex() << " " << baza[i].getImie() << " "  << baza[i].getNazwisko() << " - " << (obecnosc[i] == 1 ? "obecny" : "nie obecny") << endl;
    else
        cout << "Lista jest pusta." << endl;
}

void usunOsobe(Student *baza, bool *obecnosc, int &licznik){
    int index, licznik1 = -1;

    if (licznik != 0){
        cout << "Wpisz index osoby ktora chcesz usunac: ";
        cin >> index;
        for (int i = 0; i < licznik; i++){
            if (index == baza[i].getIndex()){
                licznik1 = i;
                break;
            }
        }
        if (licznik1 != -1){
            for (int i = licznik1; i < licznik - 1; i++)
                baza[i] = baza[i + 1];

            for (int i = licznik1; i < licznik - 1; i++)
                obecnosc[i] = obecnosc[i + 1];

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
    bool obecnosc[N]; 
    
    while (1){
        menu(wybor);

        switch (wybor){
            case 1:
                dodajOsobe(baza, obecnosc, licznik);
                break;
            case 2:
                ustawObecnosc(baza, obecnosc, licznik);
                break;
            case 3:
                zmienDane(baza, licznik);
                break;
            case 4:
                drukujListe(baza, obecnosc, licznik);
                break;
            case 5:
                usunOsobe(baza, obecnosc, licznik);
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