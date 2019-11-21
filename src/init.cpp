#include "init.hpp"

void init_cpu(cpu& mips_cpu){
  mips_cpu.memory.resize(MEM_LENGTH, 0);
  mips_cpu.registers.resize(32, 0);
  mips_cpu.hi = 0;
  mips_cpu.lo = 0;
  mips_cpu.pc = IMEM_OFFSET;
  mips_cpu.next_pc = IMEM_OFFSET + 4;
}

char get_type(const uint32_t& input_bits){
  uint32_t opcode = input_bits >> 26;

  if(opcode == 0b000000) return 'R';
  else if(opcode == 0b000010 || opcode == 0b000011) return 'J';
  else return 'I';
}

void output_char(uint32_t output){
  putchar(static_cast<int>(output));

  if(std::ferror(stdout)){
    throw(static_cast<int32_t>(error::IO));
  }
}

int32_t input_char(){
  int input;
  input = getchar();

  if(std::ferror(stdin)){
    throw(static_cast<int32_t>(error::IO));
  }
  return static_cast<int32_t>(input);
}
