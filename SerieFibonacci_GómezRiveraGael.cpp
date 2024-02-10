#include <stdio.h>

int main() {
    int opcion, limite, a, b, siguiente;
    printf("\n****Gael Gomez Rivera****\n");
printf("\n****Programacion Estructurada****\n");

    do {
        printf("\nSeleccione el ciclo con el que desea ejecutar:\n");
        printf("1. Ciclo for\n");
        printf("2. Ciclo while\n");
        printf("3. Ciclo do-while\n");
        printf("4. Salir\n");
        printf("Opcion: ");
        scanf("%d", &opcion);

        if (opcion < 1 || opcion > 4) {
            printf("Opcion no valida. Por favor, intente de nuevo.\n");
            continue; 
        } else if (opcion == 4) {
            printf("Saliendo del programa.\n");
            break; 
        }

        printf("Ingrese el valor limite: ");
        scanf("%d", &limite);

        a = 0;
        b = 1;

        switch(opcion) {
            case 1: // Ciclo for
                printf("Serie de Fibonacci usando ciclo for hasta %d: \n", limite);
                for (siguiente = 0; siguiente <= limite;) {
                    printf("%d, ", siguiente);
                    siguiente = a + b;
                    a = b;
                    b = siguiente;
                }
                printf("\n");
                break;
            case 2: // Ciclo while
                printf("Serie de Fibonacci usando ciclo while hasta %d: \n", limite);
                siguiente = 0;
                while (siguiente <= limite) {
                    printf("%d, ", siguiente);
                    siguiente = a + b;
                    a = b;
                    b = siguiente;
                }
                printf("\n");
                break;
            case 3: // Ciclo do-while
                printf("Serie de Fibonacci usando ciclo do-while hasta %d: \n", limite);
                siguiente = 0;
                if (limite == 0) {
                    printf("%d, ", siguiente);
                } else {
                    do {
                        printf("%d, ", siguiente);
                        int temp = a + b;
                        a = b;
                        b = temp;
                        siguiente = a;
                    } while (a + b <= limite);
                
                    if (a <= limite) {
                        printf("%d, ", a);
                    }
                }
                printf("\n");
                break;
        }
    } while (opcion != 4);

    return 0;
}

