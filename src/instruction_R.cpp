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

void instruction_R::execute(cpu& mips_cpu){
  switch(fn_code){
    case 0b100000: ADD(mips_cpu); mips_cpu.next_pc += 4; return;
    case 0b100001: ADDU(mips_cpu); mips_cpu.next_pc += 4; return;
    case 0b100100: AND(mips_cpu); mips_cpu.next_pc += 4; return;
    case 0b011010: DIV(mips_cpu); mips_cpu.next_pc += 4; return;
    case 0b011011: DIVU(mips_cpu); mips_cpu.next_pc += 4; return;
    case 0b001001: JALR(mips_cpu); return;
    case 0b001000: JR(mips_cpu); return;
    case 0b010000: MFHI(mips_cpu); mips_cpu.next_pc += 4; return;
    case 0b010010: MFLO(mips_cpu); mips_cpu.next_pc += 4; return;
    case 0b010001: MTHI(mips_cpu); mips_cpu.next_pc += 4; return;
    case 0b010011: MTLO(mips_cpu); mips_cpu.next_pc += 4; return;
    case 0b011000: MULT(mips_cpu); mips_cpu.next_pc += 4; return;
    case 0b011001: MULTU(mips_cpu); mips_cpu.next_pc += 4; return;
    case 0b100101: OR(mips_cpu); mips_cpu.next_pc += 4; return;
    case 0b000000: SLL(mips_cpu); mips_cpu.next_pc += 4; return;
    case 0b000100: SLLV(mips_cpu); mips_cpu.next_pc += 4; return;
    case 0b101010: SLT(mips_cpu); mips_cpu.next_pc += 4; return;
    case 0b101011: SLTU(mips_cpu); mips_cpu.next_pc += 4; return;
    case 0b000011: SRA(mips_cpu); mips_cpu.next_pc += 4; return;
    case 0b000111: SRAV(mips_cpu); mips_cpu.next_pc += 4; return;
    case 0b000010: SRL(mips_cpu); mips_cpu.next_pc += 4; return;
    case 0b000110: SRLV(mips_cpu); mips_cpu.next_pc += 4; return;
    case 0b100010: SUB(mips_cpu); mips_cpu.next_pc += 4; return;
    case 0b100011: SUBU(mips_cpu); mips_cpu.next_pc += 4; return;
    case 0b100110: XOR(mips_cpu); mips_cpu.next_pc += 4; return;
    default: throw(static_cast<int32_t>(exception::INSTRUCTION));
  }
}


void instruction_R::ADD(cpu& mips_cpu){
  // std::cerr << "ADD" << std::endl;
  // std::cerr << "reg2: " << registers[src1] << " reg3: " << registers[src2] << " reg1: " << registers[dest] << std::endl;
  //
  uint32_t msb1 = mips_cpu.registers[src1] >> 31;
  uint32_t msb2 = mips_cpu.registers[src2] >> 31;
  uint32_t temp = mips_cpu.registers[src1] + mips_cpu.registers[src2];
  uint32_t msb3 = temp >> 31;

  if((msb1 == 0 && msb2 == 0 && msb3 == 1) || (msb1 == 1 && msb2 == 1 && msb3 == 0)){
    throw(static_cast<int32_t>(exception::ARITHMETIC));
  }
  else{
    mips_cpu.registers[dest] = temp;
  }

  // std::cerr << "reg2: " << registers[src1] << " reg3: " << registers[src2] << " reg1: " << registers[dest] << std::endl;

}

void instruction_R::ADDU(cpu& mips_cpu){
  mips_cpu.registers[dest] = mips_cpu.registers[src1] + mips_cpu.registers[src2];
}

void instruction_R::AND(cpu& mips_cpu){
  mips_cpu.registers[dest] = mips_cpu.registers[src1] & mips_cpu.registers[src2];
}

void instruction_R::DIV(cpu& mips_cpu){
  if(mips_cpu.registers[src2] != 0){ // Division by 0 is undefined
    mips_cpu.lo = static_cast<int32_t>(mips_cpu.registers[src1]) / static_cast<int32_t>(mips_cpu.registers[src2]);
    mips_cpu.hi = static_cast<int32_t>(mips_cpu.registers[src1]) % static_cast<int32_t>(mips_cpu.registers[src2]);
  }
}

void instruction_R::DIVU(cpu& mips_cpu){
  if(mips_cpu.registers[src2] != 0){ // Division by 0 is undefined
    mips_cpu.lo = mips_cpu.registers[src1] / mips_cpu.registers[src2];
    mips_cpu.hi = mips_cpu.registers[src1] % mips_cpu.registers[src2];
  }
}

