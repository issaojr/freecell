#include "freecell.h"
#include "iu.h"
#include <iostream>
#include <cstdio>
#include "conio/conio.h"
#include <ncurses.h>

using namespace std;

/*
 * Funcao principal.
 */
int main()
{	
	int opcao;
	bool ganhou;	

	Baralho *baralho;
	Freecell *jogo;
	Iu *iu;

	opcao = 1;
	// partida
	/*
	 * Aloca espaco para os objetos Baralho, Freecell
	 * e Iu.
	 */
	baralho = new Baralho();
	jogo = new Freecell(baralho);
	jogo->inicia();
	iu = new Iu(jogo);
	iu->telaInicial();

	 while(opcao == 1)
	{
		ganhou = false;
		iu->printTela();

		do {
			// recebe a entrada dos usuarios
			opcao = iu->entrada();
			if(opcao != 0 && opcao != 1)
			{				
				// desenha a tela
				iu->printTela();
				ganhou = jogo->ganhou();
			}
		} while(!ganhou && (opcao != 0 && opcao != 1));
		if(ganhou)
		{
			opcao = iu->congratulacoes();
		}
		/*
		 * Se usuario optou por "novo jogo", desaloca-se a
		 * memoria.
		 */
		if(opcao == 1)
		{
			delete iu;
			delete jogo;
			delete baralho;
			baralho = new Baralho();
			jogo = new Freecell(baralho);
			jogo->inicia();
			iu = new Iu(jogo);
		}
	}
	iu->telaFinal();

	/*
	 * desaloca a memoria para encerrar o jogo.
	 */
	delete iu;
	delete jogo;
	delete baralho;

	cout << endl << endl;
	
	cin.get();	

	return 0;
}
