#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iterator>
#include <bitset>
#include <cstdlib>

#include "instruction_R.hpp"
#include "instruction_I.hpp"
#include "instruction_J.hpp"

#define IMEM_LENGTH 0x1000000
#define DMEM_LENGTH 0x4000000
#define MEM_LENGTH 0x30000004
#define IMEM_OFFSET 0x10000000
#define DMEM_OFFSET 0x20000000
#define INPUT_OFFSET 0x30000000
#define OUTPUT_OFFSET 0x30000004
#define IMEM_END_OFFSET 0x11000000
#define DMEM_END_OFFSET 0x24000000

char get_type(const uint32_t& input_bits);

int main(int argc, char *argv[]){

  //initialise memory to 0
  std::vector<uint8_t> memory(MEM_LENGTH, 0);

  //initialiste registers to 0
  std::vector<uint32_t> registers(32, 0);

  //initialise program counter to IMEM_OFFSET
  uint32_t pc = IMEM_OFFSET;

  std::cerr << "Everything initialised " << std::endl;

  //get binary name
  std::string binName = argv[1];
  //debug - display binary name
  std::cerr << "binName: " << binName << std::endl;
  //initialise binStream
  std::ifstream binStream(binName, std::ios::binary);

  if(!binStream.is_open()){
    std::cerr << "File couldn't be opened" << std::endl;
    std::exit(-21);
  }

  //calculate binSize
  binStream.seekg(0, std::ios::end);
  int binSize = binStream.tellg();
  //binSize-=1; DEBATABLE
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

  std::cerr << "Input memory OK" << std::endl;

  while(0){
    if(pc == 0){
      uint8_t exitCode = static_cast<uint8_t>(registers[2]);
      std::cerr << "Pc = 0" << std::endl;
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
        // inst.execute(registers, pc);
      }
      else if(get_type(input_bits) == 'I'){
        instruction_I inst;
        inst.set_bits(input_bits);
        // inst.execute(memory, registers, pc);
      }
      else if(get_type(input_bits) == 'J'){
        instruction_J inst;
        inst.set_bits(input_bits);
        // inst.execute(memory, registers, pc);
      }

      //increment pc by 4 if not J otherwise J manipulated it before
      //do it above!!!

    }
    else{
      //memory exception
      std::cerr << "Memory exception" << std::endl;
      std::exit(-11);
    }

  }
  return 0;
}

char get_type(const uint32_t& input_bits){
  std::bitset<6> opcode = (input_bits >> 26);

  if(opcode == 0b000000) return 'R';
  else if(opcode == 0b000010 || opcode == 0b000011) return 'J';
  else return 'I';
}
