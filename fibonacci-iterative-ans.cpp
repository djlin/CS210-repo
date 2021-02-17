/*
 * Fibonacci through iteration
 * 
 */

#include <iostream>
#include <chrono> // C++11

int fibonacci(int n) {
  int i;
  int results[n];

  results[0] = 0;

  if (n > 0) {
    results[1] = 1;
    for(i=2;i<=n;i++)
      results[i] = results[i-1] + results[i-2];
  }

  return results[n];
}

int main() {
  auto start = std::chrono::steady_clock::now();
  std::cout << "f(42) = " << fibonacci(42) << '\n';
  auto end = std::chrono::steady_clock::now();
  std::chrono::duration<double> elapsed_seconds = end-start;
  std::cout << "elapsed time: " << elapsed_seconds.count() << "s\n";
  return 0;
}
