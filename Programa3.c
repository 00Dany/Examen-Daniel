#include <stdio.h>
#include <string.h>
typedef struct
{
    char departamento[20];
} alumno;
void alumnos_guardados(alumno *guardado, int *contador)
{
    FILE *fp = fopen("Departamento.txt", "r");
    if (fp == NULL)
    {
        printf("error al abrir el archivo.\n");
        return;
    }
    while (fgets(guardado[*contador].departamento, sizeof(guardado[*contador].departamento), fp) != NULL)
    {
        guardado[*contador].departamento[strcspn(guardado[*contador].departamento, "\n")] = 0;
        (*contador)++;
    }
    fclose(fp);
}
int comparar(const void *a, const void *b)
{
    return strcmp(((alumno *)a)->departamento, ((alumno *)b)->departamento);
}
int main()
{
    int i;
    alumno guardado[100];
    int contador = 0;
    int contar;
    int desicion;
    alumnos_guardados(guardado, &contador);
    do
    {
        printf("1) Ingreso 2)Mostrar: ");
        scanf("%d", &desicion);
        
        if (desicion == 1)
        {   
            printf("Cuantos departamentos quiere ingresar?: ");
            scanf("%d", & desicion);
            getchar();
            for (int i = 0; i < desicion; i++)
            { 
            printf("Ingrese el departamento: ");
            fgets(guardado[contador].departamento, 20, stdin);
            guardado[contador].departamento[strcspn(guardado[contador].departamento, "\n")] = 0;
            FILE *fp = fopen("Departamento.txt", "a");
            if (fp == NULL)
            {
                printf("Error \n");
                return 1;
            }
            fputs(guardado[contador].departamento, fp);
            fputs("\n", fp);
            fclose(fp);
            contador++;
            }
        }
        else if (desicion == 2)
        {    
            qsort(guardado, contador, sizeof(alumno), comparar);
            for (int i = 0; i < contador; i++)
            {
                printf("Departamento no°: %s\n", guardado[i].departamento);
            }
        }
    } while (desicion <= 4);
    printf("Gracias");
}