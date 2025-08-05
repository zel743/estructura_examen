#include  <stdio.h>
#include  <stdlib.h>
#include <string.h>


struct estado {
    char nombre [50];
    struct estado *siguiente;
};


struct pais {
    char nombre [40];
    struct estado *estados;  
    struct pais *siguiente;

};

struct pais *listaPaises = NULL;



int imprimirlista() {

};

int nuevoEstado()
{};

int eliminarEstado()
{};
int nuevoPais() {
    int x;
    char nombrePais[40];
    printf("Ingrese el nombre del nuevo país: ");
    scanf(" %[^\n]", nombrePais);

    struct pais *nuevoPais = (struct pais*)malloc(sizeof(struct pais));
    strcpy(nuevoPais->nombre, nombrePais);
    nuevoPais->estados = NULL;
    nuevoPais->siguiente = NULL;
// aqui se agregan los estados
    do {

        char nombreEstado[50];
        printf("Ingrese un estado: ");
        scanf(" %[^\n]", nombreEstado);
        struct estado *nuevoEstado = (struct estado*)malloc(sizeof(struct estado));
        strcpy(nuevoEstado->nombre, nombreEstado);
        nuevoEstado->siguiente = NULL;

        if (nuevoPais->estados == NULL) {
            nuevoPais->estados = nuevoEstado;
        } else {
            struct estado *ultimo = nuevoPais->estados;
            while (ultimo->siguiente != NULL) {
                ultimo = ultimo->siguiente;
            }
            ultimo->siguiente = nuevoEstado;
        }
        printf("desea continuar? si = 1");
        scanf(" %d", &x);

    }while (x != 0);

};

int dardeBaja()
{};




void main () {

    int op, x=0;
    do {
        printf("menu\n");
        printf("1. Imprimir lista de estados de un pais\n");
        printf("2. Insertar nuevo estado dado un pais\n");
        printf("3. Eliminar un estado dado un pais\n");
        printf("4. Dar de alta un nuevo pais, con sus estados\n");
        printf("5. Dar de baja un pais con todos sus estados\n");
        printf("0. Salir\n");
        printf("elige la opcionn: \n");
        scanf("%d",&op);

        switch (op) {
            case 1:
                imprimirlista();
                break;

            case 2:
                nuevoEstado();
                break;

            case 3:
                eliminarEstado();
                break;

            case 4:
                nuevoPais();
                break;

            case 5:
                dardeBaja();
                break;

            case 0:
                printf("Salir\n");
                break;

        }


    }while(op !=0 );

};