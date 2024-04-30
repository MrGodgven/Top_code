#pragma once
#include <iostream>
using namespace std;

void generate(int array[],
  const int size,
  const int left_border,
  const int right_border)
{
  for (int i = 0; i < size; i++) {
    array[i] = (rand() % (right_border - left_border) + left_border);
  }
}

void print(const int array[], const size_t size) {
  for (size_t i = 0; i < size; i++) {
    cout << array[i] << ' ';
  }
  cout << endl;
}

int max(const int array[], const int size) {
  int max = array[0];
  for (int i = 0; i < size; i++) {
    if (array[i] > max) max = array[i];
  }
  return max;
}

int min(const int array[], const int size) {
  int min = array[0];
  for (int i = 0; i < size; i++) {
    if (array[i] < min) min = array[i];
  }
  return min;
}

void reverse(int array[], const int size) {
  int a = 0;
  for (int i = size-1; i >= size/2; i--) {
    swap(array[i], array[a]);
    a++;
  }
}
