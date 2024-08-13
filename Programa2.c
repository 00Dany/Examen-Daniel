#include <stdio.h>
#include <string.h>
typedef struct
{
    char numero_carne[20];
    char Nombre[20];
    char Grado[20];
    char Departamento[20];
    char edad[20];
}alumno ;
void alumnos_guardados(alumno * guardado, int * contador){
    FILE *fp = fopen("Escuela.txt", "r");
    if (fp == NULL) {
        printf("error al abrir el archivo.\n");
        return;
    }
    while (fgets(guardado[*contador].numero_carne, sizeof(guardado[*contador].numero_carne), fp) !=NULL );{
        guardado[*contador].numero_carne[strcspn(guardado[*contador].numero_carne, "\n")] =0; 
        fgets(guardado[*contador].Nombre, sizeof(guardado[*contador].Nombre), fp);
        guardado[*contador].Nombre[strcspn(guardado[*contador].Nombre, "\n")] =0; 
        fgets(guardado[*contador].Grado, sizeof(guardado[*contador].Grado), fp);
        guardado[*contador].Grado[strcspn(guardado[*contador].Grado, "\n")] =0; 
        fgets(guardado[*contador].Departamento, sizeof(guardado[*contador].Departamento), fp);
        guardado[*contador].Departamento[strcspn(guardado[*contador].Departamento, "\n")] =0; 
        fgets(guardado[*contador].edad, sizeof(guardado[*contador].edad), fp);
        guardado[*contador].edad[strcspn(guardado[*contador].edad, "\n")] =0; 

        (*contador )++;
    }
    fclose(fp);
}
int main() {
    int i;
    alumno guardado[100];
    int contador = 0;
    int desicion;
    alumnos_guardados(guardado, &contador);

    do
    {
        printf("\n|-------------------------------------|");
		printf("\n|              Bienvenido             |");
		printf("\n|------------------|------------------|");
		printf("\n| 1. Registrar     | 2. Lista de      |");
        printf("\n|                  |    estudiantes   |");
		printf("\n| 3. Buscar        | 4. Editar        |");
        printf("\n|    por carnet    |                  |");
        printf("\n|              ____|____              |");
		printf("\n|               |Salir|               |");
		printf("\n|-------------------------------------|\n");
        scanf("%d", & desicion);
        if (desicion == 1)
        {   
            getchar();
            printf("Ingrese su numero su carne: ");
            fgets(guardado[contador].numero_carne, 20, stdin);
            guardado[contador].numero_carne[strcspn(guardado[contador].numero_carne, "\n")] = 0; 

            printf("Ingrese su nombre ");
            fgets(guardado[contador].Nombre, 20, stdin);
            guardado[contador].Nombre[strcspn(guardado[contador].Nombre, "\n")] = 0; 

            printf("Ingrese su Grado: ");
            fgets(guardado[contador].Grado, 20, stdin);
            guardado[contador].Grado[strcspn(guardado[contador].Grado, "\n")] = 0; 

            printf("Ingrese su Departamento: ");
            fgets(guardado[contador].Departamento, 20, stdin);
            guardado[contador].Departamento[strcspn(guardado[contador].Departamento, "\n")] = 0; 

            printf("Ingrese su edad: ");
            fgets(guardado[contador].edad, 20, stdin);
            guardado[contador].edad[strcspn(guardado[contador].edad, "\n")] = 0; 


            FILE * fp = fopen("Escuela.txt", "a");
            if (fp == NULL)
            {
                printf("Error \n");
                return 1;   
            }
            fputs(guardado[contador].numero_carne, fp);
            fputs("\n", fp); 
            fputs(guardado[contador].Nombre, fp);
            fputs("\n", fp); 
             fputs(guardado[contador].Grado, fp);
            fputs("\n", fp); 
            fputs(guardado[contador].Departamento, fp);
            fputs("\n", fp); 
            fputs(guardado[contador].edad, fp);
            fputs("\n", fp); 
            fclose(fp);
           contador++;
        }else if (desicion == 2){
        for (int i = 0; i < contador; i++) {
            printf("Numero de carne: %s\n", guardado[i].numero_carne);
            printf("Nombre: %s\n", guardado[i].Nombre);
            printf("Grado: %s\n", guardado[i].Grado);
            printf("Departamento: %s\n", guardado[i].Departamento);
            printf("Edad: %s\n", guardado[i].edad);

        }
        }else if (desicion == 3)
        {
            getchar();
            printf("Ingrese el codigo de carnet del alumno ");
            char buscar_numero_carne[20];
            fgets(buscar_numero_carne, sizeof(buscar_numero_carne), stdin);
            buscar_numero_carne[strcspn(buscar_numero_carne, "\n")] =0;

            int buscar2 =0;
            for (int i = 0; i < contador; i++){
                if (strcmp(guardado[i].numero_carne, buscar_numero_carne) == 0){
                    printf("Numero de carnet: %s\nNombre: %s\nGrado: %s\nDepartamento: %s\nEdad: %s\n", 
                        guardado[i].numero_carne, guardado[i].Nombre, guardado[i].Grado, guardado[i].Departamento, guardado[i].edad);
                buscar2 =1;
                break;
                        }
        }
        if (!buscar2) {
        printf("Error \n");
        }
        }
    } while (desicion <= 4);
    printf("Gracias");
}