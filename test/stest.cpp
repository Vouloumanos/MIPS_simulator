#include <iostream>
#include <cstdint>

using namespace std;

int main(){
uint32_t r3 = -3;
uint32_t r2 = -5;
int64_t new_r3 = static_cast<int64_t>(r3) | 0xFFFFFFFF00000000;
int64_t new_r2 = static_cast<int64_t>(r2) | 0xFFFFFFFF00000000;

cout << "r3: " << hex << r3 << " new r3: " << hex << new_r3 << endl;
cout << "r2: " << hex << r2 << " new r2: " << hex << new_r2 << endl;

int64_t result = static_cast<int64_t>(r3) * static_cast<int64_t>(r2);
int64_t result2 = new_r3 * new_r2;

cout << "result: " << hex << result << endl;
cout << "result: " << result << endl;
cout << "result2: " << hex << result2 << endl;
cout << "result2: " << result2 << endl;

uint32_t lo = static_cast<uint32_t>(result);
uint32_t hi = static_cast<uint32_t>(result >> 32);

cout << "lo: " << hex << lo << endl;
cout << "hi: " << hex << hi << endl;

return 0;

}
