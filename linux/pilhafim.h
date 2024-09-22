#ifndef _PILHAFIM_H_
#define _PILHAFIM_H_

/*
 * Classe PilhaFim.
 * Essa classe e' responsavel pelas pilhas finais.
 * Cada objeto recebe no maximo 13 cartas.
 */
class PilhaFim : public Pilha
{
public:
	PilhaFim();
	~PilhaFim();
	bool empilha(Carta *x); // sobreposicao de metodo
};

#endif

