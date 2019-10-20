#ifndef MATHPARSER_H
#define MATHPARSER_H
#include "l_operator.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include "stos.h"
#include <cmath>



using namespace std;

//struktura przechowująca wyrażenie z wynikiem
struct wyrazenie{
    string dzialanie;
    float wynik;
    wyrazenie *next;
};

struct zmienna{
    string nazwa;
    string wartosc;
    zmienna *next;
};

struct funkcja{
    string nazwa;
    funkcja *next;
};




//oper *ops=new oper[10];


Selem *NaONP(string wyr, oper *lista_op, zmienna *zmienne);    //Konwertuje wyryażenie na ONP
float parse(string wyr, oper *lista_op, zmienna *zmienne);


//zmienna *lista_zmiennych();
void usun_zmienne(zmienna *lista);
void dodaj_zmienna(zmienna *&lista, string zmn, string wartosc);
bool czy_zmienna(string &sym, zmienna *lista);
wyrazenie *lista_wyrazen();

bool czy_funkcja(string symbol);



#endif // MATHPARSER_H
