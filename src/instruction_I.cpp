#include <iostream>
#include <vector>

#include "instruction_I.hpp"

#define IMEM_LENGTH 0x1000000
#define DMEM_LENGTH 0x4000000
#define MEM_LENGTH 0x30000004
#define IMEM_OFFSET 0x10000000
#define DMEM_OFFSET 0x20000000
#define INPUT_OFFSET 0x30000000
#define OUTPUT_OFFSET 0x30000004
#define IMEM_END_OFFSET 0x11000000
#define DMEM_END_OFFSET 0x24000000

void instruction_I::set_bits(const uint32_t& input_bits){
  opcode = input_bits >> 26;
  src1 = 0b11111 & (input_bits >> 21);
  src2_dest = 0b11111 & (input_bits >> 16);
  address_data = 0xFFFF & input_bits;
}

void instruction_I::execute(cpu& mips_cpu){
  switch(opcode){
    case 0b001000: ADDI(mips_cpu); mips_cpu.next_pc += 4; return;
    case 0b001001: ADDIU(mips_cpu); mips_cpu.next_pc += 4;  return;
    case 0b001100: ANDI(mips_cpu); mips_cpu.next_pc += 4; return;
    case 0b000100: BEQ(mips_cpu); return;
    case 0b000001: switch(src2_dest){
      case 0b00001: BGEZ(mips_cpu); return;
      case 0b10001: BGEZAL(mips_cpu); return;
      case 0b00000: BLTZ(mips_cpu); return;
      case 0b10000: BLTZAL(mips_cpu); return;
    }
    case 0b000111: BGTZ(mips_cpu); return;
    case 0b000110: BLEZ(mips_cpu); return;
    case 0b000101: BNE(mips_cpu); return;
    case 0b100000: LB(mips_cpu); mips_cpu.next_pc += 4; return;
    case 0b100100: LBU(mips_cpu); mips_cpu.next_pc += 4; return;
    case 0b100001: LH(mips_cpu); mips_cpu.next_pc += 4; return;
    case 0b100101: LHU(mips_cpu); mips_cpu.next_pc += 4; return;
    case 0b001111: LUI(mips_cpu); mips_cpu.next_pc += 4; return;
    case 0b100011: LW(mips_cpu); mips_cpu.next_pc += 4; return;
    case 0b100010: LWL(mips_cpu); mips_cpu.next_pc += 4; return;
    case 0b100110: LWR(mips_cpu); mips_cpu.next_pc += 4; return;
    case 0b001101: ORI(mips_cpu); mips_cpu.next_pc += 4; return;
    case 0b101000: SB(mips_cpu); mips_cpu.next_pc += 4; return;
    case 0b101001: SH(mips_cpu); mips_cpu.next_pc += 4; return;
    case 0b001010: SLTI(mips_cpu); mips_cpu.next_pc += 4; return;
    case 0b001011: SLTIU(mips_cpu); mips_cpu.next_pc += 4; return;
    case 0b101011: SW(mips_cpu); mips_cpu.next_pc += 4; return;
    case 0b001110: XORI(mips_cpu); mips_cpu.next_pc += 4; return;
    default: throw(static_cast<int32_t>(exception::INSTRUCTION));
  }
}

void instruction_I::ADDI(cpu& mips_cpu){
  uint32_t immediate;
  uint32_t msb1 = address_data >> 15;
  uint32_t msb2 = mips_cpu.registers[src1] >> 31;
  if(msb1 == 1){
    immediate = 0xFFFF0000 | address_data;
  }
  else{
    immediate = address_data;
  }

  uint32_t temp = mips_cpu.registers[src1] + immediate;
  uint32_t msb3 = temp >> 31;

  if((msb1 == 0 && msb2 == 0 && msb3 == 1) || (msb1 == 1 && msb2 == 1 && msb3 == 0)){
    throw(static_cast<int32_t>(exception::ARITHMETIC));
  }
  else{
    mips_cpu.registers[src2_dest] = temp;
  }
}

