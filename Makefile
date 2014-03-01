qDB : main.o
	g++ -o qDB main.o

main.o : main.cpp container.h
	g++ -c main.cpp -o main.o

clean :
	rm *.o
	@echo "Pulizia completata!"