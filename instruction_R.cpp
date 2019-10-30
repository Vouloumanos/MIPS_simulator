#include <iostream>
#include <bitset>
#include "instruction_R.hpp"

void instruction_R::set_bits(const uint32_t& input_bits){
  bits = input_bits;
  opcode = (bits >> 26);
  src1 = (bits >> 21);
  src2 = (bits >> 16);
  dest = (bits >> 11);
  shift_amount = (bits >> 6);
  fn_code = (bits >> 0);
}

void instruction_R::execute(std::vector<uint32_t>& registers, uint32_t& pc){
  switch(fn_code){
    case
  }
}
