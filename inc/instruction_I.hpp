#ifndef INSTRUCTION_I_HPP
#define INSTRUCTION_I_HPP

#include "init.hpp"

#include <vector>

class instruction_I{
public:
  void set_bits(const uint32_t& input_bits);
  void execute(cpu& mips_cpu);
  void ADDI(cpu& mips_cpu);
  void ADDIU(cpu& mips_cpu);
  void ANDI(cpu& mips_cpu);
  void BEQ(cpu& mips_cpu);
  void BGEZ(cpu& mips_cpu);
  void BGEZAL(cpu& mips_cpu);
  void BGTZ(cpu& mips_cpu);
  void BLEZ(cpu& mips_cpu);
  void BLTZ(cpu& mips_cpu);
  void BLTZAL(cpu& mips_cpu);
  void BNE(cpu& mips_cpu);
  void LB(cpu& mips_cpu);
  void LBU(cpu& mips_cpu);
  void LH(cpu& mips_cpu);
  void LHU(cpu& mips_cpu);
  void LUI(cpu& mips_cpu);
  void LW(cpu& mips_cpu);
  void LWL(cpu& mips_cpu);
  void LWR(cpu& mips_cpu);
  void ORI(cpu& mips_cpu);
  void SB(cpu& mips_cpu);
  void SH(cpu& mips_cpu);
  void SLTI(cpu& mips_cpu);
  void SLTIU(cpu& mips_cpu);
  void SW(cpu& mips_cpu);
  void XORI(cpu& mips_cpu);

private:
  uint32_t opcode;
  uint32_t src1;
  uint32_t src2_dest;
  uint32_t address_data;
};

#endif
