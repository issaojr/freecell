#include "pilha.h"
#include "carta.h"
#include <iostream>
using namespace std;

/*
 * Cabecalho da classe Pilha.
 * A classe Pilha consiste em uma pilha de cartas generica, ou seja,
 * nao possui as regras de empilhamento do jogo Freecell.
 */
Pilha::Pilha()
{
	topo = -1;
	tamMax = 52;
}

Pilha::~Pilha(){ }

// ver comentarios no arquivo pilha.h
bool Pilha::empilha(Carta *c)
{
	if(topo < tamMax - 1){
		cartas[++topo] = *c;
		return true;
	}else
		return false;
}

// ver comentarios no arquivo pilha.h
Carta Pilha::desempilha()
{
	return cartas[topo--];
}

// ver comentarios no arquivo pilha.h
Carta Pilha::cartaTopo()
{
	return cartas[topo];
}

// ver comentarios no arquivo pilha.h
bool Pilha::estaVazia(){
	return (topo == -1);
}

// ver comentarios no arquivo pilha.h
bool Pilha::estaCheia(){
	return (topo == tamMax - 1);
}
