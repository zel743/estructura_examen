#include  <stdio.h>
#include  <stdlib.h>

struct pais {
    char nombre_p [40];
    struct siguiente *siguiente;

}pais;

struct dato *primer = NULL;

int imprimirlista()
{};

int nuevoEstado()
{};

int eliminarEstado()
{};
int nuevoPais()
{};

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
                x = imprimirlista(x);
                break;

            case 2:
                x = nuevoEstado(x);
                break;

            case 3:
                x = eliminarEstado(x);
                break;

            case 4:
                x = nuevoPais(x);
                break;

            case 5:
                x = dardeBaja(x);
                break;

            case 0:
                printf("Salir\n");
                break;

        }


    }while(op !=0 );

};