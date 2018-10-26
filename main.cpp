#include <iostream>
using namespace std;

int main() {
  int myArray[24] = {2,32,42434,243,243,44,2,324,34,24,343,43,4,3,34,3,45,25,55,25,77,65,55,445};
  cout << sizeof(myArray)/sizeof(myArray[0]);
  return 0;
}
