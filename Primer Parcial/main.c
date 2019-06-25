#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libreria.h"
#include "utn.h"

int main()
{
    int init;

    eAutores arrayAutores[MAX];
    eLibros arrayLibros[MAX];
    eSocios arraySocios[MAX];
    ePrestamos arrayPrestamos[MAX];

    init = inicializar(arrayAutores,arrayLibros,arraySocios);

    if (init == -1)
    {
        printf("El tamanio maximo es invalido.");
    }

    setAutor(arrayAutores,0,0,"Adolf","Hitler",0);
    setAutor(arrayAutores,1,1,"Cristina","Kirchner",0);
    setAutor(arrayAutores,2,2,"Nicolas","Maquiavelo",0);
    setAutor(arrayAutores,3,3,"Mariano", "Recalde",0);
    setAutor(arrayAutores,4,4,"Jorge","Bergoglio",0);

    setLibro(arrayLibros,0,0,"Mi lucha",0,0);
    setLibro(arrayLibros,1,1,"Sinceramente",1,0);
    setLibro(arrayLibros,2,2,"El Principe",2,0);
    setLibro(arrayLibros,3,3,"Gobernar la Ciudad",3,0);
    setLibro(arrayLibros,4,4,"Momentos de Esperanza",4,0);


    int option = 0;

    while(option != 10)
    {
        system("@cls||clear");
        printf("\n------------  MENU PRINCIPAL ------------");
        printf("\n------------  SOCIOS ------------");
        option = getInt("\n1 - ALTA \n2 - MODIFICACION \n3 - BAJA \n4 - LISTAR \n5 - LISTAR LIBROS \n6 - LISTAR AUTORES \n7 - PRESTAMOS \n10 - SALIR \n\n\n");

        switch(option)
        {
            case 1:
                altaSocio(arraySocios);
                break;
            case 2:
                modificarSocio(arraySocios);
                break;
            case 3:
                bajaSocio(arraySocios);
                break;
            case 4:
                listarSocios(arraySocios);
                break;
            case 5:
                listarLibros(arrayLibros);
                break;
            case 6:
                listarAutores(arrayAutores);
                break;
            case 7:
                altaPrestamos(arrayPrestamos);
                break;

        }
    }


    return 0;
}
