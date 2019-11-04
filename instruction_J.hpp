#ifndef INSTRUCTION_J_HPP
#define INSTRUCTION_J_HPP

#include <vector>


class instruction_J{
public:
  void set_bits(const uint32_t& input_bits);
  void execute(std::vector<uint32_t>& registers, uint32_t& pc, std::vector<uint8_t>& memory);
  void J(uint32_t& pc);
  void JAL(std::vector<uint32_t>& registers, uint32_t& pc);

private:
  uint32_t bits;
  uint32_t opcode;
  uint32_t address;
};

#endif
