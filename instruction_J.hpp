#ifndef INSTRUCTION_J_HPP
#define INSTRUCTION_J_HPP

#include <bitset>
#include <vector>


class instruction_J{
public:
  void set_bits(const uint32_t& input_bits);
  void execute(std::vector<uint32_t>& registers, uint32_t& pc, std::vector<uint8_t>& memory);
  void J(uint32_t& pc);
  void JAL(std::vector<uint32_t>& registers, uint32_t& pc);

private:
  std::bitset<32> bits;
  std::bitset<6> opcode;
  std::bitset<26> address;
};

#endif
