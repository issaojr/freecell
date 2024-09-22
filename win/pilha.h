#ifndef _PILHA_H_
#define _PILHA_H_

/*
 * Implementacao da classe Pilha.
 * A classe Pilha consiste em uma pilha de cartas generica, ou seja,
 * nao possui as regras de empilhamento do jogo Freecell.
 */
#include "carta.h"
class Pilha
{
protected:
	int tamMax;
	int topo;
	Carta *cartas; // fazer alocacao dinamica nas classes filhas

public:
	Pilha(); // construtor
	/*
	 * O destrutor da Pilha deve ser virtual, uma vez que existem metodos
	 * virtuais na Pilha.
	 */
	virtual ~Pilha();
	/*
	 * O metodo abaixo e' virtual pois as classes derivadas podem imple-
	 * mentar seu proprio metodo empilha. Isso permite o polimorfismo.
	 */
	virtual bool empilha(Carta *c); //retorna true se for possivel empilhar
	Carta desempilha();
	Carta cartaTopo(); // retorna o objeto carta do topo da pilha
	bool estaVazia(); // retorna true se estiver vazia a pilha
	bool estaCheia(); // retorna true se a pilha estiver cheia
};

#endif

