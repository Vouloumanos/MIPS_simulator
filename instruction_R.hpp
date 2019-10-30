#ifndef INSTRUCTION_R_HPP
#define INSTRUCTION_R_HPP

#include <bitset>

class instruction_R{
public:
  void set_bits(const uint32_t& input_bits);
  friend void execute(std::vector<uint32_t>& registers, uint32_t& pc);

private:
  bitset<32> bits;
  bitset<6> opcode;
  bitset<5> src1;
  bitset<5> src2;
  bitset<5> dest;
  bitset<5> shift_amount;
  bitset<6> fn_code;
};

#endif
