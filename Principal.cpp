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
		//distribuir_paises2();// modo de teste
		int r = random(0, 1); /* r serve para escolher a ordem */
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
		
		
		/* Jogo */
		while( !fim ){
		if(turno % 2 ) dono_da_vez = &player1;
		else dono_da_vez = &player2;
		
		if(r == 0){
		if(turno % 2 ) dono_da_vez = &player2;
		else dono_da_vez = &player1;
		}
		
		textcolor((*dono_da_vez).cor, 0);
		if(!strcmp((*dono_da_vez).nome, "LAPA S2 POG"))fim = true;
		if(fim){
					system("cls");
					cout<<"\n\n\n\n\n\t\t\t\tParabens "<<(*dono_da_vez).nome <<" voce derrotou o inimigo!!!\n";
					cout<<"\t\t\t\tVoce esta muito feliz" << endl;
					break;
				}
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
					cout<<"\n\n\n\n\n\t\t\t\tParabens "<<(*dono_da_vez).nome <<" voce derrotou o inimigo!!!\n";
					cout<<"\t\t\t\tVoce esta muito feliz" << endl;
					break;
				}
			
				
			/* mover */
			for(int i=0; i < 26; i++)
			paisesTaux[i] = paisesT[i]; /* igualando a variavel auxiliar com o vetor dos paises */
			do{
			if(!mover_tropas())
					break;
			}while(true);

		turno++;	
		}
		/* pós jogo */
		if(r == 0){
		if(turno % 2 ) dono_da_vez = &player1;
		else dono_da_vez = &player2;
		textcolor((*dono_da_vez).cor, 0);
		cout<<"\n\n\t\t\t\t"<<(*dono_da_vez).nome <<", voce foi derrotado!"<<endl;
		cout<<"\t\t\t\tVoce esta muito triste\n\n\n\n\n\n\n\n\n\n\n";
}
		else{
		if(turno % 2 ) dono_da_vez = &player2;
		else dono_da_vez = &player1;
		textcolor((*dono_da_vez).cor, 0);
		cout<<"\n\n\t\t\t\t"<<(*dono_da_vez).nome <<", voce foi derrotado!"<<endl;
		cout<<"\t\t\t\tVoce esta muito triste\n\n\n\n\n\n\n\n\n\n\n";
		}
		textcolor(15, 0);
	return 0;
}


void Menu(){
	cout<<"\n\n\n\n\n\n"<<endl;
	cout<<"\t\t\t\t\t\t\t Bem-vindxs, ao WAR das Damas de Maria."<<endl;
	cout<<"\n\n\n\n\n\n"<<endl;
	cout<<"\t\t\t\t\t\t\t[Digite qualquer tecla para continuar]"<<endl;
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
	cout<<"3- Ao termino da distribuicao e do ataque, o jogador poderar remanejar as tropas, apenas para paises\n que lhe pertencem e que possuem fronteira entre si\n"<<endl;
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
	textcolor(player1.cor, 0);
	cout<<"\n\n\n\n"<<endl;
	cout<< "\t\t Digite o apelido do Jogador Azul: ";
	gets(player1.nome);
	textcolor(player2.cor, 0);
	cout<<"\n\n\n\n"<<endl;
	cout<< "\t\t Digite o apelido do Jogador Vermelho: ";
	gets(player2.nome); 
	textcolor(15, 0);
	
}