#include <iostream>
#include <vector>
using namespace std;
typedef vector<vector<int>> matrix_vect_int;
typedef vector<int> vect_int;

*/
//Функция вывода конечного резуьтата
void Print(matrix_vect_int aMatrix, matrix_vect_int bMatrix, matrix_vect_int& result, int rowA, int colA, int rowB, int colB) {
  for (int i = 0; i < rowA; i++) {
    for (int j = 0; j < colA; j++) {
      cout << aMatrix[i][j] << " ";
    }
    cout << endl;
  } cout << endl;

  for (int i = 0; i < rowB; i++) {
    for (int j = 0; j < colB; j++) {
      cout << bMatrix[i][j] << " ";
    }
    cout << endl;
  } cout << endl;

  for (int i = 0; i < rowA; i++) {
    for (int j = 0; j < colB; j++) {
      for (int k = 0; k < colA; k++) {
        cout << result[i][j] << " ";
      }
      cout << endl;
    }
  }

}

//Заполнение матриц случаянныим числами
void Filing(matrix_vect_int& aMatrix, matrix_vect_int& bMatrix, int rowA, int colA, int rowB, int colB) {
  for (int i = 0; i < rowA; i++) {
    for (int j = 0; j < colA; j++) {
      aMatrix[i][j] = rand() % 20 - 10;
    }
  }

  for (int i = 0; i < rowB; i++) {
    for (int j = 0; j < colB; j++) {
      bMatrix[i][j] = rand() % 20 - 10;
    }
  }
}

//Функция перемножения матриц
void Multiply(const matrix_vect_int& aMatrix, const matrix_vect_int& bMatrix) {
  int rowA = aMatrix.size();
  int colA = aMatrix[0].size();
  int rowB = bMatrix.size();
  int colB = bMatrix[0].size();

  //Создание вектора с результатом
  matrix_vect_int result(rowA, vect_int(colB, 0));

  for (int i = 0; i < rowA; i++) {
    for (int j = 0; j < colB; j++) {
      for (int k = 0; k < colA; k++) {
        result[i][j] += aMatrix[i][k] * bMatrix[k][j];
      }
    }
  }
  Print(aMatrix, bMatrix, result, rowA, colA, rowB, colB);
}

void inputData(matrix_vect_int& aMatrix, matrix_vect_int& bMatrix) {
  int rowA, colA, rowB, colB;

  //Ввод строк и столбцов
  cout << "Enter rows for aMatrix: "; cin >> rowA;
  cout << "Enter culums for aMatrix: "; cin >> colA;
  cout << endl;
  cout << "Enter rows for bMatrix: "; cin >> rowB;
  cout << "Enter culums for bMatrix: "; cin >> colB;

  // Проверка на равенство строк аMatrix со столбцами bMatrix
  if (colA != rowB) {
    cout << "Error: aMatrix rows must equal bMatrix colums!";
      return;
  }

  // Изменение размера матриц под новые данные
  aMatrix.resize(rowA, vect_int(colA));
  bMatrix.resize(rowB, vect_int(colB));

  //Вызов остальных функций
  Filing(aMatrix, bMatrix, rowA, colA, rowB, colB);
  Multiply(aMatrix, bMatrix);
}

int main() {
  srand(time(NULL));
  matrix_vect_int aMatrix, bMatrix;

  inputData(aMatrix, bMatrix);

}