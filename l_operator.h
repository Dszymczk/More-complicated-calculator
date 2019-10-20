#ifndef L_OPERATOR_H
#define L_OPERATOR_H
#include <string>
#include <cstdlib>
#include <cmath>

using namespace std;

struct oper{
    string nazwa;
    int priorytet;
    string dir; //p||l
    oper *next;
    float(*func)(float a,float b);

};



    oper *lista(); //Tworzy listę
    void usun_liste(oper* glowa);    //Usuwa liste
    bool czy_operator(oper *glowa, string w1,oper *op);
    void dodaj(oper *&glowa, string nazwa, int priorytet, string dir,float(*func)(float,float));  //dodawanie elementu na koniec listy
    void zdejmij(oper *&glowa);     //usuwanie elementu z końca listy
    int ile_operatorow(oper *glowa);  //Wylicza glugosc listy
    //void drukuj(oper *glowa);
    //std::string ostatni(oper *glowa);
    float add(float a, float b);// Dodawanie
    float sub(float a, float b);
    float divide(float a, float b);
    float multiply(float a, float b);

#endif // L_OPERATOR_H
