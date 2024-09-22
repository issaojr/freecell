all: info freecell-1.0.1-win32.exe	
	@echo Programa construido com sucesso.
	
info:
	@echo Bem-vindo ao Freecell_v.1.0.1.
	@echo Iniciando construcao do programa...	

freecell-1.0.1-win32.exe: carta.o pilha.o pilhaini.o pilhainter.o pilhafim.o baralho.o freecell.o main.o iu.o
	g++ -o freecell-1.0.1-win32.exe carta.o pilha.o pilhaini.o pilhainter.o pilhafim.o baralho.o freecell.o main.o iu.o conio/conio.o	
		
carta.o:
	g++ -Wall -pedantic -c carta.cpp	
	
pilha.o:
	g++ -Wall -pedantic -c pilha.cpp	

pilhaini.o:
	g++ -Wall -pedantic -c pilhaini.cpp	

pilhainter.o:
	g++ -Wall -pedantic -c pilhainter.cpp	

pilhafim.o:
	g++ -Wall -pedantic -c pilhafim.cpp	

baralho.o:
	g++ -Wall -pedantic -c baralho.cpp	

freecell.o:
	g++ -Wall -pedantic -c freecell.cpp	

main.o:
	g++ -Wall -pedantic -c main.cpp	

iu.o:
	g++ -Wall -pedantic -c iu.cpp	

clean:
	del *.o	
	
	
	
