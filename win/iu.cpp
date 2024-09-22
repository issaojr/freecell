/*
 * Interface de usuario, versao Windows. Com base em CONIO.
 */

#include "iu.h"
#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <string>
#include "conio/conio.h"

using namespace std;

/*
 * Construtor. Recebe um objeto do tipo Freecell por referencia.
 */
Iu::Iu(Freecell *jogo)
{
	this->jogo = jogo;
}

/*
 * Desenho da tela inicial. Esta tela aparece somente uma vez na
 * execucao do jogo. E' a tela de abertura.
 */
void Iu::telaInicial()
{
	textbackground(LIGHTGRAY);
	textcolor(WHITE);
	window(1,1,80,52);

	textbackground(YELLOW);
	window(21,15,60,26);
	textbackground(BLUE);
	textcolor(WHITE);
	window(23,16,58,25);
	cprintf("                                    ");
	cprintf("                                    ");
	cprintf("              FREECELL              ");
	cprintf("           V.1.0.1 - 2008           ");
	cprintf("                                    ");
	cprintf("           Seja Bem-Vindo!          ");
	cprintf("                                    ");
	_setcursortype(0);
	getch();
}

/*
 * Tela de encerramento do programa. Ocorre somente uma vez durante
 * a execucao.
 */
void Iu::telaFinal()
{
	textbackground(LIGHTGRAY);
	textcolor(WHITE);
	window(1,1,80,52);

	textbackground(YELLOW);
	window(21,15,60,26);
	textbackground(BLUE);
	textcolor(WHITE);
	window(23,16,58,25);
	cprintf("                                    ");
	cprintf("                                    ");
	cprintf("                                    ");
	cprintf("               %c%c%c%c                 ",3,4,5,6);
	cprintf("                                    ");
	cprintf("        OBRIGADO POR JOGAR!         ");
	cprintf("                                    ");
	cprintf("               %c%c%c%c                 ",6,5,4,3);
	cprintf("                                    ");
	cprintf("                                    ");
	_setcursortype(0);
	getch();
}

/*
 * Metodo responsavel por desenhar a tela de jogo. Este metodo e'
 * chamado apos cada entrada do usuario para efetuar o redesenho
 * da tela.
 */
void Iu::printTela()
{
	int i, v, n;
	int coluna; // para desenho com conio

	clrscr(); // limpa tela

	_setcursortype(_NORMALCURSOR);

	textbackground(GREEN);
	textcolor(WHITE);
	window(1,1,80,52);

	// Menu de opcoes
	Iu::menu();

	//cabecalho das pilhas superiores
	printf("    1        2        3        4        5        6        7        8    \n");

	/*
	 * Espacos intermediarios, de 1 ate 4.
	 */
	coluna = 1;
	for(i = 0; i < 4; i++)
	{
		if(!jogo->getPinter(i)->estaVazia())
		{
			v = jogo->getPinter(i)->cartaTopo().getValor();
			n = jogo->getPinter(i)->cartaTopo().getNaipe();
			Iu::desenhaCarta(coluna, 4, v, n);
		}
		else
		{
			Iu::desenhaEspaco(coluna);
		}
		coluna += 9;
	}

	/*
	 * Espacos para as pilhas finais, de 5 ate 8.
	 */
	for(i = 0; i < 4; i++)
	{
		if(!jogo->getPfim(i)->estaVazia())
		{
			v = jogo->getPfim(i)->cartaTopo().getValor();
			n = jogo->getPfim(i)->cartaTopo().getNaipe();
			Iu::desenhaCarta(coluna, 4, v, n);
		}
		else
		{
			Iu::desenhaEspaco(coluna);
		}
		coluna += 9;
	}

	Iu::printPilhaIni();
}

/*
 * Metodo para desenho das pilhas iniciais, que sao as que ficam
 * na parte inferior da tela.
 */
