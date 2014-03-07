qDB : main.o marketitem.o fooditem.o date.o
	g++ -o qDB main.o marketitem.o fooditem.o date.o

main.o : main.cpp container.h fooditem.h
	g++ -c main.cpp -o main.o

marketitem.o : marketitem.cpp marketitem.h
	g++ -c marketitem.cpp -o marketitem.o

fooditem.o : fooditem.cpp fooditem.h marketitem.h date.h
	g++ -c fooditem.cpp -o fooditem.o

date.o : date.cpp date.h
	g++ -c date.cpp -o date.o

clean :
	rm *.o
	@echo "Pulizia completata!"