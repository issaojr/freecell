#ifndef _PILHAINI_H_
#define _PILHAINI_H_
#include "pilha.h"

/*
 * Cabecalho da PilhaIni.
 * Esta pilha acomoda as cartas em suas posicoes iniciais.
 * Possui um metodo empilha() proprio.
 */
class PilhaIni : public Pilha
{
public:
	PilhaIni();
	~PilhaIni();
	bool empilha(Carta *x); // sobreposicao de metodo
};

#endif

