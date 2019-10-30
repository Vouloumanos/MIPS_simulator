#ifndef INSTRUCTION_R_HPP
#define INSTRUCTION_R_HPP

#include <bitset>

class instruction_R{
public:
  void set_bits(const uint32_t& input_bits);
  friend void execute(std::vector<uint32_t>& registers, uint32_t& pc);

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
