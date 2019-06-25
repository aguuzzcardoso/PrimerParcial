#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "utn.h"
#include "libreria.h"

int inicializar(eAutores arrayAutores[], eLibros arrayLibros[], eSocios arraySocios[])
{
    if (MAX < 0){
        return -1;
    }
    else {
        for(int i=0; i < MAX; i++)
        {
            arrayAutores[i].isEmpty = 1;
            arrayLibros[i].isEmpty = 1;
            arraySocios[i].isEmpty = 1;
        }
        return 0;
    }
}

void setAutor(eAutores arrayAutores[], int indice, int idAux, char nombreAux[], char apellidoAux[],int isEmptyAux)
{
    arrayAutores[indice].codigo = idAux;
    strcpy(arrayAutores[indice].nombre,nombreAux);
    strcpy(arrayAutores[indice].apellido,apellidoAux);
    arrayAutores[indice].isEmpty = isEmptyAux;
}

void setLibro(eLibros arrayLibros[], int indice, int idAux, char tituloAux[], int codigoAutorAux, int isEmptyAux)
{
    arrayLibros[indice].codigo = idAux;
    strcpy(arrayLibros[indice].titulo, tituloAux);
    arrayLibros[indice].codigoAutor = codigoAutorAux;
    arrayLibros[indice].isEmpty = isEmptyAux;
}

void setSocio(eSocios arraySocios[], int indice, int idAux, char nombreAux[], char apellidoAux[], char sexoAux, char telefonoAux[], char eMailAux[], int diaAux, int mesAux, int anoAux, int isEmptyAux)
{
    arraySocios[indice].codigo = idAux;
    strcpy(arraySocios[indice].nombre, nombreAux);
    strcpy(arraySocios[indice].apellido, apellidoAux);
    strcpy(arraySocios[indice].sexo, sexoAux);
    strcpy(arraySocios[indice].telefono, telefonoAux);
    strcpy(arraySocios[indice].email, eMailAux);
    arraySocios[indice].dia = diaAux;
    arraySocios[indice].mes = mesAux;
    arraySocios[indice].ano = anoAux;
    arraySocios[indice].isEmpty = 0;
}

void altaSocio (eSocios arraySocios[])
{
    int indice;
    int codigoAux;
    char apellidoAux[31];
    char nombreAux[31];
    char sexoAux;
    char telefonoAux[16];
    char emailAux[31];
    int diaAux;
    int mesAux;
    int anoAux;

    indice = buscarLibre(arraySocios);

    if(indice == -1)
    {
        printf("No hay lugar en el sistema\n\n");
        system("pause");
    }

    else
    {
        system("@cls||clear");
        printf("\n------------  ALTA AUTOR ------------");

        codigoAux = indice + 1;
        getValidString("Ingrese el nombre: ", "El nombre solamente puede contener letras.\n", nombreAux);
        getValidString("Ingrese el apellido: ","El nombre debe estar compuesto solo por letras\n", apellidoAux);
        getValidSex("Ingrese |M| si es masculino o |F| si es femenino: ", "Debe ingresar el caracter correcto\n", sexoAux);
        getValidTelephono("Ingrese el telefono: ", "Debe ingresar un numero de telefono correcto\n", telefonoAux);
        getValidEmail("Ingrese el eMail: ", "El eMail no puede contener caracteres especiales, ni espacios\n", emailAux);
        diaAux = getValidInt("Ingrese el dia en que se asocio", "Ingrese un dia del 1 al 31\n",1,31);
        mesAux = getValidInt("Ingrese el mes en que se asocio", "Ingrese un mes del 1 al 12\n",1,12);
        anoAux = getValidInt("Ingrese el ano en que se asocio", "Ingrese un ano del 2000 al 2019\n",2000,2019);

        setSocio(arraySocios,indice,codigoAux,nombreAux,apellidoAux,sexoAux,telefonoAux,emailAux,diaAux,mesAux,anoAux,1);
    }
}


int buscarLibre(eSocios arraySocios[])
{
    int indice = -1;

    for(int i=0; i < MAX; i++)
    {

        if(arraySocios[i].isEmpty == 1)
        {
            indice = i;
            break;
        }
    }
    return indice;
}
