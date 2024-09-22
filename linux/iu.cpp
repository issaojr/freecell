/*
 * Interface de usuario, versao Linux. Para console, modo texto.
 */

#include "iu.h"
#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

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
	system("clear");	
	cout << "                                    " << endl;
	cout << "                                    " << endl;
	cout << "              FREECELL              " << endl;
	cout << "           V.1.0.0 - 2008           " << endl;
	cout << "                                    " << endl;
	cout << "           Seja Bem-Vindo!          " << endl;
	cout << "                                    " << endl;	
	cin.get();
}

/*
 * Tela de encerramento do programa. Ocorre somente uma vez durante
 * a execucao.
 */
void Iu::telaFinal()
{
	system("clear");	
	cout << "                                    " << endl;
	cout << "                                    " << endl;
	cout << "                                    " << endl;
	cout << "               \u2660\u2663\u2665\u2666                 " << endl;
	cout << "                                    " << endl;
	cout << "        OBRIGADO POR JOGAR!         " << endl;
	cout << "                                    " << endl;
	cout << "               \u2660\u2663\u2665\u2666                 " << endl;
	cout << "                                    " << endl;
	cout << "                                    " << endl;		
}

/*
 * Metodo responsavel por desenhar a tela de jogo. Este metodo e'
 * chamado apos cada entrada do usuario para efetuar o redesenho
 * da tela.
 */

void Iu::printTela()
{
	int i, v, n, col;
	Carta cAux;
	
	system("clear"); // !!! Atencao !!! incompativel com Windows!
	cout << ".:Freecell" << endl;
	Iu::menu();
	
	/* 
	 * A seguir e' feito o desempilhamento de todas as cartas das 8
	 * pilhas iniciais, empilhando-as em pilhas auxiliares
	 */		
	
	col = 4;
	
	//cabecalho das pilhas superiores
	printf("    1     ");
	printf("    2     ");
	printf("    3     ");
	printf("    4     ");
	printf("    5     ");
	printf("    6     ");
	printf("    7     ");
	printf("    8     \n");
	
	// Primeira linha
	Iu::linhaH(col);	
	Iu::linhaH(col);
	cout << endl;	
	
	for(i = 0; i < 4; i++)
	{
		if(!jogo->getPinter(i)->estaVazia())
		{
			cAux = jogo->getPinter(i)->desempilha();
			v = cAux.getValor();
			n = cAux.getNaipe();
			jogo->getPinter(i)->empilha(&cAux);								
			
			// Segunda linha	
			Iu::linhaId(v,n, 1);			
		}
		else
		{
			Iu::linhaVazia(1);			
		}
		
	}	
	
	for(i = 0; i < 4; i++)
	{
		if(!jogo->getPfim(i)->estaVazia())
		{
			v = jogo->getPfim(i)->cartaTopo().getValor();
			n = jogo->getPfim(i)->cartaTopo().getNaipe();
			// Segunda linha	
			Iu::linhaId(v,n, 1);			
		}
		else
		{
			Iu::linhaVazia(1);			
		}		
	}
	cout << endl;
	
	// Terceira linha	
	Iu::linhaVazia(col);	
	Iu::linhaVazia(col);
	cout << endl;
	
	// Quarta linha	
	Iu::linhaVazia(col);	
	Iu::linhaVazia(col);
	cout << endl;
	
	// Quinta linha	
	Iu::linhaVazia(col);	
	Iu::linhaVazia(col);
	cout << endl;
		
	//Linha Final	
	Iu::linhaH(col);	
	Iu::linhaH(col);
	cout << endl << endl << endl;				
	
	Iu::printPilhaIni();	
}

void Iu::printPilhaIni()
{	
	int v, n, i, j;
	Carta cAux;
	PilhaIni *aux[8];
	int maiorPilha;
	int contCartas = 0;
	int maisCartas = 0;
	
	// verifica a maior pilha	
	
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
		{
			maisCartas = contCartas;
			maiorPilha = i;
		}
		contCartas = 0;
	}
	
	
	printf("    Q     ");
	printf("    W     ");
	printf("    E     ");
	printf("    R     ");
	printf("    T     ");
	printf("    Y     ");
	printf("    U     ");
	printf("    I     \n");
	
	Iu::linhaH(8);
		
	/*
	 * Verifica-se o valor e naipe das cartas que estao no topo das
	 * pilhas auxiliares e reempilha-as nas pilhas originais.
	 */
	
	cout << endl;
	
	for(j = 0; j < maisCartas; j++)
	{
		i = 0;
		while(i < 8)
		{
			if(!aux[i]->estaVazia())
			{
				v = aux[i]->cartaTopo().getValor();
				n = aux[i]->cartaTopo().getNaipe();
				Iu::linhaId(v, n, 1);				
				
				cAux = aux[i]->desempilha();
				jogo->getPini(i)->Pilha::empilha(&cAux);
			}
			else
			{				
				cout << "          ";
			}
			i++;			
		}	
		cout << endl;
		
		cout << endl;
	}
	
}

void Iu::menu()
{
	// digitar opcoes
	cout << "[ (N)ovo jogo | (A)juda | (S)air ]" << endl << endl << endl;
}

