#ifndef INSTRUCTION_I_HPP
#define INSTRUCTION_I_HPP

#include <bitset>

class instruction_I{
public:
  void set_bits(const uint32_t& input_bits);

private:
  bitset<32> bits;
  bitset<6> opcode;
  bitset<5> src1;
  bitset<5> src2_dest;
  bitset<16> address_data;
};

#endif
