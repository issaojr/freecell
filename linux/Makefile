all: info teste.exe	
	@echo Programa construido com sucesso.
	
info:
	@echo Bem-vindo ao Freecell_v.1.0.0 Linux
	@echo Iniciando construcao do programa...	

teste.exe: carta.o pilha.o pilhaini.o pilhainter.o pilhafim.o baralho.o freecell.o main.o iu.o
	g++ -o freecell-1.0.0-linux.bin carta.o pilha.o pilhaini.o pilhainter.o pilhafim.o baralho.o freecell.o main.o iu.o conio/conio.o -lncurses		
		
carta.o:
	g++ -c carta.cpp	
	
pilha.o:
	g++ -c pilha.cpp	

pilhaini.o:
	g++ -c pilhaini.cpp	

pilhainter.o:
	g++ -c pilhainter.cpp	

pilhafim.o:
	g++ -c pilhafim.cpp	

baralho.o:
	g++ -c baralho.cpp	

freecell.o:
	g++ -c freecell.cpp	

main.o:
	g++ -c main.cpp	

iu.o:
	g++ -c iu.cpp	

clean:
	rm *.o	
	
	
	
