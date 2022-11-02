#include <iostream>
#include <string>
#include <vector>

using namespace std;
int foo() {
  int *ptr = 0;
  *ptr = 1;
}

int main() {
  int arr[]{0, 1, 2, 3, 4, 5, 16, 32, 64, 9};
  for (int i = 0; i < 10000; i++) {
    arr[i] = i;  // mostly it will segmentation fault i between 1000 and 4000
    // cout << i << endl;
  }
  // int *ptr = 0;
  // *ptr = 1;
  // return 0;
  foo();
  return 0;
}