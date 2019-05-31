/*									PRINCIPAL 	   		                      */
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <conio.h>
#include "Comandos.cpp"


using namespace std;


void Menu();

int main(){
	player1.cor = 11;
	player2.cor = 12;
	criarMapa();
	for(int i=0; i<27; i++){
		player1.dominio[i] = -1;
		player2.dominio[i] = -1;
}
	srand((unsigned)time(0));
	Menu();
		distribuir_paises();
		int r = random(0, 1);
		if(r == 1){
		dono_da_vez = &player1;
		distribuir_tropas();
		dono_da_vez = &player2;
		distribuir_tropas();
		}
		else{
		dono_da_vez = &player2;
		distribuir_tropas();
		dono_da_vez = &player1;
		distribuir_tropas();
		}
		
		while( !fim ){
		if(turno % 2 ) dono_da_vez = &player1;
		else dono_da_vez = &player2;
		
		if(r == 0){
		if(turno % 2 ) dono_da_vez = &player2;
		else dono_da_vez = &player1;
		}
		
		textcolor((*dono_da_vez).cor, 0);
			distribuir_tropas();
			
			system ("cls");
			
			
			/* ataque */
			do{
				ataque();
			}while(user != '.');
		
				/* condição de vitória */
				if((*dono_da_vez).Ndominios == 26) fim = true;
				if(fim){
					system("cls");
					cout<<"\n\n\n\n\n\t\t\t\tParabens "<<(*dono_da_vez).nome <<" voce venceu!!!\n";
					cout<<"\t\t\t\tVoce esta muito feliz" << endl;
					break;
				}
			
			/* mover */
			do{
				if(!mover_tropas())
					break;
			}while(true);

		turno++;	
		}
		if(turno % 2 ) dono_da_vez = &player1;
		else dono_da_vez = &player2;
		cout<<"\n\n\t\t\t\t"<<(*dono_da_vez).nome <<", a sua incompetencia me supreende, parabens!"<<endl;
		cout<<"\t\t\t\tVoce esta muito triste\n\n\n\n";
	return 0;
}


void Menu(){
	cout<<"\n\n\n\n"<<endl;
	cout<<"\t\t Bem-vindxs, ao WAR das Damas de Maria."<<endl;
	cout<<"\n\n\n\n"<<endl;
	cout<<"\t\t[Digite qualquer tecla para continuar]"<<endl;
	cout<<"\n\n\n\n"<<endl;
	getch();
	system("cls");
	
	cout<<"\n"<<endl;
	cout<<"\t\t**Como o jogo funciona?**"<<endl;
	cout<<"\n";
	cout<<"*INICIO*\n";
	cout<<"1- Cada jogador recebera 13 paises aleatoriamente\n"<<endl;
	cout<<"2- Cada jogador inicialmente tera 6 tropas para distribuir em seus territorios\n"<<endl;
	cout<<"\t OBS: O numero de tropas e definido a partir do numero de paises que o jogador possui dividido por 2\n caso este numero seja impar o numero de tropas sera aproximado para seu antecessor\n"<<endl;
	cout<<"3- Ao termino da distribuicao, o jogador poderar remanejar as tropas, apenas para paises\n que lhe pertencem e que possuem fronteira entre si\n"<<endl;
	cout<<"\t OBS: O jogador pode opitar por nao mover nenhuma tropa.\n"<<endl;
	cout<<"\t OBS2: O jogador so pode mover tropas no seu turno.\n"<<endl;
	cout<<"*ATAQUE E DEFESA*"<<endl;
	cout<<"1- O ataque so pode ser feito por paises com mais de um exercito em seu territorio\n"<<endl;
	cout<<"2- O jogador so podera realizar o ataque ao pais inimigo que faz fronteira com o de seu dominio.\n"<<endl;
	cout<<"3- Para vencer o ataque, ao jogar os dados e necessario tirar um numero maior que o da defesa\n"<<endl;
	cout<<"\t OBS: Em caso de empate, a defesa sempre ira vencer\n"<<endl;
	cout<<"4- O jogador pode atacar um pais com quantos exercitos desejar, porem so poderar usar no maximo 3 dados\n"<<endl;
	cout<<"*TURNO*"<<endl;
	cout<<"Um turno consiste em:\n*Distribuir tropas\n*Ataque(opcional)\n*Remanejar as tropas(opcional)\n\nNESTA ORDEM!\n"<<endl;
	system("pause");
	system("cls");
	
cout<<"\n\n\n\n"<<endl;
cout<<"\tOBS: Voce ser o player 1 nao significa que sera o primeiro a jogar!"<<endl;
	textcolor(player1.cor, 0);
	cout<<"\n\n\n\n"<<endl;
	cout<< "\t\t Digite o apelido do Player 1: ";
	gets(player1.nome);
	textcolor(player2.cor, 0);
	cout<<"\n\n\n\n"<<endl;
	cout<< "\t\t Digite o apelido do Player 2: ";
	gets(player2.nome); 
	textcolor(15, 0);
	
}
/*								COMANDOS									  */
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <time.h>
#include <windows.h>
#include "mapa.cpp"

