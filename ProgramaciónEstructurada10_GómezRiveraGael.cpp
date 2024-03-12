#include <iostream>
#include <ctime> // Para generar n�meros aleatorios
#include <cstdlib> // Para generar n�meros aleatorios

// Nombre: Gael G�mez Rivera
// C�digo: 423034247
// Centro Universitario de los Altos 


using namespace std;

const int Tmaximo = 15; // Tama�o m�ximo de la matriz

// Funci�n para imprimir una matriz
void printMatrix(int matrix[Tmaximo][Tmaximo], int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}

// Funci�n para llenar una matriz con valores aleatorios
void fillMatrixRandom(int matrix[Tmaximo][Tmaximo], int size, int seed) {
    srand(seed); // Inicializar la semilla para n�meros aleatorios

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            matrix[i][j] = rand() % 601 - 200; // Generar un n�mero aleatorio entre -200 y 400
        }
    }
}

// Funci�n para sumar dos matrices
void addMatrices(int matrixA[Tmaximo][Tmaximo], int matrixB[Tmaximo][Tmaximo], int result[Tmaximo][Tmaximo], int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }
}

// Funci�n para restar dos matrices
void subtractMatrices(int matrixA[Tmaximo][Tmaximo], int matrixB[Tmaximo][Tmaximo], int result[Tmaximo][Tmaximo], int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result[i][j] = matrixA[i][j] - matrixB[i][j];
        }
    }
}

// Funci�n para multiplicar dos matrices
void multiplyMatrices(int matrixA[Tmaximo][Tmaximo], int matrixB[Tmaximo][Tmaximo], int result[Tmaximo][Tmaximo], int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result[i][j] = 0; // Inicializar el elemento de la matriz resultante en 0
            for (int k = 0; k < size; ++k) {
                result[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }
}

// Funci�n para dividir dos matrices
void divideMatrices(int numerator[Tmaximo][Tmaximo], int denominator[Tmaximo][Tmaximo], int result[Tmaximo][Tmaximo], int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (denominator[i][j] != 0) {
                result[i][j] = numerator[i][j] / denominator[i][j];
            } else {
                cout << "Error: No se puede dividir por cero." << endl;
                return;
            }
        }
    }
}

int main() {
    int size;
    cout << "Ingrese el tama�o de las matrices (entre 2 y 15): ";
    cin >> size;

    if (size < 2 || size > 15) {
        cout << "Tama�o de matriz no v�lido. Debe estar entre 2 y 15." << endl;
        return 1;
    }

    int matrixA[Tmaximo][Tmaximo];
    int matrixB[Tmaximo][Tmaximo];
    int result[Tmaximo][Tmaximo];

    char option;
    cout << "�Desea llenar las matrices con valores aleatorios? (S/N): ";
    cin >> option;

    if (option == 'S' || option == 's') {
        fillMatrixRandom(matrixA, size, time(0)); // Usamos la hora actual como semilla para matriz A
        fillMatrixRandom(matrixB, size, time(0) + 1); // Usamos la hora actual m�s 1 segundo como semilla para matriz B
    } else if (option == 'N' || option == 'n') {
        cout << "Ingrese los valores de la matriz A:" << endl;
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                cout << "Ingrese el valor para la posici�n (" << i << ", " << j << "): ";
                cin >> matrixA[i][j];
            }
        }

        cout << "Ingrese los valores de la matriz B:" << endl;
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                cout << "Ingrese el valor para la posici�n (" << i << ", " << j << "): ";
                cin >> matrixB[i][j];
            }
        }
    } else {
        cout << "Opci�n no v�lida." << endl;
        return 1;
    }

    cout << "Matriz A:" << endl;
    printMatrix(matrixA, size);

    cout << "Matriz B:" << endl;
    printMatrix(matrixB, size);

    cout << "Seleccione la operaci�n a realizar:" << endl;
    cout << "1. Suma" << endl;
    cout << "2. Resta" << endl;
    cout << "3. Multiplicaci�n" << endl;
    cout << "4. Divisi�n (Matriz A / Matriz B)" << endl;
    cout << "Ingrese su opci�n: ";
    cin >> option;

    switch(option) {
        case '1':
            addMatrices(matrixA, matrixB, result, size);
            cout << "Resultado de la suma:" << endl;
            printMatrix(result, size);
            break;
        case '2':
            subtractMatrices(matrixA, matrixB, result, size);
            cout << "Resultado de la resta:" << endl;
            printMatrix(result, size);
            break;
        case '3':
            multiplyMatrices(matrixA, matrixB, result, size);
            cout << "Resultado de la multiplicaci�n:" << endl;
            printMatrix(result, size);
            break;
        case '4':
            divideMatrices(matrixA, matrixB, result, size);
            cout << "Resultado de la divisi�n:" << endl;
            printMatrix(result, size);
            break;
        default:
            cout << "Opci�n no v�lida." << endl;
            break;
    }

    return 0;
}

