objects = base.o main.o ping.o utils.o

ping: $(objects)
	g++ -o ping $(objects) -lwiringPi

base.o: base.cpp base.h
	g++ -c -o base.o base.cpp -lwiringPi

main.o: main.cpp main.h
	g++ -c -o main.o main.cpp -lwiringPi

ping.o: ping.cpp ping.h
	g++ -c -o ping.o ping.cpp -lwiringPi

utils.o: utils.cpp utils.h
	g++ -c -o utils.o utils.cpp -lwiringPi

.PHONY: clean
clean:
	rm ping $(objects)