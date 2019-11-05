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
  bits = input_bits;
  opcode = bits >> 26;
  src1 = 0b11111 & (bits >> 21);
  src2_dest = 0b11111 & (bits >> 16);
  address_data = 0xFFFF & bits;
}

void instruction_I::execute(std::vector<uint32_t>& registers, uint32_t& pc, std::vector<uint8_t>& memory){
  switch(opcode){
    case 0b001000:{
      ADDI(registers);
      pc += 4;
    }
    case 0b001001:{
      ADDIU(registers);
      pc += 4;
    }
    case 0b001100:{
      ANDI(registers);
      pc += 4;
    }
    case 0b000100: BEQ(registers, pc);
    case 0b000001: switch(src2_dest){
      case 0b00001: BGEZ(registers, pc);
      case 0b10001: BGEZAL(registers, pc);
      case 0b00000: BLTZ(registers, pc);
      case 0b10000: BGEZAL(registers, pc);
    }
    case 0b000111: BGTZ(registers, pc);
    case 0b000110: BLEZ(registers, pc);
    case 0b000101: BNE(registers, pc);
    case 0b100000:{
      LB(registers, memory);
      pc += 4;
    }
    case 0b100100:{
      LBU(registers, memory);
      pc += 4;
    }
    case 0b100001:{
      LH(registers, memory);
      pc += 4;
    }
    case 0b100101:{
      LHU(registers, memory);
      pc += 4;
    }
    case 0b001111:{
      LUI(registers);
      pc += 4;
    }
    case 0b100011:{
      LW(registers, memory);
      pc += 4;
    }
    case 0b100010:{
      LWL(registers, memory);
      pc += 4;
    }
    case 0b100110:{
      LWR(registers, memory);
      pc += 4;
    }
    case 0b001101:{
      ORI(registers);
      pc += 4;
    }
    case 0b101000:{
      SB(registers, memory);
      pc += 4;
    }
    case 0b101001:{
      SH(registers, memory);
      pc += 4;
    }
    case 0b001010:{
      SLTI(registers);
      pc += 4;
    }
    case 0b001011:{
      SLTIU(registers);
      pc += 4;
    }
    case 0b101011:{
      SW(registers, memory);
      pc += 4;
    }
    case 0b001110:{
      XORI(registers);
      pc += 4;
    }
  }
}

void instruction_I::ADDI(std::vector<uint32_t>& registers){
  uint32_t immediate;
  uint32_t msb1 = address_data >> 15;
  uint32_t msb2 = registers[src1] >> 31;
  if(msb1 == 1){
    immediate = 0xFFFF0000 | address_data;
  }
  else{
    immediate = address_data;
  }

  uint32_t temp = registers[src1] + immediate;
  uint32_t msb3 = temp >> 31;

  if((msb1 == 0 && msb2 == 0 && msb3 == 1) || (msb1 == 1 && msb2 == 1 && msb3 == 0)){
    //TRIGGER OVERFLOW
  }
  else{
    registers[src2_dest] = temp;
  }
}

void instruction_I::ADDIU(std::vector<uint32_t>& registers){
  uint32_t immediate;
  if((address_data >> 15) == 1){
    immediate = 0xFFFF0000 | address_data;
  }
  else{
    immediate = address_data;
  }
  registers[src2_dest] = registers[src1] + immediate;
}

void instruction_I::ANDI(std::vector<uint32_t>& registers){
  registers[src2_dest] = registers[src1] & address_data;
}

void instruction_I::BEQ(std::vector<uint32_t>& registers, uint32_t& pc){
  if(registers[src1] == registers[src2_dest]){
    int32_t offset;
    if((address_data >> 15) == 1){
      offset = 0xFFFC0000 | (address_data << 2);
    }
    else{
      offset = address_data << 2;
    }
    pc += 4 + offset;
  }
  else{
    pc += 4;
  }
}

