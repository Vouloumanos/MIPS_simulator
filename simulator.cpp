#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iterator>

#include "instruction.hpp"

#define IMEM_LENGTH 0x1000000
#define DMEM_LENGTH 0x4000000
#define MEM_LENGTH 0x30000004
#define IMEM_OFFSET 0x10000000
#define DMEM_OFFSET 0x20000000
#define INPUT_OFFSET 0x30000000
#define OUTPUT_OFFSET 0x30000004

int main(int argc, char *argv[]){

  //get binary name
  std::string binName = argv[1];
  //debug - display binary name
  std::cerr << "binName: " << binName << std::endl;
  //initialise binStream
  std::ifstream binStream(binName, std::ios::binary);

  //calculate binSize
  binStream.seekg(0, std::ios::end);
  int binSize = binStream.tellg();
  //binSize-=1; DEBATABLE
  binStream.seekg(0, std::ios::beg);
  std::cerr << "Binary file size: " << binSize << std::endl;

  //initialise memory to 0
  std::vector<uint8_t> memory(MEM_LENGTH, 0);

  //initialiste registers to 0
  std::vector<uint32_t> registers(32, 0);

  //initialise program counter to IMEM_OFFSET
  uint32_t pc = IMEM_OFFSET;

  std::cerr << "Everything initialised " << std::endl;

  //load instruction memory

  //std::cerr << "Instruction memory loaded" << std::endl;;

  instruction inst;
  while(1){

    if(pc == 0){
      uint8_t exitCode = static_cast<uint8_t>(registers[2]);
      std::cerr << "Pc = 0" << std::endl;
      std::exit(exitCode);
    }
    else if((pc < IMEM_LENGTH + IMEM_OFFSET) && (pc >= IMEM_OFFSET)){
      std::cerr << "Valid pc" << std::endl;

      //get instruction
      inst.set_bits(memory[pc]);
      //execute instruction

      //increment pc by 4 if not J otherwise J manipulated it before
      if(inst.get_type() != 'J') pc+= 4;

    }
    else{
      //memory exception
      std::cerr << "Memory exception" << std::endl;
      std::exit(-11);
    }

    //increment
  }
  return 0;
}
