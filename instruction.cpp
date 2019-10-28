#include "instruction.hpp"

void instruction::set_bits(const uint32_t& input_bits){
  bits = input_bits;
  determine_type();
}

uint32_t instruction::get_bits() const{
  return bits;
}

char instruction::get_type() const{
  return type;
}

void instruction::determine_type(){ //put proper conditions!!!
  if(1){
    type = 'R';
  }
  else if(0){
    type = 'I';
  }
  else{
    type = 'J';
  }
}
