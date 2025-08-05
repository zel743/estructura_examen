#include  <stdio.h>
#include  <stdlib.h>
#include <string.h>

#define max_paises 30

struct estado {
    char nombre [50];
    struct estado *siguiente;
};


struct pais {
    char nombre [40];
    struct estado *primer;
    struct estado *ultimo;

};

struct pais paises [max_paises];
int paisesTodos = 0;

//funcion que se va a usar para buscar
int buscar( char *nombre) {

for (int i = 0; i < paisesTodos; i++)
    {
    if (strcmp (paises[i].nombre, nombre) == 0)
        return i;
}
return -1;
};


//funcion para enlistar los estados de los paises
void imprimirlista() {
char nombrepais[40];
    int ind = 0;
    printf("ingrese el nombre del pais: \n");
    scanf(" %[^\n]", nombrepais);


    ind = buscar(nombrepais);
    if (ind == -1) {

        printf("el pais no existe: \n");
        getchar();
        return;
    }
    printf("\nEstados de %s:\n", nombrepais);
struct estado *aux = paises[ind].primer;
    while (aux != NULL) {
        printf("- %s\n", aux->nombre);
        aux = aux->siguiente;
    }

getchar();
};

//funcion para agregar un estado nuevo en un pais
void nuevoEstado() {
char nombrepais[50];
    printf("ingrese el nombre del pais: \n");
    scanf(" %[^\n]", nombrepais);
    int ind = buscar(nombrepais);
    if (ind == -1) {
        printf("el pais no existe: \n");
        getchar();
        return;
    }

    struct estado *nuevo = (struct estado*)malloc(sizeof(struct estado));
    if (nuevo == NULL) {
        printf("\nNo hay suficiente espacio!\n");
        getchar();
        return;
    }

    printf("Ingrese el nombre del nuevo estado: ");
    scanf(" %[^\n]", nuevo->nombre);
    nuevo->siguiente = NULL;

    if (paises[ind].primer == NULL) {
        paises[ind].primer = nuevo;
        paises[ind].ultimo = nuevo;
    } else {
        paises[ind].ultimo->siguiente = nuevo;
        paises[ind].ultimo = nuevo;
    }

    printf("Estado '%s' agregado a '%s'.\n", nuevo->nombre, nombrepais);
    getchar();

};

//funcion eliminar estado

int eliminarEstado() {

    char nombrePais[40], nombreEstado[50];
    int ind = 0;

    printf("ingrese el nombre del país: ");
    scanf(" %[^\n]", nombrePais);
    printf("ingrese el nombre del estado a eliminar: ");
    scanf(" %[^\n]", nombreEstado);

    ind = buscar(nombrePais);
    if (ind == -1) {
        printf("Error: El país no existe.\n");
        getchar();
        return;
    }

    struct estado *actual = paises[ind].primer;
    struct estado *anterior = NULL;

    while (actual != NULL && strcmp(actual->nombre, nombreEstado) != 0) {
        anterior = actual;
        actual = actual->siguiente;
    }


    if (actual == NULL) {
        printf("error: el estado no existe en este país.\n");
        getchar();
        return;
    }


    if (anterior == NULL) {
        paises[ind].primer = actual->siguiente;
        if (actual->siguiente == NULL) {
            paises[ind].ultimo = NULL;
        }
    } else {
        anterior->siguiente = actual->siguiente;
        if (actual->siguiente == NULL) {
            paises[ind].ultimo = anterior;
        }
    }


    free(actual);
    printf("Estado eliminado \n");
    getchar();




};
//funcion nuevo pais
void nuevoPais() {
    int x = 0;
    printf("ingrese el nombre del pais: \n");
    scanf(" %[^\n]", paises[paisesTodos].nombre);

    if (buscar(paises[paisesTodos].nombre) != -1) {
        printf("pais ya existente\n");
        getchar();
        return;
    }

    paises[paisesTodos].primer= NULL;
    paises[paisesTodos].ultimo = NULL;

    do {
        struct estado *nuevo = (struct estado*)malloc(sizeof(struct estado));
        if (nuevo == NULL) {
            printf("\nno hay suficiente espacio!\n");
            getchar();
            break;
        }

        printf("ingrese un estado: ");
        scanf(" %[^\n]", nuevo->nombre);
        nuevo->siguiente = NULL;

        if (paises[paisesTodos].primer== NULL) {
            paises[paisesTodos].primer = nuevo;
            paises[paisesTodos].ultimo = nuevo;
        } else {
            paises[paisesTodos].ultimo->siguiente = nuevo;
            paises[paisesTodos].ultimo = nuevo;
        }

        printf("agregar otro estado = 1, salir = 0: ");
        scanf(" %d", &x);
    } while (x == 1);

    paisesTodos++;
    printf("País '%s' agregado con sus estados.\n", paises[paisesTodos-1].nombre);
    getchar();

};

int dardeBaja() {
char nombrepais[50];
    int ind = 0;
    if (paisesTodos == 0) {
        printf("no hay países\n");
        getchar();
        return;
    }
    printf("ingresa el nombre de pais a borrar: ");
    scanf(" %[^\n]", nombrepais);
    ind = buscar(nombrepais);
    if (ind == -1) {

        printf("el pais no existe: \n");
        getchar();
        return;
    }
    struct estado *aux = paises[ind].primer;
    while (aux != NULL) {
        struct estado *temp = aux;
        aux = aux->siguiente;
        free(temp);
    }
paisesTodos--;
    printf("pais eliminado: ");
};




void main () {

    int op, x=0;
    do {
        printf("menu\n");
        printf("1. Imprimir lista de estados de un pais\n");
        printf("2. Insertar nuevo estado en un pais\n");
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