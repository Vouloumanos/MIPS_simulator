#ifndef INIT_HPP
#define INIT_HPP

#include <cstdint> //for ints and uints
#include <cstdlib>
#include <iostream> //for cin and cout
#include <vector> //for memory and registers in cpu

//include all other headers
#include "instruction_R.hpp"
#include "instruction_I.hpp"
#include "instruction_J.hpp"

//define memory addresses and sizes
#define IMEM_LENGTH 0x1000000
#define DMEM_LENGTH 0x4000000
#define MEM_LENGTH 0x30000004

#define IMEM_OFFSET 0x10000000
#define IMEM_END_OFFSET 0x11000000

#define DMEM_OFFSET 0x20000000
#define DMEM_END_OFFSET 0x24000000

#define INPUT_OFFSET 0x30000000
#define INPUT_END_OFFSET 0x30000004

#define OUTPUT_OFFSET 0x30000004
#define OUTPUT_END_OFFSET 0x30000008


//structure for easier management of data related to the state of the processor
struct cpu{
  std::vector<uint8_t> memory;
  std::vector<uint32_t> registers;
  uint32_t hi;
  uint32_t lo;
  uint32_t pc;
  uint32_t next_pc;
};

//error and exception handling
enum class exception{
  ARITHMETIC = -10,
  MEMORY = -11,
  INSTRUCTION = -12,
};

enum class error{
  INTERNAL = -20,
  IO = -21,
};

//function declarations
void init_cpu(cpu& mips_cpu);
char get_type(const uint32_t& input_bits);
void output_char(uint32_t output);
int32_t input_char();

#endif
