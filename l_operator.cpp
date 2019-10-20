#include "l_operator.h"
#include <iostream>
#include <string>


oper* lista(){
    oper* glowa= new oper;
    glowa=NULL;
    return glowa;

}

//------------------------------------------------------------

bool czy_operator(oper *glowa, string w1,oper *op){//wskaźnik?
    oper *tmp=glowa;
    bool czyOperator = false;
    while(tmp!=NULL){
        if(tmp->nazwa == w1){
            czyOperator=true;
            *op=*tmp;
            break;
        }
        tmp=tmp->next;
    }
    return czyOperator;
}
//----------------------------------------------------------------

//destruktor
void usun_liste(oper *glowa){
    if(glowa==NULL) return;
    oper *tmp;
    while(glowa->next!=NULL){
        tmp=glowa;
        glowa=glowa->next;
        delete tmp;

    }
}


//--------------------------------------------------------------
//Tworzy element na końcu listy
void dodaj(oper *&glowa, string nazwa,int priorytet,string dir,float(*func)(float,float)){
    oper *akt=glowa;

    if(glowa!=NULL) {
        while(akt->next!=NULL) akt=akt->next;
    }
    if(glowa==NULL){
        glowa=new oper;
        glowa->nazwa=nazwa;
        glowa->priorytet=priorytet;
        glowa->dir=dir;
        glowa->func=func;
        glowa->next=NULL;
        akt=glowa;
    }else{
        akt->next=new oper;
        akt=akt->next;
        akt->nazwa=nazwa;
        akt->priorytet=priorytet;
        akt->dir=dir;
        akt->func=func;
        akt->next=NULL;
    }
}

//--------------------------------------------------------------
//Usuwa element z końca listy, a aktualny ustawia jeden wczesniej
void zdejmij(oper *&glowa){
    oper *akt=glowa;
    oper* tmp;
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


//--------------------------------------------------------------


//Zwraca ilosc elementow w liscie
int dlugosc(oper *glowa){
    int i=0;
    oper *tmp=glowa;
    while(tmp!=NULL){
        i++;
        tmp=tmp->next;
    }
    return i;
}

//--------------------------------------------------------------


//Dodawanie
float add(float a,float b){
    return (a+b);
}

//Odejmowanie
float sub(float a, float b){
    return (a-b);
}

//Mnożenie
float multiply(float a, float b){
    return (a*b);
}

//Dzielenie
float divide(float a,float b){
    if(b!=0){
        return (a/b);
    }else{
        return RAND_MAX;
    }

}

