#ifndef _FREECELL_H_
#define _FREECELL_H_

#include "pilha.h"
#include "baralho.h"
#include "pilhaini.h"
#include "pilhainter.h"
#include "pilhafim.h"
#include "carta.h"

class Freecell
{
private:
	PilhaIni *pInicial[8];
	PilhaFim *pFinal[4];
	PilhaInter *pInter[4];
	Baralho *baralho;
public:
	Freecell(Baralho *baralho);
	~Freecell();
	bool inicia();
	bool distribui(Pilha *destino);
	bool move(Pilha *origem, Pilha *destino); // polimorfismo puro!!!! :-D
	bool ganhou();
	PilhaIni *getPini(int i);
	PilhaFim *getPfim(int i);
	PilhaInter *getPinter(int i);
};

#endif

