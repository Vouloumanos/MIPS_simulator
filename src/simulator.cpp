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
    cpu mips_cpu;
    init_cpu(mips_cpu);

    //set up binstream
    std::string binName = argv[1]; //get binary name
    //std::cerr << "binName: " << binName << std::endl; //debug - display binary name
    std::ifstream binStream(binName, std::ios::binary); //initialise binStream

    if(!binStream.is_open()){
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
        mips_cpu.memory[i+IMEM_OFFSET] = buffer[i];
      }
      else{
        throw(static_cast<uint32_t>(exception::MEMORY));
      }
    }
    delete[] buffer;

    while(1){ //processor running
      if(mips_cpu.pc == 0){ //program has finished, return lower 8 bits of register 2
        uint8_t returnCode = static_cast<uint8_t>(mips_cpu.registers[2]);
        std::exit(returnCode);
      }
      else if(mips_cpu.pc % 4 != 0){
        throw(static_cast<int32_t>(exception::MEMORY));
      }
      else if((mips_cpu.pc < IMEM_END_OFFSET) && (mips_cpu.pc >= IMEM_OFFSET)){
        //get instruction
        uint32_t input_bits = (uint32_t(mips_cpu.memory[mips_cpu.pc]) << 24) + (uint32_t(mips_cpu.memory[mips_cpu.pc+1]) << 16) + (uint32_t(mips_cpu.memory[mips_cpu.pc+2]) << 8) + (uint32_t(mips_cpu.memory[mips_cpu.pc+3]) << 0);

        uint32_t temp_next_pc = mips_cpu.next_pc;

        //execute instruction depending on the type
        if(get_type(input_bits) == 'R'){
          instruction_R inst;
          inst.set_bits(input_bits);
          inst.execute(mips_cpu);
        }
        else if(get_type(input_bits) == 'I'){
          instruction_I inst;
          inst.set_bits(input_bits);
          inst.execute(mips_cpu);
        }
        else if(get_type(input_bits) == 'J'){
          instruction_J inst;
          inst.set_bits(input_bits);
          inst.execute(mips_cpu);
        }

        mips_cpu.registers[0] = 0; // register 0 is grounded and cannot hold value other than 0
        
        mips_cpu.pc = temp_next_pc;
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
