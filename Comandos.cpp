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

   /* HANDLE h = GetStdHandle ( STD_OUTPUT_HANDLE );
    CONSOLE_SCREEN_BUFFER_INFO csbiInfo;


    GetConsoleScreenBufferInfo(h, &csbiInfo);*/

    SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),color  + 16* background );
}



//Jogo normal
void distribuir_paises(){
	int aux;
	for(int i=0; i<26 ;){
		aux=random(1, 2);
		if(aux == 1 && player1.Ndominios < 13){
			paisesT[i].player = &player1;
			player1.dominio[player1.Ndominios] = i;
			player1.Ndominios++;	
			i++;
		}else if(aux == 2 && player2.Ndominios < 13){
			paisesT[i].player = &player2;
			player2.dominio[player2.Ndominios] = i;
			player2.Ndominios++;	
			i++;
		}
	}
}
//Modo de teste
void distribuir_paises2(){
	int aux;
	for(int i=0; i<26 ;){
		aux=random(0, 1);
		if(aux == 0 && player1.Ndominios < 1){
			paisesT[i].player = &player1;
			player1.dominio[player1.Ndominios] = i;
			player1.Ndominios++;	
			i++;
		}else if(aux == 1 && player2.Ndominios < 25){
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
		//Deixa Branco
		if(mapa[i][j] == ' ' || mapa[i][j] == '+')
			textcolor(15, 0);
		else if(mapa[i][j] == '#' || mapa[i][j] < 'A') textcolor(15, 0);
		//Deixar colorido
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
			if(user == '.') return false; /* condi��o para encerrar o movimento */
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
		
		/* condi��o para encerrar o movimento */
		if(user == '.') return false; 
		pais_destino = &paisesT[(int)(user - 'A')];
	if((*pais_destino).player != dono_da_vez){
		cout<<"Esse pais nao te pertence!\n";
		system("pause");
	}
	}while((*pais_destino).player != dono_da_vez);
	
	/* TESTANDO FRONTEIRA */
	bool front = faz_fronteira(pais_origem, pais_destino);
	if(!front){
		cout<<"Estes paises nao possuem fronteiras entre si!\n";
		system("pause");
		return true;
	}
	if( paisesTaux[(*pais_origem).id].nexercitos == 1 ){
		cout<<"Voce nao pode mover tropas de paises que possuem apenas 1 tropa no inicio do turno\n";
		system("pause");
		return true;
	}
	
	do{
	Printar_mapa();
	cout<<"Digite o numero de tropas a serem movidas de "<< (char)((*pais_origem).id + 'A')<<" para "<< (char)((*pais_destino).id + 'A');
	cout<<" (no maximo " << paisesTaux[(*pais_origem).id].nexercitos << ")\n";
	cin>>num;
	if(num >= paisesTaux[(*pais_origem).id].nexercitos ){
		cout<<"\nNumero de tropas invalido\n\n";
		system("pause");
	}
	}while( num >= paisesTaux[(*pais_origem).id].nexercitos );
	
	(*pais_origem).nexercitos -= num;
	(*pais_destino).nexercitos += num;
	
	
	return true;
}

//Atualiza o N� de exercito no mapa
void num_exercito (Territorio add){
	int X=add.x, Y=add.y;
	char unidade, dezena, centena;
	unidade = add.nexercitos%10 + 48;
	dezena = (add.nexercitos/10)%10 + 48;   /* pega a parte inteira da divis�o (Notas e moedas)(ASCII) */
	centena = (add.nexercitos/100)%10 + 48;
	
	mapa[X+1][Y+1] = unidade;
	mapa[X][Y+1] = dezena;
	mapa[X-1][Y+1] = centena;
	
}


void distribuir_tropas(){
	int total = (*dono_da_vez).Ndominios/2;
	if(total < 3)total = 3;
	
	while(total > 0){
		int nadd; //Numero de tropas que o usuario quer/vai colocar.
		
		/* Ler o pais que vai receber as tropas */
		do{
			Printar_mapa();
			cout<<"Digite a que pais quer adicionar tropas\n";
			cin>>user;
			if(paisesT[user-'A'].player != dono_da_vez){
				cout<<"Este pais nao te pertence\n";
				system("pause");
			}
		}while(paisesT[user - 'A'].player != dono_da_vez);
		
		/* Ler quantas tropas ser�o adicionadas */
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
			cout<<"Voce possui apenas uma tropa para distribuir" <<endl;
			system("pause");
		}
		}while(nadd > total);
		
		/* Realizando efetivamente a adi��o de tropas */
		paisesT[user - 'A'].nexercitos += nadd;
		total -= nadd;
	}
		
}

