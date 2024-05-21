/****
** JESUS GONZALEZ DE LA TORRE
** GAEL GOMEZ RIVERA
** ALBERTO GUADALUPE HERNANDEZ VALENCIA
** FECHA 20/05/24
** CENTRO UNIVERSITARIO DE LOS ALTOS
** VERSION 1.0.0
** PROYECTO FINAL
** SERGIO FRANCO CASILLAS
******/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definimos constantes para los límites de estudiantes, nombre y materias
#define MaxEstudiante 100
#define MaxNombre 50
#define MaxMateria 5

// Definimos una estructura para almacenar los datos de un estudiante
typedef struct {
    int id;                            // ID del estudiante
    char nombre[MaxNombre];            // Nombre del estudiante
    float calificaciones[MaxMateria];  // Calificaciones del estudiante en diferentes materias
} Estudiante;

// Declaramos un arreglo de estructuras para almacenar los estudiantes
Estudiante estudiantes[MaxEstudiante];
int cuenta_estudiantes = 0; // Contador de estudiantes registrados

// Función para cargar los datos de los estudiantes desde un archivo
void cargar_datos() {
    FILE *file = fopen("estudiantes.txt", "r");
    if (file) {
        fscanf(file, "%d", &cuenta_estudiantes);
        for (int i = 0; i < cuenta_estudiantes; ++i) {
            fscanf(file, "%d", &estudiantes[i].id);
            fscanf(file, " %[^\n]", estudiantes[i].nombre);
            for (int j = 0; j < MaxMateria; ++j) {
                fscanf(file, "%f", &estudiantes[i].calificaciones[j]);
            }
        }
        fclose(file);
    }
}

// Función para guardar los datos de los estudiantes en un archivo
void guardar_datos() {
    FILE *file = fopen("estudiantes.txt", "w");
    fprintf(file, "%d\n", cuenta_estudiantes);
    for (int i = 0; i < cuenta_estudiantes; ++i) {
        fprintf(file, "%d\n", estudiantes[i].id);
        fprintf(file, "%s\n", estudiantes[i].nombre);
        for (int j = 0; j < MaxMateria; ++j) {
            fprintf(file, "%.2f\n", estudiantes[i].calificaciones[j]);
        }
    }
    fclose(file);
}

// Función para guardar los datos de un estudiante específico en un archivo separado
void guardar_estudiante_especifico(Estudiante estudiante) {
    FILE *file = fopen("estudiante_especifico.txt", "w");
    fprintf(file, "Nombre: %s\n", estudiante.nombre);
    fprintf(file, "Calificaciones: ");
    float total = 0;
    for (int j = 0; j < MaxMateria; ++j) {
        fprintf(file, "%.2f ", estudiante.calificaciones[j]);
        total += estudiante.calificaciones[j];
    }
    float promedio = total / MaxMateria;
    fprintf(file, "\nPromedio: %.2f\n", promedio);
    fclose(file);
    printf("Estudiante guardado en 'estudiante_especifico.txt'.\n");
}

// Función para agregar un nuevo estudiante al sistema
void agregar_estudiante() {
    if (cuenta_estudiantes < MaxEstudiante) {
        Estudiante nuevo_estudiante;
        nuevo_estudiante.id = cuenta_estudiantes + 1;
        printf("Ingrese nombre: ");
        scanf(" %[^\n]", nuevo_estudiante.nombre);
        for (int i = 0; i < MaxMateria; ++i) {
            do {
                printf("Ingrese calificacion para la materia %d (1-100): ", i + 1);
                scanf("%f", &nuevo_estudiante.calificaciones[i]);
                if (nuevo_estudiante.calificaciones[i] < 1 || nuevo_estudiante.calificaciones[i] > 100) {
                    printf("Calificacion invalida. Debe ser entre 1 y 100.\n");
                }
            } while (nuevo_estudiante.calificaciones[i] < 1 || nuevo_estudiante.calificaciones[i] > 100);
        }
        estudiantes[cuenta_estudiantes++] = nuevo_estudiante;
        guardar_datos();
    } else {
        printf("Se alcanzó el limite maximo de estudiantes.\n");
    }
}

