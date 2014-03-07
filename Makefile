qDB : main.o marketitem.o fooditem.o
	g++ -o qDB main.o marketitem.o fooditem.o

main.o : main.cpp container.h fooditem.h
	g++ -c main.cpp -o main.o

marketitem.o : marketitem.cpp marketitem.h
	g++ -c marketitem.cpp -o marketitem.o

fooditem.o : fooditem.cpp fooditem.h marketitem.h
	g++ -c fooditem.cpp -o fooditem.o

clean :
	rm *.o
	@echo "Pulizia completata!"