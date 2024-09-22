#ifndef _IU_H_
#define _IU_H_

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include "freecell.h"
#include "pilha.h"

using namespace std;

class Iu
{
private:
	Freecell *jogo;
	//PilhaIni auxIni[8];
	
	void linhaH(int col);
	void linhaId(int valor,int naipe, int col);
	void linhaVazia(int col);
	void linhaFinal(int col);
	
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
};

#endif
