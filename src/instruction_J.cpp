#include <iostream>
#include <vector>
#include "instruction_J.hpp"
#include "init.hpp"

void instruction_J::set_bits(const uint32_t& input_bits){
  opcode = 0b111111 & (input_bits >> 26);
  address = 0x3FFFFFF & input_bits;
}

void instruction_J::execute(std::vector<uint32_t>& registers, uint32_t& pc, uint32_t& next_pc, std::vector<uint8_t>& memory){
  switch(opcode){
    case 0b000010: J(next_pc);
    case 0b000011: JAL(registers, pc, next_pc);
    default: throw(static_cast<int32_t>(exception::INSTRUCTION));
  }
}

void instruction_J::J(uint32_t& next_pc){
  next_pc = (0xF0000000 & next_pc) | address*4;
}
void instruction_J::JAL(std::vector<uint32_t>& registers, uint32_t& pc, uint32_t& next_pc){
  registers[31] = pc + 8;
  next_pc = (0xF0000000 & next_pc) | address*4;
}
