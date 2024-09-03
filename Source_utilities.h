#pragma once
#include <iostream>
#include <vector>
using namespace std;
typedef vector <char> vector_char;
typedef vector <int> vector_int;

void generate(int arr[],
  const int size,
  const int left_border,
  const int right_border)
{
  for (int i = 0; i < size; i++) {
    arr[i] = (rand() % (right_border - left_border) + left_border);
  }
}

void print(const int arr[], size_t size) {
  for (size_t i = 0; i < size; i++) {
    cout << arr[i] << ' ';
  }
  cout << endl;
}

int max(const int arr[], size_t size) {
  int max = arr[0];
  for (size_t i = 0; i < size; i++) {
    if (arr[i] > max) max = arr[i];
  }
  return max;
}

int min(const int arr[], size_t size) {
  int min = arr[0];
  for (size_t i = 0; i < size; i++) {
    if (arr[i] < min) min = arr[i];
  }
  return min;
}

void reverse(int arr[], size_t size) {
  int a = 0;
  for (size_t i = size-1; i >= size/2; i--) {
    swap(arr[i], arr[a]);
    a++;
  }
}

bool isin(const int arr[], size_t size, int x) {
  for (size_t index = 0; index < size; index++) {
    if (x == arr[index]) return true;
  }
  return false;
}

int sum_range(int a, int b) {
  if (a == b) return a;
  return b + sum_range(a, b - 1);
}

void rekurs_print(const int arr[], size_t size, size_t from = 0) {
  if (size == from) return;

  cout << arr[from] << " ";

  rekurs_print(arr, size, from + 1);
}

int arr_sum(const int arr[], size_t size, size_t from = 0, int sum = 0) {

  if (size == from) return sum; 

  sum += arr[from];

  return arr_sum(arr, size, from + 1, sum);

}

void swup(int& a, int& b) {
  int c = a;
  a = b;
  b = c;
}

int fact(int a) {
  if (a == 1) return 1;
  return a * fact(a - 1);
}

int* concat(const int* arr1, const size_t size1,
           const int* arr2, const size_t size2) {

  int* result = new int[size1 + size2];

  for (size_t i = 0; i < size1; i++) {
    result[i] = arr1[i];
  }

  for (size_t i = 0; i < size2; i++) {
    result[i+size1] = arr2[i];
  }

  return result;

}

int* concat_new(const int* arr1, const size_t size1,
  const int* arr2, const size_t size2) {
  int count = 0;

  int* result = new int[size1 + size2];

  for (size_t i = 0; i < size1; i++) {
    if (!isin(result, size1 + size2, arr1[i])) {
      result[count] = arr1[i];
      count++;
    }
  }

  for (size_t i = 0; i < size2; i++) {
    if (!isin(result, size1 + size2, arr2[i])) {
      result[count] = arr2[i];
      count++;
    }
  }
  return result;
}


int numcheck(const int arr1[], const int* size, int choose) {
  int plus = 0, minus = 0, zero = 0;
  for (int i = 0; i < *size; i++){
    if (arr1[i] >= 1) plus++;
    else if (arr1[i] <= -1) minus++;
    else zero++;
  }

  if (choose >= 1) return plus;
  else if (choose <= -1) return minus;
  else return zero;

}

void relocate(int* arr, size_t size, size_t new_size) {
  int* new_arr = new int[new_size];
  const size_t min_size = min(size, new_size);

  for (size_t i = 0; i < min_size; i++) {
    new_arr[i] = arr[i];
  }

  delete[] arr;
  arr = new_arr;
}

int* isin_arr(int* arr1, size_t size1, int* arr2, size_t size2) {
  for (size_t i = 0; i < size2; i++) {
    if (isin(arr1, size1, arr2[i])) return arr1 + i + 1;
  }
  return nullptr;
}

void pop(int* arr, size_t size, size_t index) {
  for (size_t i = index; i < size - 1; i++) {
    arr[i] = arr[i + 1];
  }
}

int st_lenght(const char *stroke) {
  int x = 0;
  for (size_t i = 0; stroke[i] != '\0'; i++) x++;
  return x;
}

char * mystrchr(char * str, char s) {
  for (size_t i = 0; str[i] != '\0'; i++) {
    if (str[i] == s) {
      return str + i;
      break;
    }
  }
  return nullptr;
}

void print_char_vector(vector_char& vect) {
  for (size_t i = 0; i < vect.size(); i++) {
    cout << vect.at(i);
  }
}

void fill_int_vector(vector_int& vect) {
  int x; cin >> x;
  for (size_t i = 0; i < x; i++) {
    int y = 0; cin >> y;
    vect.push_back(y);
  }
}

void print_int_vector(vector_int& vect) {
  for (auto& i : vect) {
    cout << i << " ";
  }
}

void reDraw(char mass[3][3]) {
  system("CLS");
  for (size_t i = 0; i < 3; i++) {
    for (size_t j = 0; j < 3; j++) {
      cout << mass[i][j] << " ";
    }
    cout << endl;
  }
}

void restart(char mass[3][3]) {
  system("CLS");
  for (size_t i = 0; i < 3; i++) {
    for (size_t j = 0; j < 3; j++) {
      mass[i][j] = '#';
    }
    cout << endl;
  }
  reDraw(mass);
}

bool isfilled(char mass[3][3]) {
  for (size_t i = 0; i < 3; i++) {
    for (size_t j = 0; j < 3; j++) {
      if (mass[i][j] == '#') return false;
    }
    cout << endl;
  }
  return true;
}