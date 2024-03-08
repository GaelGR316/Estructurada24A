#include <iostream>
#include <cstdlib> // Para rand()

using namespace std;

const int FilasMax = 10;
const int ColumnasMax = 10;

// Función para llenar una matriz con valores aleatorios entre -100 y 100
void llenarMatrizAleatoriamente(int matriz[][ColumnasMax], int filas, int columnas) {
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            matriz[i][j] = rand() % 201 - 100; // Valores entre -100 y 100
        }
    }
}

// Función para mostrar una matriz
void mostrarMatriz(int matriz[][ColumnasMax], int filas, int columnas) {
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
}

// Función para sumar dos matrices
void sumaMatrices(int matriz1[][ColumnasMax], int matriz2[][ColumnasMax], int resultado[][ColumnasMax], int filas, int columnas) {
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            resultado[i][j] = matriz1[i][j] + matriz2[i][j];
        }
    }
}

// Función para restar dos matrices
void restaMatrices(int matriz1[][ColumnasMax], int matriz2[][ColumnasMax], int resultado[][ColumnasMax], int filas, int columnas) {
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            resultado[i][j] = matriz1[i][j] - matriz2[i][j];
        }
    }
}

// Función para multiplicar dos matrices
void multiplicacionMatrices(int matriz1[][ColumnasMax], int matriz2[][ColumnasMax], int resultado[][ColumnasMax], int filas, int columnas) {
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            resultado[i][j] = 0;
            for (int k = 0; k < columnas; ++k) {
                resultado[i][j] += matriz1[i][k] * matriz2[k][j];
            }
        }
    }
}

int main() {
    int filas, columnas;
    cout << "Ingrese el numero de filas (maximo 10): ";
    cin >> filas;
    cout << "Ingrese el numero de columnas (maximo 10): ";
    cin >> columnas;

    int matriz1[FilasMax][ColumnasMax];
    int matriz2[FilasMax][ColumnasMax];
    int resultado[FilasMax][ColumnasMax];

    llenarMatrizAleatoriamente(matriz1, filas, columnas);
    llenarMatrizAleatoriamente(matriz2, filas, columnas);

    cout << "Matriz 1:" << endl;
    mostrarMatriz(matriz1, filas, columnas);

    cout << "Matriz 2:" << endl;
    mostrarMatriz(matriz2, filas, columnas);

    // Realiza las operaciones que desees aquí (suma, resta, multiplicación, etc.)

    return 0;
}