void Iu::printPilhaIni()
{
	int v, n, i, j;
	int lin, col;
	Carta cAux;
	PilhaIni *aux[8];
	int contCartas = 0;
	int maisCartas = 0;

	// inicializando pilhas auxiliares
	for(i = 0; i < 8; i++)
		aux[i] = new PilhaIni();

	/*
	 * Desempilha as cartas das 8 pilhas iniciais e empilha-as
	 * nas 8 pilhas auxiliares.
	 */
	for(i = 0; i < 8; i++)
	{
		while(!jogo->getPini(i)->estaVazia())
		{
			cAux = jogo->getPini(i)->desempilha();
			aux[i]->Pilha::empilha(&cAux);
			contCartas++;
		}

		if(contCartas > maisCartas)
			maisCartas = contCartas;

		contCartas = 0;
	}

	textbackground(GREEN);
	textcolor(WHITE);
	window(1,12,80,14);
	cputs("                                                                                ");
	cputs("    Q        W        E        R        T        Y        U        I            ");
	cputs("                                                                                ");

	/*
	 * Verifica-se o valor e naipe das cartas que estao no topo das
	 * pilhas auxiliares e reempilha-as nas pilhas originais.
	 */
	lin = 13;
	for(j = 0; j < maisCartas; j++)
	{
		i = 0;
		col = 1;

		while(i < 8)
		{
			if(!aux[i]->estaVazia())
			{
				v = aux[i]->cartaTopo().getValor();
				n = aux[i]->cartaTopo().getNaipe();

				Iu::desenhaCarta(col, lin, v, n);

				cAux = aux[i]->desempilha();
				jogo->getPini(i)->Pilha::empilha(&cAux);
			}
			i++;
			col += 9;
		}
		cout << endl;
		lin += 2;
	}

	// finalizando pilhas auxiliares
	for(i = 0; i < 8; i++)
		delete aux[i];
}

/*
 * Metodo que desenha os espacos vazios das pilhas intermediarias
 * e finais.
 */
void Iu::desenhaEspaco(int col)
{
	int lin = 4;

	textbackground(GREEN);
	textcolor(WHITE);
	window(col,lin,col+7,lin+6);
	cputs("+------+");
	cputs("|      |");
	cputs("|      |");
	cputs("|      |");
	cputs("|      |");
	cputs("+------+");
}

/*
 * Metodo que desenha as cartas de baralho.
 */
void Iu::desenhaCarta(int col, int lin, int v, int n)
{
	/*
	 * Metodo que desenha cartas. Recebe coluna e linha,
	 * valor e naipe.
	 *
	 * Naipes(ASCII II):
	 * 3 - copas
	 * 4 - ouros
	 * 5 - paus
	 * 6 - espadas
	 */
	char vchar[3];

	switch(v)
	{
	case 1: strcpy(vchar," A"); break;
	case 2: strcpy(vchar," 2"); break;
	case 3: strcpy(vchar," 3"); break;
	case 4: strcpy(vchar," 4"); break;
	case 5: strcpy(vchar," 5"); break;
	case 6: strcpy(vchar," 6"); break;
	case 7: strcpy(vchar," 7"); break;
	case 8: strcpy(vchar," 8"); break;
	case 9: strcpy(vchar," 9"); break;
	case 10: strcpy(vchar,"10"); break;
	case 11: strcpy(vchar," J"); break;
	case 12: strcpy(vchar," Q"); break;
	case 13: strcpy(vchar," K"); break;
	}

	/*
	 * A seguir, os naipes sao adaptados para sua represen-
	 * tacao em ASCII 2
	 */
	switch(n)
	{
	case 1: n = 3; break;
	case 2: n = 5; break;
	case 3: n = 4; break;
	case 4: n = 6; break;
	}

	/*
	 * A seguir, colorem-se as cartas de acordo com os naipes.
	 */
	if(n == 3 || n == 4)
	{
		textbackground(WHITE);
		textcolor(LIGHTRED);
	}
	else if(n == 5 || n == 6)
	{
		textbackground(WHITE);
		textcolor(BLACK);
	}

	window(col,lin,col+7,lin+6);
	cputs("+------+");
	cprintf("|%c%c%c   |", vchar[0],vchar[1], n);
	cputs("|      |");
	cputs("|      |");
	cputs("|      |");
	cputs("+------+");
	textbackground(GREEN);
	textcolor(WHITE);
	window(col,lin+6,col+7,lin+6);
}

/*
 * Imprime as opcoes de menu
 */
void Iu::menu()
{
	// digitar opcoes
	printf("[ (N)ovo jogo | (A)juda | (S)air ]\n\n");
}

/*
 * Metodo que realiza leitura e tratamento de entradas do usuario.
 */
