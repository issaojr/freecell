#include "freecell.h"
#include "pilha.h"
#include "baralho.h"
#include "pilhaini.h"
#include "pilhainter.h"
#include "pilhafim.h"
#include "carta.h"

Freecell::Freecell(Baralho *baralho)
{
	int i;
	this->baralho = baralho;
	for(i = 0; i < 8; i++)
		pInicial[i] = new PilhaIni();
	for(i = 0; i < 4; i++)
	{
		pInter[i] = new PilhaInter();
		pFinal[i] = new PilhaFim();
	}
}

Freecell::~Freecell()
{
	int i;
	for(i = 0; i < 8; i++)
		delete pInicial[i];
	for(i = 0; i < 4; i++)
	{
		delete pInter[i];
		delete pFinal[i];
	}
}

bool Freecell::inicia()
{
	int i = 0;

	while(!baralho->estaVazia())
	{
		if(!(Freecell::distribui(pInicial[i])))
			return false;
		if(i == 7)
			i = 0;
		else
			i++;
	}

	return true;
}

bool Freecell::distribui(Pilha *destino)
{
	Carta cAux;

	cAux = baralho->desempilha();

	if(destino->Pilha::empilha(&cAux))
		return true;
	else{
		baralho->empilha(&cAux);
		return false;
	}
}

bool Freecell::move(Pilha *origem, Pilha *destino)
{
	Carta cAux;

	if(!origem->estaVazia())
	{
		cAux = origem->desempilha();
		if(destino->empilha(&cAux))
			return true;
		else{
			origem->Pilha::empilha(&cAux);
			return false;
		}
	}
	else
		return false;
}

bool Freecell::ganhou()
{
	bool p[4];
	int i;

	//for(i = 0; i < 4; i++) // PARA TESTES
		//p[i] = true;
	for(i = 0; i < 4; i++)
		p[i] = pFinal[i]->estaCheia();

	return (p[0] && p[1] && p[2] && p[3]);
}

PilhaIni *Freecell::getPini(int i)
{
	return pInicial[i];
}

PilhaFim *Freecell::getPfim(int i)
{
	return pFinal[i];
}

PilhaInter *Freecell::getPinter(int i)
{
	return pInter[i];
}

