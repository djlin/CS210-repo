/**
 * Reference: https://en.cppreference.com/w/cpp/algorithm/qsort
 */
#include <iostream>
#include <algorithm>
#include <chrono>
#include <fstream>
using namespace std;

#define INPUT_SIZE 200000

int main() {
  int input[INPUT_SIZE], index=0;
  ifstream ifs("random_numbers.txt", ifstream::in);
  while(ifs.good()) {
    ifs >> input[index++];
  }
  ifs.close();

  auto start = std::chrono::steady_clock::now();

  qsort(input, INPUT_SIZE, sizeof(int), [](const void* a, const void* b) {
    int arg1 = *static_cast<const int*>(a);
    int arg2 = *static_cast<const int*>(b);
 
    if(arg1 < arg2) return -1;
    if(arg1 > arg2) return 1;
    return 0;
 
    //  return (arg1 > arg2) - (arg1 < arg2); // possible shortcut
    //  return arg1 - arg2; // erroneous shortcut (fails if INT_MIN is present)
  });

  auto end = std::chrono::steady_clock::now();
  std::chrono::duration<double> elapsed_seconds = end-start;
  std::cout << "elapsed time: " << elapsed_seconds.count() << "s\n";

  ofstream ofs("sorted_numbers.txt", ofstream::out);
  for(index=0; index < INPUT_SIZE; index++) {
    ofs << input[index] << endl;
  }
  ofs.close();

  return 0;
}