int Iu::entrada()
{
	/*
	 * Esta funcao recebe e trata as strings de entrada.
	 */
	textbackground(GREEN);
	textcolor(WHITE);
	_setcursortype(_NORMALCURSOR);

	int origem, destino; // indices para as pilhas
	int p1, p2; // 1 para pilhaIni, 2 para pilhaInter, 3 para pilhaFim
	string str1, str2;
	string cmd; // armazena a entrada do usuario

	printf("\n->Entre com o comando desejado: ");
	cin >> cmd;

	/*
	 * A seguir, verifica-se a string. Retorna 0 para sair, 1 para iniciar novo
	 * jogo, 2 para auxilio, 3 para visualizar os creditos, 4 para informar
	 * que o comando digitado e' desconhecido e 5 para indicar que houve sucesso.
	 *
	 * Primeiramente, testa se a string nao e' formada por 1 caractere. Strings
	 * de 2 caracteres normalmente referem-se a movimentos de cartas.
	 */
	if(cmd.length() == 1)
	{
		if(cmd[0] == 's' || cmd[0] == 'S')
		{
			return Iu::confirma();
		}
		else if(cmd[0] == 'n' || cmd[0] == 'N')
			return 1;
		else if(cmd[0] == 'a' || cmd[0] == 'A')
			return Iu::ajuda();
		else if(cmd[0] == 'c' || cmd[0] == 'C')
			return 3;
		else{
			return Iu::comDesconhecido();
		}
	}else{
		/*
		 * Caso a string seja formada por 2 caracteres, separam-se os dois
		 * atribuindo cada um a uma variavel, str1 e str2.
		 */
		str1 = cmd.substr(0,1); // pega primeiro caractere
		str2 = cmd.substr(1,1); // pega segundo caractere

		char ch1, ch2;
		ch1 = str1[0];
		ch2 = str2[0];

		/*
		 * O teste a seguir define a pilha de origem e representando os
		 * caracteres por meio de inteiros. A funcao Freecell::move()
		 * recebera' esses valores inteiros que sao produzidos aqui.
		 */
		if(ch1 >= '1' && ch1 <= '4')
		{
			p1 = 2;
			origem = atoi(str1.c_str()) - 1;
		}
		else if(ch1 >= '5' && ch1 <= '8')
		{
			p1 = 3;
			origem = atoi(str1.c_str()) - 5;
		}
		else
		{
			p1 = 1;
			switch(ch1)
			{
			case 'q': case 'Q': origem = 0; break;
			case 'w': case 'W': origem = 1; break;
			case 'e': case 'E': origem = 2; break;
			case 'r': case 'R': origem = 3; break;
			case 't': case 'T': origem = 4; break;
			case 'y': case 'Y': origem = 5; break;
			case 'u': case 'U': origem = 6; break;
			case 'i': case 'I': origem = 7; break;
			default:
				return Iu::comDesconhecido();
			}
		}

		/*
		 * O mesmo e' feito para a str2, que se refere ao destino da
		 * carta
		 */
		if(ch2 >= '1' && ch2 <= '4')
		{
			p2 = 2;
			destino = atoi(str2.c_str()) - 1;
		}
		else if(ch2 >= '5' && ch2 <= '8')
		{
			p2 = 3;
			destino = atoi(str2.c_str()) - 5;
		}
		else
		{
			p2 = 1;
			switch(ch2)
			{
			case 'q': case 'Q': destino = 0; break;
			case 'w': case 'W': destino = 1; break;
			case 'e': case 'E': destino = 2; break;
			case 'r': case 'R': destino = 3; break;
			case 't': case 'T': destino = 4; break;
			case 'y': case 'Y': destino = 5; break;
			case 'u': case 'U': destino = 6; break;
			case 'i': case 'I': destino = 7; break;
			default:
				return Iu::comDesconhecido();
			}
		}
	}

	if(Iu::movimente(p1, origem, p2, destino))
	{
		return 5;
	}
	else
	{
		return Iu::movInvalido();
	}
}

/*
 * Metodo que serve como interface para realizacao do movimento
 * de cartas. Apos tratar as entradas, as mesmas sao traduzidas e
 * passadas para o metodo move() da classe Freecell.
 */
bool Iu::movimente(int p1, int orig, int p2, int dest)
{
	Pilha *pOrigem, *pDestino;

	switch(p1)
	{
	case 1:
		pOrigem = new PilhaIni;
		pOrigem = jogo->getPini(orig);
		break;
	case 2:
		pOrigem = new PilhaInter;
		pOrigem = jogo->getPinter(orig);
		break;
	case 3:
		pOrigem = new PilhaFim;
		pOrigem = jogo->getPfim(orig);
		break;
	}

	switch(p2)
	{
	case 1:
		pDestino = new PilhaIni;
		pDestino = jogo->getPini(dest);
		break;
	case 2:
		pDestino = new PilhaInter;
		pDestino = jogo->getPinter(dest);
		break;
	case 3:
		pDestino = new PilhaFim;
		pDestino = jogo->getPfim(dest);
		break;
	}

	return(jogo->move(pOrigem,pDestino));
}

/*
 * Box que indica que ocorreu uma tentativa invalida de movimento.
 */
