#ifndef STOS_H
#define STOS_H

#include <string>

struct Selem{
    std::string dane;
    Selem *next;
};



    Selem *stosf(); //Tworzy listę
    void usun_stos(Selem* glowa);    //Usuwa liste

    void push_back(Selem *&glowa, std::string dane);  //dodawanie elementu na koniec listy
    void pop_back(Selem *&glowa);     //usuwanie elementu z końca listy
    int dlugosc(Selem *glowa);  //Wylicza glugosc listy
    void drukuj(Selem *glowa);
    std::string ostatni(Selem *glowa);
    Selem *odwroc(Selem* glowa);


#endif // STOS_H
