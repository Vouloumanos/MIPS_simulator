#include "init.hpp"

char get_type(const uint32_t& input_bits){
  uint32_t opcode = input_bits >> 26;

  if(opcode == 0b000000) return 'R';
  else if(opcode == 0b000010 || opcode == 0b000011) return 'J';
  else return 'I';
}