int Iu::movInvalido()
{
	textbackground(RED);
	window(21,15,60,26);
	textbackground(LIGHTGRAY);
	textcolor(BLUE);
	window(23,16,58,25);
	cprintf("                                    ");
	cprintf("                                    ");
	cprintf("           ESTE MOVIMENTO           ");
	cprintf("           NAO E' VALIDO!           ");
	cprintf("                                    ");
	cprintf("        Digite qualquer tecla       ");
	cprintf("          para continuar...         ");
	_setcursortype(0);
	getch();

	return 6;
}

/*
 * Box que indica entrada inexistente por parte do usuario.
 */
int Iu::comDesconhecido()
{
	textbackground(RED);
	window(21,15,60,26);
	textbackground(LIGHTGRAY);
	textcolor(BLUE);
	window(23,16,58,25);
	cprintf("                                    ");
	cprintf("                                    ");
	cprintf("        COMANDO INEXISTENTE!        ");
	cprintf("                                    ");
	cprintf("                                    ");
	cprintf("        Digite qualquer tecla       ");
	cprintf("          para continuar...         ");
	_setcursortype(0);
	getch();

	return 4;
}

/*
 * Box de congratulacoes que aparece quando o usuario fecha um jogo.
 */
int Iu::congratulacoes()
{
	char opcao = 'x';

	while(opcao != 'S' && opcao != 's' && opcao != 'N' && opcao != 'n')
	{
		textbackground(RED);
		window(21,15,60,30);
		textbackground(LIGHTGRAY);
		textcolor(BLUE);
		window(23,16,58,29);
		cprintf("                                    ");
		cprintf("                                    ");
		cprintf("            VOCE VENCEU!            ");
		cprintf("             PARABENS!!!            ");
		cprintf("                                    ");
		cprintf("  (N)ovo jogo                       ");
		cprintf("  (S)air                            ");
		cprintf("           Opcao: ");
		cscanf("%c", &opcao);
	}

	if(opcao == 'S' || opcao == 's')
		return 0;
	else
		return 1;
}

/*
 * Box de confirmacao para sair do jogo.
 */
int Iu::confirma()
{
	char opcao = 'x';

	while(opcao != 'S' && opcao != 's' && opcao != 'N' && opcao != 'n')
	{
		textbackground(RED);
		window(21,15,60,30);
		textbackground(LIGHTGRAY);
		textcolor(BLUE);
		window(23,16,58,29);
		cprintf("                                    ");
		cprintf("                                    ");
		cprintf("         TEM CERTEZA DE QUE         ");
		cprintf("          DESEJA FINALIZAR?         ");
		cprintf("                                    ");
		cprintf("  (N)ao                             ");
		cprintf("  (S)im                             ");
		cprintf("           Opcao: ");
		cscanf("%c", &opcao);
	}

	if(opcao == 'S' || opcao == 's')
		return 0;
	else
		return 5;
}

/*
 * Tela com instrucoes de ajuda.
 */
int Iu::ajuda()
{
	textbackground(BLUE);
	window(2,3,79,31);
	textbackground(LIGHTGRAY);
	textcolor(BLUE);
	window(4,4,77,30);
	cprintf("                                                                          ");
	cprintf("   AJUDA:                                                                 ");
	cprintf("                                                                          ");
	cprintf("   -> As pilhas de Q ate I sao as pilhas iniciais.                        ");
	cprintf("                                                                          ");
	cprintf("   -> Os espacos de 1 ate 4 sao espacos intermediários, que aceitam       ");
	cprintf("      somente uma carta de cada vez.                                      ");
	cprintf("                                                                          ");
	cprintf("   -> Os espacos de 5 ate 8 sao o destino final para as pilhas de cartas. ");
	cprintf("                                                                          ");
	cprintf("   -> Para vencer, empilhe todas as cartas, em ordem crescente de valor,  ");
	cprintf("      nos espacos de 5 ate 8, sendo cada espaco para cartas de um         ");
	cprintf("      unico naipe.                                                        ");
	cprintf("                                                                          ");
	cprintf("   -> Para realizar um movimento:                                         ");
	cprintf("      Digite o caractere referente a pilha de origem seguido do caractere ");
	cprintf("         referente a pilha de destino.                                    ");
	cprintf("           Exemplos:                                                      ");
	cprintf("             rt (para mover a ultima carta da pilha R para a pilha T)     ");
	cprintf("             E5 (para mover da pilha E para a pilha 5)                    ");
	cprintf("      Obs. Sao permitidos caracteres maiusculos ou minusculos.            ");
	cprintf("                                                                          ");
	cprintf("                          Digite qualquer tecla                           ");
	cprintf("                            para continuar...                             ");

	_setcursortype(0);
	getch();

	return 2;
}

