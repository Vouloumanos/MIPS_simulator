#include <iostream>
#include <fstream>
#include <vector>
#include <bitset>

int main(int argc, char *argv[]){

  std::string binName = argv[1];
  std::cerr << "binName: " << binName << std::endl;
  std::ifstream binStream(binName, std::ios::binary);

  binStream.seekg(0, std::ios::end);
  int binSize = binStream.tellg();
  std::cout << binSize << std::endl;
  binStream.seekg(0, std::ios::beg);
  std::cerr << "Binary file size: " << binSize << std::endl;

  char c;
  std::vector<uint8_t> mem;
  while(binStream >> c){
    mem.push_back(c);
  }
  for(int i=0; i<mem.size(); i++){
    std::cout << std::bitset<8>(mem[i]) << " ";
  }
  std::cout << std::endl;

  // std::vector<uint8_t> buffer;
  // buffer.reserve(binSize);
  // buffer.insert(buffer.begin(), std::istream_iterator<uint8_t> (binStream), std::istream_iterator<uint8_t> ());
  // std::cerr << "Instruction memory loaded" << std::endl;
  // std::cerr << "Buffer size: " << buffer.size() << std::endl;
  // for(int i = 0; i < buffer.size(); i++){
  //   std::cerr << buffer[i] << " ";
  // }
  // std::cerr << std::endl;

  return 0;
}
