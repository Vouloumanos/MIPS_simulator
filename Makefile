simulator: simulator.o instruction_R.o instruction_I.o instruction_J.o init.o
	g++ -std=c++11 $^ -o sim

simulator.o: simulator.cpp
	g++ -c $<

instruction_R.o: instruction_R.cpp instruction_R.hpp
	g++ -c $<

instruction_I.o: instruction_I.cpp instruction_I.hpp
	g++ -c $<

instruction_J.o: instruction_J.cpp instruction_J.hpp
	g++ -c $<

init.o: init.cpp init.hpp
	g++ -c $<

run:
	./sim binary.bin

clean:
	rm *.o sim
