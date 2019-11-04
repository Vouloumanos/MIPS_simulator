#include <iostream>
#include <bitset>
#include <vector>
#include <cmath>
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
  switch((int)fn_code.to_ulong()){
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


void instruction_R::ADD(std::vector<uint32_t>& registers){
  uint32_t msb1 = registers[src1.to_ulong()] >> 31;
  uint32_t msb2 = registers[src2.to_ulong()] >> 31;
  uint32_t temp = registers[src1.to_ulong()] + registers[src2.to_ulong()];
  uint32_t msb3 = temp >> 31;

  if((msb1 == 0 && msb2 == 0 && msb3 == 1) || (msb1 == 1 && msb2 == 1 && msb3 == 0)){
    //TRIGGER OVERFLOW
  }
  else{
    registers[dest.to_ulong()] = temp;
  }
}

void instruction_R::ADDU(std::vector<uint32_t>& registers){
  registers[dest.to_ulong()] = registers[src1.to_ulong()] + registers[src2.to_ulong()];
}

void instruction_R::AND(std::vector<uint32_t>& registers){
  registers[dest.to_ulong()] = registers[src1.to_ulong()] & registers[src2.to_ulong()];
}

void instruction_R::DIV(std::vector<uint32_t>& registers){
  registers[32] = static_cast<int>(registers[src1.to_ulong()]) / static_cast<int>(registers[src2.to_ulong()]);
  registers[33] = static_cast<int>(registers[src1.to_ulong()]) % static_cast<int>(registers[src2.to_ulong()]);
}

void instruction_R::DIVU(std::vector<uint32_t>& registers){
  registers[32] = registers[src1.to_ulong()] / registers[src2.to_ulong()];
  registers[33] = registers[src1.to_ulong()] % registers[src2.to_ulong()];
}

void instruction_R::JALR(std::vector<uint32_t>& registers, uint32_t& pc){
  registers[dest.to_ulong()] = pc + 8;
  pc = registers[src1.to_ulong()];
}

void instruction_R::JR(std::vector<uint32_t>& registers, uint32_t& pc){
  pc = registers[src1.to_ulong()];
}

void instruction_R::MFHI(std::vector<uint32_t>& registers){
  registers[dest.to_ulong()] = registers[33];
}

void instruction_R::MFLO(std::vector<uint32_t>& registers){
  registers[dest.to_ulong()] = registers[32];
}

void instruction_R::MTHI(std::vector<uint32_t>& registers){
  registers[33] = registers[src1.to_ulong()];
}

void instruction_R::MTLO(std::vector<uint32_t>& registers){
  registers[32] = registers[src1.to_ulong()];
}

void instruction_R::MULT(std::vector<uint32_t>& registers){
  int64_t product = static_cast<int>(registers[src1.to_ulong()]) * static_cast<int>(registers[src2.to_ulong()]);
  registers[32] = product & 0x00000000FFFFFFFF;
  registers[33] = product & 0xFFFFFFFF00000000;
}

void instruction_R::MULTU(std::vector<uint32_t>& registers){
  uint64_t product = registers[src1.to_ulong()] * registers[src2.to_ulong()];
  registers[32] = product & 0x00000000FFFFFFFF;
  registers[33] = product & 0xFFFFFFFF00000000;
}

void instruction_R::OR(std::vector<uint32_t>& registers){
  registers[dest.to_ulong()] = registers[src1.to_ulong()] | registers[src2.to_ulong()];
}

void instruction_R::SLL(std::vector<uint32_t>& registers){
  registers[dest.to_ulong()] = registers[src2.to_ulong()] << shift_amount.to_ulong();
}

void instruction_R::SLLV(std::vector<uint32_t>& registers){
  registers[dest.to_ulong()] = registers[src2.to_ulong()] << registers[src1.to_ulong()];
}

void instruction_R::SLT(std::vector<uint32_t>& registers){
  if(static_cast<int>(registers[src1.to_ulong()]) < static_cast<int>(registers[src2.to_ulong()])) registers[dest.to_ulong()] = 1;
  else registers[dest.to_ulong()] = 0;
}

void instruction_R::SLTU(std::vector<uint32_t>& registers){
  if(registers[src1.to_ulong()] < registers[src2.to_ulong()]) registers[dest.to_ulong()] = 1;
  else registers[dest.to_ulong()] = 0;
}

void instruction_R::SRA(std::vector<uint32_t>& registers){
  uint32_t msb = registers[src2.to_ulong()] >> 31;
  uint32_t temp = registers[src2.to_ulong()] >> shift_amount.to_ulong();
  if(msb){
    uint32_t right_ones = 0;
    for(int i = 0; i < shift_amount.to_ulong(); i++){
      right_ones += std::pow(2, 31-i);
    }
    temp = temp | right_ones;
  }
  registers[dest.to_ulong()] = temp;
}

void instruction_R::SRAV(std::vector<uint32_t>& registers){
  uint32_t msb = registers[src2.to_ulong()] >> 31;
  uint32_t temp = registers[src2.to_ulong()] >> registers[src1.to_ulong()];
  if(msb){
    uint32_t right_ones = 0;
    for(int i = 0; i < registers[src1.to_ulong()]; i++){
      right_ones += std::pow(2, 31-i);
    }
    temp = temp | right_ones;
  }
  registers[dest.to_ulong()] = temp;
}

void instruction_R::SRL(std::vector<uint32_t>& registers){
  registers[dest.to_ulong()] = registers[src2.to_ulong()] >> shift_amount.to_ulong();
}

void instruction_R::SRLV(std::vector<uint32_t>& registers){
  registers[dest.to_ulong()] = registers[src2.to_ulong()] >> registers[src1.to_ulong()];
}

void instruction_R::SUB(std::vector<uint32_t>& registers){
  uint32_t msb1 = registers[src1.to_ulong()] >> 31;
  uint32_t msb2 = registers[src2.to_ulong()] >> 31;
  uint32_t temp = registers[src1.to_ulong()] - registers[src2.to_ulong()];
  uint32_t msb3 = temp >> 31;

  if((msb1 == 0 && msb2 == 1 && msb3 == 1) || (msb1 == 1 && msb2 == 0 && msb3 == 0)){
    //TRIGGER OVERFLOW
  }
  else{
    registers[dest.to_ulong()] = temp;
  }
}

void instruction_R::SUBU(std::vector<uint32_t>& registers){
  registers[dest.to_ulong()] = registers[src1.to_ulong()] - registers[src2.to_ulong()];
}

void instruction_R::XOR(std::vector<uint32_t>& registers){
  registers[dest.to_ulong()] = registers[src1.to_ulong()] ^ registers[src2.to_ulong()];

}
