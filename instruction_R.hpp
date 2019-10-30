#ifndef INSTRUCTION_R_HPP
#define INSTRUCTION_R_HPP

#include <bitset>
#include <vector>

class instruction_R{
public:
  void set_bits(const uint32_t& input_bits);
  void execute(std::vector<uint32_t>& registers, uint32_t& pc);
  void ADD(std::vector<uint32_t>& registers);
  void ADDU(std::vector<uint32_t>& registers);
  void AND(std::vector<uint32_t>& registers);
  void DIV(std::vector<uint32_t>& registers);
  void DIVU(std::vector<uint32_t>& registers);
  void JALR(std::vector<uint32_t>& registers, uint32_t& pc);
  void JR(std::vector<uint32_t>& registers, uint32_t& pc);
  void MFHI(std::vector<uint32_t>& registers);
  void MFLO(std::vector<uint32_t>& registers);
  void MTHI(std::vector<uint32_t>& registers);
  void MTLO(std::vector<uint32_t>& registers);
  void MULT(std::vector<uint32_t>& registers);
  void MULTU(std::vector<uint32_t>& registers);
  void OR(std::vector<uint32_t>& registers);
  void SLL(std::vector<uint32_t>& registers);
  void SLLV(std::vector<uint32_t>& registers);
  void SLT(std::vector<uint32_t>& registers);
  void SLTU(std::vector<uint32_t>& registers);
  void SRA(std::vector<uint32_t>& registers);
  void SRAV(std::vector<uint32_t>& registers);
  void SRL(std::vector<uint32_t>& registers);
  void SRLV(std::vector<uint32_t>& registers);
  void SUB(std::vector<uint32_t>& registers);
  void SUBU(std::vector<uint32_t>& registers);
  void XOR(std::vector<uint32_t>& registers);


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
