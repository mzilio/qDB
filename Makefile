qDB : main.o marketitem.o generalitem.o fooditem.o fridgeitem.o stapleitem.o date.o
	g++ -o qDB main.o marketitem.o generalitem.o fooditem.o fridgeitem.o stapleitem.o date.o

main.o : main.cpp container.h marketitem.h generalitem.h fooditem.h fridgeitem.h stapleitem.h
	g++ -c main.cpp -o main.o

marketitem.o : marketitem.cpp marketitem.h
	g++ -c marketitem.cpp -o marketitem.o

generalitem.o : generalitem.cpp generalitem.h marketitem.h
	g++ -c generalitem.cpp -o generalitem.o

fooditem.o : fooditem.cpp fooditem.h marketitem.h date.h
	g++ -c fooditem.cpp -o fooditem.o

fridgeitem.o : fridgeitem.cpp fridgeitem.h fooditem.h
	g++ -c fridgeitem.cpp -o fridgeitem.o

stapleitem.o : stapleitem.cpp stapleitem.h fooditem.h
	g++ -c stapleitem.cpp -o stapleitem.o

date.o : date.cpp date.h
	g++ -c date.cpp -o date.o

clean :
	rm *.o
	@echo "Pulizia completata!"