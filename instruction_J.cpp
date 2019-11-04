#include <iostream>
#include <vector>
#include "instruction_J.hpp"

void instruction_J::set_bits(const uint32_t& input_bits){
  bits = input_bits;
  opcode = 0b111111 & (bits >> 26);
  address = 0x3FFFFFF & bits;
}

void instruction_J::execute(std::vector<uint32_t>& registers, uint32_t& pc, std::vector<uint8_t>& memory){
  switch(opcode){
    case 0b000010: J(pc);
    case 0b000011: JAL(registers, pc);
  }
}

void instruction_J::J(uint32_t& pc){
  pc = address*4;
}
void instruction_J::JAL(std::vector<uint32_t>& registers, uint32_t& pc){
  registers[31] = pc + 8;
  pc = address*4;
}
