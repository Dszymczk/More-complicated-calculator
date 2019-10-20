#include <iostream>
#include <cstdlib>
#include "interfejs.h"
#include "stos.h"
#include "MathParser.h"
#include "l_operator.h"


using namespace std;

int main()
{

    Selem *glowa=stosf();
    zmienna *zmienne=NULL;
    oper *dzialania=lista();
    wyrazenie *historia=NULL;
    dodaj(dzialania,"+",1,"l",add);
    dodaj(dzialania,"-",1,"l",sub);
    dodaj(dzialania,"*",2,"l",multiply);
    dodaj(dzialania,"/",2,"l",divide);
    //dodaj(dzialania,"^",3,"l",pow); potęgowanie mus być funkcją


    bool loop=1;
    while(loop){
        loop=menu(dzialania,zmienne,historia);
    }


    usun_liste(dzialania);
     usun_stos(glowa);
     usun_zmienne(zmienne);
     cout<<endl;
    return 0;
}

//Jeśli podamy liczbę zmiennoprzecinkową z zerem na początku, to czyta tylko 0
