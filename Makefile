simulator: simulator.o instruction.o
	g++ simulator.o instruction.o -o sim

main.o: simulator.cpp
	g++ -c simulator.cpp

instruction.o: instruction.cpp instruction.hpp
	g++ -c instruction.cpp

run:
	./sim binary.bin

clean:
	rm *.o sim
