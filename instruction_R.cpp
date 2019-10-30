#include <iostream>
#include <bitset>
#include "instruction_R.hpp"

void instruction_R::set_bits(const uint32_t& input_bits){
  bits = input_bits;
  opcode = std::bitset<6>((bits >> 26).to_ulong());
  src1 = std::bitset<5>((bits >> 21).to_ulong());
  src2 = std::bitset<5>((bits >> 16).to_ulong());
  dest = std::bitset<5>((bits >> 11).to_ulong());
  shift_amount = std::bitset<5>((bits >> 6).to_ulong());
  fn_code = std::bitset<6>((bits >> 0).to_ulong());
}

void instruction_R::execute(std::vector<uint32_t>& registers, uint32_t& pc){
  switch(fn_code){
    case
  }
}