void instruction_R::JALR(cpu& mips_cpu){
  mips_cpu.registers[dest] = mips_cpu.pc + 8;
  mips_cpu.next_pc = mips_cpu.registers[src1];
}

void instruction_R::JR(cpu& mips_cpu){
  mips_cpu.next_pc = mips_cpu.registers[src1];
}

void instruction_R::MFHI(cpu& mips_cpu){
  mips_cpu.registers[dest] = mips_cpu.hi;
}

void instruction_R::MFLO(cpu& mips_cpu){
  mips_cpu.registers[dest] = mips_cpu.lo;
}

void instruction_R::MTHI(cpu& mips_cpu){
  mips_cpu.hi = mips_cpu.registers[src1];
}

void instruction_R::MTLO(cpu& mips_cpu){
  mips_cpu.lo = mips_cpu.registers[src1];
}

void instruction_R::MULT(cpu& mips_cpu){
  int64_t temp1, temp2;
  if(mips_cpu.registers[src1] >> 31) temp1 = static_cast<int64_t>(mips_cpu.registers[src1]) | 0xFFFFFFFF00000000;
  else temp1 = static_cast<int64_t>(mips_cpu.registers[src1]);

  if(mips_cpu.registers[src2] >> 31) temp2 = static_cast<int64_t>(mips_cpu.registers[src2]) | 0xFFFFFFFF00000000;
  else temp2 = static_cast<int64_t>(mips_cpu.registers[src2]);

  int64_t product = temp1 * temp2;
  mips_cpu.lo = static_cast<int32_t>(product);
  mips_cpu.hi = static_cast<int32_t>(product >> 32);
}

void instruction_R::MULTU(cpu& mips_cpu){
  uint64_t product = static_cast<uint64_t>(mips_cpu.registers[src1]) * static_cast<uint64_t>(mips_cpu.registers[src2]);
  mips_cpu.lo = static_cast<int32_t>(product);
  mips_cpu.hi = static_cast<int32_t>(product >> 32);
}

void instruction_R::OR(cpu& mips_cpu){
  mips_cpu.registers[dest] = mips_cpu.registers[src1] | mips_cpu.registers[src2];
}

void instruction_R::SLL(cpu& mips_cpu){
  mips_cpu.registers[dest] = mips_cpu.registers[src2] << shift_amount;
}

void instruction_R::SLLV(cpu& mips_cpu){
  mips_cpu.registers[dest] = mips_cpu.registers[src2] << (mips_cpu.registers[src1] & 0b11111);
}

void instruction_R::SLT(cpu& mips_cpu){
  if(static_cast<int32_t>(mips_cpu.registers[src1]) < static_cast<int32_t>(mips_cpu.registers[src2])) mips_cpu.registers[dest] = 1;
  else mips_cpu.registers[dest] = 0;
}

void instruction_R::SLTU(cpu& mips_cpu){
  if(mips_cpu.registers[src1] < mips_cpu.registers[src2]) mips_cpu.registers[dest] = 1;
  else mips_cpu.registers[dest] = 0;
}

void instruction_R::SRA(cpu& mips_cpu){
  mips_cpu.registers[dest] = static_cast<int32_t>(mips_cpu.registers[src2]) >> shift_amount;
}

void instruction_R::SRAV(cpu& mips_cpu){
  mips_cpu.registers[dest] = static_cast<int32_t>(mips_cpu.registers[src2]) >> (mips_cpu.registers[src1] & 0b11111);
}

void instruction_R::SRL(cpu& mips_cpu){
  mips_cpu.registers[dest] = mips_cpu.registers[src2] >> shift_amount;
}

void instruction_R::SRLV(cpu& mips_cpu){
  mips_cpu.registers[dest] = mips_cpu.registers[src2] >> (mips_cpu.registers[src1] & 0b11111);
}

void instruction_R::SUB(cpu& mips_cpu){
  uint32_t msb1 = mips_cpu.registers[src1] >> 31;
  uint32_t msb2 = mips_cpu.registers[src2] >> 31;
  uint32_t temp = mips_cpu.registers[src1] - mips_cpu.registers[src2];
  uint32_t msb3 = temp >> 31;

  if((msb1 == 0 && msb2 == 1 && msb3 == 1) || (msb1 == 1 && msb2 == 0 && msb3 == 0)){
    throw(static_cast<int32_t>(exception::ARITHMETIC));
  }
  else{
    mips_cpu.registers[dest] = temp;
  }
}

void instruction_R::SUBU(cpu& mips_cpu){
  mips_cpu.registers[dest] = mips_cpu.registers[src1] - mips_cpu.registers[src2];
}

void instruction_R::XOR(cpu& mips_cpu){
  mips_cpu.registers[dest] = mips_cpu.registers[src1] ^ mips_cpu.registers[src2];
}
