#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iterator>
#include <cstdlib>

#include "init.hpp"

int main(int argc, char *argv[]){

  //initalisation
  std::vector<uint8_t> memory(MEM_LENGTH, 0); //initialise memory to 0
  std::vector<uint32_t> registers(34, 0); //initialiste registers to 0, registers[32] is LO, registers[33] is HI
  uint32_t pc = IMEM_OFFSET; //initialise program counter to IMEM_OFFSET
  uint32_t next_pc = IMEM_OFFSET + 4; //initialise next program counter to 
  std::cerr << "Everything initialised " << std::endl; //debug - status update

  //set up binstream
  std::string binName = argv[1]; //get binary name
  std::cerr << "binName: " << binName << std::endl; //debug - display binary name
  std::ifstream binStream(binName, std::ios::binary); //initialise binStream

  if(!binStream.is_open()){
    std::cerr << "File couldn't be opened" << std::endl; //debug - error message
    std::exit(-21);
  }

  binStream.seekg(0, std::ios::end); //calculate binSize
  int binSize = binStream.tellg();
  binStream.seekg(0, std::ios::beg);
  std::cerr << "Binary file size: " << binSize << std::endl;

  char c;
  int index = 0;
  while(binStream >> c){
    if((index + IMEM_OFFSET) < IMEM_END_OFFSET){
      memory[index+IMEM_OFFSET] = c;
      index++;
    }
  }

  std::cerr << "Input memory OK" << std::endl; //debug - status message

  while(0){ //processor running
    if(pc == 0){
      uint8_t exitCode = static_cast<uint8_t>(registers[2]);
      std::exit(exitCode);
    }
    else if((pc < IMEM_LENGTH + IMEM_OFFSET) && (pc >= IMEM_OFFSET)){
      std::cerr << "Valid pc" << std::endl;

      //get instruction
      uint32_t input_bits = (memory[pc] << 24) + (memory[pc+1] << 16) + (memory[pc+2] << 8) + (memory[pc+3] << 0);

      //execute instruction depending on the type
      if(get_type(input_bits) == 'R'){
        instruction_R inst;
        inst.set_bits(input_bits);
        inst.execute(registers, pc);
      }
      else if(get_type(input_bits) == 'I'){
        instruction_I inst;
        inst.set_bits(input_bits);
        inst.execute(registers, pc, memory);
      }
      else if(get_type(input_bits) == 'J'){
        instruction_J inst;
        inst.set_bits(input_bits);
        inst.execute(registers, pc, memory);
      }

    }
    else{
      //memory exception
      std::cerr << "Memory exception" << std::endl;
      std::exit(-11);
    }

  }
  return 0;
}