void instruction_I::BGEZ(std::vector<uint32_t>& registers, uint32_t& pc){
  if(static_cast<int32_t>(registers[src1]) >= 0){
    int32_t offset;
    if((address_data >> 15) == 1){
      offset = 0xFFFC0000 | (address_data << 2);
    }
    else{
      offset = address_data << 2;
    }
    pc += 4 + offset;
  }
  else{
    pc += 4;
  }
}

//Question:: Look up Bucknell!
void instruction_I::BGEZAL(std::vector<uint32_t>& registers, uint32_t& pc){
  if(static_cast<int32_t>(registers[src1]) >= 0){
    int32_t offset;
    if((address_data >> 15) == 1){
      offset = 0xFFFC0000 | (address_data << 2);
    }
    else{
      offset = address_data << 2;
    }
    registers[31] = pc + 8;
    pc += 4 + offset;
  }
  else{
    pc += 4;
  }
}

void instruction_I::BGTZ(std::vector<uint32_t>& registers, uint32_t& pc){
  if(static_cast<int32_t>(registers[src1]) > 0){
    int32_t offset;
    if((address_data >> 15) == 1){
      offset = 0xFFFC0000 | (address_data << 2);
    }
    else{
      offset = address_data << 2;
    }
    pc += 4 + offset;
  }
  else{
    pc += 4;
  }
}

void instruction_I::BLEZ(std::vector<uint32_t>& registers, uint32_t& pc){
  if(static_cast<int32_t>(registers[src1]) <= 0){
    int32_t offset;
    if((address_data >> 15) == 1){
      offset = 0xFFFC0000 | (address_data << 2);
    }
    else{
      offset = address_data << 2;
    }
    pc += 4 + offset;
  }
  else{
    pc += 4;
  }
}

void instruction_I::BLTZ(std::vector<uint32_t>& registers, uint32_t& pc){
  if(static_cast<int32_t>(registers[src1]) < 0){
    int32_t offset;
    if((address_data >> 15) == 1){
      offset = 0xFFFC0000 | (address_data << 2);
    }
    else{
      offset = address_data << 2;
    }
    pc += 4 + offset;
  }
  else{
    pc += 4;
  }
}

void instruction_I::BLTZAL(std::vector<uint32_t>& registers, uint32_t& pc){
  if(static_cast<int32_t>(registers[src1]) <= 0){
    int32_t offset;
    if((address_data >> 15) == 1){
      offset = 0xFFFC0000 | (address_data << 2);
    }
    else{
      offset = address_data << 2;
    }
    registers[31] = pc + 8;
    pc += 4 + offset;
  }
  else{
    pc += 4;
  }
}

void instruction_I::BNE(std::vector<uint32_t>& registers, uint32_t& pc){
  if(registers[src1] != registers[src2_dest]){
    int32_t offset;
    if((address_data >> 15) == 1){
      offset = 0xFFFC0000 | (address_data << 2);
    }
    else{
      offset = address_data << 2;
    }
    pc += 4 + offset;
  }
  else{
    pc += 4;
  }
}

void instruction_I::LB(std::vector<uint32_t>& registers, const std::vector<uint8_t>& memory){
  int32_t offset;
  if((address_data >> 15) == 1){
    offset = 0xFFFF0000 | address_data;
  }
  else{
    offset = address_data;
  }
  uint32_t address = registers[src1] + offset;
  if((address >= DMEM_OFFSET) && (address < DMEM_END_OFFSET)){
    if((memory[address] >> 7) == 1){
      registers[src2_dest] = 0xFFFFFF00 | memory[address];
    }
    else{
      registers[src2_dest] = memory[address];
    }
  }
  else{
    //Memory exception
  }
}

void instruction_I::LBU(std::vector<uint32_t>& registers, const std::vector<uint8_t>& memory){
  int32_t offset;
  if((address_data >> 15) == 1){
    offset = 0xFFFF0000 | address_data;
  }
  else{
    offset = address_data;
  }
  uint32_t address = registers[src1] + offset;
  if((address >= DMEM_OFFSET) && (address < DMEM_END_OFFSET)){
    registers[src2_dest] = memory[address];
  }
  else{
    //Memory exception
  }
}

