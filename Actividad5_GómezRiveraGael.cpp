#include <stdio.h>

int main() {
    int arr[10] = {0}; 
    int size = 0; 
    int option, index, value, i, sum;

    do {

        printf("\n1. Añadir/Editar elemento\n2. Eliminar elemento\n3. Mostrar arreglo\n4. Mostrar sumatoria\n5. Vaciar arreglo\n6. Salir\nSeleccione una opción: ");
        scanf("%d", &option);

        switch (option) {
            case 1: 
                printf("Ingrese el índice (0-9) y el valor: ");
                scanf("%d %d", &index, &value);
                if (index >= 0 && index < 10) {
                    arr[index] = value;
                    if (index >= size) size = index + 1;
                } else {
                    printf("Índice fuera de rango.\n");
                }
                break;
            case 2: 
                printf("Ingrese el índice del elemento a eliminar (0-9): ");
                scanf("%d", &index);
                if (index >= 0 && index < size) {
                    for (i = index; i < size - 1; i++) {
                        arr[i] = arr[i + 1];
                    }
                    size--;
                } else {
                    printf("Índice fuera de rango.\n");
                }
                break;
            case 3: 
                printf("Array: [");
                for (i = 0; i < size; i++) {
                    printf("%d", arr[i]);
                    if (i < size - 1) printf(", ");
                }
                printf("]\n");
                break;
            case 4: 
                sum = 0;
                for (i = 0; i < size; i++) {
                    sum += arr[i];
                }
                printf("Sumatoria: %d\n", sum);
                break;
            case 5: 
                size = 0;
                printf("Arreglo vaciado.\n");
                break;
            case 6: // Salir
                printf("Saliendo...\n");
                break;
            default:
                printf("Opción no válida.\n");
        }
    } while (option != 6);

    return 0;
}
