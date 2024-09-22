#ifndef _CARTA_H_
#define _CARTA_H_

class Carta
{
private:
	int valor;
	int naipe;

public:
	Carta();
	Carta(int naipe, int valor);
	static bool jaExiste(int n, int v);
	int getNaipe();
	int getValor();
};

#endif
