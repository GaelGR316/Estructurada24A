#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Funciones para la manipulación de conjuntos
void mostrarConjunto(const vector<int>& conjunto, const string& nombreConjunto) {
    cout << nombreConjunto << ": ";
    for (size_t i = 0; i < conjunto.size(); ++i) {
        cout << conjunto[i] << " ";
    }
    cout << endl;
}

void insertarValor(vector<int>& conjunto) {
    int valor;
    cout << "Ingrese el valor a insertar: ";
    cin >> valor;
    conjunto.push_back(valor);
}

void borrarValor(vector<int>& conjunto) {
    int valor;
    cout << "Ingrese el valor a borrar: ";
    cin >> valor;
    vector<int>::iterator it = remove(conjunto.begin(), conjunto.end(), valor);
    conjunto.erase(it, conjunto.end());
}

void editarValor(vector<int>& conjunto) {
    int valorActual, valorNuevo;
    cout << "Ingrese el valor actual: ";
    cin >> valorActual;
    // Encontrar el elemento con un bucle manual
    vector<int>::iterator it = find(conjunto.begin(), conjunto.end(), valorActual);
    if (it != conjunto.end()) {
        cout << "Ingrese el nuevo valor: ";
        cin >> valorNuevo;
        *it = valorNuevo;
    } else {
        cout << "Valor no encontrado.\n";
    }
}

void vaciarConjunto(vector<int>& conjunto) {
    conjunto.clear();
}

vector<int> unionConjuntos(const vector<int>& conjuntoA, const vector<int>& conjuntoB) {
    vector<int> resultado(conjuntoA);
    resultado.insert(resultado.end(), conjuntoB.begin(), conjuntoB.end());
    sort(resultado.begin(), resultado.end());
    // Usando unique y erase para eliminar duplicados
    vector<int>::iterator it = unique(resultado.begin(), resultado.end());
    resultado.erase(it, resultado.end());
    return resultado;
}

vector<int> interseccionConjuntos(const vector<int>& conjuntoA, const vector<int>& conjuntoB) {
    vector<int> resultado;
    for (size_t i = 0; i < conjuntoA.size(); ++i) {
        if (find(conjuntoB.begin(), conjuntoB.end(), conjuntoA[i]) != conjuntoB.end()) {
            resultado.push_back(conjuntoA[i]);
        }
    }
    // Ordenar y eliminar duplicados
    sort(resultado.begin(), resultado.end());
    vector<int>::iterator it = unique(resultado.begin(), resultado.end());
    resultado.erase(it, resultado.end());
    return resultado;
}

vector<int> diferenciaConjuntos(const vector<int>& conjuntoA, const vector<int>& conjuntoB) {
    vector<int> resultado;
    for (size_t i = 0; i < conjuntoA.size(); ++i) {
        if (find(conjuntoB.begin(), conjuntoB.end(), conjuntoA[i]) == conjuntoB.end()) {
            resultado.push_back(conjuntoA[i]);
        }
    }
    return resultado;
}

vector<int> complementoConjuntos(const vector<int>& conjuntoA, const vector<int>& conjuntoB) {
    return diferenciaConjuntos(conjuntoB, conjuntoA);
}

int main() {
    vector<int> conjuntoA, conjuntoB;

    // Ejemplo de uso
    insertarValor(conjuntoA);
    insertarValor(conjuntoB);
    mostrarConjunto(conjuntoA, "Conjunto A");
    mostrarConjunto(conjuntoB, "Conjunto B");

    vector<int> resultadoUnion = unionConjuntos(conjuntoA, conjuntoB);
    mostrarConjunto(resultadoUnion, "Unión");

    vector<int> resultadoInterseccion = interseccionConjuntos(conjuntoA, conjuntoB);
    mostrarConjunto(resultadoInterseccion, "Intersección");

    vector<int> resultadoDiferencia = diferenciaConjuntos(conjuntoA, conjuntoB);
    mostrarConjunto(resultadoDiferencia, "Diferencia A-B");

    vector<int> resultadoComplemento = complementoConjuntos(conjuntoA, conjuntoB);
    mostrarConjunto(resultadoComplemento, "Complemento A respecto a B");

    return 0;
}



