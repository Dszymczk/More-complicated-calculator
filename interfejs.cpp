#include "interfejs.h"


using namespace std;

bool menu(oper *dzialania, zmienna *&zmienne, wyrazenie *&historia){
    cout <<"Wybierz opcje: " <<endl;
    cout <<"1) Licz "<<endl;
    cout <<"2) Zdefiniuj zmienna "<<endl;
    cout <<"3) Wczytaj historie "<<endl;
    cout <<"4) Zapisz historie do pliku "<<endl;
    cout <<"5) Wyjscie "<<endl;

    string wybor;
    cin>>wybor;
    int i=atoi(wybor.c_str());

    switch(i)
    {
    case 1:
    {
        cout<<"Podaj wyrazenie: "<<endl;
        string wyr;
        float wynik;
        cin>>wyr;
        wynik=parse(wyr, dzialania,zmienne);
        cout<<endl<<"Wynik: " <<wynik<<endl;
        if(historia==NULL){
            historia=new wyrazenie;
            historia->dzialanie=wyr;
            historia->wynik=wynik;
            historia->next=NULL;
        }else{
            wyrazenie *akt=historia;
            while(akt->next!=NULL){
                akt=akt->next;
            }
            akt->next=new wyrazenie;
            akt=akt->next;
            akt->dzialanie=wyr;
            akt->wynik=wynik;
            akt->next=NULL;
        }
        cin.get();
        break;
    }
    case 2:
    {
        string name="", value="";
        while(!(name[0]>='a'&&name[0]<='z'&&name[1]==NULL)){

            cout <<endl<<"Podaj nazwe zmiennej(jedna, mala litera): ";
            cin>>name;
        }
        while( atoi(value.c_str())==0 ){
            cout<<" Podaj wartosc zmiennej: " ;
            cin>>value;
        }
        dodaj_zmienna(zmienne,name,value);
        break;
    }
    case 3:{
        //Funkcja do wczytywania historii
        wyrazenie *akt=historia;
        cout<<endl<<" Historia:"<<endl;
        while(akt!=NULL){
            cout<<akt->dzialanie<<" = "<<akt->wynik<<endl;
            akt=akt->next;
        }
        break;
    }
    case 4:
    {
        string nazwa;
        cout<<endl<<" Podaj nazwe pliku do zapisu ";
        cin >>nazwa;
        ofstream plik_wy;
        string tekst;
        plik_wy.open(nazwa.c_str());
        wyrazenie *akt=historia;
        while(akt!=NULL){
            tekst=akt->dzialanie;
            plik_wy<<tekst<<" = ";
            tekst=akt->wynik;
            plik_wy<<akt->wynik<<"\n";
            akt=akt->next;

        }
        plik_wy.close();
        break;
    }
    case 5:
    {
        //Wyjście z aplilacji
        return 0;
        break;
    }
    default:
        //system( "cls" );
        cout<<endl<< "Podano bledna wartosc"<<endl<<endl;
        menu(dzialania,zmienne,historia);
    }
    cout<<endl;
    return 1;
}
