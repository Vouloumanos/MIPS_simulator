#include <iostream>
#include <bitset>
#include "instruction_J.hpp"

void instruction_J::set_bits(const uint32_t& input_bits){
  bits = input_bits;
  opcode = std::bitset<6>((bits >> 26).to_ulong());
  address = std::bitset<26>((bits >> 0).to_ulong());
}
