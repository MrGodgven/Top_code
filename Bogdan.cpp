#include <iostream>
#include "Source_utilities.h"
using namespace std;

int main() {
	int sum = 0;
	int mult = 1;
	const int size1 = 5, size2 = 3;

	int x[size1]{ 1, 2, 3, 4, 5 };
	int y[size2]{ 2, 3, 4 };

	cout << *isin_arr(x, size1, y, size2);
}