simulator: simulator.o instruction_R.o instruction_I.o instruction_J.o
	g++ simulator.o instruction_R.o instruction_I.o instruction_J.o -o sim

main.o: simulator.cpp
	g++ -c simulator.cpp

instruction_R.o: instruction_R.cpp instruction_R.hpp
	g++ -c instruction_R.cpp

instruction_I.o: instruction_I.cpp instruction_I.hpp
	g++ -c instruction_I.cpp

instruction_J.o: instruction_J.cpp instruction_J.hpp
	g++ -c instruction_J.cpp

run:
	./sim binary.bin

clean:
	rm *.o sim
