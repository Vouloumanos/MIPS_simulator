#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iterator>




int main(int argc, char *argv[]){

  //get binary name
  std::string binName = argv[1];
  //debug - display binary name
  std::cerr << "binName: " << binName << std::endl;
  //initialise binStream
  std::ifstream binStream(binName, std::ios::binary);

  std::vector<uint32_t> buffer(std::istream_iterator<uint32_t>(binStream), {});





  return 0;
}