void instruction_I::LH(std::vector<uint32_t>& registers, const std::vector<uint8_t>& memory){
  int32_t offset;
  if((address_data >> 15) == 1){
    offset = 0xFFFF0000 | address_data;
  }
  else{
    offset = address_data;
  }
  uint32_t address = registers[src1] + offset;
  if((address >= DMEM_OFFSET) && (address < DMEM_END_OFFSET) && (address%2 == 0)){
    if((memory[address] >> 7) == 1){
      registers[src2_dest] = 0xFFFF0000 | (memory[address] << 8) | (memory[address+1]);
    }
    else{
      registers[src2_dest] = (memory[address] << 8) | (memory[address+1]);
    }
  }
  else{
    //Memory exception
  }
}

void instruction_I::LHU(std::vector<uint32_t>& registers, const std::vector<uint8_t>& memory){
  int32_t offset;
  if((address_data >> 15) == 1){
    offset = 0xFFFF0000 | address_data;
  }
  else{
    offset = address_data;
  }
  uint32_t address = registers[src1] + offset;
  if((address >= DMEM_OFFSET) && (address < DMEM_END_OFFSET) && (address%2 == 0)){
    registers[src2_dest] = (memory[address] << 8) | memory[address+1];
  }
  else{
    //Memory exception
  }
}

void instruction_I::LUI(std::vector<uint32_t>& registers){
  registers[src2_dest] = (address_data << 16);
}

void instruction_I::LW(std::vector<uint32_t>& registers, const std::vector<uint8_t>& memory){
  int32_t offset;
  if((address_data >> 15) == 1){
    offset = 0xFFFF0000 | address_data;
  }
  else{
    offset = address_data;
  }
  uint32_t address = registers[src1] + offset;
  if((address >= DMEM_OFFSET) && (address < DMEM_END_OFFSET) && (address%4 == 0)){
    registers[src2_dest] = (memory[address] << 24) | (memory[address+1] << 16) | (memory[address+2] << 8) << (memory[address+3]);
  }
  else{
    //Memory exception
  }
}

void instruction_I::LWL(std::vector<uint32_t>& registers, const std::vector<uint8_t>& memory){
  int32_t offset;
  if((address_data >> 15) == 1){
    offset = 0xFFFF0000 | address_data;
  }
  else{
    offset = address_data;
  }
  uint32_t address = registers[src1] + offset;
  if((address >= DMEM_OFFSET) && (address < DMEM_END_OFFSET)){
    switch(address%4){
      case 0: {
        registers[src2_dest] = (memory[address] << 24) | (memory[address+1] << 16) | (memory[address+2] << 8) | (memory[address+3]);
      }
      case 1: {
        registers[src2_dest] = registers[src2_dest] & 0xFF;
        registers[src2_dest] = (memory[address] << 24) | (memory[address+1] << 16) | (memory[address+2] << 8) | registers[src2_dest];
      }
      case 2: {
        registers[src2_dest] = registers[src2_dest] & 0xFFFF;
        registers[src2_dest] = (memory[address] << 24) | (memory[address+1] << 16) | registers[src2_dest];
      }
      case 3: {
        registers[src2_dest] = registers[src2_dest] & 0xFFFFFF;
        registers[src2_dest] = (memory[address] << 24) | registers[src2_dest];
      }
    }
  }
  else{
    //Memory exception
  }
}

