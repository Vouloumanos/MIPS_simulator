#ifndef INIT_HPP
#define INIT_HPP

#include <cstdint> //for ints and uints
#include <cstdlib>

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
#define OUTPUT_OFFSET 0x30000004

//error and exception handling
enum class error{
  ARITHMETIC = -10,
  MEMORY = -11,
  INSTRUCTION = -12,
};

enum class exception{
  INTERNAL = -20,
  IO = -21,
};

//function declarations
char get_type(const uint32_t& input_bits);

#endif
