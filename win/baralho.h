#ifndef _BARALHO_H_
#define _BARALHO_H_
#include "pilha.h"

/*
 * Cabecalho da classe Baralho.
 * A classe Baralho e' uma pilha. Assim, ela foi desenhada como
 * derivada da classe Pilha.
 * Esta classe instancia todas as 52 cartas e empilha-as.
 */
class Baralho : public Pilha
{
private:
	Carta *c; // ponteiro para Carta
public:
	Baralho(); // inicializa o baralho
	~Baralho(); // destroi o baralho
};

#endif
