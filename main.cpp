#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <iomanip>
#define N 10
using namespace std;

class Osoba{
    private:
        string imie;
        string nazwisko;
    public:
        void setImie(string);
        void setNazwisko(string);
        string getImie();
        string getNazwisko();
};

class Student : public Osoba{
    private:
        int index = -1;
    public:
        void setIndex(int);
        int getIndex();
};

class ListaObecnosci{
    private:
        int licznik = 0;
        Student *baza[N];
        bool obecnosc[N]; 
    public:
        void dodajOsobe(Student*);
        void ustawObecnosc();
        void zmienDane();
        void drukujListe();
        void usunOsobe();
};

class Interfejs{
    private:
        Student wszyscyStudenci[N];
        int wybor, licznikStudentow = 0;
        ListaObecnosci *listaAktywna;
        ListaObecnosci Analiza1;
        ListaObecnosci PPO;
    public:
        void wprowadzNowegoStudenta();
        void wybierzListe();
        void menu();
        int uruchom();
};

void Student::setIndex(int nowyIndex){
    if (nowyIndex >= 0 && nowyIndex <= 999999){
        index = nowyIndex;
    }
}
void Osoba::setImie(string noweImie){
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
void Osoba::setNazwisko(string noweNazwisko){
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
string Osoba::getImie(){
    return imie;
}
string Osoba::getNazwisko(){
    return nazwisko;
}

void Interfejs::wprowadzNowegoStudenta(){
        int tymczasowyIndex = -1;
        string tymczasoweImie, tymczasoweNazwisko;

        do{
            cout << "Wpisz index: ";
            cin >> tymczasowyIndex;
            wszyscyStudenci[licznikStudentow].setIndex(tymczasowyIndex);
        }
        while (wszyscyStudenci[licznikStudentow].getIndex() == -1);

        do{
            cout << "Wpisz imie: ";
            cin >> tymczasoweImie;
            wszyscyStudenci[licznikStudentow].setImie(tymczasoweImie);
        }
        while (wszyscyStudenci[licznikStudentow].getImie() == "");

        do{
            cout << "Wpisz nazwisko: ";
            cin >> tymczasoweNazwisko;
            wszyscyStudenci[licznikStudentow].setNazwisko(tymczasoweNazwisko);
        }
        while (wszyscyStudenci[licznikStudentow].getNazwisko() == "");
        
        listaAktywna->dodajOsobe(&wszyscyStudenci[licznikStudentow]);
        licznikStudentow++;
}

void ListaObecnosci::dodajOsobe(Student *nowyStudent){
    if (licznik < N){
        baza[licznik] = nowyStudent;
        obecnosc[licznik] = 0;       
        licznik++;                   
    }
    else
        cout << "Lista jest pelna, nie mozna dodac wiecej osob." << endl;
}

void ListaObecnosci::ustawObecnosc(){
    bool tymczasowaObecnosc;
    if (licznik != 0){
        for (int i = 0; i < licznik; i++){
            cout << "Ustaw obecnosc dla " << setfill('0') << setw(6) << baza[i]->getIndex() << " " << baza[i]->getImie() << " " << baza[i]->getNazwisko() << ": ";
            cin >> tymczasowaObecnosc;
            obecnosc[i] = tymczasowaObecnosc;
        }
    }
    else
        cout << "Lista jest pusta." << endl;
}

void ListaObecnosci::zmienDane(){
    int index, licznik1 = -1, tymczasowyIndex = -1;
    string tymczasoweImie, tymczasoweNazwisko;

    if (licznik != 0){
        cout << "Wpisz index osoby dane ktorej chcesz zmienic: ";
        cin >> index;
        for (int i = 0; i < licznik; i++){
            if (index == baza[i]->getIndex()){
                licznik1 = i;
                break;
            }
        }
        if (licznik1 != -1){

            do{
                cout << "Wpisz nowy index: ";
                cin >> tymczasowyIndex;
                baza[licznik1]->setIndex(tymczasowyIndex);
            }
            while (baza[licznik1]->getIndex() == -1);
            
            do{
                cout << "Wpisz nowe imie: ";
                cin >> tymczasoweImie;
                baza[licznik1]->setImie(tymczasoweImie);
            }
            while (baza[licznik1]->getImie() == "");

            do{
                cout << "Wpisz nowe nazwisko: ";
                cin >> tymczasoweNazwisko;
                baza[licznik1]->setNazwisko(tymczasoweNazwisko);
            }
            while (baza[licznik1]->getNazwisko() == "");
        }
        else
            cout << "Nieprawidlowy index." << endl;
    }
    else
        cout << "Lista jest pusta." << endl;
}

void ListaObecnosci::drukujListe(){
    if (licznik != 0)
        for (int i = 0; i < licznik; i++)
            cout << i + 1 << ". " << setfill('0') << setw(6) << baza[i]->getIndex() << " " << baza[i]->getImie() << " "  << baza[i]->getNazwisko() << " - " << (obecnosc[i] == 1 ? "obecny" : "nie obecny") << endl;
    else
        cout << "Lista jest pusta." << endl;
}

void ListaObecnosci::usunOsobe(){
    int index, licznik1 = -1;

    if (licznik != 0){
        cout << "Wpisz index osoby ktora chcesz usunac: ";
        cin >> index;
        for (int i = 0; i < licznik; i++){
            if (index == baza[i]->getIndex()){
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

void Interfejs::wybierzListe(){
    int wybor;

    cout << "1. Analiza 1." << endl;
    cout << "2. PPO." << endl;
    cout << "Wpisz numer listy z ktora chcesz dzialac: ";
    cin >> wybor;

    switch (wybor){
            case 1:
                listaAktywna = &Analiza1;
                break;
            case 2:
                listaAktywna = &PPO;
                break;
            default:
                cout << "Wystapil blad!" << endl;
                break;
    }
}

void Interfejs::menu(){
    cout << endl;
    cout << "========MENU========" << endl;
    cout << "1. Dodac osobe." << endl;
    cout << "2. Ustawic obecnosc." << endl;
    cout << "3. Zmienic dane." << endl;
    cout << "4. Drukowac liste." << endl;
    cout << "5. Usunac osobe." << endl;
    cout << "6. Zmien liste." << endl;
    cout << "0. Zakoncz program." << endl;
    cout << "Twoj wybor: ";
    cin >> wybor;
    cout << endl;
}

int Interfejs::uruchom(){
    listaAktywna = &Analiza1;

    while (1){
        menu();

        switch (wybor){
            case 1:
                wprowadzNowegoStudenta();
                break;
            case 2:
                listaAktywna->ustawObecnosc();
                break;
            case 3:
                listaAktywna->zmienDane();
                break;
            case 4:
                listaAktywna->drukujListe();
                break;
            case 5:
                listaAktywna->usunOsobe();
                break;
            case 6:
                wybierzListe();
                break;
            case 0: 
                return 0;
                break;
            default:
                cout << "Wystapil blad!" << endl;
                break;
        }
    }
}

int main(){

    Interfejs program;
    program.uruchom();
    
    return 0;
}