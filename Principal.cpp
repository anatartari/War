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
		Printar_mapa();
		if(turno % 2 ) dono_da_vez = &player1;
		else dono_da_vez = &player2;
		mover_tropas();
		Printar_mapa();
		
	/*	while( !fim ){
		if(turno % 2 ) dono_da_vez = &player1;
		else dono_da_vez = &player2;
		
		
			distribuir_tropas();
			system ("cls");
			burro='1';
			
			while(burro == '1'){
			cout<<"\n\n\n\n\t\tDigite 1, para mover tropas ou digite 2 para atacar ou 3 para passar a vez.\n";
			cin>>burro;
			system("cls");
			if(burro == '1')
			burro = mover_tropas();
			
			}
			
			
			system("cls");
			Printar_mapa();
			if(burro == '2'){
				cout<<"\n\n\n\n\t\tSelecione o pais atacante: "; 
				cin>>burro;
				atacante = paisesT[(int)(burro - 'A')];
				cout<<"\n\n\t\tSelecione quem vai receber porrada: ";
				cin>>burro;
				defensor = paisesT[(int)(burro - 'A')];
				porradaria();
			}
			
		turno++;	
		}*/
		
	return 0;
}


void Menu(){
	cout<<"\n\n\n\n"<<endl;
	cout<< "\t\t Bem-vindxs, ao WAR das Damas de Maria."<<endl;
	cout<<"\n\n\n\n"<<endl;
	cout<<"\t\t[Digite qualquer tecla para continuar]"<<endl;
	cout<<"\n\n\n\n"<<endl;
	getch();
	system("cls");
	
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