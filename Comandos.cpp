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



char mover_tropas(){
	int num=0;
	Territorio* pais_origem;
	Territorio* pais_destino;
	
	do{
			system("cls");
			Printar_mapa();
			cout<<"\n\nDigite o pais de origem: ";
			cin>>user;
			pais_origem = &paisesT[(int)(user - 'A')];
		if((*pais_origem).player != dono_da_vez){
			cout<<"Esse pais nao te pertence!\n";
			system("pause");
		}
	
	}while((*pais_origem).player != dono_da_vez);
	
	do{	
		system("cls");
		Printar_mapa();
		cout<<"Digite o pais destino: ";
		cin>>user;
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
		return '1';
	}
	if((*pais_origem).nexercitos == 1 ){
		cout<<"Voce nao pode mover paises que possuem apenas 1 tropa\n";
		system("pause");
		return '1';
	}
	
	do{
	cout<<"Digite o numero de tropas a serem movidas: ";
	cin>>num;
	if(num > (*pais_origem).nexercitos ){
		cout<<"Ao menos 1 tropa deve permanecer no territorio de origem\n";
		system("pause");
	}
	}while( num > (*pais_origem).nexercitos );
	
	(*pais_origem).nexercitos -= num;
	(*pais_destino).nexercitos += num;
	
	return '1';
}


void num_exercito (Territorio add){
	int X=add.x, Y=add.y;
	char unidade, dezena, centena;
	unidade = add.nexercitos%10 + 48;
	dezena = (add.nexercitos/10)%10 + 48;   /* pega a parte inteira da divis�o */
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
		
		/* Receber quantas tropas ser�o adicionadas */
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
		
		/* Realizando efetivamente a adi��o de tropas */
		paisesT[user - 'A'].nexercitos += nadd;
		total -= nadd;
	}
		
}

void ataque(){
	int vitorias = 0, derrotas = 0;
	textcolor((*dono_da_vez).cor, 0);
	do{
	Printar_mapa();
	cout<<"Escolha o pais atacante\n";
	cin>>user;
	atacante = &paisesT[user-'A'];
	if((*atacante).player != dono_da_vez ){
		cout<<"Este pais nao te pertence\n";
		system("pause");
	}
	}while( (*atacante).player != dono_da_vez );
	
	
	do{
	Printar_mapa();
	cout<<"Escolha um pais inimigo para atacar\n";
	cin>>user;
	defensor = &paisesT[user-'A'];
	if( (*atacante).player != dono_da_vez ){
		cout<<"Este pais te pertence\n";
		system("pause");
	}
	}while( (*atacante).player != dono_da_vez );
	
	do{
		Printar_mapa();
		cout<<"Digite quantas tropas deseja usar no ataque\n";
		cin>>user_int;
		if(user_int > 3 || user_int >= (*atacante).nexercitos){
		cout<<"O numero deve ser menor ou igual a 3 e menor que "<<(*atacante).nexercitos<<endl;
		system("pause");
	}
	}while(user_int > 3 || user_int >= (*atacante).nexercitos);
	
	rolar_dados(user_int, (*defensor).nexercitos);
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
		if(dado_atk[i] != 0 && dado_def != 0){
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
		(*atacante).nexercitos--;
		(*defensor).nexercitos = 1;
		(*(*defensor).player).Ndominios--;
		(*dono_da_vez).Ndominios++;
		(*defensor).player = dono_da_vez;
	}
	
	Printar_mapa();
	
	cout<<"Para continuar atacando, digite 2\n"<<"Digite qualquer outra tecla para passar a vez\n"; 
	cin>>user;
}








