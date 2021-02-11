#include <iostream>
#include <utility>
#include <fstream>
using namespace std;

#define INPUT_SIZE 200000

void selection_sort(int s[], int n) {
  int i, j;
  int min;

  for(i=0; i<n; i++) {
    min = i;
    for(j=i+1; j<n; j++)
      if (s[j] < s[min]) min=j;
    swap(s[i], s[min]);
  }
}

int main() {
  int input[INPUT_SIZE], index=0;
  ifstream ifs("random_numbers.txt", ifstream::in);
  while(ifs.good()) {
    ifs >> input[index++];
  }
  ifs.close();

  selection_sort(input, INPUT_SIZE);

  ofstream ofs("sorted_numbers.txt", ofstream::out);
  for(index=0; index < INPUT_SIZE; index++) {
    ofs << input[index] << endl;
  }

  ofs.close();

  return 0;
}
