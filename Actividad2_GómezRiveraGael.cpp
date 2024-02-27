#include <iostream>
#include <stdio.h>

int main() {
    std::cout << "Ejemplo de uso de caracteres de escape:\n";
    std::cout << "1. Nueva línea \\n\n";
    std::cout << "2. Tabulador \\t\t<- Aquí hay un tabulador.\n";
    std::cout << "3. Retroceso \\b" << "\b<- Aquí hay un retroceso.\n";
    std::cout << "4. Comillas dobles \\\"\n";
    std::cout << "5. Barra invertida \\\\n";
    std::cout << "6. Alerta sonora \\a";

    std::cout << "\n\nEjemplo de uso de cadenas de control de tipos de salida:\n";
    printf("1. Entero: %d\n", 10);
    printf("2. Carácter: %c\n", 'A');
    printf("3. Flotante: %f\n", 3.1416);
    printf("4. Doble: %lf\n", 3.1415926535);
    printf("5. Cadena: %s\n", "Hola mundo");
    printf("6. Puntero: %p\n", (void*)&main);

    return 0;
}
