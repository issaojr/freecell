#include "pilha.h"
#include "carta.h"
#include "pilhafim.h"

/*
 * Construtor da PilhaFim.
 * tamanho maximo de 13 cartas
 */
PilhaFim::PilhaFim() : Pilha::Pilha()
{
	tamMax = 13;
	cartas = new Carta[tamMax];
}

// destrutor
PilhaFim::~PilhaFim()
{
	delete [] cartas;
}

/*
 * O metodo a seguir sobrepoe o metodo empilha.
 * Com este metodo empilha-se com a regra adequada.
 */
bool PilhaFim::empilha(Carta *c)
{
	Carta cTopo;
	int vTopo, vEntra; // para comparacao de valores
	int nTopo, nEntra; // para comparacao de naipes

	if(!this->estaVazia())
	{
		cTopo = this->cartaTopo();
		vTopo = cTopo.getValor();
		vEntra = c->getValor();

		nTopo = cTopo.getNaipe();
		nEntra = c->getNaipe();

		if(vEntra == vTopo + 1 && nTopo == nEntra)
		{
			this->Pilha::empilha(c);
			return true;
		}
	}
	else
	{
		cTopo = this->cartaTopo();
		vTopo = cTopo.getValor();
		vEntra = c->getValor();

		if(vEntra == 1)
		{
			this->Pilha::empilha(c);
			return true;
		}
	}
	return false;
}

