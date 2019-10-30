#include <iostream>
#include <bitset>
#include <vector>
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
    case 0b100000: ADD(registers);
    case 0b100001: ADDU(registers);
    case 0b100100: AND(registers);
    case 0b011010: DIV(registers);
    case 0b011011: DIVU(registers);
    case 0b001001: JALR(registers, pc);
    case 0b001000: JR(registers, pc);
    case 0b010000: MFHI(registers);
    case 0b010010: MFLO(registers);
    case 0b010001: MTHI(registers);
    case 0b010011: MTLO(registers);
    case 0b011000: MULT(registers);
    case 0b011001: MULTU(registers);
    case 0b100101: OR(registers);
    case 0b000000: SLL(registers);
    case 0b000100: SLLV(registers);
    case 0b101010: SLT(registers);
    case 0b101011: SLTU(registers);
    case 0b000011: SRA(registers);
    case 0b000111: SRAV(registers);
    case 0b000010: SRL(registers);
    case 0b000110: SRLV(registers);
    case 0b100010: SUB(registers);
    case 0b100011: SUBU(registers);
    case 0b100110: XOR(registers);
  }
  if(fn_code != 0b001001 && fn_code != 0b001000) pc += 4;
}

void instruction_R::ADD(std::vector<uint32_t>& registers, uint32_t& pc){

}
void instruction_R::ADDU(std::vector<uint32_t>& registers, uint32_t& pc){

}
void instruction_R::AND(std::vector<uint32_t>& registers, uint32_t& pc){

}
void instruction_R::DIV(std::vector<uint32_t>& registers, uint32_t& pc){

}
void instruction_R::DIVU(std::vector<uint32_t>& registers, uint32_t& pc){

}
void instruction_R::JALR(std::vector<uint32_t>& registers, uint32_t& pc){

}
void instruction_R::JR(std::vector<uint32_t>& registers, uint32_t& pc){

}
void instruction_R::MFHI(std::vector<uint32_t>& registers, uint32_t& pc){

}
void instruction_R::MFLO(std::vector<uint32_t>& registers, uint32_t& pc){

}
void instruction_R::MTHI(std::vector<uint32_t>& registers, uint32_t& pc){

}
void instruction_R::MTLO(std::vector<uint32_t>& registers, uint32_t& pc){

}
void instruction_R::MULT(std::vector<uint32_t>& registers, uint32_t& pc){

}
void instruction_R::MULTU(std::vector<uint32_t>& registers, uint32_t& pc){

}
void instruction_R::OR(std::vector<uint32_t>& registers, uint32_t& pc){

}
void instruction_R::SLL(std::vector<uint32_t>& registers, uint32_t& pc){

}
void instruction_R::SLLV(std::vector<uint32_t>& registers, uint32_t& pc){

}
void instruction_R::SLT(std::vector<uint32_t>& registers, uint32_t& pc){

}
void instruction_R::SLTU(std::vector<uint32_t>& registers, uint32_t& pc){

}
void instruction_R::SRA(std::vector<uint32_t>& registers, uint32_t& pc){

}
void instruction_R::SRAV(std::vector<uint32_t>& registers, uint32_t& pc){

}
void instruction_R::SRL(std::vector<uint32_t>& registers, uint32_t& pc){

}
void instruction_R::SRLV(std::vector<uint32_t>& registers, uint32_t& pc){

}
void instruction_R::SUB(std::vector<uint32_t>& registers, uint32_t& pc){

}
void instruction_R::SUBU(std::vector<uint32_t>& registers, uint32_t& pc){

}
void instruction_R::XOR(std::vector<uint32_t>& registers, uint32_t& pc){

}