int Iu::entrada()
{
	/*
	 * Esta funcao recebe e trata as strings de entrada.
	 */
	
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

bool Iu::movimente(int p1, int orig, int p2, int dest)
{	
	Pilha *pOrigem, *pDestino;	
	cout << endl << p1 << orig << p2 << dest << endl;
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
 * Metodos para desenho das cartas.
 */
void Iu::linhaH(int col)
{
	int i, j;
	
	//cout << "   ";
	for(i = 0; i < col; i++){
		cout << "+";
		for(j = 0; j < 7; j++)
			cout << "-";
		cout << "+ ";
	}	
}

void Iu::linhaFinal(int col)
{
	int i, j;	
	
	for(i = 0; i < col; i++){
		cout << "+";
		for(j = 0; j < 7; j++)
			cout << "-";
		cout << "+ ";
	}
}

void Iu::linhaId(int valor, int naipe, int col)
{
	int i, j;
	string strN, strV;
	
	
	for(i = 0; i < col; i++){
		switch(naipe)
		{
		case 1:	strN = "[\u2660]"; break;
		case 2:	strN = "<\u2665>"; break;
		case 3: strN = "[\u2663]"; break;
		case 4: strN = "<\u2666>"; break;			
		}
		
		switch(valor)
		{
		case 1: strV = " A"; break;
		case 2: strV = " 2"; break;
		case 3: strV = " 3"; break;
		case 4: strV = " 4"; break;
		case 5: strV = " 5"; break;
		case 6: strV = " 6"; break;
		case 7: strV = " 7"; break;
		case 8: strV = " 8"; break;
		case 9: strV = " 9"; break;
		case 10: strV = "10"; break;
		case 11: strV = " J"; break;
		case 12: strV = " Q"; break;
		case 13: strV = " K"; break;
		}
		
		cout << "| " << strV << strN << " | ";		
	}			
}

void Iu::linhaVazia(int col)
{
	int i, j;
	
	
	for(i = 0; i < col; i++){
		cout << "|";
		for(j = 0; j < 7; j++)
			cout << " ";
		cout << "| ";
	}			
}

/*
 * Fim dos metodos para desenho das cartas
 */

/*
 * Box que indica que ocorreu uma tentativa invalida de movimento.
 */
int Iu::movInvalido()
{
	
	system("clear");
	cout << "                                    " << endl;
	cout << "                                    " << endl;
	cout << "           ESTE MOVIMENTO           " << endl;
	cout << "           NAO E' VALIDO!           " << endl;
	cout << "                                    " << endl;
	cout << "        Digite qualquer tecla       " << endl;
	cout << "          para continuar...         " << endl;
	cin.get();
	cin.get();

	return 6;
}

/*
 * Box que indica entrada inexistente por parte do usuario.
 */
int Iu::comDesconhecido()
{
	system("clear");
	cout << "                                    " << endl;
	cout << "                                    " << endl;
	cout << "        COMANDO INEXISTENTE!        " << endl;
	cout << "                                    " << endl;
	cout << "                                    " << endl;
	cout << "        Digite qualquer tecla       " << endl;
	cout << "          para continuar...         " << endl;
	cin.get();
	cin.get();

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
		system("clear");
		cout << "                                    " << endl;
		cout << "                                    " << endl;
		cout << "            VOCE VENCEU!            " << endl;
		cout << "             PARABENS!!!            " << endl;
		cout << "                                    " << endl;
		cout << "  (N)ovo jogo                       " << endl;
		cout << "  (S)air                            " << endl;
		cout << "           Opcao: ";
		cin >> opcao;
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
		system("clear");
		cout << "                                    " << endl;
		cout << "                                    " << endl;
		cout << "         TEM CERTEZA DE QUE         " << endl;
		cout << "          DESEJA FINALIZAR?         " << endl;
		cout << "                                    " << endl;
		cout << "  (N)ao                             " << endl;
		cout << "  (S)im                             " << endl;
		cout << "           Opcao: ";
		cin >> opcao;
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
	system("clear");
	cout << "                                                                          " << endl;
	cout << "   AJUDA:                                                                 " << endl;
	cout << "                                                                          " << endl;
	cout << "   -> As pilhas de Q ate I sao as pilhas iniciais.                        " << endl;
	cout << "                                                                          " << endl;
	cout << "   -> Os espacos de 1 ate 4 sao espacos intermediarios, que aceitam       " << endl;
	cout << "      somente uma carta de cada vez.                                      " << endl;
	cout << "                                                                          " << endl;
	cout << "   -> Os espacos de 5 ate 8 sao o destino final para as pilhas de cartas. " << endl;
	cout << "                                                                          " << endl;
	cout << "   -> Para vencer, empilhe todas as cartas, em ordem crescente de valor,  " << endl;
	cout << "      nos espacos de 5 ate 8, sendo cada espaco para cartas de um         " << endl;
	cout << "      unico naipe.                                                        " << endl;
	cout << "                                                                          " << endl;
	cout << "   -> Para realizar um movimento:                                         " << endl;
	cout << "      Digite o caractere referente a pilha de origem seguido do caractere " << endl;
	cout << "         referente a pilha de destino.                                    " << endl;
	cout << "           Exemplos:                                                      " << endl;
	cout << "             rt (para mover a ultima carta da pilha R para a pilha T)     " << endl;
	cout << "             E5 (para mover da pilha E para a pilha 5)                    " << endl;
	cout << "      Obs. Sao permitidos caracteres maiusculos ou minusculos.            " << endl;
	cout << "                                                                          " << endl;
	cout << "                          Digite qualquer tecla                           " << endl;
	cout << "                            para continuar...                             " << endl;

	cin.get();
	cin.get();

	return 2;
}