void instruction_I::ADDIU(cpu& mips_cpu){
  uint32_t immediate;
  if((address_data >> 15) == 1){
    immediate = 0xFFFF0000 | address_data;
  }
  else{
    immediate = address_data;
  }
  mips_cpu.registers[src2_dest] = mips_cpu.registers[src1] + immediate;
}

void instruction_I::ANDI(cpu& mips_cpu){
  mips_cpu.registers[src2_dest] = mips_cpu.registers[src1] & address_data;
}

void instruction_I::BEQ(cpu& mips_cpu){
  if(mips_cpu.registers[src1] == mips_cpu.registers[src2_dest]){
    int32_t offset;
    if((address_data >> 15) == 1){
      offset = 0xFFFC0000 | (address_data*4);
    }
    else{
      offset = address_data*4;
    }
    mips_cpu.next_pc += offset;
  }
  else{
    mips_cpu.next_pc += 4;
  }
}

void instruction_I::BGEZ(cpu& mips_cpu){
  if(static_cast<int32_t>(mips_cpu.registers[src1]) >= 0){
    int32_t offset;
    if((address_data >> 15) == 1){
      offset = 0xFFFC0000 | (address_data*4);
    }
    else{
      offset = address_data*4;
    }
    mips_cpu.next_pc += offset;
  }
  else{
    mips_cpu.next_pc += 4;
  }
}

void instruction_I::BGEZAL(cpu& mips_cpu){
  mips_cpu.registers[31] = mips_cpu.pc + 8;
  if(static_cast<int32_t>(mips_cpu.registers[src1]) >= 0){
    int32_t offset;
    if((address_data >> 15) == 1){
      offset = 0xFFFC0000 | (address_data*4);
    }
    else{
      offset = address_data*4;
    }

    mips_cpu.next_pc += offset;
  }
  else{
    mips_cpu.next_pc += 4;
  }
}

void instruction_I::BGTZ(cpu& mips_cpu){
  if(static_cast<int32_t>(mips_cpu.registers[src1]) > 0){
    int32_t offset;
    if((address_data >> 15) == 1){
      offset = 0xFFFC0000 | (address_data*4);
    }
    else{
      offset = address_data*4;
    }
    mips_cpu.next_pc += offset;
  }
  else{
    mips_cpu.next_pc += 4;
  }
}

void instruction_I::BLEZ(cpu& mips_cpu){
  if(static_cast<int32_t>(mips_cpu.registers[src1]) <= 0){
    int32_t offset;
    if((address_data >> 15) == 1){
      offset = 0xFFFC0000 | (address_data*4);
    }
    else{
      offset = address_data*4;
    }
    mips_cpu.next_pc += offset;
  }
  else{
    mips_cpu.next_pc += 4;
  }
}

void instruction_I::BLTZ(cpu& mips_cpu){
  if(static_cast<int32_t>(mips_cpu.registers[src1]) < 0){
    int32_t offset;
    if((address_data >> 15) == 1){
      offset = 0xFFFC0000 | (address_data*4);
    }
    else{
      offset = address_data*4;
    }
    mips_cpu.next_pc += offset;
  }
  else{
    mips_cpu.next_pc += 4;
  }
}

void instruction_I::BLTZAL(cpu& mips_cpu){
  mips_cpu.registers[31] = mips_cpu.pc + 8;
  if(static_cast<int32_t>(mips_cpu.registers[src1]) < 0){
    int32_t offset;
    if((address_data >> 15) == 1){
      offset = 0xFFFC0000 | (address_data*4);
    }
    else{
      offset = address_data*4;
    }
    mips_cpu.next_pc += offset;
  }
  else{
    mips_cpu.next_pc += 4;
  }
}

