#ifndef INSTRUCTION_J_HPP
#define INSTRUCTION_J_HPP

#include <bitset>

class instruction_J{
public:
  void set_bits(const uint32_t& input_bits);
  void execute(std::vector<uint8_t>& memory, std::vector<uint32_t>& registers, uint32_t& pc);
  void J(uint32_t& pc);
  void JAL(std::vector<uint32_t>& registers, uint32_t& pc);

private:
  std::bitset<32> bits;
  std::bitset<6> opcode;
  std::bitset<26> address;
};

#endif
