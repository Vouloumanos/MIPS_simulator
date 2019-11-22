#################################################
# For simulator:

CC = g++
CPPFLAGS = -W -Wall -I inc/
SIM_DEP = src/simulator.cpp src/instruction_R.cpp src/instruction_I.cpp src/instruction_J.cpp src/init.cpp

simulator: $(SIM_DEP)
	mkdir -p bin
	$(CC) $(CPPFLAGS) $(SIM_DEP) -o bin/mips_simulator
	chmod +x ./bin/mips_simulator
	#g++ -std=c++11 bin/*.o -o bin/mips_simulator

#################################################
# For testbench:

testbench:
	mkdir -p bin
	./test/converter.sh
	cp -f ./test/mips_testbench ./bin
	chmod +x ./bin/mips_testbench

#################################################
# For clean:

clean:
	rm bin/*

#################################################
# DEBUG START
simulator.o:
	g++ -std=c++11 -I inc/ -c src/simulator.cpp -o bin/simulator.o

instruction_R.o:
	g++ -std=c++11 -I inc/ -c src/instruction_R.cpp -o bin/instruction_R.o

instruction_I.o:
	g++ -std=c++11 -I inc/ -c src/instruction_I.cpp -o bin/instruction_I.o

instruction_J.o:
	g++ -std=c++11 -I inc/ -c src/instruction_J.cpp -o bin/instruction_J.o

init.o:
	g++ -std=c++11 -I inc/ -c src/init.cpp -o bin/init.o
# DEBUG END
