#ifndef INSTRUCTION_J_HPP
#define INSTRUCTION_J_HPP

#include "init.hpp"

#include <vector>

class instruction_J{
public:
  void set_bits(const uint32_t& input_bits);
  void execute(cpu& mips_cpu);
  void J(cpu& mips_cpu);
  void JAL(cpu& mips_cpu);

private:
  uint32_t opcode;
  uint32_t address;
};

#endif
