#include <iostream>
#include "Source_utilities.h"
using namespace std;

int main() {
	srand(time(NULL));
  const int size = 10;
  int x[10];

  generate(x, size, 1, 10);

  print(x, size);

  reverse(x, size);

  print(x, size);

}