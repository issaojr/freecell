#include "carta.h"
#include "pilha.h"
#include "pilhaini.h"

using namespace std;

/*
 * Implementacao da PilhaIni.
 * Esta pilha acomoda as cartas em suas posicoes iniciais.
 * Possui um metodo empilha() proprio.
 */
PilhaIni::PilhaIni() : Pilha::Pilha()
{
	tamMax = 19;
	cartas = new Carta[tamMax]; // cria espacos vazios para cartas
}

/*
 * O destrutor da PilhaIni desaloca a memoria alocada para as cartas.
 */
PilhaIni::~PilhaIni()
{
	delete [] cartas;
}

/*
 * Metodo que sobrepoe metodo empilha() da classe base Pilha. Trata-se de uma
 * implementacao alternativa, que acrescenta regra de empilhamento
 */
bool PilhaIni::empilha(Carta *c)
{
	Carta cTopo;
	int vTopo, vEntra;
	bool nTopo, nEntra;

	cTopo = this->cartaTopo();
	vTopo = cTopo.getValor();
	vEntra = c->getValor();

	//naipes vermelhos (ouros e copas) sao impares, naipes pretos, pares
	nTopo = cTopo.getNaipe() % 2 == 0;
	nEntra = c->getNaipe() % 2 == 0;

	if(vEntra == vTopo -1 && nTopo != nEntra || this->estaVazia())
	{
		cartas[++topo] = *c;
		return true;
	}else{
		return false;
	}
}