void instruction_I::BNE(cpu& mips_cpu){
  if(mips_cpu.registers[src1] != mips_cpu.registers[src2_dest]){
    int32_t offset;
    if((address_data >> 15) == 1){
      offset = 0xFFFC0000 | (address_data*4);
    }
    else{
      offset = address_data*4;
    }
    mips_cpu.next_pc += offset;
  }
  else{
    mips_cpu.next_pc += 4;
  }
}

void instruction_I::LB(cpu& mips_cpu){
  int32_t offset;
  if((address_data >> 15) == 1){
    offset = 0xFFFF0000 | address_data;
  }
  else{
    offset = address_data;
  }
  uint32_t address = mips_cpu.registers[src1] + offset;
  if(((address >= DMEM_OFFSET) && (address < DMEM_END_OFFSET)) || ((address >=IMEM_OFFSET) && (address < IMEM_END_OFFSET))){
    if((mips_cpu.memory[address] >> 7) == 1){
      mips_cpu.registers[src2_dest] = 0xFFFFFF00 | static_cast<uint32_t>(mips_cpu.memory[address]);
    }
    else{
      mips_cpu.registers[src2_dest] = static_cast<uint32_t>(mips_cpu.memory[address]);
    }
  }
  else if((address >= INPUT_OFFSET) && (address < INPUT_END_OFFSET)){ //verify
    int32_t input = input_char();

    if(address == INPUT_OFFSET+3){
      if((input >> 7) == 1){
        mips_cpu.registers[src2_dest] = 0xFFFFFF00 | input;
      }
      else if((input >> 7) == 0){
        mips_cpu.registers[src2_dest] = 0x000000FF & input;
      }
    }
    else if(input == -1){
        mips_cpu.registers[src2_dest] = -1;
    }
    else{
      mips_cpu.registers[src2_dest] = 0;
    }
  }
  else{
    throw(static_cast<int32_t>(exception::MEMORY));
  }
}

void instruction_I::LBU(cpu& mips_cpu){
  int32_t offset;
  if((address_data >> 15) == 1){
    offset = 0xFFFF0000 | address_data;
  }
  else{
    offset = address_data;
  }
  uint32_t address = mips_cpu.registers[src1] + offset;
  if(((address >= DMEM_OFFSET) && (address < DMEM_END_OFFSET)) || ((address >=IMEM_OFFSET) && (address < IMEM_END_OFFSET))){
    mips_cpu.registers[src2_dest] = static_cast<uint32_t>(mips_cpu.memory[address]);
  }
  else if((address >= INPUT_OFFSET) && (address < INPUT_END_OFFSET)){ //verify
    int32_t input = input_char();

    if(address == INPUT_OFFSET+3){
        mips_cpu.registers[src2_dest] = 0x000000FF & input;
    }
    else if(input == -1){
      mips_cpu.registers[src2_dest] = 0x000000FF;
    }
    else{
      mips_cpu.registers[src2_dest] = 0;
    }
  }
  else{
    throw(static_cast<int32_t>(exception::MEMORY));
  }
}

void instruction_I::LH(cpu& mips_cpu){
  int32_t offset;
  if((address_data >> 15) == 1){
    offset = 0xFFFF0000 | address_data;
  }
  else{
    offset = address_data;
  }
  uint32_t address = mips_cpu.registers[src1] + offset;

  if((((address >= DMEM_OFFSET) && (address < DMEM_END_OFFSET)) || ((address >=IMEM_OFFSET) && (address <IMEM_END_OFFSET))) && (address%2 == 0)){
    if((mips_cpu.memory[address] >> 7) == 1){
      mips_cpu.registers[src2_dest] = 0xFFFF0000 | (static_cast<uint32_t>(mips_cpu.memory[address]) << 8) | (static_cast<uint32_t>(mips_cpu.memory[address+1]));
    }
    else{
      mips_cpu.registers[src2_dest] = (static_cast<uint32_t>(mips_cpu.memory[address]) << 8) | (static_cast<uint32_t>(mips_cpu.memory[address+1]));
    }
  }
  else if(address == INPUT_OFFSET+2){
    int32_t input = input_char();

    if(input == -1){
      mips_cpu.registers[src2_dest] = -1;
    }
    else{
      mips_cpu.registers[src2_dest] = 0x000000FF & input;
    }
  }
  else if(address == INPUT_OFFSET){
    if(input == -1){
      mips_cpu.registers[src2_dest] = -1;
    }
    else{
      mips_cpu.registers[src2_dest] = 0;
    }
  }
  else{
    throw(static_cast<int32_t>(exception::MEMORY));
  }
}

