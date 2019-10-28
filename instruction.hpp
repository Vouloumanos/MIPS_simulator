#ifndef INSTRUCTION_HPP
#define INSTRUCTION_HPP

class instruction{
public:
  void set_bits(const uint32_t& input_bits);
  uint32_t get_bits() const;
  char get_type() const;
  void determine_type();


private:
  uint32_t bits;
  char type;
};

#endif
