#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <iomanip>
#define N 10
using namespace std;

class IPrzedstawialny {
    public:

    virtual string przedstawSie() = 0;
};

class Osoba{
    protected:
        string imie;
        string nazwisko;
    public:
        virtual ~Osoba() = default;
        void setImie(string);
        void setNazwisko(string);
        string getImie();
        string getNazwisko();
};

class Student : public Osoba, public IPrzedstawialny{
    private:
        int index = -1;
    public:
    string przedstawSie() override {
        return "STUDENT " + imie + " " + nazwisko; 
    }
        void setIndex(int);
        int getIndex();
};

class Pracownik : public Osoba, public IPrzedstawialny{
    private:
        
    public:
    string przedstawSie() override {
        return "PRACOWNIK " + imie + " " + nazwisko; 
    }
};

class ListaObecnosci{
    private:
        int licznik = 0;
        Osoba *baza[N];
        bool obecnosc[N]; 
    public:
        ~ListaObecnosci() {
            for (int i = 0; i < licznik; i++) {
                delete baza[i];
            }
        }
        void dodajOsobe(Osoba*);
        void ustawObecnosc();
        void zmienDane();
        void drukujListe();
        void usunOsobe();
};

class Interfejs{
    private:
        int wybor;
        ListaObecnosci *listaAktywna;
        ListaObecnosci Analiza1;
        ListaObecnosci PPO;
    public:
        void wprowadzNowaOsobe();
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

void Interfejs::wprowadzNowaOsobe(){
        int tymczasowyIndex = -1, typ;
        string tymczasoweImie, tymczasoweNazwisko;

        cout << "Kogo chcesz dodac? (1 - Student, 2 - Pracownik): ";
        cin >> typ;

        if (typ == 1) {
            Student* nowyStudent = new Student(); 
            do{
                cout << "Wpisz index: ";
                cin >> tymczasowyIndex;
                nowyStudent->setIndex(tymczasowyIndex);
            }
            while (nowyStudent->getIndex() == -1);

            do{
                cout << "Wpisz imie: ";
                cin >> tymczasoweImie;
                nowyStudent->setImie(tymczasoweImie);
            }
            while (nowyStudent->getImie() == "");

            do{
                cout << "Wpisz nazwisko: ";
                cin >> tymczasoweNazwisko;
                nowyStudent->setNazwisko(tymczasoweNazwisko);
            }
            while (nowyStudent->getNazwisko() == "");
            listaAktywna->dodajOsobe(nowyStudent); 
        }
        else if (typ == 2){
            Pracownik* nowyPracownik = new Pracownik(); 
            do{
                cout << "Wpisz imie: ";
                cin >> tymczasoweImie;
                nowyPracownik->setImie(tymczasoweImie);
            }
            while (nowyPracownik->getImie() == "");

            do{
                cout << "Wpisz nazwisko: ";
                cin >> tymczasoweNazwisko;
                nowyPracownik->setNazwisko(tymczasoweNazwisko);
            }
            while (nowyPracownik->getNazwisko() == "");
            listaAktywna->dodajOsobe(nowyPracownik);
        }
        else 
            cout << "Nieznany wybor!" << endl;
}

void ListaObecnosci::dodajOsobe(Osoba *nowaOsoba){
    if (licznik < N){
        baza[licznik] = nowaOsoba;
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
            Student* potencjalnyStudent = dynamic_cast<Student*>(baza[i]);
            if (potencjalnyStudent != nullptr)
                cout << "Ustaw obecnosc dla " << setfill('0') << setw(6) << potencjalnyStudent->getIndex() << " " << baza[i]->getImie() << " " << baza[i]->getNazwisko() << ": ";
            else
                cout << "Ustaw obecnosc dla " << "------" << baza[i]->getImie() << " " << baza[i]->getNazwisko() << ": ";
            cin >> tymczasowaObecnosc;
            obecnosc[i] = tymczasowaObecnosc;
        }
    }
    else
        cout << "Lista jest pusta." << endl;
}

void ListaObecnosci::zmienDane(){
    int licznik1 = -1, tymczasowyIndex = -1;
    string tymczasoweImie, tymczasoweNazwisko, nazwisko;

    if (licznik != 0){
        cout << "Wpisz nazwisko osoby dane ktorej chcesz zmienic: ";
        cin >> nazwisko;
        for (int i = 0; i < licznik; i++){
            if (nazwisko == baza[i]->getNazwisko()){
                licznik1 = i;
                break;
            }
        }
        if (licznik1 != -1){
            Student* potencjalnyStudent = dynamic_cast<Student*>(baza[licznik1]);
            if (potencjalnyStudent != nullptr) {
                do{
                    cout << "Wpisz nowy index: ";
                    cin >> tymczasowyIndex;
                    potencjalnyStudent->setIndex(tymczasowyIndex);
                }
                while (potencjalnyStudent->getIndex() == -1);
            }
            
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
            for (int i = 0; i < licznik; i++) {
                Student* potencjalnyStudent = dynamic_cast<Student*>(baza[i]);
                IPrzedstawialny* obiektPrzedstawialny = dynamic_cast<IPrzedstawialny*>(baza[i]);
                cout << i + 1 << ". ";
                if (potencjalnyStudent != nullptr) 
                    cout << setfill('0') << setw(6) << potencjalnyStudent->getIndex() << " "; 
                else
                    cout << "------" << " "; 
                if (obiektPrzedstawialny != nullptr)
                    cout << obiektPrzedstawialny->przedstawSie() << " ";
                else
                    cout << baza[i]->getImie() << " "  << baza[i]->getNazwisko() << " ";
                cout << "- " << (obecnosc[i] == 1 ? "obecny" : "nie obecny") << endl;
            }
        else
            cout << "Lista jest pusta." << endl;  
}

void ListaObecnosci::usunOsobe(){
    int licznik1 = -1;
    string nazwisko;

    if (licznik != 0){
        cout << "Wpisz nazwisko osoby ktora chcesz usunac: ";
        cin >> nazwisko;
        for (int i = 0; i < licznik; i++){
            if (nazwisko == baza[i]->getNazwisko()){
                licznik1 = i;
                break;
            }
        }
        if (licznik1 != -1){
            delete baza[licznik1];
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
                wprowadzNowaOsobe();
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