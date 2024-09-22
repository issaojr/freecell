#include "carta.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

Carta::Carta()
{
	int i, j;
	
	srand(time(NULL));
	i = rand() % 4;
	j = rand() % 13;
	
	naipe = i;
	valor = j;
}

Carta::Carta(int naipe, int valor)
{
	this->naipe = naipe;
	this->valor = valor;
}

bool Carta::jaExiste(int n, int v)
{
	static bool cartaJaExiste[4][13];
	static int numCartas = 0;
	if(numCartas == 0)
	{
		for(int i = 0; i < 4; i++)
			for(int j = 0; j < 13; j++)
				cartaJaExiste[i][j] = false;
		cartaJaExiste[n][v] = true;
		numCartas++;
		return false;
	}

	if(cartaJaExiste[n][v])
	{
		return true;
	}
	else
	{
		cartaJaExiste[n][v] = true;
		numCartas++;

		/*
		 * A seguir, reseta-se a variavel numCartas, possi-
		 * bilitando o inicio de novos jogos.
		 */
		if(numCartas == 52)
			numCartas = 0;

		return false;
	}
}

int Carta::getNaipe()
{
	return naipe;
}

int Carta::getValor()
{
	return valor;
}