using namespace std;

Territorio* atacante;
Territorio* defensor;

void distribuir_paises(int numero_jogadores);

void distribuir_tropas();

void num_exercito (Territorio add);

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
	textcolor((*dono_da_vez).cor, 0);
}



bool mover_tropas(){
	int num=0;
	Territorio* pais_origem;
	Territorio* pais_destino;
	/* pais de origem */
	do{
			system("cls");
			Printar_mapa();
			cout<<"\n\nDigite a partir de qual pais quer mover tropas ou digite . para concluir sua vez\n";
			cin>>user;
			if(user == '.') return false; /* condição para encerrar o movimento */
			pais_origem = &paisesT[(int)(user - 'A')];
		if((*pais_origem).player != dono_da_vez){
			cout<<"Esse pais nao te pertence!\n";
			system("pause");
		}
	
	}while((*pais_origem).player != dono_da_vez);
	/* pais destino */
	do{
		system("cls");
		Printar_mapa();
		cout<<"Digite o pais destino ou digite . para concluir sua vez\n";
		cin>>user;
		if(user == '.') return false; /* condição para encerrar o movimento */
		pais_destino = &paisesT[(int)(user - 'A')];
	if((*pais_destino).player != dono_da_vez){
		cout<<"Esse pais nao te pertence!\n";
		system("pause");
	}
	}while((*pais_destino).player != dono_da_vez);
	bool front = faz_fronteira(pais_origem, pais_destino);
	if(!front){
		cout<<"Estes paises nao possuem fronteiras entre si!\n";
		system("pause");
		return true;
	}
	if((*pais_origem).nexercitos == 1 ){
		cout<<"Voce nao pode mover paises que possuem apenas 1 tropa\n";
		system("pause");
		return true;
	}
	
	do{
	Printar_mapa();
	cout<<"Digite o numero de tropas a serem movidas de "<< (char)((*pais_origem).id + 'A')<<" para "<< (char)((*pais_destino).id + 'A')<<"\n";
	cin>>num;
	if(num >= (*pais_origem).nexercitos ){
		system("cls");
		cout<<"\n\n\n\n\t\t\t\tAo menos 1 tropa deve permanecer no territorio de origem\n\n";
		system("pause");
	}
	}while( num >= (*pais_origem).nexercitos );
	
	(*pais_origem).nexercitos -= num;
	(*pais_destino).nexercitos += num;
	
	return true;
}


void num_exercito (Territorio add){
	int X=add.x, Y=add.y;
	char unidade, dezena, centena;
	unidade = add.nexercitos%10 + 48;
	dezena = (add.nexercitos/10)%10 + 48;   /* pega a parte inteira da divisão */
	centena = (add.nexercitos/100)%10 + 48;
	
	mapa[X+1][Y+1] = unidade;
	mapa[X][Y+1] = dezena;
	mapa[X-1][Y+1] = centena;
	
}


void distribuir_tropas(){
	int total = (*dono_da_vez).Ndominios/2;
	if(total == 0)total++;
	
	while(total > 0){
		int nadd;
		/* Receber o pais que vai receber as tropas */
		do{
			Printar_mapa();
			cout<<"Digite a que pais quer adicionar tropas\n";
			cin>>user;
			if(paisesT[user-'A'].player != dono_da_vez){
				cout<<"Este pais nao te pertence\n";
				system("pause");
			}
		}while(paisesT[user - 'A'].player != dono_da_vez);
		
		/* Receber quantas tropas serão adicionadas */
		do{
		Printar_mapa();
		cout<<"Digite quantas tropas quer adicionar ao pais "<< user <<endl;
		cout<<"Lembre-se voce possui "<<total<< " tropas!"<<endl;
		cin>>nadd;
		if(nadd > total && total > 1){
			cout<<"Digite um numero menor ou igual a "<<total<<endl;
			system("pause");
		}
		if(nadd > total && total == 1){
			cout<<"Voce possui apenas uma tropa" <<endl;
			system("pause");
		}
		}while(nadd > total);
		
		/* Realizando efetivamente a adição de tropas */
		paisesT[user - 'A'].nexercitos += nadd;
		total -= nadd;
	}
		
}

