#include <iostream>
#include <bitset>
#include "instruction_I.hpp"

void instruction_I::set_bits(const uint32_t& input_bits){
  bits = input_bits;
  opcode = std::bitset<6> ((bits >> 26).to_ulong());
  src1 = std::bitset<5> ((bits >> 21).to_ulong());
  src2_dest = std::bitset<5>((bits >> 16).to_ulong());
  address_data = std::bitset<16>((bits >> 0).to_ulong());
}
