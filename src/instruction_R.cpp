#include <iostream>
#include <vector>
#include <cmath>
#include "instruction_R.hpp"
#include "init.hpp"

void instruction_R::set_bits(const uint32_t& input_bits){
  src1 = 0b11111 & (input_bits >> 21);
  src2 = 0b11111 & (input_bits >> 16);
  dest = 0b11111 & (input_bits >> 11);
  shift_amount = 0b11111 & (input_bits >> 6);
  fn_code = 0b111111 & input_bits;
}

void instruction_R::execute(std::vector<uint32_t>& registers, uint32_t& pc, uint32_t& next_pc){
  switch(fn_code){
    case 0b100000: ADD(registers);
    case 0b100001: ADDU(registers);
    case 0b100100: AND(registers);
    case 0b011010: DIV(registers);
    case 0b011011: DIVU(registers);
    case 0b001001: JALR(registers, pc, next_pc);
    case 0b001000: JR(registers, next_pc);
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
    default: throw(static_cast<int32_t>(exception::INSTRUCTION));
  }
  if(fn_code != 0b001001 && fn_code != 0b001000) next_pc += 4;
}


void instruction_R::ADD(std::vector<uint32_t>& registers){
  uint32_t msb1 = registers[src1] >> 31;
  uint32_t msb2 = registers[src2] >> 31;
  uint32_t temp = registers[src1] + registers[src2];
  uint32_t msb3 = temp >> 31;

  if((msb1 == 0 && msb2 == 0 && msb3 == 1) || (msb1 == 1 && msb2 == 1 && msb3 == 0)){
    throw(static_cast<int32_t>(exception::ARITHMETIC));
  }
  else{
    registers[dest] = temp;
  }
}

void instruction_R::ADDU(std::vector<uint32_t>& registers){
  registers[dest] = registers[src1] + registers[src2];
}

void instruction_R::AND(std::vector<uint32_t>& registers){
  registers[dest] = registers[src1] & registers[src2];
}

void instruction_R::DIV(std::vector<uint32_t>& registers){
  if(registers[src2] == 0){ // Treating division by zero as an exception
    throw(static_cast<int32_t>(exception::ARITHMETIC));
  }
  else{
    registers[32] = static_cast<int32_t>(registers[src1]) / static_cast<int32_t>(registers[src2]);
    registers[33] = static_cast<int32_t>(registers[src1]) % static_cast<int32_t>(registers[src2]);
  }
}

void instruction_R::DIVU(std::vector<uint32_t>& registers){
  if(registers[src2] == 0){ // Treating division by zero as an exception
    throw(static_cast<int32_t>(exception::ARITHMETIC));
  }
  else{
    registers[32] = registers[src1] / registers[src2];
    registers[33] = registers[src1] % registers[src2];
  }
}

void instruction_R::JALR(std::vector<uint32_t>& registers, uint32_t& pc, uint32_t& next_pc){
  registers[dest] = pc + 8;
  next_pc = registers[src1];
}

void instruction_R::JR(std::vector<uint32_t>& registers, uint32_t& next_pc){
  next_pc = registers[src1];
}

void instruction_R::MFHI(std::vector<uint32_t>& registers){
  registers[dest] = registers[33];
}

void instruction_R::MFLO(std::vector<uint32_t>& registers){
  registers[dest] = registers[32];
}

void instruction_R::MTHI(std::vector<uint32_t>& registers){
  registers[33] = registers[src1];
}

void instruction_R::MTLO(std::vector<uint32_t>& registers){
  registers[32] = registers[src1];
}

void instruction_R::MULT(std::vector<uint32_t>& registers){
  int64_t product = static_cast<int32_t>(registers[src1]) * static_cast<int32_t>(registers[src2]);
  registers[32] = product & 0x00000000FFFFFFFF;
  registers[33] = product & 0xFFFFFFFF00000000;
}

void instruction_R::MULTU(std::vector<uint32_t>& registers){
  uint64_t product = registers[src1] * registers[src2];
  registers[32] = product & 0x00000000FFFFFFFF;
  registers[33] = product & 0xFFFFFFFF00000000;
}

void instruction_R::OR(std::vector<uint32_t>& registers){
  registers[dest] = registers[src1] | registers[src2];
}

void instruction_R::SLL(std::vector<uint32_t>& registers){
  registers[dest] = registers[src2] << shift_amount;
}

void instruction_R::SLLV(std::vector<uint32_t>& registers){
  registers[dest] = registers[src2] << registers[src1];
}

void instruction_R::SLT(std::vector<uint32_t>& registers){
  if(static_cast<int32_t>(registers[src1]) < static_cast<int32_t>(registers[src2])) registers[dest] = 1;
  else registers[dest] = 0;
}

void instruction_R::SLTU(std::vector<uint32_t>& registers){
  if(registers[src1] < registers[src2]) registers[dest] = 1;
  else registers[dest] = 0;
}

void instruction_R::SRA(std::vector<uint32_t>& registers){
  registers[dest] = static_cast<int32_t>(registers[src2]) >> shift_amount;
}

void instruction_R::SRAV(std::vector<uint32_t>& registers){
  registers[dest] = static_cast<int32_t>(registers[src2]) >> registers[src1];
}

void instruction_R::SRL(std::vector<uint32_t>& registers){
  registers[dest] = registers[src2] >> shift_amount;
}

void instruction_R::SRLV(std::vector<uint32_t>& registers){
  registers[dest] = registers[src2] >> registers[src1];
}

void instruction_R::SUB(std::vector<uint32_t>& registers){
  uint32_t msb1 = registers[src1] >> 31;
  uint32_t msb2 = registers[src2] >> 31;
  uint32_t temp = registers[src1] - registers[src2];
  uint32_t msb3 = temp >> 31;

  if((msb1 == 0 && msb2 == 1 && msb3 == 1) || (msb1 == 1 && msb2 == 0 && msb3 == 0)){
    throw(static_cast<int32_t>(exception::ARITHMETIC));
  }
  else{
    registers[dest] = temp;
  }
}

void instruction_R::SUBU(std::vector<uint32_t>& registers){
  registers[dest] = registers[src1] - registers[src2];
}

void instruction_R::XOR(std::vector<uint32_t>& registers){
  registers[dest] = registers[src1] ^ registers[src2];
}
