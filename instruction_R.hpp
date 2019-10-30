#ifndef INSTRUCTION_R_HPP
#define INSTRUCTION_R_HPP

#include <bitset>
#include <vector>

class instruction_R{
public:
  void set_bits(const uint32_t& input_bits);
  friend void execute(std::vector<uint32_t>& registers, uint32_t& pc);
  friend void ADD(std::vector<uint32_t>& registers, uint32_t& pc);
  friend void ADDU(std::vector<uint32_t>& registers, uint32_t& pc);
  friend void AND(std::vector<uint32_t>& registers, uint32_t& pc);
  friend void DIV(std::vector<uint32_t>& registers, uint32_t& pc);
  friend void DIVU(std::vector<uint32_t>& registers, uint32_t& pc);
  friend void JALR(std::vector<uint32_t>& registers, uint32_t& pc);
  friend void JR(std::vector<uint32_t>& registers, uint32_t& pc);
  friend void MFHI(std::vector<uint32_t>& registers, uint32_t& pc);
  friend void MFLO(std::vector<uint32_t>& registers, uint32_t& pc);
  friend void MTHI(std::vector<uint32_t>& registers, uint32_t& pc);
  friend void MTLO(std::vector<uint32_t>& registers, uint32_t& pc);
  friend void MULT(std::vector<uint32_t>& registers, uint32_t& pc);
  friend void MULTU(std::vector<uint32_t>& registers, uint32_t& pc);
  friend void OR(std::vector<uint32_t>& registers, uint32_t& pc);
  friend void SLL(std::vector<uint32_t>& registers, uint32_t& pc);
  friend void SLLV(std::vector<uint32_t>& registers, uint32_t& pc);
  friend void SLT(std::vector<uint32_t>& registers, uint32_t& pc);
  friend void SLTU(std::vector<uint32_t>& registers, uint32_t& pc);
  friend void SRA(std::vector<uint32_t>& registers, uint32_t& pc);
  friend void SRAV(std::vector<uint32_t>& registers, uint32_t& pc);
  friend void SRL(std::vector<uint32_t>& registers, uint32_t& pc);
  friend void SRLV(std::vector<uint32_t>& registers, uint32_t& pc);
  friend void SUB(std::vector<uint32_t>& registers, uint32_t& pc);
  friend void SUBU(std::vector<uint32_t>& registers, uint32_t& pc);
  friend void XOR(std::vector<uint32_t>& registers, uint32_t& pc);


private:
  std::bitset<32> bits;
  std::bitset<6> opcode;
  std::bitset<5> src1;
  std::bitset<5> src2;
  std::bitset<5> dest;
  std::bitset<5> shift_amount;
  std::bitset<6> fn_code;
};

#endif
