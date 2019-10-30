#include <iostream>
#include <bitset>
#include "instruction_J.hpp"

void instruction_J::set_bits(const uint32_t& input_bits){
  bits = input_bits;
  opcode = std::bitset<6>((bits >> 26).to_ulong());
  address = std::bitset<26>((bits >> 0).to_ulong());
}

void instruction_J::execute(std::vector<uint8_t>& memory, std::vector<uint32_t>& registers, uint32_t& pc){
  switch(opcode){
    case 0b000010: J(pc);
    case 0b000011: JAL(registers, pc);
  }
}

void instruction_J::J(uint32_t& pc){

}
void instruction_J::JAL(std::vector<uint32_t>& registers, uint32_t& pc){

}