void instruction_I::LHU(cpu& mips_cpu){
  int32_t offset;
  if((address_data >> 15) == 1){
    offset = 0xFFFF0000 | address_data;
  }
  else{
    offset = address_data;
  }
  uint32_t address = mips_cpu.registers[src1] + offset;
  if((((address >= DMEM_OFFSET) && (address < DMEM_END_OFFSET)) || ((address >=IMEM_OFFSET) && (address <IMEM_END_OFFSET))) && (address%2 == 0)){
    mips_cpu.registers[src2_dest] = (static_cast<uint32_t>(mips_cpu.memory[address]) << 8) | static_cast<uint32_t>(mips_cpu.memory[address+1]);
  }
  else if(address == INPUT_OFFSET+2){
    int32_t input = input_char();

    if(input == -1){
      mips_cpu.registers[src2_dest] = 0x0000FFFF;
    }
    else{
      mips_cpu.registers[src2_dest] = 0x000000FF & input;
    }
  }
  else if(address == INPUT_OFFSET){
    if(input == -1){
      mips_cpu.registers[src2_dest] = 0x0000FFFF;
    }
    else{
      mips_cpu.registers[src2_dest] = 0;
    }  
  }
  else{
    throw(static_cast<int32_t>(exception::MEMORY));
  }
}

void instruction_I::LUI(cpu& mips_cpu){
  mips_cpu.registers[src2_dest] = (address_data << 16);
}

void instruction_I::LW(cpu& mips_cpu){
  int32_t offset;
  if((address_data >> 15) == 1){
    offset = 0xFFFF0000 | address_data;
  }
  else{
    offset = address_data;
  }
  uint32_t address = mips_cpu.registers[src1] + offset;
  if((((address >= DMEM_OFFSET) && (address < DMEM_END_OFFSET)) || ((address >=IMEM_OFFSET) && (address <IMEM_END_OFFSET))) && (address%4 == 0)){
    mips_cpu.registers[src2_dest] = (static_cast<uint32_t>(mips_cpu.memory[address]) << 24) | (static_cast<uint32_t>(mips_cpu.memory[address+1]) << 16) | (static_cast<uint32_t>(mips_cpu.memory[address+2]) << 8) | (static_cast<uint32_t>(mips_cpu.memory[address+3]));
  }
  else if(address == INPUT_OFFSET){
    int32_t input = input_char();

    if(input == -1){
      mips_cpu.registers[src2_dest] = -1;
    }
    else{
      mips_cpu.registers[src2_dest] = 0x000000FF & input;
    }
  }
  else{
    throw(static_cast<int32_t>(exception::MEMORY));
  }
}

