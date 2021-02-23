#include <iostream>
#include <chrono>
#include <utility>
#include <fstream>
using namespace std;

#define INPUT_SIZE 200000

void merge(int s[],  int U[],  int V[], int h, int m) {
  int i=0, j=0, k=0;

  while( i<h && j < m) {
    if(U[i] < V[j]) {
      s[k] = U[i];
      i++;
    }
    else {
      s[k] = V[j];
      j++;
    }
    k++;
  }
  if(i==h) {
    // copy V[j...m-1] to s[k...n-1]
    for(int idx=j; idx < m; idx++, k++) {
      s[k] = V[idx];
    }    
  }
  else {
    // copy U[i...h-1] to s[k...n-1]
    for(int idx=i; idx < h; idx++, k++) {
      s[k] = U[idx];
    }
  }
}


void merge_sort(int s[], int n) {
  if(n>1) {
    const int h = n/2, m = n-h;
    int U[h], V[m];

    // copy s[0..h-1] to U[]
    for(int idx=0; idx < h; idx++) {
      U[idx] = s[idx];
    }

    // copy s[h..n-1] to V[]
    for(int idx=0; idx < m; idx++) {
      V[idx] = s[idx+h];
    }

    merge_sort(U, h);
    merge_sort(V, m);
    merge(s, U, V, h, m);
  }
}

int main() {
  int input[INPUT_SIZE], index=0;
  ifstream ifs("random_numbers.txt", ifstream::in);
  while(ifs.good()) {
    ifs >> input[index++];
  }
  ifs.close();

  auto start = std::chrono::steady_clock::now();

  merge_sort(input, INPUT_SIZE);
  
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