// Función para modificar los datos de un estudiante existente
void modificar_estudiante() {
    int id;
    printf("Ingrese ID del estudiante a modificar: ");
    scanf("%d", &id);
    if (id > 0 && id <= cuenta_estudiantes) {
        Estudiante *estudiante = &estudiantes[id - 1];
        printf("Ingrese nuevo nombre (actual: %s): ", estudiante->nombre);
        scanf(" %[^\n]", estudiante->nombre);
        for (int i = 0; i < MaxMateria; ++i) {
            do {
                printf("Ingrese nueva calificacion para la materia %d (actual: %.2f): ", i + 1, estudiante->calificaciones[i]);
                scanf("%f", &estudiante->calificaciones[i]);
                if (estudiante->calificaciones[i] < 1 || estudiante->calificaciones[i] > 100) {
                    printf("Calificación invalida. Debe ser entre 1 y 100.\n");
                }
            } while (estudiante->calificaciones[i] < 1 || estudiante->calificaciones[i] > 100);
        }
        guardar_datos();
    } else {
        printf("ID de estudiante invalido.\n");
    }
}

// Función para eliminar un estudiante del sistema
void eliminar_estudiante() {
    int id;
    printf("Ingrese ID del estudiante a eliminar: ");
    scanf("%d", &id);
    if (id > 0 && id <= cuenta_estudiantes) {
        for (int i = id - 1; i < cuenta_estudiantes - 1; ++i) {
            estudiantes[i] = estudiantes[i + 1];
        }
        --cuenta_estudiantes;
        guardar_datos();
    } else {
        printf("ID de estudiante invalido.\n");
    }
}

// Función para eliminar todos los estudiantes del sistema
void eliminar_todos_los_estudiantes() {
    cuenta_estudiantes = 0;
    guardar_datos();
    printf("Todos los estudiantes han sido eliminados.\n");
}

// Función para imprimir una leyenda basada en el promedio de calificaciones
void imprimir_leyenda_promedio(float promedio) {
    if (promedio <= 59) {
        printf("Reprobado\n");
    } else if (promedio <= 79) {
        printf("Regular\n");
    } else if (promedio <= 89) {
        printf("Muy bien\n");
    } else {
        printf("Excelente\n");
    }
}

// Función para ver los datos de un estudiante específico
void ver_estudiante() {
    int id;
    printf("Ingrese ID del estudiante a ver: ");
    scanf("%d", &id);
    if (id > 0 && id <= cuenta_estudiantes) {
        Estudiante *estudiante = &estudiantes[id - 1];
        printf("ID: %d\n", estudiante->id);
        printf("Nombre: %s\n", estudiante->nombre);
        float total = 0;
        for (int i = 0; i < MaxMateria; ++i) {
            printf("Calificacion para la materia %d: %.2f\n", i + 1, estudiante->calificaciones[i]);
            total += estudiante->calificaciones[i];
        }
        float promedio = total / MaxMateria;
        printf("Promedio: %.2f - ", promedio);
        imprimir_leyenda_promedio(promedio);
        guardar_estudiante_especifico(*estudiante);
    } else {
        printf("ID de estudiante inválido.\n");
    }
}

// Función para ver los datos de todos los estudiantes
void ver_todos_los_estudiantes() {
    for (int i = 0; i < cuenta_estudiantes; ++i) {
        printf("ID: %d, Nombre: %s\n", estudiantes[i].id, estudiantes[i].nombre);
    }
}

// Función para ver las calificaciones de todos los estudiantes en una materia específica
void ver_por_materia() {
    int materia;
    printf("Ingrese numero de la materia (1-%d): ", MaxMateria);
    scanf("%d", &materia);
    if (materia > 0 && materia <= MaxMateria) {
        for (int i = 0; i < cuenta_estudiantes; ++i) {
            printf("ID: %d, Nombre: %s, Calificacion: %.2f\n", estudiantes[i].id, estudiantes[i].nombre, estudiantes[i].calificaciones[materia - 1]);
        }
    } else {
        printf("Numero de materia invalido.\n");
    }
}

int main() {
    cargar_datos();  // Cargar datos iniciales de estudiantes desde el archivo
    int opcion;
    do {
        // Menú de opciones para el usuario
        printf("1. Agregar Estudiante\n");
        printf("2. Modificar Estudiante\n");
        printf("3. Eliminar Estudiante\n");
        printf("4. Ver Estudiante\n");
        printf("5. Ver Todos los Estudiantes\n");
        printf("6. Ver por Materia\n");
        printf("7. Eliminar Todos los Estudiantes\n");
        printf("8. Salir\n");
        printf("Ingrese opcion: ");
        scanf("%d", &opcion);
        switch (opcion) {
            case 1: agregar_estudiante(); break;
            case 2: modificar_estudiante(); break;
            case 3: eliminar_estudiante(); break;
            case 4: ver_estudiante(); break;
            case 5: ver_todos_los_estudiantes(); break;
            case 6: ver_por_materia(); break;
            case 7: eliminar_todos_los_estudiantes(); break;
            case 8: guardar_datos(); break;
            default: printf("Opcion invalida.\n");
        }
    } while (opcion != 8);
    return 0;
}
