#include "stos.h"
#include <iostream>
#include <string>


//Strukturea do stworzenia listy(stosu)
Selem* stosf(){
    Selem* glowa= new Selem;
    glowa=NULL;
    return glowa;

}

//destruktor
void usun_stos(Selem *glowa){
    if(glowa==NULL) return;
    Selem *tmp;
    while(glowa->next!=NULL){
        tmp=glowa;
        glowa=glowa->next;
        delete tmp;

    }
}



//Tworzy element na końcu listy
void push_back(Selem *&glowa, std::string dane){
    Selem *akt=glowa;

    if(glowa!=NULL) {
        while(akt->next!=NULL) akt=akt->next;
    }
    if(glowa==NULL){
        glowa=new Selem;
        glowa->dane=dane;
        glowa->next=NULL;
        akt=glowa;
    }else{
        akt->next=new Selem;
        akt=akt->next;
        akt->dane=dane;
        akt->next=NULL;
    }
}

//Usuwa element z końca listy, a aktualny ustawia jeden wczesniej
void pop_back(Selem *&glowa){
    Selem *akt=glowa;
    Selem* tmp;
    if(glowa==NULL){
        return;
    }
    while(akt->next!=NULL) akt=akt->next;

    tmp=akt;
    if(tmp==glowa){
        delete glowa;
        glowa=NULL;
        return;
    }
    akt=glowa;
    while(akt->next!=tmp){
        akt=akt->next;
    }
    delete tmp;
    akt->next=NULL;
}

//drukuje liste
void drukuj(Selem* glowa){
    //if(glowa==NULL) return;
    Selem *tmp=glowa;
    while(tmp!=NULL){
        std::cout<<tmp->dane <<"\t";
        tmp=tmp->next;
    }
    std::cout<<std::endl;
}

//Zwraca ilosc elementow w liscie
int dlugosc(Selem *glowa){
    int i=0;
    Selem *tmp=glowa;
    while(tmp!=NULL){
        i++;
        tmp=tmp->next;
    }
    return i;
}

//Zwraca ostatni element listy
std::string ostatni(Selem *glowa){
    std::string ost;
    if(glowa==NULL) return "Error";
    while(glowa->next!=NULL){
        glowa=glowa->next;
    }
    ost=glowa->dane;
    return ost;

}

//Odwraca kolejność elementów w liście
Selem *odwroc(Selem *glowa){
    Selem *odwrocona=stosf();
    Selem *tmp;
    while(glowa!=NULL){
        tmp=glowa;
        while(tmp->next!=NULL){
            tmp=tmp->next;
        }
        push_back(odwrocona,tmp->dane);
        pop_back(glowa);
    }
    return odwrocona;
}




