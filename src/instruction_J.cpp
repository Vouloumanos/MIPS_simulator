#include <iostream>
#include <vector>
#include "instruction_J.hpp"
#include "init.hpp"

void instruction_J::set_bits(const uint32_t& input_bits){
  opcode = 0b111111 & (input_bits >> 26);
  address = 0x3FFFFFF & input_bits;
}

void instruction_J::execute(cpu& mips_cpu){
  switch(opcode){
    case 0b000010: J(mips_cpu); return;
    case 0b000011: JAL(mips_cpu); return;
    default: throw(static_cast<int32_t>(exception::INSTRUCTION));
  }
}

void instruction_J::J(cpu& mips_cpu){
  mips_cpu.next_pc = (0xF0000000 & mips_cpu.pc) | address*4;
}
void instruction_J::JAL(cpu& mips_cpu){
  mips_cpu.registers[31] = mips_cpu.pc + 8;
  mips_cpu.next_pc = (0xF0000000 & mips_cpu.pc) | address*4;
}
