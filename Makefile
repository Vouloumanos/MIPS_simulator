#################################################
# For MIPS:

# For MIPS binaries. Turn on all warnings, enable all optimisations and link everything statically
MIPS_CC = mips-linux-gnu-gcc
MIPS_OBJCOPY = mips-linux-gnu-objcopy
MIPS_OBJDUMP = mips-linux-gnu-objdump
MIPS_CPPFLAGS = -W -Wall -O3 -fno-builtin -march=mips1 -mfp32
MIPS_LDFLAGS = -nostdlib -Wl,-melf32btsmip -march=mips1 -nostartfiles -mno-check-zero-division -Wl,--gpsize=0 -static -Wl,-Bstatic -Wl,--build-id=none

# Compile C file (.c) into MIPS object file (.o)
%.mips.o: %.c
	$(MIPS_CC) $(MIPS_CPPFLAGS) -c $< -o $@

# Assemble MIPS assembly file (.s) into MIPS object file (.o)
%.mips.o: %.s
	$(MIPS_CC) $(MIPS_CPPFLAGS) -c $< -o $@

# Link MIPS object file (.o), producing .elf, using memory locations specified in spec
%.mips.elf: %.mips.o
	$(MIPS_CC) $(MIPS_CPPFLAGS) $(MIPS_LDFLAGS) -T src/linker.ld $< -o $@

# Extract binary instructions only from linked object file (.elf)
%.mips.bin: %.mips.elf
	$(MIPS_OBJCOPY) -O binary --only-section=.text $< $@

# Disassemble linked object file (.elf), pulling out instructions as MIPS assembly file (.s)
%.mips.s : %.mips.elf
	$(MIPS_OBJDUMP) -j .text -D $< > $@

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
	#cp ./test/mips_testbench /bin FIX



#################################################
# For run and clean:

run:
	./bin/mips_simulator test/binary.bin

clean:
	rm bin/*.o bin/mips_simulator

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
