#include <iostream>
#include <bitset>
#include "instruction_J.hpp"

void instruction_J::set_bits(const uint32_t& input_bits){
  bits = input_bits;
  opcode = (bits >> 26);
  address = (bits >> 0);
}
