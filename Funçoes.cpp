#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <list>
#include <conio.h>
#include <windows.h>

using namespace std;
void mapa(int n){
    
}
int random(int menor, int maior){
    return rand()%(maior-menor+1)+menor;
}
void textcolor(int color){
    //static int __BACKGROUND;

    //HANDLE h = GetStdHandle ( STD_OUTPUT_HANDLE );
    //CONSOLE_SCREEN_BUFFER_INFO csbiInfo;


    //GetConsoleScreenBufferInfo(h, &csbiInfo);

    SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),color //+ (__BACKGROUND << 4));
    );
}

class Territorio{
    public:
    int player;
    int x, y;
    int fronteira[8][2];
    int nexercitos;
    int naviao;//pula um territorio e atravessa o mar
};
class Jogador{
    public:
    string nome;
    int nexercitos;
    int nterritorios;
    int naddEX;
};
void ataqueexercito(Territorio* atacante, Territorio* defensor){
    int dado, natk, ndef=defensor->nexercitos;
    if(atacante->nexercitos>1 && defensor->nexercitos>0){
    cout<<"digite o numero de exercitos usados no ataque:";
    cin>>natk;
    while(natk>=atacante->nexercitos || natk>3 || natk<=0){
        if(atacante->nexercitos<=3)cout<<"digite um numero natural menor ou igual a "<<atacante->nexercitos-1<<"\n";
        else cout<<"digite um numero natural menor ou igual a 3\n";
        cin>>natk;
        fflush(stdin);
    }
    if(ndef>3)ndef=3;
    list <int> latk, ldef;
    list <int>::iterator itA,itD;
    int resultA=0,resultD=0;
    for(int i=0;i<natk || i<ndef;i++){
        if(i<natk){
        dado=random(1,6);
        latk.push_back(dado);
}
        if(i<ndef){
        dado=random(1,6);
        ldef.push_back(dado);
}
    }
    latk.sort();
    ldef.sort();
    cout<<"dados de ataque:\n";
    for(itA=latk.begin();itA != latk.end();itA++)
        cout<<*itA<<endl;
        cout<<"dados de defesa:\n";
    for(itD=ldef.begin();itD != ldef.end();itD++)
        cout<<*itD<<endl;
    while(latk.size()>ldef.size())
    latk.pop_front();
    while(ldef.size()>latk.size())
    ldef.pop_front();

cout<<"confrontando os dados:\natk|def\n";
    for(itA=latk.begin(), itD=ldef.begin();itA != latk.end();itA++, itD++){
        if(*itA>*itD){ defensor->nexercitos--;resultA++;}
        else {atacante->nexercitos--;resultD++;}
        cout<<' '<<*itA<<" | "<<*itD<<endl;
}
cout<<"O defensor perdeu "<<resultA<<" exercitos\nO atacante perdeu "<<resultD<< " exercitos\n\n";
    }
    else if(atacante->nexercitos<=1)cout<<"O territorio nao pode atacar\n";
    else if(defensor->nexercitos<=0)cout<<"O atacante conquistou o territorio\n";
}


void addexercitos(Jogador* player){
    int nadd;
    while(player->naddEX>0){
        cout<<"digite quantos exercitos quer adicionar (no maximo "<<player->naddEX<<")\n";
        cin>>nadd;
        while(nadd>player->naddEX){cout<<"digite um numero menor que "<<player->naddEX<<endl;cin>>nadd;}
        cout<<"digite em qual territorio quer adicionar "<<nadd<<" exercitos, ou digite cancelar";


    player->naddEX=player->naddEX - nadd;
    }
}


int main()
{
    srand((unsigned)time(0));
    int njog;
    system("color F0");
    cout<<"digite o numero de jogadores:";
    cin>>njog;
    Jogador play[njog];
    bool continuar=true;
    Territorio pais[20];
    pais[0].nexercitos=20;
    pais[1].nexercitos=30;

    while(continuar){

    Territorio atacante, alvo;
    atacante=pais[0];
    alvo=pais[1];
    ataqueexercito(&atacante,&alvo);
    pais[0]=atacante;
    pais[1]=alvo;
    system("pause");
    system("cls");
    }
    return 0;
}