void instruction_I::LWR(std::vector<uint32_t>& registers, const std::vector<uint8_t>& memory){
  int32_t offset;
  if((address_data >> 15) == 1){
    offset = 0xFFFF0000 | address_data;
  }
  else{
    offset = address_data;
  }
  uint32_t address = registers[src1] + offset;
  if((address >= DMEM_OFFSET) && (address < DMEM_END_OFFSET)){
    switch(address%4){
      case 3: {
        registers[src2_dest] = (memory[address-3] << 24) | (memory[address-2] << 16) | (memory[address-1] << 8) | (memory[address]);
      }
      case 2: {
        registers[src2_dest] = registers[src2_dest] & 0xFF000000;
        registers[src2_dest] = registers[src2_dest] | (memory[address-2] << 16) | (memory[address-1] << 8) | (memory[address]);
      }
      case 1: {
        registers[src2_dest] = registers[src2_dest] & 0xFFFF0000;
        registers[src2_dest] = registers[src2_dest] | (memory[address-1] << 24) | (memory[address+1] << 16);
      }
      case 0: {
        registers[src2_dest] = registers[src2_dest] & 0xFFFFFF00;
        registers[src2_dest] = (memory[address] << 24) | registers[src2_dest];
      }
    }
  }
  else{
    //Memory exception
  }
}

void instruction_I::ORI(std::vector<uint32_t>& registers){
  registers[src2_dest] = registers[src1] | address_data;
}

void instruction_I::SB(std::vector<uint32_t>& registers, std::vector<uint8_t>& memory){
  int32_t offset;
  if((address_data >> 15) == 1){
    offset = 0xFFFF0000 | address_data;
  }
  else{
    offset = 0x00000000 | address_data;
  }
  uint32_t address = registers[src1] + offset;
  if((address >= DMEM_OFFSET) && (address < DMEM_END_OFFSET)){
    memory[address] = registers[src2_dest];
  }
  else{
    //Memory exception
  }
}

//Should the address be even??
void instruction_I::SH(std::vector<uint32_t>& registers, std::vector<uint8_t>& memory){
  int32_t offset;
  if((address_data >> 15) == 1){
    offset = 0xFFFF0000 | address_data;
  }
  else{
    offset = 0x00000000 | address_data;
  }
  uint32_t address = registers[src1] + offset;
  if((address >= DMEM_OFFSET) && (address < DMEM_END_OFFSET) && (address%2 == 0)){
    memory[address] = registers[src2_dest] >> 8;
    memory[address+1] = registers[src2_dest];
  }
  else{
    //Memory exception
  }
}

void instruction_I::SLTI(std::vector<uint32_t>& registers){
  int32_t immediate;
  if((address_data >> 15) == 1){
    immediate = 0xFFFF0000 | address_data;
  }
  else{
    immediate = 0x00000000 | address_data;
  }

  if(static_cast<int32_t>(registers[src1]) < immediate){
    registers[src2_dest] = 1;
  }
  else{
    registers[src2_dest] = 0;
  }
}

void instruction_I::SLTIU(std::vector<uint32_t>& registers){
  uint32_t immediate;
  if((address_data >> 15) == 1){
    immediate = 0xFFFF0000 | address_data;
  }
  else{
    immediate = 0x00000000 | address_data;
  }

  if(registers[src1] < immediate){
    registers[src2_dest] = 1;
  }
  else{
    registers[src2_dest] = 0;
  }
}

void instruction_I::SW(std::vector<uint32_t>& registers, std::vector<uint8_t>& memory){
  int32_t offset;
  if((address_data >> 15) == 1){
    offset = 0xFFFF0000 | address_data;
  }
  else{
    offset = 0x00000000 | address_data;
  }
  uint32_t address = registers[src1] + offset;
  if((address >= DMEM_OFFSET) && (address < DMEM_END_OFFSET) && (address%4 == 0)){
    memory[address] = registers[src2_dest] >> 24;
    memory[address+1] = registers[src2_dest] >> 16;
    memory[address+2] = registers[src2_dest] >> 8;
    memory[address+3] = registers[src2_dest];
  }
  else{
    //Memory exception
  }
}

void instruction_I::XORI(std::vector<uint32_t>& registers){
  registers[src2_dest] = registers[src1] ^ address_data;
}
