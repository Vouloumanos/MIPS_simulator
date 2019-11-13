simulator: simulator.o instruction_R.o instruction_I.o instruction_J.o init.o
	g++ -std=c++11 bin/*.o -o bin/sim

simulator.o:
	g++ -I inc/ -c src/simulator.cpp -o bin/simulator.o

instruction_R.o:
	g++ -I inc/ -c src/instruction_R.cpp -o bin/instruction_R.o

instruction_I.o:
	g++ -I inc/ -c src/instruction_I.cpp -o bin/instruction_I.o

instruction_J.o:
	g++ -I inc/ -c src/instruction_J.cpp -o bin/instruction_J.o

init.o:
	g++ -I inc/ -c src/init.cpp -o bin/init.o

run:
	./bin/sim bin/binary.bin

clean:
	rm bin/*.o bin/sim