void instruction_I::LWL(cpu& mips_cpu){
  int32_t offset;
  if((address_data >> 15) == 1){
    offset = 0xFFFF0000 | address_data;
  }
  else{
    offset = address_data;
  }
  uint32_t address = mips_cpu.registers[src1] + offset;
  if(((address >= DMEM_OFFSET) && (address < DMEM_END_OFFSET)) || ((address >=IMEM_OFFSET) && (address < IMEM_END_OFFSET))){
    switch(address%4){
      case 0: {
        mips_cpu.registers[src2_dest] = (static_cast<uint32_t>(mips_cpu.memory[address]) << 24) | (static_cast<uint32_t>(mips_cpu.memory[address+1]) << 16) | (static_cast<uint32_t>(mips_cpu.memory[address+2]) << 8) | (static_cast<uint32_t>(mips_cpu.memory[address+3]));
      }
      case 1: {
        mips_cpu.registers[src2_dest] = mips_cpu.registers[src2_dest] & 0xFF;
        mips_cpu.registers[src2_dest] = (static_cast<uint32_t>(mips_cpu.memory[address]) << 24) | (static_cast<uint32_t>(mips_cpu.memory[address+1]) << 16) | (static_cast<uint32_t>(mips_cpu.memory[address+2]) << 8) | mips_cpu.registers[src2_dest];
      }
      case 2: {
        mips_cpu.registers[src2_dest] = mips_cpu.registers[src2_dest] & 0xFFFF;
        mips_cpu.registers[src2_dest] = (static_cast<uint32_t>(mips_cpu.memory[address]) << 24) | (static_cast<uint32_t>(mips_cpu.memory[address+1]) << 16) | mips_cpu.registers[src2_dest];
      }
      case 3: {
        mips_cpu.registers[src2_dest] = mips_cpu.registers[src2_dest] & 0xFFFFFF;
        mips_cpu.registers[src2_dest] = (static_cast<uint32_t>(mips_cpu.memory[address]) << 24) | mips_cpu.registers[src2_dest];
      }
    }
  }
  else if(address == INPUT_OFFSET){ //only when memory access is aligned
    int32_t input = input_char();

    if(input == -1){
      mips_cpu.registers[src2_dest] = -1;
    }
    else{
      mips_cpu.registers[src2_dest] = 0x000000FF & input;
    }
  }
  else{
    throw(static_cast<int32_t>(exception::MEMORY));
  }
}

void instruction_I::LWR(cpu& mips_cpu){
  int32_t offset;
  if((address_data >> 15) == 1){
    offset = 0xFFFF0000 | address_data;
  }
  else{
    offset = address_data;
  }
  uint32_t address = mips_cpu.registers[src1] + offset;
  if(((address >= DMEM_OFFSET) && (address < DMEM_END_OFFSET)) || ((address >=IMEM_OFFSET) && (address < IMEM_END_OFFSET))){
    switch(address%4){
      case 3: {
        mips_cpu.registers[src2_dest] = (static_cast<uint32_t>(mips_cpu.memory[address-3]) << 24) | (static_cast<uint32_t>(mips_cpu.memory[address-2]) << 16) | (static_cast<uint32_t>(mips_cpu.memory[address-1]) << 8) | (static_cast<uint32_t>(mips_cpu.memory[address]));
      }
      case 2: {
        mips_cpu.registers[src2_dest] = mips_cpu.registers[src2_dest] & 0xFF000000;
        mips_cpu.registers[src2_dest] = mips_cpu.registers[src2_dest] | (static_cast<uint32_t>(mips_cpu.memory[address-2]) << 16) | (static_cast<uint32_t>(mips_cpu.memory[address-1]) << 8) | (static_cast<uint32_t>(mips_cpu.memory[address]));
      }
      case 1: {
        mips_cpu.registers[src2_dest] = mips_cpu.registers[src2_dest] & 0xFFFF0000;
        mips_cpu.registers[src2_dest] = mips_cpu.registers[src2_dest] | (static_cast<uint32_t>(mips_cpu.memory[address-1]) << 8) | static_cast<uint32_t>(mips_cpu.memory[address]);
      }
      case 0: {
        mips_cpu.registers[src2_dest] = mips_cpu.registers[src2_dest] & 0xFFFFFF00;
        mips_cpu.registers[src2_dest] = mips_cpu.registers[src2_dest] | static_cast<uint32_t>(mips_cpu.memory[address]);
      }
    }
  }
  else if(address == INPUT_OFFSET+3){  //only when memory access is aligned
    int32_t input = input_char();

    if(input == -1){
      mips_cpu.registers[src2_dest] = -1;
    }
    else{
      mips_cpu.registers[src2_dest] = 0x000000FF & input;
    }
  }
  else{
    throw(static_cast<int32_t>(exception::MEMORY));
  }
}

