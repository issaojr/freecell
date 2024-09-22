#ifndef _PILHAINTER_H_
#define _PILHAINTER_H_
#include "pilha.h"

/*
 * Cabecalho da PilhaInter.
 * Esta classe e' responsavel pelos 4 espacos intermediarios do jogo.
 * Optou-se por deriva-la da classe Pilha pois com isso e' possivel
 * aproveitar os metodos de empilha e desempilha, padronizando a
 * implementacao.
 */
class PilhaInter : public Pilha
{
public:
	PilhaInter();
	~PilhaInter();
};

#endif

