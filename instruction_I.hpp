#ifndef INSTRUCTION_I_HPP
#define INSTRUCTION_I_HPP

#include <vector>

class instruction_I{
public:
  void set_bits(const uint32_t& input_bits);
  void execute(std::vector<uint32_t>& registers, uint32_t& pc, std::vector<uint8_t>& memory);
  void ADDI(std::vector<uint32_t>& registers);
  void ADDIU(std::vector<uint32_t>& registers);
  void ANDI(std::vector<uint32_t>& registers);
  void BEQ(std::vector<uint32_t>& registers, uint32_t& pc);
  void BGEZ(std::vector<uint32_t>& registers, uint32_t& pc);
  void BGEZAL(std::vector<uint32_t>& registers, uint32_t& pc);
  void BGTZ(std::vector<uint32_t>& registers, uint32_t& pc);
  void BLEZ(std::vector<uint32_t>& registers, uint32_t& pc);
  void BLTZ(std::vector<uint32_t>& registers, uint32_t& pc);
  void BLTZAL(std::vector<uint32_t>& registers, uint32_t& pc);
  void BNE(std::vector<uint32_t>& registers, uint32_t& pc);
  void LB(std::vector<uint32_t>& registers, const std::vector<uint8_t>& memory);
  void LBU(std::vector<uint32_t>& registers, const std::vector<uint8_t>& memory);
  void LH(std::vector<uint32_t>& registers, const std::vector<uint8_t>& memory);
  void LHU(std::vector<uint32_t>& registers, const std::vector<uint8_t>& memory);
  void LUI(std::vector<uint32_t>& registers);
  void LW(std::vector<uint32_t>& registers, const std::vector<uint8_t>& memory);
  void LWL(std::vector<uint32_t>& registers, const std::vector<uint8_t>& memory);
  void LWR(std::vector<uint32_t>& registers, const std::vector<uint8_t>& memory);
  void ORI(std::vector<uint32_t>& registers);
  void SB(std::vector<uint32_t>& registers, std::vector<uint8_t>& memory);
  void SH(std::vector<uint32_t>& registers, std::vector<uint8_t>& memory);
  void SLTI(std::vector<uint32_t>& registers);
  void SLTIU(std::vector<uint32_t>& registers);
  void SW(std::vector<uint32_t>& registers, std::vector<uint8_t>& memory);
  void XORI(std::vector<uint32_t>& registers);

private:
  uint32_t bits;
  uint32_t opcode;
  uint32_t src1;
  uint32_t src2_dest;
  uint32_t address_data;
};

#endif
