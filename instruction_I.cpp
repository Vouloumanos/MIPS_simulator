#include <iostream>
#include <bitset>
#include "instruction_I.hpp"

void instruction_I::set_bits(const uint32_t& input_bits){
  bits = input_bits;
  opcode = ((bits >> 26).to_ulong());
  src1 = std::bitset<5> ((bits >> 21).to_ulong());
  src2_dest = std::bitset<5>((bits >> 16).to_ulong());
  address_data = std::bitset<16>((bits >> 0).to_ulong());
}

void instruction_I::execute(std::vector<uint32_t>& registers, uint32_t& pc, std::vector<uint8_t>& memory){
  switch((int)opcode.to_ulong()){
    case 0b001000: ADDI(registers);
    case 0b001001: ADDIU(registers);
    case 0b001100: ANDI(registers);
    case 0b000100: BEQ(registers, pc);
    case 0b000001: switch((int)src2_dest.to_ulong()){
      case 0b00001: BGEZ(registers, pc);
      case 0b10001: BGEZAL(registers, pc);
      case 0b00000: BLTZ(registers, pc);
      case 0b10000: BGEZAL(registers, pc);
    }
    case 0b000111: BGTZ(registers, pc);
    case 0b000110: BLEZ(registers, pc);
    case 0b000101: BNE(registers, pc);
    case 0b100000: LB(registers, memory);
    case 0b100100: LBU(registers, memory);
    case 0b100001: LH(registers, memory);
    case 0b100101: LHU(registers, memory);
    case 0b001111: LUI(registers);
    case 0b100011: LW(registers, memory);
    case 0b100010: LWL(registers, memory);
    case 0b100110: LWR(registers, memory);
    case 0b001101: ORI(registers);
    case 0b101000: SB(registers, memory);
    case 0b101001: SH(registers, memory);
    case 0b001010: SLTI(registers);
    case 0b001011: SLTIU(registers);
    case 0b101011: SW(registers, memory);
    case 0b001110: XORI(registers);
  }
}

void set_bits(const uint32_t& input_bits){

}
void execute(std::vector<uint32_t>& registers, uint32_t& pc, std::vector<uint8_t>& memory){

}
void ADDI(std::vector<uint32_t>& registers){

}
void ADDIU(std::vector<uint32_t>& registers){

}
void ANDI(std::vector<uint32_t>& registers){

}
void BEQ(std::vector<uint32_t>& registers, uint32_t& pc){

}
void BGEZ(std::vector<uint32_t>& registers, uint32_t& pc){

}
void BGEZAL(std::vector<uint32_t>& registers, uint32_t& pc){

}
void BGTZ(std::vector<uint32_t>& registers, uint32_t& pc){

}
void BLEZ(std::vector<uint32_t>& registers, uint32_t& pc){

}
void BLTZ(std::vector<uint32_t>& registers, uint32_t& pc){

}
void BLTZAL(std::vector<uint32_t>& registers, uint32_t& pc){

}
void BNE(std::vector<uint32_t>& registers, uint32_t& pc){

}
void LB(std::vector<uint32_t>& registers, std::vector<uint8_t>& memory){

}
void LBU(std::vector<uint32_t>& registers, std::vector<uint8_t>& memory){

}
void LH(std::vector<uint32_t>& registers, std::vector<uint8_t>& memory){

}
void LHU(std::vector<uint32_t>& registers, std::vector<uint8_t>& memory){

}
void LUI(std::vector<uint32_t>& registers){

}
void LW(std::vector<uint32_t>& registers, std::vector<uint8_t>& memory){

}
void LWL(std::vector<uint32_t>& registers, std::vector<uint8_t>& memory){

}
void LWR(std::vector<uint32_t>& registers, std::vector<uint8_t>& memory){

}
void ORI(std::vector<uint32_t>& registers){

}
void SB(std::vector<uint32_t>& registers, std::vector<uint8_t>& memory){

}
void SH(std::vector<uint32_t>& registers, std::vector<uint8_t>& memory){

}
void SLTI(std::vector<uint32_t>& registers){

}
void SLTIU(std::vector<uint32_t>& registers){

}
void SW(std::vector<uint32_t>& registers, std::vector<uint8_t>& memory){

}
void XORI(std::vector<uint32_t>& registers){

}
