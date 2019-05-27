#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <time.h>
#include <windows.h>
#include "Mapa.cpp"
#include "Auxi.cpp"

using namespace std;

Territorio atacante, defensor;

void distribuir_paises(int numero_jogadores);



char num_exercito (Territorio add);

void textcolor(int color, int background){

    HANDLE h = GetStdHandle ( STD_OUTPUT_HANDLE );
    CONSOLE_SCREEN_BUFFER_INFO csbiInfo;


    GetConsoleScreenBufferInfo(h, &csbiInfo);

    SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),color  + 16* background );
}




void distribuir_paises(){
	int aux;
	for(int i=0; i<26 ;){
		aux=random(0, 1);
		if(aux == 0 && player1.Ndominios < 13){
			paisesT[i].player = &player1;
			player1.dominio[player1.Ndominios] = i;
			player1.Ndominios++;	
			i++;
		}else if(aux == 1 && player2.Ndominios < 13){
			paisesT[i].player = &player2;
			player2.dominio[player2.Ndominios] = i;
			player2.Ndominios++;	
			i++;
		}
	}
}

void Printar_mapa(){
	system("cls");
	for(int j=0; j<alt; j++){
	for(int i=0; i<larg; i++){
		if(mapa[i][j] == ' ' || mapa[i][j] == '+')
			textcolor(15, 0);
		else if(mapa[i][j] == '#' || mapa[i][j] < 'A') textcolor(15, 0);
		
		else{
		 textcolor((*paisesT[mapa[i][j] - 'A' ].player).cor, 0);
		num_exercito (paisesT[mapa[i][j] - 'A' ]);
		}
		
		cout<<mapa[i][j];	
		
	}
	cout<<"\n";
	}
	textcolor(15, 0);
}

char distribuir_tropas(){
	
	
	
	
	return '1';
}

char mover_tropas(){
	int num=0;
	Territorio* pais_origem;
	Territorio* pais_destino;
	
	do{
			system("cls");
			Printar_mapa();
			cout<<"\n\nDigite o pais de origem: ";
			cin>>burro;
			pais_origem = &paisesT[(int)(burro - 'A')];
		if((*pais_origem).player != dono_da_vez){
			cout<<"Esse pais nao te pertence!\n";
			system("pause");
		}
	
	}while((*pais_origem).player != dono_da_vez);
	
	do{	
		system("cls");
		Printar_mapa();
		cout<<"Digite o pais destino: ";
		cin>>burro;
		pais_destino = &paisesT[(int)(burro - 'A')];
	if((*pais_destino).player != dono_da_vez){
		cout<<"Esse pais nao te pertence!\n";
		system("pause");
	}
	}while((*pais_destino).player != dono_da_vez);
	bool front = faz_fronteira(*pais_origem, *pais_destino);
	if(front){
		cout<<"Estes paises nao possuem fronteiras entre si!\n";
		system("pause");
		return '1';
	}
	if((*pais_origem).nexercitos == 1 ){
		cout<<"Voce nao pode mover paises que possuem apenas 1 tropa "<< (char)((pais_origem-&paisesT[0]) + 'A')<<endl;
		system("pause");
	}
	
	cout<<"Digite o numero de tropas a serem movidas: ";
	cin>>num;
	
	(*pais_origem).nexercitos -= num;
	(*pais_destino).nexercitos += num;
	
	return '1';
}


char num_exercito (Territorio add){
	int X=add.x, Y=add.y;
	char unidade, dezena, centena;
	unidade = add.nexercitos%10 + 48;
	dezena = ((add.nexercitos - (unidade - 48))/10)%10 + 48;
	centena = ((add.nexercitos - (dezena - 48))/10)%10 + 48;
	
	mapa[X+1][Y+1] = unidade;
	mapa[X][Y+1] = dezena;
	mapa[X-1][Y+1] = centena;
	
	return '1';
}









