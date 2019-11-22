#ifndef INSTRUCTION_R_HPP
#define INSTRUCTION_R_HPP

#include "init.hpp"

#include <vector>

struct cpu;

class instruction_R{
public:
  void set_bits(const uint32_t& input_bits);
  void execute(cpu& mips_cpu);
  void ADD(cpu& mips_cpu);
  void ADDU(cpu& mips_cpus);
  void AND(cpu& mips_cpu);
  void DIV(cpu& mips_cpu);
  void DIVU(cpu& mips_cpu);
  void JALR(cpu& mips_cpu);
  void JR(cpu& mips_cpu);
  void MFHI(cpu& mips_cpu);
  void MFLO(cpu& mips_cpu);
  void MTHI(cpu& mips_cpu);
  void MTLO(cpu& mips_cpu);
  void MULT(cpu& mips_cpu);
  void MULTU(cpu& mips_cpu);
  void OR(cpu& mips_cpu);
  void SLL(cpu& mips_cpu);
  void SLLV(cpu& mips_cpu);
  void SLT(cpu& mips_cpu);
  void SLTU(cpu& mips_cpu);
  void SRA(cpu& mips_cpu);
  void SRAV(cpu& mips_cpu);
  void SRL(cpu& mips_cpu);
  void SRLV(cpu& mips_cpu);
  void SUB(cpu& mips_cpu);
  void SUBU(cpu& mips_cpu);
  void XOR(cpu& mips_cpu);

private:
  uint32_t src1;
  uint32_t src2;
  uint32_t dest;
  uint32_t shift_amount;
  uint32_t fn_code;
};

#endif
