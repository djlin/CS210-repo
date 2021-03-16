#include <iostream>
#include <stack>
using namespace std;

class Tower {
public:
  char id;
  stack<int> disks;
};

void MoveTopDisk(Tower& source, Tower& destination) {
  int topDiskNumber = source.disks.top();
  source.disks.pop();
  destination.disks.push(topDiskNumber);
  cout << "Move " << topDiskNumber << " from " << source.id << " to " << destination.id << endl;
}

void MovePile(Tower& source, Tower& destination, Tower& intermediate, int disks) {
  if(disks > 0) {
    MovePile(source, intermediate, destination, disks-1);
    MoveTopDisk(source, destination);
    MovePile(intermediate, destination, source, disks-1);
  }
}


int main() {
  int numberOfDisks;
  Tower A, B, C;
  A.id = 'A';
  B.id = 'B';
  C.id = 'C';

  cout << "Enter the number of disks: ";
  cin >> numberOfDisks;

  // initialize the disks
  for(int i=numberOfDisks; i>0; i--) {
    C.disks.push(i);
  }

  MovePile(C, B, A, numberOfDisks);

  cout << "number of disks in A: " << A.disks.size() << ", B: " << B.disks.size() << ", C: " << C.disks.size() << endl;

  return 0;
}
