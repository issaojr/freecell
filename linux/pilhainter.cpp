#include "pilha.h"
#include "carta.h"
#include "pilhainter.h"

/*
 * Cabecalho da PilhaInter.
 * O construtor aloca memoria para uma Carta somente.
 */
PilhaInter::PilhaInter() : Pilha::Pilha()
{
	tamMax = 1;
	cartas = new Carta[tamMax];
}

// destrutor
PilhaInter::~PilhaInter()
{
	delete [] cartas;
}
