#include <iostream>
#include <bitset>
#include "instruction_I.hpp"

void instruction_I::set_bits(const uint32_t& input_bits){
  bits = input_bits;
  opcode = (bits >> 26);
  src1 = (bits >> 21);
  src2_dest = (bits >> 16);
  address_data = (bits >> 0);
}
