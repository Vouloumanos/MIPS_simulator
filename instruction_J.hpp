#ifndef INSTRUCTION_J_HPP
#define INSTRUCTION_J_HPP

#include <bitset>

class instruction_J{
public:
  void set_bits(const uint32_t& input_bits);

private:
  std::bitset<32> bits;
  std::bitset<6> opcode;
  std::bitset<26> address;
};

#endif
