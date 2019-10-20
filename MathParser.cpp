
#include "MathParser.h"



using namespace std;




Selem *NaONP(string wyr, oper *lista_op, zmienna *zmienne){
    oper ex;
    Selem *wyjscie=stosf();
    Selem *stos=stosf();   //stos z operatorami
    int length=wyr.size();
    string w1, w2;
    for(int i=0;i<length;i++){
        w1 = wyr[i];
        w2 = wyr[i+1];
        if(atoi(w1.c_str())<=9&&(atoi(w1.c_str())>0 || w1=="0")){
            // Symbol jest cyfra
            w2=wyr[++i];//sprawdzanianie, czy kkolejna symbol też jest cyfrą
            string c=w1;
            while(atoi(w2.c_str() )<=9 && atoi(w2.c_str() )>0 || w2=="0"||w2=="."){
                c+=w2;
                w2=wyr[++i];
                continue;
            }
            i--;
            push_back(wyjscie,c);

        }
        else if( czy_zmienna(w1,zmienne )){
            //Symbol jest zmienną
            push_back(wyjscie,w1);


        }else if(w1==","){
            //Symbol jest znakiem oddzielającym argumenty funkcji
            while( ostatni(stos) != "(" ){
                push_back(wyjscie,ostatni(stos) );
                pop_back(stos);
            }
        }else if(w1 == "("){
            push_back(stos,w1);
        }else if(w1 == ")"){
            while(ostatni(stos) != "(")
            {
                push_back(wyjscie,ostatni(stos));
                pop_back(stos);
            }
            pop_back(stos);
        }else if(czy_operator(lista_op,w1,&ex)) {
            //symbol jest operatorem
            oper cur;

            czy_operator(lista_op,w1, &cur);//pobranie aktualnego operatora do zmiennej cur
            if(dlugosc(stos)<=0 ){
                //Nie ma żadnych opoeratorów na stosie
                push_back(stos,w1);
                continue;
            }
            oper op;
            while(czy_operator(lista_op,ostatni(stos), &op) == true){//dopóki na stosie znajduje się odpowiedni operator
                if((cur.dir=="l"&&cur.priorytet<=op.priorytet)||(cur.dir=="p"&&cur.priorytet<op.priorytet)||czy_funkcja(ostatni(stos))){
                    push_back(wyjscie,ostatni(stos));
                    pop_back(stos);
                }else
                    break;
                if(dlugosc(stos)<=0){
                    break;
                }
            }
            push_back(stos,w1);
        }else if((w1=="s"&&wyr[i+1]=='i'&&wyr[i+2]=='n') || (w1=="c"&&wyr[i+1]=='o'&&wyr[i+2]=='s')|| (w1=="^") ){
            if(w1=="s"){
                push_back(stos,"sin");
                i++;
                i++;
            }else if(w1=="c"){
                push_back(stos,"cos");
                i++;
                i++;
            }else if(w1=="^"){
                push_back(stos,"^");
            }
        }

    }
    while(dlugosc(stos)>0)
    {
        //Wysłanie wszystkiego do wyjścia
        push_back(wyjscie,ostatni(stos));
        pop_back(stos);
    }


    return wyjscie;
}

//Parser
float parse(string wyr, oper *lista_op,  zmienna *zmienne){
    Selem *lista=NaONP(wyr,lista_op,zmienne);
    Selem *stos=stosf();
    lista=odwroc(lista);

    while(lista!=NULL){
        string sym=ostatni(lista);
        oper op;
        if(atoi(sym.c_str() )>0 || sym=="0"||sym[0]=='0'&&sym[1]=='.'){
            push_back(stos,sym);
        }
        else if(czy_operator(lista_op,sym, &op ) )
        {
            string a = ostatni(stos);
            pop_back(stos);
            string b = ostatni(stos);
            pop_back(stos);
            float result=op.func(atof(b.c_str() ),atof(a.c_str() ) );  //tutaj w kodzie był też wskaźnik Atof - zmiana stringa na zmiennoprzecinkowa
            char buf[10];
            gcvt(result,3,buf);
            push_back(stos,buf);

        }
        else if(czy_funkcja(sym)){
            if(sym=="sin"){
                string a = ostatni(stos);
                pop_back(stos);
                float result=sin(atof(a.c_str()));
                char buf[10];
                gcvt(result,3,buf);
                push_back(stos,buf);
            }else if(sym=="cos"){
                string a = ostatni(stos);
                pop_back(stos);
                float result=cos(atof(a.c_str()));
                char buf[10];
                gcvt(result,3,buf);
                push_back(stos,buf);
            }else if(sym=="^"){
                string a = ostatni(stos);
                pop_back(stos);
                string b = ostatni(stos);
                pop_back(stos);
                double result=pow(atof(b.c_str() ),atof(a.c_str() ) );  //tutaj w kodzie był też wskaźnik Atof - zmiana stringa na zmiennoprzecinkowa
                char buf[10];
                gcvt(result,3,buf);
                push_back(stos,buf);
            }

        }
        pop_back(lista);
    }
    string result = "";
    result=ostatni(stos);
    return atof(result.c_str());





}

/*---------------------------------------------------------------------*/
//zmienne
/*zmienna *lista_zmiennych(){
    zmienna *lista; //Czy takie cos jest potrzebne? Chyba nie...
    lista=NULL;
    //zmienna->next=NULL;
    return lista;
}*/

void usun_zmienne(zmienna *lista){
    zmienna *tmp=lista;
    while(lista){
        tmp=lista;
        lista=lista->next;
    }
}


void dodaj_zmienna(zmienna *&lista, string zmn, string wartosc){
    zmienna *akt=lista;

    if(lista!=NULL){
        while(akt->next!=NULL){
            akt=akt->next;
        }
    }

    if(lista==NULL){
        lista=new zmienna;
        lista->nazwa=zmn;
        lista->next=NULL;
        lista->wartosc=wartosc;
    }else{
        akt->next=new zmienna;
        akt=akt->next;
        akt->nazwa=zmn;
        akt->next=NULL;
        akt->wartosc=wartosc;
    }
}

bool czy_zmienna(string &sym, zmienna *lista){
    bool ok=0;
    while (lista!=NULL){
        if(sym==lista->nazwa){
            ok=1;
            sym=lista->wartosc;
            return ok;
        }
        lista=lista->next;
    }
    return ok;
}


bool czy_funkcja(string symbol){
    if(symbol=="sin"||symbol=="cos"||symbol=="^") return 1;
    else return 0;
}