bool ataque(){
	int vitorias = 0, derrotas = 0;
	textcolor((*dono_da_vez).cor, 0);
	do{
	Printar_mapa();
	cout<<"Escolha o pais atacante ou digite . para encerrar os ataques\n";
	cin>>user;
	if(user == '.') return false;
	atacante = &paisesT[user-'A'];
	if((*atacante).player != dono_da_vez ){
		cout<<"Este pais nao te pertence\n";
		system("pause");
	}
	}while( (*atacante).player != dono_da_vez );
	if((*atacante).nexercitos == 1){
		cout<<"Paises com apenas 1 tropa nao podem atacar"<<endl;
		system("pause");
		return false;
	}
	
	do{
	Printar_mapa();
	cout<<"Escolha um pais inimigo para atacar\n";
	cin>>user;
	defensor = &paisesT[user-'A'];
	if( (*defensor).player == dono_da_vez ){
		cout<<"Este pais te pertence\n";
		system("pause");
	}
	}while( (*defensor).player == dono_da_vez );
	/* Fronteira */
	if(!faz_fronteira(atacante, defensor)){
		cout<<"Os paises nao fazem fronteira"<<endl;
		system("pause");
		return false;
	}
	
	/* rolagem de dados */
	rolar_dados((*atacante).nexercitos - 1, (*defensor).nexercitos);
	ordenar_dados();  
	system("cls");
	cout<<"\t\t\t\tComparando os dados:\n\n\n";
	for(int i=0; i < 3; i++){
		cout<<"\t\t\t\t\t";
		textcolor((*dono_da_vez).cor, 0);
		if(dado_atk[i] > 0)
		cout<< dado_atk[i];
		else cout<< ' ';
		textcolor(15, 0);
		cout<< "\t|\t";
		textcolor( (*(*defensor).player).cor, 0 );
		if(dado_def[i] > 0)
		cout<< dado_def[i];
		else cout<<' ';
		if(dado_atk[i] != 0 && dado_def[i] != 0){
		if(dado_atk[i] > dado_def[i])vitorias++;
		else derrotas++;
		}
		cout<<endl;
}
	textcolor((*dono_da_vez).cor, 0);
	cout<<"\nO ataque venceu "<< vitorias <<" vezes\n";
	(*atacante).nexercitos -= derrotas;
	(*defensor).nexercitos -= vitorias;
	system("pause");
	
	if((*defensor).nexercitos <= 0){
		system("cls");
		cout<<"\n\n\n\n\t\t\t\tPais conquistado. Voce esta feliz!";
		do{
		Printar_mapa();
		cout<<"Digite com quantas tropas quer invadir\n";
		if((*atacante).nexercitos < 4)
		cout<<"Lembre que deve ser no maximo "<< (*atacante).nexercitos - 1<<endl;
		else cout<<"Lembre que deve ser no maximo 3"<<endl;
		cin>>user_int;
		if( user_int > 3 || user_int < 1 ){
			system("cls");
			cout<<"\n\n\n\n\t\t\t\tValor invalido\n";
			system("pause");
		}
		}while(user_int > 3 || user_int < 1);
		
		(*atacante).nexercitos -= user_int;
		(*defensor).nexercitos += user_int;
		
		
		(*(*defensor).player).Ndominios--;
		(*dono_da_vez).Ndominios++;
		(*defensor).player = dono_da_vez;
	}
	
	Printar_mapa();
	
	return true;
}
/*									MAPA									  */
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
		if(j==y+1 && (i==x-1 || i==x || i==x+1))mapa[i][j]='0';
		else mapa[i][j] = '#';
	}
mapa[x+1][y+1] = '1';
	mapa[x][y]=nome;
}

