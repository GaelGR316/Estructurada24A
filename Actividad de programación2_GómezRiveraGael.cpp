#include <stdio.h>

int main() {

    printf("Demostración de caracteres de escape\n");
    printf("Nueva línea\n");
    printf("Tabulación\tHorizontal\n");
    printf("Comillas simples \' y comillas dobles \"\n");
    printf("Barra invertida \\ y alarma audible (sonido del sistema)\a\n");
    printf("Avance de página\fNueva página iniciada aquí\n");
    printf("Retorno de carro\rInicio de esta línea\n");

    printf("\nDemostración de cadenas de control de tipos de salida\n");
    printf("Entero decimal: %d\n", 255);
    printf("Entero octal: %o\n", 255);
    printf("Entero hexadecimal: %x\n", 255);
    printf("Real en notación fija: %f\n", 123.456);
    printf("Real en notación científica: %e\n", 123.456);
    printf("Carácter: %c\n", 'A');

    return 0;
}