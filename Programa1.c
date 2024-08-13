#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ejercicio();

typedef struct 
{
    char nombre[20];
    char cod_empleado[20];
    char sueldo[20];
    char horas_trabajadas[20];
}trabajadores;


int main(){
    ejercicio();
}

int ejercicio(){
    int desicion, contador;
    trabajadores * puntero;
    int desicion2;

    do
    {
        printf("\n|-------------------------------------|");
		printf("\n|            ° Bienvenido °           |");
		printf("\n|------------------|------------------|");
		printf("\n| 1. Insertar      | 2. Consultas     |");
        printf("\n|                  |    Generales     |");
		printf("\n| 3. Consultar por | 4.Consulta por   |");
        printf("\n|    Clave         |   Nombre         |");
        printf("\n|              ____|____              |");
		printf("\n|               |Salir|               |");
		printf("\n|-------------------------------------|\n");
        scanf("%d", & desicion2);
        if (desicion2 == 1)
        {        
        printf("Cuantos elementos quiere en el vector. ");
        scanf("%d", & desicion);

        puntero = malloc(desicion * sizeof(trabajadores));
        
        for (int i = 0; i < desicion; i++)
            {   
            getchar(); 
            printf("Ingrese el nombre: ");
            fgets(puntero[i].nombre, 20, stdin);
            puntero[i].nombre[strcspn(puntero[i].nombre, "\n")] =0;

            printf("Ingrese el codigo del empleado: ");
            fgets(puntero[i].cod_empleado, 20, stdin);
            puntero[i].cod_empleado[strcspn(puntero[i].cod_empleado, "\n")] =0;

            printf("Ingrese el sueldo: ");
            fgets(puntero[i].sueldo, 20, stdin);
            puntero[i].sueldo[strcspn(puntero[i].sueldo, "\n")] =0;

            printf("Ingrese las horas trabajadas: ");
            fgets(puntero[i].horas_trabajadas, 20, stdin);
            puntero[i].horas_trabajadas[strcspn(puntero[i].horas_trabajadas, "\n")] =0;

            }   

        }else if (desicion2 == 2)
        {
        printf("Todos los trabajadores: \n");

        for (int i = 0; i < desicion; i++)
        {   
            printf("Nombre: %s\n", puntero[i].nombre);
            printf("codido del empleado: %s\n", puntero[i].cod_empleado);
            printf("sueldo: %s\n", puntero[i].sueldo);
            printf("horas de trabajo: %s\n", puntero[i].horas_trabajadas);
        }
        free(puntero);
        }else if (desicion2 == 3)
        {
        getchar();    
        printf("Ingrese el nombre del trabajador: ");
        char buscar_trabajador[20];
        fgets(buscar_trabajador, sizeof(buscar_trabajador), stdin);
        buscar_trabajador[strcspn(buscar_trabajador, "\n")] = 0;
        int buscar__ = 0;
        for (int i = 0; i < i; i++) {
            if (strcmp(puntero[i].nombre, buscar_trabajador) == 0) {
                printf("|Nombre| %s, |Descricpion| %s, |suelod_| %s", 
                        puntero[i].nombre, puntero[i].cod_empleado, puntero[i].sueldo);
                buscar__ = 1;
                break;
            }
        }
        if (!buscar__) {
        printf("Error \n");
        }
    } 
    } while (desicion2 <= 3);
}