bool ataque(){
	int vitorias = 0, derrotas = 0;
	textcolor((*dono_da_vez).cor, 0);
	
	//Escolha do pais atacante
	do{
	Printar_mapa();
	cout<<"Escolha o pais atacante ou digite . para encerrar os ataques\n";
	cin>>user;
	//Verifica se o jogador n�o quer mais atacar
	if(user == '.') return false;
	
	atacante = &paisesT[user-'A'];

	//Verifica��o do proprietario
	if((*atacante).player != dono_da_vez ){
		cout<<"Este pais nao te pertence\n";
		system("pause");
	}
	}while( (*atacante).player != dono_da_vez );
	
	//Verifica se o pais tem mais de 1 tropa
	if((*atacante).nexercitos == 1){
		cout<<"Paises com apenas 1 tropa nao podem atacar"<<endl;
		system("pause");
		return false;
	}
	
	//Escolhe o pais que sera atacado
	do{
	Printar_mapa();
	cout<<"Escolha um pais inimigo para atacar ou digite . para encerrar os ataques\n";
	cin>>user;
	//Verifica se o jogador n�o quer mais atacar
	if(user == '.') return false;
	
	defensor = &paisesT[user-'A'];

	//Verifica se o pais pertence ao jogador
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
		
		//pro dado ficar da cor certa
		textcolor( (*(*defensor).player).cor, 0 );
		if(dado_def[i] > 0)
		cout<< dado_def[i];
		else cout<<' ';
		
		//Conta as vitorias e derrotas
		if(dado_atk[i] != 0 && dado_def[i] != 0){
		if(dado_atk[i] > dado_def[i])vitorias++;
		else derrotas++;
		}
		cout<<endl;
}
	textcolor((*dono_da_vez).cor, 0);
	cout<<"\nO ataque venceu "<< vitorias <<" vezes\n"<<endl;
	cout<<"\nO atacante perdeu "<<derrotas <<" tropas"<<endl;
	cout<<"\nO defensor perdeu "<<vitorias <<" tropas"<<endl;
	(*atacante).nexercitos -= derrotas;
	(*defensor).nexercitos -= vitorias;
	system("pause");
	
	if((*defensor).nexercitos <= 0){
		system("cls");
		cout<<"\n\n\n\n\t\t\t\tPais conquistado. "<<(*dono_da_vez).nome<<" esta feliz!";
		do{
		Printar_mapa();
		//Colocar tropas no territorio conquistado
		cout<<"Digite com quantas tropas quer invadir\n";
		if((*atacante).nexercitos < 4)
		cout<<"Lembre que devem ser no maximo "<< (*atacante).nexercitos - 1<<endl;
		else cout<<"Lembre que deve ser no maximo 3"<<endl;
		cin>>user_int;
	
		if( user_int > 3 || user_int < 1 || user_int > (*atacante).nexercitos - 1){
			system("cls");
			cout<<"\n\n\n\n\t\t\t\tValor invalido\n";
			system("pause");
		}
		}while(user_int > 3 || user_int < 1);
		//Tira do territorio e coloca no outro
		(*atacante).nexercitos -= user_int;
		(*defensor).nexercitos += user_int;
		
		//Atualiza a variavel de numeros de territorios
		(*(*defensor).player).Ndominios--;
		(*dono_da_vez).Ndominios++;
		(*defensor).player = dono_da_vez;
	}
	
	Printar_mapa();
	
	return true;
}








