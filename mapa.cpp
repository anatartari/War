#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <windows.h>
#include "Auxi.cpp"

using namespace std;

const int larg = 105, alt= 30;
char mapa[larg][alt];


void inicializarMapa();

void criarTerritorio(int x, int y, char nome){
	for(int i=x-2; i<x+3; i++)
	for(int j=y; j<y+3; j++){
   	   	  mapa[i][j] = '#';
	}

	mapa[x][y]=nome;
}

void criarMapa();


//Preenche com ' '.
void inicializarMapa(){
player1.Ndominios = 0;
player2.Ndominios = 0;
	for(int i=0; i<larg; i++)
	for(int j=0; j<alt; j++)
	mapa[i][j]=' ';	
}




void criarMapa(){
	inicializarMapa();
	/* inicializando o numero de tropas como 1 */
	for(int i=0; i<26;i++)
	paisesT[i].nexercitos=1;

	/* inicializando os paises */
	
	
	//Trabalho das damas.
	
	criarTerritorio(3, 1, 'A');
	paisesT[0].x = 3;
	paisesT[0].y = 1;
	paisesT[0].fronteira[0] = &paisesT[(int)('B'-'A')];
	
	criarTerritorio(7, 4, 'B');
	paisesT[1].x = 7;
	paisesT[1].y = 4;
	paisesT[1].fronteira[0] = &paisesT[(int)('A'-'A')];
	paisesT[1].fronteira[1] = &paisesT[(int)('C'-'A')];
	paisesT[1].fronteira[2] = &paisesT[(int)('D'-'A')];
	paisesT[1].fronteira[3] = &paisesT[(int)('O'-'A')];
	
	criarTerritorio(7, 7, 'C');
	paisesT[2].x = 7;
	paisesT[2].y = 7;
	paisesT[2].fronteira[0] = &paisesT[(int)('B'-'A')];
	paisesT[2].fronteira[1] = &paisesT[(int)('D'-'A')];
	paisesT[2].fronteira[2] = &paisesT[(int)('E'-'A')];
	
	criarTerritorio(12, 7, 'D');
	paisesT[3].x = 12;
	paisesT[3].y = 7;
	paisesT[3].fronteira[0] = &paisesT[(int)('B'-'A')];
	paisesT[3].fronteira[1] = &paisesT[(int)('C'-'A')];
	paisesT[3].fronteira[2] = &paisesT[(int)('E'-'A')];
	paisesT[3].fronteira[3] = &paisesT[(int)('I'-'A')];
	
	criarTerritorio(9, 10, 'E');
	paisesT[4].x = 9;
	paisesT[4].y = 10;
	paisesT[4].fronteira[0] = &paisesT[(int)('C'-'A')];
	paisesT[4].fronteira[1] = &paisesT[(int)('D'-'A')];
	paisesT[4].fronteira[2] = &paisesT[(int)('F'-'A')];
	paisesT[4].fronteira[3] = &paisesT[(int)('G'-'A')];
	
	criarTerritorio(14, 13, 'F');
	paisesT[5].x = 14;
	paisesT[5].y = 13;
	paisesT[5].fronteira[0] = &paisesT[(int)('E'-'A')];
	paisesT[5].fronteira[1] = &paisesT[(int)('H'-'A')];
	
	criarTerritorio(4, 13, 'G');
	paisesT[6].x = 4;
	paisesT[6].y = 13;
	paisesT[6].fronteira[0] = &paisesT[(int)('E'-'A')];
	paisesT[6].fronteira[1] = &paisesT[(int)('H'-'A')];
	
	criarTerritorio(9, 16, 'H');
	paisesT[7].x = 9;
	paisesT[7].y = 16;
	paisesT[7].fronteira[0] = &paisesT[(int)('F'-'A')];
	paisesT[7].fronteira[1] = &paisesT[(int)('G'-'A')];
	paisesT[7].fronteira[2] = &paisesT[(int)('V'-'A')];
	paisesT[7].fronteira[3] = &paisesT[(int)('X'-'A')];
	
	criarTerritorio(42, 3, 'I');
	paisesT[8].x = 42;
	paisesT[8].y = 3;
	paisesT[8].fronteira[0] = &paisesT[(int)('D'-'A')];
	paisesT[8].fronteira[1] = &paisesT[(int)('K'-'A')];
	
	criarTerritorio(50, 3, 'J');
	paisesT[9].x = 50;
	paisesT[9].y = 3;
	paisesT[9].fronteira[0] = &paisesT[(int)('K'-'A')];
	
	criarTerritorio(46, 6, 'K');
	paisesT[10].x = 46;
	paisesT[10].y = 6;
	paisesT[10].fronteira[0] = &paisesT[(int)('I'-'A')];
	paisesT[10].fronteira[1] = &paisesT[(int)('J'-'A')];
	paisesT[10].fronteira[2] = &paisesT[(int)('L'-'A')];
	paisesT[10].fronteira[3] = &paisesT[(int)('M'-'A')];
	
	criarTerritorio(42, 9, 'L');
	paisesT[11].x = 42;
	paisesT[11].y = 9;
	paisesT[11].fronteira[0] = &paisesT[(int)('K'-'A')];
	paisesT[11].fronteira[1] = &paisesT[(int)('N'-'A')];
	
	criarTerritorio(50, 9, 'M');
	paisesT[12].x = 50;
	paisesT[12].y = 9;
	paisesT[12].fronteira[0] = &paisesT[(int)('K'-'A')];
	paisesT[12].fronteira[1] = &paisesT[(int)('N'-'A')];
	paisesT[12].fronteira[2] = &paisesT[(int)('P'-'A')];
	
	criarTerritorio(46, 12, 'N');
	paisesT[13].x = 46;
	paisesT[13].y = 12;
	paisesT[13].fronteira[0] = &paisesT[(int)('L'-'A')];
	paisesT[13].fronteira[1] = &paisesT[(int)('M'-'A')];
	paisesT[13].fronteira[2] = &paisesT[(int)('Y'-'A')];
	
	criarTerritorio(90, 4, 'O');
	paisesT[14].x = 90;
	paisesT[14].y = 4;
	paisesT[14].fronteira[0] = &paisesT[(int)('B'-'A')];
	paisesT[14].fronteira[1] = &paisesT[(int)('R'-'A')];
	
	criarTerritorio(85, 9, 'P');
	paisesT[15].x = 85;
	paisesT[15].y = 9;
	paisesT[15].fronteira[0] = &paisesT[(int)('M'-'A')];
	paisesT[15].fronteira[1] = &paisesT[(int)('R'-'A')];
	
	criarTerritorio(95, 9, 'Q');
	paisesT[16].x = 95;
	paisesT[16].y = 9;
	paisesT[16].fronteira[0] = &paisesT[(int)('R'-'A')];
	
	criarTerritorio(90, 12, 'R');
	paisesT[17].x = 90;
	paisesT[17].y = 12;
	paisesT[17].fronteira[0] = &paisesT[(int)('O'-'A')];
	paisesT[17].fronteira[1] = &paisesT[(int)('P'-'A')];
	paisesT[17].fronteira[2] = &paisesT[(int)('Q'-'A')];
	paisesT[17].fronteira[3] = &paisesT[(int)('U'-'A')];
	//paisesT[17].fronteira[4] = &paisesT[(int)('T'-'A')];
	
	criarTerritorio(79, 15, 'S');
	paisesT[18].x = 79;
	paisesT[18].y = 15;
	paisesT[18].fronteira[0] = &paisesT[(int)('T'-'A')];
	
	criarTerritorio(84, 15, 'T');
	paisesT[19].x = 84;
	paisesT[19].y = 15;
	//paisesT[19].fronteira[0] = &paisesT[(int)('R'-'A')];
	paisesT[19].fronteira[1] = &paisesT[(int)('S'-'A')];
	paisesT[19].fronteira[2] = &paisesT[(int)('U'-'A')];
	paisesT[19].fronteira[3] = &paisesT[(int)('W'-'A')];
	
	criarTerritorio(89, 15, 'U');
	paisesT[20].x = 89;
	paisesT[20].y = 15;
	paisesT[20].fronteira[0] = &paisesT[(int)('R'-'A')];
	paisesT[20].fronteira[1] = &paisesT[(int)('T'-'A')];
	paisesT[20].fronteira[2] = &paisesT[(int)('V'-'A')];
	paisesT[20].fronteira[3] = &paisesT[(int)('W'-'A')];
	
	criarTerritorio(94, 16, 'V');
	paisesT[21].x = 94;
	paisesT[21].y = 16;
	paisesT[21].fronteira[0] = &paisesT[(int)('U'-'A')];
	paisesT[21].fronteira[1] = &paisesT[(int)('H'-'A')];
	
	criarTerritorio(87, 18, 'W');
	paisesT[22].x = 87;
	paisesT[22].y = 18;
	paisesT[22].fronteira[0] = &paisesT[(int)('T'-'A')];
	paisesT[22].fronteira[1] = &paisesT[(int)('U'-'A')];
	paisesT[22].fronteira[2] = &paisesT[(int)('Z'-'A')];
	
	criarTerritorio(41, 24, 'X');
	paisesT[23].x = 41;
	paisesT[23].y = 24;
	paisesT[23].fronteira[0] = &paisesT[(int)('H'-'A')];
	paisesT[23].fronteira[1] = &paisesT[(int)('Y'-'A')];
	
	criarTerritorio(46, 21, 'Y');
	paisesT[24].x = 46;
	paisesT[24].y = 21;
	paisesT[24].fronteira[0] = &paisesT[(int)('N'-'A')];
	paisesT[24].fronteira[1] = &paisesT[(int)('X'-'A')];
	paisesT[24].fronteira[2] = &paisesT[(int)('Z'-'A')];
	
	criarTerritorio(51, 24, 'Z');
	paisesT[25].x = 51;
	paisesT[25].y = 24;
	paisesT[25].fronteira[0] = &paisesT[(int)('W'-'A')];
	paisesT[25].fronteira[1] = &paisesT[(int)('Y'-'A')];
	
	
	/* colocando o id dos paises */
	
	for(int i=0; i < 26; i++)
		paisesT[i].id=i;
	
	
	/* printando as fronteiras marinhas */
	
	for(int i =53 ; i < 83 ; i++)
		mapa[i][10]='+';
	
	for(int i =15 ; i < 21 ; i++)
		mapa[46][i]='+';
	
	for(int i =53 ; i < 83 ; i++)
		mapa[i][10]='+';	
	
	for(int i =97 ; i < 105 ; i++)
		mapa[i][17]='+';
	for(int i =0 ; i < 7 ; i++)
		mapa[i][17]='+';
	
	for(int i =7 ; i < 12 ; i++)
		mapa[90][i]='+';
	for(int i =93 ; i < 105 ; i++)
		mapa[i][5]='+';
	for(int i =0 ; i < 5 ; i++)
		mapa[i][5]='+';
	
	for(int i=19; i <26  ;i++) 
		mapa[9][i]='+';
	for(int i = 9 ; i< 39 ;i++)
		mapa[i][25]='+';
	
	for(int i =54; i < 88 ; i++)
		mapa[i][25]='+';			
	for (int i =21 ; i<26  ; i++)
		mapa[87][i]='+';
	
	for(int i=16 ; i<30 ; i++)
		mapa[i][8]='+';
	for(int i= 4 ; i< 8; i++)
		mapa[29][i]='+';
	for(int i = 29; i <39 ;i++)
		mapa[i][4]='+';
	
}

bool faz_fronteira(Territorio* primeiro, Territorio* segundo){
	for(int i = 0; i < 4; i++)
		if(primeiro->fronteira[i] == segundo) return true;
	return false;
}





