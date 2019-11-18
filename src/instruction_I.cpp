#include <iostream>
#include <vector>

#include "instruction_I.hpp"
#include "init.hpp"

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

void instruction_I::execute(std::vector<uint32_t>& registers, uint32_t& pc, uint32_t& next_pc, std::vector<uint8_t>& memory){
  switch(opcode){
    case 0b001000: ADDI(registers); next_pc += 4; return;
    case 0b001001: ADDIU(registers); next_pc += 4;  return;
    case 0b001100: ANDI(registers); next_pc += 4; return;
    case 0b000100: BEQ(registers, next_pc); return;
    case 0b000001: switch(src2_dest){
      case 0b00001: BGEZ(registers, next_pc); return;
      case 0b10001: BGEZAL(registers, pc, next_pc); return;
      case 0b00000: BLTZ(registers, next_pc); return;
      case 0b10000: BLTZAL(registers, pc, next_pc); return;
    }
    case 0b000111: BGTZ(registers, next_pc); return;
    case 0b000110: BLEZ(registers, next_pc); return;
    case 0b000101: BNE(registers, next_pc); return;
    case 0b100000: LB(registers, memory); next_pc += 4; return;
    case 0b100100: LBU(registers, memory); next_pc += 4; return;
    case 0b100001: LH(registers, memory); next_pc += 4; return;
    case 0b100101: LHU(registers, memory); next_pc += 4; return;
    case 0b001111: LUI(registers); next_pc += 4; return;
    case 0b100011: LW(registers, memory); next_pc += 4; return;
    case 0b100010: LWL(registers, memory); next_pc += 4; return;
    case 0b100110: LWR(registers, memory); next_pc += 4; return;
    case 0b001101: ORI(registers); next_pc += 4; return;
    case 0b101000: SB(registers, memory); next_pc += 4; return;
    case 0b101001: SH(registers, memory); next_pc += 4; return;
    case 0b001010: SLTI(registers); next_pc += 4; return;
    case 0b001011: SLTIU(registers); next_pc += 4; return;
    case 0b101011: SW(registers, memory); next_pc += 4; return;
    case 0b001110: XORI(registers); next_pc += 4; return;
    default: throw(static_cast<int32_t>(exception::INSTRUCTION));
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
    throw(static_cast<int32_t>(exception::ARITHMETIC));
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

void instruction_I::BEQ(std::vector<uint32_t>& registers, uint32_t& next_pc){
  if(registers[src1] == registers[src2_dest]){
    int32_t offset;
    if((address_data >> 15) == 1){
      offset = 0xFFFC0000 | (address_data*4);
    }
    else{
      offset = address_data*4;
    }
    next_pc += offset;
  }
  else{
    next_pc += 4;
  }
}

void instruction_I::BGEZ(std::vector<uint32_t>& registers, uint32_t& next_pc){
  if(static_cast<int32_t>(registers[src1]) >= 0){
    int32_t offset;
    if((address_data >> 15) == 1){
      offset = 0xFFFC0000 | (address_data*4);
    }
    else{
      offset = address_data*4;
    }
    next_pc += offset;
  }
  else{
    next_pc += 4;
  }
}

void instruction_I::BGEZAL(std::vector<uint32_t>& registers, uint32_t& pc, uint32_t& next_pc){
  registers[31] = pc + 8;
  if(static_cast<int32_t>(registers[src1]) >= 0){
    int32_t offset;
    if((address_data >> 15) == 1){
      offset = 0xFFFC0000 | (address_data*4);
    }
    else{
      offset = address_data*4;
    }

    next_pc += offset;
  }
  else{
    next_pc += 4;
  }
}

void instruction_I::BGTZ(std::vector<uint32_t>& registers, uint32_t& next_pc){
  if(static_cast<int32_t>(registers[src1]) > 0){
    int32_t offset;
    if((address_data >> 15) == 1){
      offset = 0xFFFC0000 | (address_data*4);
    }
    else{
      offset = address_data*4;
    }
    next_pc += offset;
  }
  else{
    next_pc += 4;
  }
}

void instruction_I::BLEZ(std::vector<uint32_t>& registers, uint32_t& next_pc){
  if(static_cast<int32_t>(registers[src1]) <= 0){
    int32_t offset;
    if((address_data >> 15) == 1){
      offset = 0xFFFC0000 | (address_data*4);
    }
    else{
      offset = address_data*4;
    }
    next_pc += offset;
  }
  else{
    next_pc += 4;
  }
}

void instruction_I::BLTZ(std::vector<uint32_t>& registers, uint32_t& next_pc){
  if(static_cast<int32_t>(registers[src1]) < 0){
    int32_t offset;
    if((address_data >> 15) == 1){
      offset = 0xFFFC0000 | (address_data*4);
    }
    else{
      offset = address_data*4;
    }
    next_pc += offset;
  }
  else{
    next_pc += 4;
  }
}

void instruction_I::BLTZAL(std::vector<uint32_t>& registers, uint32_t& pc, uint32_t& next_pc){
  registers[31] = pc + 8;
  if(static_cast<int32_t>(registers[src1]) <= 0){
    int32_t offset;
    if((address_data >> 15) == 1){
      offset = 0xFFFC0000 | (address_data*4);
    }
    else{
      offset = address_data*4;
    }
    next_pc += offset;
  }
  else{
    next_pc += 4;
  }
}

void instruction_I::BNE(std::vector<uint32_t>& registers, uint32_t& next_pc){
  if(registers[src1] != registers[src2_dest]){
    int32_t offset;
    if((address_data >> 15) == 1){
      offset = 0xFFFC0000 | (address_data*4);
    }
    else{
      offset = address_data*4;
    }
    next_pc += offset;
  }
  else{
    next_pc += 4;
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
      registers[src2_dest] = 0xFFFFFF00 | static_cast<uint32_t>(memory[address]);
    }
    else{
      registers[src2_dest] = static_cast<uint32_t>(memory[address]);
    }
  }
  else if(address == INPUT_OFFSET+3){//verify
    char c = input_char();

    if(c == -1){
      registers[src2_dest] = -1;
    }
    else{
      registers[src2_dest] = 0x000000FF & c;
    }
  }
  else{
    throw(static_cast<int32_t>(exception::MEMORY));
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
    registers[src2_dest] = static_cast<uint32_t>(memory[address]);
  }
  else if(address == INPUT_OFFSET+3){//verify
    char c = input_char();

    if(c == -1){
      registers[src2_dest] = -1;
    }
    else{
      registers[src2_dest] = 0x000000FF & c;
    }
  }
  else{
    throw(static_cast<int32_t>(exception::MEMORY));
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
      registers[src2_dest] = 0xFFFF0000 | (static_cast<uint32_t>(memory[address]) << 8) | (static_cast<uint32_t>(memory[address+1]));
    }
    else{
      registers[src2_dest] = (static_cast<uint32_t>(memory[address]) << 8) | (static_cast<uint32_t>(memory[address+1]));
    }
  }
  else if(address == INPUT_OFFSET+2){
    char c = input_char();

    if(c == -1){
      registers[src2_dest] = -1;
    }
    else{
      registers[src2_dest] = 0x000000FF & c;
    }
  }
  else{
    throw(static_cast<int32_t>(exception::MEMORY));
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
    registers[src2_dest] = (static_cast<uint32_t>(memory[address]) << 8) | static_cast<uint32_t>(memory[address+1]);
  }
  else if(address == INPUT_OFFSET+2){//verify
    char c = input_char();

    if(c == -1){
      registers[src2_dest] = -1;
    }
    else{
      registers[src2_dest] = 0x000000FF & c;
    }
  }
  else{
    throw(static_cast<int32_t>(exception::MEMORY));
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
    registers[src2_dest] = (static_cast<uint32_t>(memory[address]) << 24) | (static_cast<uint32_t>(memory[address+1]) << 16) | (static_cast<uint32_t>(memory[address+2]) << 8) << (static_cast<uint32_t>(memory[address+3]));
  }
  else if(address == INPUT_OFFSET){
    char c = input_char();

    if(c == -1){
      registers[src2_dest] = -1;
    }
    else{
      registers[src2_dest] = 0x000000FF & c;
    }
  }
  else{
    throw(static_cast<int32_t>(exception::MEMORY));
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
        registers[src2_dest] = (static_cast<uint32_t>(memory[address]) << 24) | (static_cast<uint32_t>(memory[address+1]) << 16) | (static_cast<uint32_t>(memory[address+2]) << 8) | (static_cast<uint32_t>(memory[address+3]));
      }
      case 1: {
        registers[src2_dest] = registers[src2_dest] & 0xFF;
        registers[src2_dest] = (static_cast<uint32_t>(memory[address]) << 24) | (static_cast<uint32_t>(memory[address+1]) << 16) | (static_cast<uint32_t>(memory[address+2]) << 8) | registers[src2_dest];
      }
      case 2: {
        registers[src2_dest] = registers[src2_dest] & 0xFFFF;
        registers[src2_dest] = (static_cast<uint32_t>(memory[address]) << 24) | (static_cast<uint32_t>(memory[address+1]) << 16) | registers[src2_dest];
      }
      case 3: {
        registers[src2_dest] = registers[src2_dest] & 0xFFFFFF;
        registers[src2_dest] = (static_cast<uint32_t>(memory[address]) << 24) | registers[src2_dest];
      }
    }
  }
  else if(address == INPUT_OFFSET){
    //io
  }
  else{
    throw(static_cast<int32_t>(exception::MEMORY));
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
        registers[src2_dest] = (static_cast<uint32_t>(memory[address-3]) << 24) | (static_cast<uint32_t>(memory[address-2]) << 16) | (static_cast<uint32_t>(memory[address-1]) << 8) | (static_cast<uint32_t>(memory[address]));
      }
      case 2: {
        registers[src2_dest] = registers[src2_dest] & 0xFF000000;
        registers[src2_dest] = registers[src2_dest] | (static_cast<uint32_t>(memory[address-2]) << 16) | (static_cast<uint32_t>(memory[address-1]) << 8) | (static_cast<uint32_t>(memory[address]));
      }
      case 1: {
        registers[src2_dest] = registers[src2_dest] & 0xFFFF0000;
        registers[src2_dest] = registers[src2_dest] | (static_cast<uint32_t>(memory[address-1]) << 8) | static_cast<uint32_t>(memory[address]);
      }
      case 0: {
        registers[src2_dest] = registers[src2_dest] & 0xFFFFFF00;
        registers[src2_dest] = registers[src2_dest] | static_cast<uint32_t>(memory[address]);
      }
    }
  }
  else if(address == INPUT_OFFSET){
    //io
  }
  else{
    throw(static_cast<int32_t>(exception::MEMORY));
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
    offset = address_data;
  }
  uint32_t address = registers[src1] + offset;
  if((address >= DMEM_OFFSET) && (address < DMEM_END_OFFSET)){
    memory[address] = registers[src2_dest];
  }
  else if(address == OUTPUT_OFFSET+3){ //VERIFY
    output_char(static_cast<char>(registers[src2_dest] & 0xFF));
  }
  else{
    throw(static_cast<int32_t>(exception::MEMORY));
  }
}

