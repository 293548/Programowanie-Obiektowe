#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <iomanip>
#define N 10
using namespace std;

class Student{
    private:
        int index;
        string imie;
        string nazwisko;
    public:
        //void setline(int, string, string, vector<Student>);
        //void getline(int, string, string, vector<Student>);
        bool setIndex(int);
        bool setImie(string);
        bool setNazwisko(string);
        int getIndex();
        string getImie();
        string getNazwisko();
};

// void Student::setline(int index, string imie, string nazwisko, vector<Student> &baza){
//     if (index);
//         index
//     else
//         baza.
//     if (imie);
//     if (nazwisko);
// }

// void Student::getline(int index, string imie, string nazwisko, vector<Student> &baza){



// }

bool Student::setIndex(int nowyIndex){
    if (nowyIndex >= 0 && nowyIndex <= 999999){
        index = nowyIndex;
        return 1;
    }
    return 0;
}
bool Student::setImie(string noweImie){
    for (int i = 0; i < noweImie.length(); i++){
        if (!isalpha(noweImie[i]))
            return 0;
    }
    imie = noweImie;
    return 1;
}
bool Student::setNazwisko(string noweNazwisko){
    for (int i = 0; i < noweNazwisko.length(); i++){
        if (!isalpha(noweNazwisko[i]))
            return 0;
    }
    nazwisko = noweNazwisko;
    return 1;
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

void dodajOsobe(vector<Student> *baza, vector<bool> *obecnosc){
    if (baza->size() < N){
        Student nowaOsoba;
        int tymczasowyIndex;
        string tymczasoweImie, tymczasoweNazwisko;

        do{
            cout << "Wpisz index: ";
            cin >> tymczasowyIndex;
        }
        while 
            (nowaOsoba.setIndex(tymczasowyIndex) == 0);

        do{
            cout << "Wpisz imie: ";
            cin >> tymczasoweImie;
        }
        while
            (nowaOsoba.setImie(tymczasoweImie) == 0);

        do{
            cout << "Wpisz nazwisko: ";
            cin >> tymczasoweNazwisko;
        }
        while 
            (nowaOsoba.setNazwisko(tymczasoweNazwisko) == 0);

        baza->push_back(nowaOsoba);
        obecnosc->push_back(0);
    }
    else
        cout << "Lista jest pelna, nie mozna dodac wiecej osob." << endl;
}

void ustawObecnosc(vector<Student> *baza, vector<bool> *obecnosc){
    bool tymczasowaObecnosc;
    if (baza->size() != 0){
        for (int i = 0; i < baza->size(); i++){
            cout << "Ustaw obecnosc dla " << setfill('0') << setw(6) << baza->at(i).getIndex() << " " << baza->at(i).getImie() << " " << baza->at(i).getNazwisko() << ": ";
            cin >> tymczasowaObecnosc;
            obecnosc->at(i) = tymczasowaObecnosc;
        }
    }
    else
        cout << "Lista jest pusta." << endl;
}

void zmienDane(vector<Student> *baza){
    int index, licznik1 = -1, tymczasowyIndex;
    string tymczasoweImie, tymczasoweNazwisko;

    if (baza->size() != 0){
        cout << "Wpisz index osoby dane ktorej chcesz zmienic: ";
        cin >> index;
        for (int i = 0; i < baza->size(); i++){
            if (index == baza->at(i).getIndex()){
                licznik1 = i;
                break;
            }
        }
        if (licznik1 != -1){

            do{
                cout << "Wpisz nowy index: ";
                cin >> tymczasowyIndex;
            }
            while 
                (baza->at(licznik1).setIndex(tymczasowyIndex) == 0);
            
            do{
                cout << "Wpisz nowe imie: ";
                cin >> tymczasoweImie;
            }
            while
                (baza->at(licznik1).setImie(tymczasoweImie) == 0);

            do{
                cout << "Wpisz nowe nazwisko: ";
                cin >> tymczasoweNazwisko;
            }
            while
                (baza->at(licznik1).setNazwisko(tymczasoweNazwisko) == 0);
        }
        else
            cout << "Nieprawidlowy index." << endl;
    }
    else
        cout << "Lista jest pusta." << endl;
}

void drukujListe(vector<Student> *baza, vector<bool> *obecnosc){
    if (baza->size() != 0)
        for (int i = 0; i < baza->size(); i++)
            cout << i + 1 << ". " << setfill('0') << setw(6) << baza->at(i).getIndex() << " " << baza->at(i).getImie() << " "  << baza->at(i).getNazwisko() << " - " << (obecnosc->at(i) == 1 ? "obecny" : "nie obecny") << endl;
    else
        cout << "Lista jest pusta." << endl;
}

void usunOsobe(vector<Student> *baza, vector<bool> *obecnosc){
    int index, licznik1 = -1;

    if (baza->size() != 0){
        cout << "Wpisz index osoby ktora chcesz usunac: ";
        cin >> index;
        for (int i = 0; i < baza->size(); i++){
            if (index == baza->at(i).getIndex()){
                licznik1 = i;
                break;
            }
        }
        if (licznik1 != -1){
            for (int i = licznik1; i < baza->size() - 1; i++)
                baza->at(i) = baza->at(i + 1);
            baza->pop_back();

            for (int i = licznik1; i < obecnosc->size() - 1; i++)
                obecnosc->at(i) = obecnosc->at(i + 1);
            obecnosc->pop_back();
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
    int wybor;
    vector<Student> baza;
    vector<bool> obecnosc; 
    
    while (1){
        menu(wybor);

        switch (wybor){
            case 1:
                dodajOsobe(&baza, &obecnosc);
                break;
            case 2:
                ustawObecnosc(&baza, &obecnosc);
                break;
            case 3:
                zmienDane(&baza);
                break;
            case 4:
                drukujListe(&baza, &obecnosc);
                break;
            case 5:
                usunOsobe(&baza, &obecnosc);
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