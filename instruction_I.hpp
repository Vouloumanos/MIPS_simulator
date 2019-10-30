#ifndef INSTRUCTION_I_HPP
#define INSTRUCTION_I_HPP

#include <bitset>

class instruction_I{
public:
  void set_bits(const uint32_t& input_bits);

private:
  std::bitset<32> bits;
  std::bitset<6> opcode;
  std::bitset<5> src1;
  std::bitset<5> src2_dest;
  std::bitset<16> address_data;
};

#endif
