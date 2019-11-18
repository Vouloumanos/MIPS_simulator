#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iterator>
#include <cstdlib>
#include <bitset>

#include "init.hpp"

int main(int argc, char *argv[]){

  try
  {
    if(argc != 2){
      std::cerr << "Expected 1 input binary file" << std::endl;
      std::exit(1);
    }

    //initalisation
    std::vector<uint8_t> memory(MEM_LENGTH, 0); //initialise memory to 0
    std::vector<uint32_t> registers(34, 0); //initialiste registers to 0, registers[32] is LO, registers[33] is HI
    uint32_t pc = IMEM_OFFSET; //initialise program counter to IMEM_OFFSET
    uint32_t next_pc = IMEM_OFFSET + 4; //initialise next program counter to
    //std::cerr << "Everything initialised " << std::endl; //debug - status update

    //set up binstream
    std::string binName = argv[1]; //get binary name
    //std::cerr << "binName: " << binName << std::endl; //debug - display binary name
    std::ifstream binStream(binName, std::ios::binary); //initialise binStream

    if(!binStream.is_open()){ //THINK ABOUT CORRECT ERROR CODE
      std::cerr << "File couldn't be opened" << std::endl; //debug - error message
      throw(static_cast<int32_t>(error::IO));
    }

    binStream.seekg(0, std::ios::end); //calculate binSize
    int binSize = binStream.tellg();
    //std::cerr << "Binary file size: " << binSize << std::endl;

    binStream.seekg(0, std::ios::beg);
    char* buffer = new char[binSize];
    binStream.read(buffer, binSize);
    binStream.close();

    for(int i=0; i<binSize; i++){
      if((i + IMEM_OFFSET) < IMEM_END_OFFSET){
        memory[i+IMEM_OFFSET] = buffer[i];
      }
      else{
        throw(static_cast<uint32_t>(exception::MEMORY));
      }
    }
    delete[] buffer;

    //std::cerr << "Input memory OK" << std::endl; //debug - status message

    //std::cerr << std::endl;
    //std::cerr << std::endl;

    while(1){ //processor running

      //std::cerr << "pc: " << std::hex <<pc << " next_pc: " << std::hex << next_pc;

      if(pc == 0){ //program has finished, return lower 8 bits of register 2
        uint8_t returnCode = static_cast<uint8_t>(registers[2]);
        std::exit(returnCode);
      }
      else if(pc % 4 != 0){
        throw(static_cast<int32_t>(exception::MEMORY));
      }
      else if((pc < IMEM_LENGTH + IMEM_OFFSET) && (pc >= IMEM_OFFSET)){
        //std::cerr << "Valid pc" << std::endl;

        //get instruction
        uint32_t input_bits = (uint32_t(memory[pc]) << 24) + (uint32_t(memory[pc+1]) << 16) + (uint32_t(memory[pc+2]) << 8) + (uint32_t(memory[pc+3]) << 0);
        //std::cerr << "instruction: " << std::bitset<32> (input_bits) << std::endl;//debug - status

        //store next_pc temporarily as it will get changed during execution
        uint32_t temp_next_pc = next_pc;
        //std::cerr << " temp_next_pc: " << std::hex << temp_next_pc;

        //execute instruction depending on the type
        if(get_type(input_bits) == 'R'){
          //std::cerr << "instruction R detected" << std::endl;
          instruction_R inst;
          inst.set_bits(input_bits);
          inst.execute(registers, pc, next_pc);
          //std::cerr << "instruction R executed" << std::endl;

        }
        else if(get_type(input_bits) == 'I'){
          //std::cerr << "instruction I detected" << std::endl;
          instruction_I inst;
          inst.set_bits(input_bits);
          inst.execute(registers, pc, next_pc, memory);
          //std::cerr << "instruction I executed" << std::endl;

        }
        else if(get_type(input_bits) == 'J'){
          //std::cerr << "instruction J detected" << std::endl;
          instruction_J inst;
          inst.set_bits(input_bits);
          inst.execute(registers, pc, next_pc);
          //std::cerr << "instruction J executed" << std::endl;
        }

        registers[0] = 0; // register 0 is grounded and cannot hold value other than 0

        //point pc to the next instruction
        //std::cerr << " temp_next_pc: " << std::hex << temp_next_pc << std::endl;
        pc = temp_next_pc;
        //std::cerr << "reg: " << registers[3] << std::endl;

      }
      else{
        throw(static_cast<int32_t>(exception::MEMORY));
      }
    }
  }

  catch(int32_t exitCode){
    switch (exitCode) {
      case -10: std::exit(static_cast<int32_t>(exception::ARITHMETIC));
      case -11: std::exit(static_cast<int32_t>(exception::MEMORY));
      case -12: std::exit(static_cast<int32_t>(exception::INSTRUCTION));
      case -21: std::exit(static_cast<int32_t>(error::IO));
    }
  }
  catch(...){
    std::exit(static_cast<int32_t>(error::INTERNAL)); //Unexpected behaviour caused by the simulator
  }
  return 0;
}
