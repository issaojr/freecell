#ifndef _IU_H_
#define _IU_H_

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include "freecell.h"
#include "pilha.h"

using namespace std;

/*
 * Classe responsavel pela interface de usuario.
 * A interface e' baseada em CONIO.
 */
class Iu
{
private:
	Freecell *jogo; // ponteiro para objeto jogo
public:
	Iu(Freecell *jogo);
	void telaInicial();
	void telaFinal();
	void printTela();
	void printPilhaIni();
	void menu();
	int entrada();
	bool movimente(int p1, int orig, int p2, int dest);
	int congratulacoes();
	int confirma();
	int ajuda();
	int movInvalido();
	int comDesconhecido();
	void desenhaCarta(int, int, int, int);
	void desenhaEspaco(int);
};

#endif
