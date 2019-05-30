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
			while(user != '3'){
			user='1';
			
			while(user == '1'){
			Printar_mapa();
			cout<<"\t\tDigite 1, para mover tropas ou digite 2 para atacar ou 3 para passar a vez.\n";
			cin>>user;
			system("cls");
			if(user == '1')
			user = mover_tropas();
			
			}
			while(user == '2'){
				ataque();
				cout<<"Para continuar atacando, digite 2\n"<<"Digite qualquer outra tecla para passar a vez\n"; 
	   	   	   	cin>>user;
		}

		
			if((*dono_da_vez).Ndominios == 0) fim = true;
			if(fim){
				system("cls");
				cout<<"\n\n\n\n\n\t\t\t\tParabens "<<(*dono_da_vez).nome<<" voce venceu!!!\n";
				cout<<"\t\t\t\tVoce esta muito feliz";
			}	
		}
		turno++;	
		}
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
	cout<<"\t OBS: O numero de tropas e definino apartir do numero de paises que o jogador possui dividido por 2\n caso este numero seja impar o numero de tropas sera aproximado para seu antecessor\n"<<endl;
	cout<<"3- Ao termino da distribuicao, o jogador poderar remanejar as tropas, apenas para paises\n que lhe pertence e que possuem fronteira entre si\n"<<endl;
	cout<<"\t OBS: O jogador pode opitar por nao mover nenhuma tropa.\n"<<endl;
	cout<<"\t OBS2: O jogador so pode mover tropas no seu turno.\n"<<endl;
	cout<<"*ATAQUE E DEFESA*"<<endl;
	cout<<"1- O ataque so pode ser feito por paises com mais de um exercito em seu territorio\n"<<endl;
	cout<<"2- O jogador so podera realizar o ataque ao pais inimigo que faz fronteira com o de seu dominio.\n"<<endl;
	cout<<"3- Para vencer o ataque, ao jogar os dados e necessario tirar um numero maior que o da defesa\n"<<endl;
	cout<<"\t OBS: Em caso de empeta, a defesa sempre ira vencer\n"<<endl;
	cout<<"4- O jogador pode atacar um pais com quantos exercitos desejar, porem so poderar usar no maximo 3 dados\n"<<endl;
	cout<<"*TURNO*"<<endl;
	cout<<"Um turno consiste em:\n*Distribuir tropas\n*Remanejar as tropas(opcional)\n*Ataque(opcional)\n\nNESTA ORDEM!\n"<<endl;
	system("pause");
	system("cls");
	
cout<<"\n\n\n\n"<<endl;
cout<<"\tOBS: Voce ser o player 1 nao significa que ira iniciar o jogo!"<<endl;
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