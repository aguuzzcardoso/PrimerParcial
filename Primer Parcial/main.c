#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libreria.h"
#include "utn.h"

void submenu(eAutor arrayAutores[], eLibro arrayLibros[],ePrestamo arrayPrestamos[],eSocio arraySocios[]);
int main()
{
    int init;

    eAutor arrayAutores[MAX];
    eLibro arrayLibros[MAX];
    eSocio arraySocios[MAX];
    ePrestamo arrayPrestamos[MAX];

    init = inicializar(arrayAutores,arrayLibros,arraySocios,arrayPrestamos);

    if (init == -1)
    {
        printf("El tamanio maximo es invalido.");
    }

    setAutor(arrayAutores,0,1,"Adolf","Hitler");
    setAutor(arrayAutores,1,2,"Cristina","Kirchner");
    setAutor(arrayAutores,2,3,"Nicolas","Maquiavelo");
    setAutor(arrayAutores,3,4,"Mariano", "Recalde");
    setAutor(arrayAutores,4,5,"Jorge","Bergoglio");

    setLibro(arrayLibros,0,1,"Mi lucha",1);
    setLibro(arrayLibros,1,2,"Sinceramente",2);
    setLibro(arrayLibros,2,3,"El Principe",3);
    setLibro(arrayLibros,3,4,"Gobernar la Ciudad",4);
    setLibro(arrayLibros,4,5,"Momentos de Esperanza",5);

    setSocio(arraySocios,0,1,"Miguel","Pichetto","m","11-00005000","mpichetto@vendido.com",11,6,2019);
    setSocio(arraySocios,1,2,"Sergio","Massa","m","11-12345678","smassa@elarrepentido.com",13,6,2019);
    setSocio(arraySocios,2,3,"Mauricio","Macri","m","507-987654","elgato@nocambiemos.com",1,12,2019);
    setSocio(arraySocios,3,4,"Daniel","Filmus","m","11-00000000","nose@exfpv.com",1,1,2003);
    setSocio(arraySocios,4,5,"Jose","Espert","m","00000000","perdi@todo.com",22,6,2019);

    setPrestamo(arrayPrestamos,0,1,2,3,2,12,2019);
    setPrestamo(arrayPrestamos,1,2,1,1,2,12,2019);
    setPrestamo(arrayPrestamos,2,3,1,2,1,12,2019);
    setPrestamo(arrayPrestamos,3,4,3,2,1,12,2019);
    setPrestamo(arrayPrestamos,4,5,5,4,3,12,2019);

    int option = 0;

    while(option != 10)
    {
        system("@cls||clear");
        printf("\n------------  MENU PRINCIPAL ------------");
        printf("\n------------      SOCIOS     ------------");
        option = getInt("\n1 - ALTA \n2 - MODIFICACION \n3 - BAJA \n4 - LISTAR \n5 - LISTAR LIBROS \n6 - LISTAR AUTORES \n7 - PRESTAMOS \n8 - INFORMAR Y LISTAR \n9 - SALIR \n\n\n");

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
//                listarSocios(arraySocios);
                break;
            case 5:
//                listarLibros(arrayLibros);
                break;
            case 6:
//                listarAutores(arrayAutores);
                break;
            case 7:
                altaPrestamo(arrayPrestamos,arrayAutores,arrayLibros,arraySocios);
                break;
            case 8:
                submenu(arrayAutores,arrayLibros,arrayPrestamos,arraySocios);
                break;
            case 9:
                exit(0);;
        }
    }

    return 0;
}

void submenu(eAutor arrayAutores[],eLibro arrayLibros[],ePrestamo arrayPrestamos[],eSocio arraySocios[])
{
    int option = getInt("\n1 - INFORMAR TOTAL GENERAL, PROMEDIO DIARIO Y CANTIDAD DE DIAS QUE MO SUPERAN DICHO PROMEDIO \n2 - LISTAR SOCIOS QUE SOLITARON PRESTAMO POR LIBRO DETERMINADO \n3 - LISTAR LIBROS SOLICITADOS POR SOCIO DETERMINADO \n4 - LISTAR LIBRO/S MENOS SOLICITADO/S A PRESTAMOS \n5 - LISTAR SOCIOS/S CON MAS SOLICITUDES A PRESTAMOS \n6 - LISTAR LIBROS SOLICITADOS A PRESTAMOS EN FECHA DETERMINADA \n7 - LISTAR SOCIOS CON SOLICITUDES A UNA FECHA DETERMINADA \n8 - LISTAR LIBROS ORDENADOS POR TITULOS DESCENDENTEMENTE - METODO DE BURBUJEO MAS EFICIENTE \n9 - LISTAR SOCIOS ORDENADOS POR APELLIDO ASCENDENTEMENTE - METODO DE INSERCCION \n10 - VOLVER AL MENU PRINCIPAL\n\n");
    float promedio;

    switch(option)
    {
        case 1:
            totalPrestamosYPromedio(arrayPrestamos);
            break;
        case 2:
            listarSociosSegunLibro(arrayPrestamos, arraySocios, arrayLibros);
            break;
        case 3:
            listarLibrosSegunSocio(arrayPrestamos, arraySocios, arrayLibros);
            break;
        case 4:
            libroMenosSolicitado(arrayPrestamos, arrayLibros);
            break;
        case 5:
            listarSociosMasSolic(arrayPrestamos, arraySocios);
            break;
        case 6:
            listarLibrosPorFecha(arrayPrestamos, arrayLibros);
            break;
        case 7:
            listarSociosPorPrestamosEnFecha(arraySocios,arrayPrestamos);
            break;
        case 8:
            listarTitulosDes(arrayLibros);
            break;
        case 9:
            listarApellidosAsc(arraySocios);
            break;
        case 10:
            return;
    }
}