void criarMapa();



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
	paisesT[17].fronteira[3] = &paisesT[(int)('T'-'A')];
	paisesT[17].fronteira[4] = &paisesT[(int)('U'-'A')];
	
	criarTerritorio(80, 15, 'S');
	paisesT[18].x = 80;
	paisesT[18].y = 15;
	paisesT[18].fronteira[0] = &paisesT[(int)('T'-'A')];
	
	criarTerritorio(85, 15, 'T');
	paisesT[19].x = 85;
	paisesT[19].y = 15;
	paisesT[19].fronteira[0] = &paisesT[(int)('R'-'A')];
	paisesT[19].fronteira[1] = &paisesT[(int)('S'-'A')];
	paisesT[19].fronteira[2] = &paisesT[(int)('U'-'A')];
	paisesT[19].fronteira[3] = &paisesT[(int)('W'-'A')];
	
	criarTerritorio(90, 15, 'U');
	paisesT[20].x = 90;
	paisesT[20].y = 15;
	paisesT[20].fronteira[0] = &paisesT[(int)('R'-'A')];
	paisesT[20].fronteira[1] = &paisesT[(int)('T'-'A')];
	paisesT[20].fronteira[2] = &paisesT[(int)('V'-'A')];
	paisesT[20].fronteira[3] = &paisesT[(int)('W'-'A')];
	
	criarTerritorio(95, 16, 'V');
	paisesT[21].x = 95;
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
	
	for(int i =98 ; i < 105 ; i++)
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
		if((*primeiro).fronteira[i] == segundo) return true;
	return false;
}

/*									AUXI	  								  */
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime>

using namespace std;

class Territorio;

class jogador{
public:
	int dominio[27];
	int id;
	char nome[20];
	int Ndominios;
	int cor;
};

class Territorio{
    public:
    jogador* player;
    int x, y, id;
    Territorio* fronteira[5];
    int nexercitos;
};

Territorio paisesT[26]; /* declarando os paises */
jogador player1, player2;
jogador* dono_da_vez;
char user;
int user_int;
bool fim = false;
int dado_atk[3];
int dado_def[3];

void ordenar_dados();
int random(int menor, int maior);
void roll_atk(int n);

int turno=1;

void ordenar_dados(){
	int aux[3]={0,0,0}, p[3]={0,0,0};
	/* ordenando os dados de ataque */
	for(int i=0; i<3; i++)
	if(aux[0] < dado_atk[i] ){
	aux[0] = dado_atk[i]; // guarda o maior em aux
	p[0] = i;
	}
	
	for(int i=0; i<3; i++)
	if(aux[1] < dado_atk[i] && i != p[0]) {
	aux[1] = dado_atk[i]; // guarda o intermediario em aux
	p[1] = i;
	}
	
	for(int i=0; i<3; i++)
	if(i != p[0] && i != p[1]) aux[2] = dado_atk[i]; // guarda o menor em aux
	
	for(int i=0; i<3; i++){
		dado_atk[i] = aux[i];
		aux[i] = 0;
		p[i]=0;
		}
	/* ordenando os dados de defesa */
	for(int i=0; i<3; i++)
	if(aux[0] < dado_def[i] ){
	aux[0] = dado_def[i]; // guarda o maior em aux
	p[0] = i;
	}
	
	for(int i=0; i<3; i++)
	if(aux[1] < dado_def[i] && i != p[0]) {
	aux[1] = dado_def[i]; // guarda o intermediario em aux
	p[1] = i;
	}
	
	for(int i=0; i<3; i++)
	if(i != p[0] && i != p[1]) aux[2] = dado_def[i]; // guarda o menor em aux
	
	for(int i=0; i<3; i++){
		dado_def[i] = aux[i];
		aux[i] = 0;
		p[i] = 0;
		}
	
}

int random(int menor, int maior){
	return rand()%(maior-menor+1)+menor;
}


void rolar_dados(int num_atk, int num_def){
	if(num_atk > 3)num_atk = 3;
	if(num_def > 3)num_def = 3;
	
	for(int i=0; i<3; i++){
		dado_atk[i] = 0;
		dado_def[i] = 0;
	}
	for(int i=0; i<num_atk; i++){
		dado_atk[i] = random(1, 6);
	}
	for(int i=0; i<num_def; i++){
		dado_def[i] = random(1, 6);
	}
	
}