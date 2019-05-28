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
    int x, y;
    Territorio* fronteira[4];
    int nexercitos;
};

Territorio paisesT[26]; /* declarando os paises */
jogador player1, player2;
jogador* dono_da_vez;
char burro;
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