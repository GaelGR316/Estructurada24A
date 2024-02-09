#include <iostream>

int main() {
    int numero, contador = 0;
    char opcion;
    do {
        std::cout << "Introduce un número: ";
        std::cin >> numero;

        if (numero > 0 && numero < 500) {
            for (int i = 0; i < 100; i++) {
                numero += 5;
                contador++;
            }
        } else if (numero > 500 && numero < 1000) {
            for (int i = 0; i < 50; i++) {
                numero += 10;
                contador++;
            }
        } else if (numero > 1000) {
            std::cout << "No se puede calcular el valor\n";
        }

        std::cout << "¿Deseas terminar el programa? (s/n): ";
        std::cin >> opcion;
    } while (opcion != 's' && opcion != 's');

    std::cout << "Realizaste " << contador << " operaciones.\n";

    return 0;
}

