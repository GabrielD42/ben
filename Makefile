objects = base.o main.o ping.o utils.o square.o list.o node.h

ping: $(objects)
	g++ -o ping $(objects) -lwiringPi
	rm $(objects)

base.o: base.cpp base.h
	g++ -c -o base.o base.cpp -lwiringPi

main.o: main.cpp main.h
	g++ -c -o main.o main.cpp -lwiringPi

ping.o: ping.cpp ping.h
	g++ -c -o ping.o ping.cpp -lwiringPi

utils.o: utils.cpp utils.h
	g++ -c -o utils.o utils.cpp -lwiringPi

square.o: square.cpp square.h
	g++ -c -o square.o square.cpp

list.o: list.cpp list.h
	g++ -c -o list.o list.cpp