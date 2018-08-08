SOURCES = main.cpp objeto.c coordenadas.c 
HEADERS = objeto.h coordenadas.h 
OBJECTS = main.o objeto.o coordenadas.o 
LIBS    = -lglut -lGLU -lGL -lm -lSOIL  -lalut  -lopenal  -lsfml-audio
CFLAGS  = -O3 -Wall


all: tp2
 
tp2: $(OBJECTS)
	g++ -o tp2 $(OBJECTS) $(CFLAGS) $(LIBS)

objeto.o: objeto.c objeto.h
	g++ -o objeto.o -c objeto.c $(LIBS) -nostartfiles -std=c++11

coordenadas.o: coordenadas.c coordenadas.h
	g++ -o coordenadas.o -c coordenadas.c $(LIBS) -nostartfiles -std=c++11

main.o: main.cpp $(HEADERS)
	g++ -o main.o -c main.cpp  $(LIBS)
clean:
	rm -rf *.o
clean-all: 
	rm -rf tp1 *.o

