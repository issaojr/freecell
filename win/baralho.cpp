#include "carta.h"
#include "baralho.h"
#include "pilha.h"
#include <cstdlib>
#include <ctime>

/*
 * A classe Baralho e' uma pilha. Assim, ela foi desenhada como
 * derivada da classe Pilha.
 * Esta classe instancia todas as 52 cartas e empilha-as.
 */
Baralho::Baralho() : Pilha::Pilha()
{
	int i;
	int n, v;
	cartas = new Carta[52]; // cria espacos para cartas

	srand(time(NULL));

	for(i = 0; i < 52; i++){
		do
		{
			n = rand() % 4;
			v = rand() % 13;
		} while(Carta::jaExiste(n,v));
		c = new Carta(n + 1, v + 1);
		empilha(c);
		delete c;
	}
}

Baralho::~Baralho()
{
	delete [] cartas;
}

