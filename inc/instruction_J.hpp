#ifndef INSTRUCTION_J_HPP
#define INSTRUCTION_J_HPP

#include <vector>


class instruction_J{
public:
  void set_bits(const uint32_t& input_bits);
  void execute(std::vector<uint32_t>& registers, uint32_t& pc, uint32_t& next_pc, std::vector<uint8_t>& memory);
  void J(uint32_t& next_pc);
  void JAL(std::vector<uint32_t>& registers, uint32_t& pc, uint32_t& next_pc);

private:
  uint32_t opcode;
  uint32_t address;
};

#endif
