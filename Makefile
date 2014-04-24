qDB : main.o beneimmobile.o fabbricato.o terreno.o error.o record.o
	g++ -o qDB main.o beneimmobile.o fabbricato.o terreno.o error.o record.o

main.o : main.cpp container.h beneimmobile.h fabbricato.h terreno.h error.h record.h
	g++ -c main.cpp -o main.o

beneimmobile.o : beneimmobile.cpp beneimmobile.h
	g++ -c beneimmobile.cpp -o beneimmobile.o

fabbricato.o : fabbricato.cpp fabbricato.h beneimmobile.h error.h
	g++ -c fabbricato.cpp -o fabbricato.o

terreno.o : terreno.cpp terreno.h beneimmobile.h
	g++ -c terreno.cpp -o terreno.o

error.o : error.cpp error.h
	g++ -c error.cpp -o error.o

record.o : record.cpp record.h
	g++ -c record.cpp -o record.o

clean :
	rm *.o
	@echo "Pulizia completata!"