void instruction_I::SH(std::vector<uint32_t>& registers, std::vector<uint8_t>& memory){
  int32_t offset;
  if((address_data >> 15) == 1){
    offset = 0xFFFF0000 | address_data;
  }
  else{
    offset = address_data;
  }
  uint32_t address = registers[src1] + offset;
  if((address >= DMEM_OFFSET) && (address < DMEM_END_OFFSET) && (address%2 == 0)){
    memory[address] = registers[src2_dest] >> 8;
    memory[address+1] = registers[src2_dest];
  }
  else if(address == OUTPUT_OFFSET+2){//VERIFY
    output_char(static_cast<char>(registers[src2_dest] & 0xFF));
  }
  else{
    throw(static_cast<int32_t>(exception::MEMORY));
  }
}

void instruction_I::SLTI(std::vector<uint32_t>& registers){
  int32_t immediate;
  if((address_data >> 15) == 1){
    immediate = 0xFFFF0000 | address_data;
  }
  else{
    immediate = address_data;
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
    immediate = address_data;
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
    offset = address_data;
  }
  uint32_t address = registers[src1] + offset;
  if((address >= DMEM_OFFSET) && (address < DMEM_END_OFFSET) && (address%4 == 0)){
    memory[address] = registers[src2_dest] >> 24;
    memory[address+1] = registers[src2_dest] >> 16;
    memory[address+2] = registers[src2_dest] >> 8;
    memory[address+3] = registers[src2_dest];
  }
  else if(address == OUTPUT_OFFSET){
    output_char(static_cast<char>(registers[src2_dest] & 0xFF));

  }
  else{
    throw(static_cast<int32_t>(exception::MEMORY));
  }
}

void instruction_I::XORI(std::vector<uint32_t>& registers){
  registers[src2_dest] = registers[src1] ^ address_data;
}