void instruction_I::ORI(cpu& mips_cpu){
  mips_cpu.registers[src2_dest] = mips_cpu.registers[src1] | address_data;
}

void instruction_I::SB(cpu& mips_cpu){
  int32_t offset;
  if((address_data >> 15) == 1){
    offset = 0xFFFF0000 | address_data;
  }
  else{
    offset = address_data;
  }
  uint32_t address = mips_cpu.registers[src1] + offset;
  if((address >= DMEM_OFFSET) && (address < DMEM_END_OFFSET)){
    mips_cpu.memory[address] = mips_cpu.registers[src2_dest];
  }
  else if((address >= OUTPUT_OFFSET) && (address < OUTPUT_END_OFFSET)){
    if(address == OUTPUT_OFFSET+3){
      output_char(mips_cpu.registers[src2_dest] & 0xFF);
    }
    else{
      output_char(0);
    }
  }
  else{
    throw(static_cast<int32_t>(exception::MEMORY));
  }
}

void instruction_I::SH(cpu& mips_cpu){
  int32_t offset;
  if((address_data >> 15) == 1){
    offset = 0xFFFF0000 | address_data;
  }
  else{
    offset = address_data;
  }
  uint32_t address = mips_cpu.registers[src1] + offset;
  if((address >= DMEM_OFFSET) && (address < DMEM_END_OFFSET) && (address%2 == 0)){
    mips_cpu.memory[address] = mips_cpu.registers[src2_dest] >> 8;
    mips_cpu.memory[address+1] = mips_cpu.registers[src2_dest];
  }
  else if(address == OUTPUT_OFFSET+2){
    output_char(mips_cpu.registers[src2_dest] & 0xFF);
  }
  else if(address == OUTPUT_OFFSET){
    output_char(0);
  }
  else{
    throw(static_cast<int32_t>(exception::MEMORY));
  }
}

void instruction_I::SLTI(cpu& mips_cpu){
  int32_t immediate;
  if((address_data >> 15) == 1){
    immediate = 0xFFFF0000 | address_data;
  }
  else{
    immediate = address_data;
  }

  if(static_cast<int32_t>(mips_cpu.registers[src1]) < immediate){
    mips_cpu.registers[src2_dest] = 1;
  }
  else{
    mips_cpu.registers[src2_dest] = 0;
  }
}

void instruction_I::SLTIU(cpu& mips_cpu){
  uint32_t immediate;
  if((address_data >> 15) == 1){
    immediate = 0xFFFF0000 | address_data;
  }
  else{
    immediate = address_data;
  }

  if(mips_cpu.registers[src1] < immediate){
    mips_cpu.registers[src2_dest] = 1;
  }
  else{
    mips_cpu.registers[src2_dest] = 0;
  }
}

void instruction_I::SW(cpu& mips_cpu){
  int32_t offset;
  if((address_data >> 15) == 1){
    offset = 0xFFFF0000 | address_data;
  }
  else{
    offset = address_data;
  }
  uint32_t address = mips_cpu.registers[src1] + offset;
  if((address >= DMEM_OFFSET) && (address < DMEM_END_OFFSET) && (address%4 == 0)){
    mips_cpu.memory[address] = mips_cpu.registers[src2_dest] >> 24;
    mips_cpu.memory[address+1] = mips_cpu.registers[src2_dest] >> 16;
    mips_cpu.memory[address+2] = mips_cpu.registers[src2_dest] >> 8;
    mips_cpu.memory[address+3] = mips_cpu.registers[src2_dest];
  }
  else if(address == OUTPUT_OFFSET){
    output_char(mips_cpu.registers[src2_dest] & 0xFF);
  }
  else{
    throw(static_cast<int32_t>(exception::MEMORY));
  }
}

void instruction_I::XORI(cpu& mips_cpu){
  mips_cpu.registers[src2_dest] = mips_cpu.registers[src1] ^ address_data;
}
