#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "utn.h"
#include "libreria.h"

int inicializar(eAutor arrayAutores[], eLibro arrayLibros[], eSocio arraySocios[], ePrestamo arrayPrestamos[])
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
            arrayPrestamos[i].isEmpty = 1;
        }
        return 0;
    }
}

void setAutor(eAutor arrayAutores[], int indice, int id, char nombre[], char apellido[])
{
    arrayAutores[indice].codigo = id;
    strcpy(arrayAutores[indice].nombre,nombre);
    strcpy(arrayAutores[indice].apellido,apellido);
    arrayAutores[indice].isEmpty = 0;

}

void setLibro(eLibro arrayLibros[], int indice, int id, char titulo[], int codigoAutor)
{
    arrayLibros[indice].codigo = id;
    strcpy(arrayLibros[indice].titulo, titulo);
    arrayLibros[indice].codigoAutor = codigoAutor;
    arrayLibros[indice].isEmpty = 0;
}

void setSocio(eSocio arraySocios[], int indice, int id, char nombre[], char apellido[], char sexo[], char telefono[], char eMail[], int dia, int mes, int ano)
{
    arraySocios[indice].codigo = id;
    strcpy(arraySocios[indice].nombre, nombre);
    strcpy(arraySocios[indice].apellido, apellido);
    strcpy(arraySocios[indice].sexo, sexo);
    strcpy(arraySocios[indice].telefono, telefono);
    strcpy(arraySocios[indice].email, eMail);
    arraySocios[indice].dia = dia;
    arraySocios[indice].mes = mes;
    arraySocios[indice].ano = ano;
    arraySocios[indice].isEmpty = 0;
}

void setPrestamo(ePrestamo arrayPrestamos[], int indice, int id, int idLibro, int idSocio, int dia, int mes, int ano)
{
    arrayPrestamos[indice].codigoPrestamo = id;
    arrayPrestamos[indice].codigoLibro = idLibro;
    arrayPrestamos[indice].codigoSocio = idSocio;
    arrayPrestamos[indice].dia = dia;
    arrayPrestamos[indice].mes = mes;
    arrayPrestamos[indice].ano = ano;
    arrayPrestamos[indice].isEmpty = 0;
}

void altaSocio (eSocio arraySocios[])
{
    int indice;
    int codigo;
    char apellido[31];
    char nombre[31];
    char sexo;
    char telefono[16];
    char email[31];
    int dia;
    int mes;
    int ano;

    indice = buscarLibreSocio(arraySocios);

    if(indice == -1)
    {
        printf("No hay lugar en el sistema\n\n");
        system("pause");
    }

    else
    {
        system("@cls||clear");
        printf("------------  ALTA SOCIO ------------\n");

        codigo = indice + 1;
        getValidString("Ingrese el nombre: ", "El nombre solamente puede contener letras.\n", nombre);
        getValidString("Ingrese el apellido: ","El nombre debe estar compuesto solo por letras\n", apellido);
        getValidSex("Ingrese |M| si es masculino o |F| si es femenino: ", "Debe ingresar el caracter correcto\n", sexo);
        getValidTelephono("Ingrese el telefono: ", "Debe ingresar un numero de telefono correcto\n", telefono);
        getValidEmail("Ingrese el eMail: ", "El eMail no puede contener caracteres especiales, ni espacios\n", email);
        dia = getValidInt("Ingrese el dia en que se asocio", "Ingrese un dia del 1 al 31\n",1,31);
        mes = getValidInt("Ingrese el mes en que se asocio", "Ingrese un mes del 1 al 12\n",1,12);
        ano = getValidInt("Ingrese el ano en que se asocio", "Ingrese un ano del 2000 al 2019\n",2000,2019);

        setSocio(arraySocios,indice,codigo,nombre,apellido,sexo,telefono,email,dia,mes,ano);
    }
}

void modificarSocio(eSocio arraySocios[]){
    int codigo;
    int index;

    char apellido[31];
    char nombre[31];
    char sexo;
    char telefono[16];
    char email[31];


    codigo = getValidInt("Ingrese el codigo del socio a modificar: ","El codigo del socio debe ser numerico\n", 1, MAX);
    index = buscarSocio(arraySocios, codigo);
    if(index == -1)
    {
        return;
    }

    getValidString("Ingrese el nombre: ", "El nombre solamente puede contener letras.\n", nombre);
    getValidString("Ingrese el apellido: ","El nombre debe estar compuesto solo por letras\n", apellido);
    getValidSex("Ingrese |M| si es masculino o |F| si es femenino: ", "Debe ingresar el caracter correcto\n", sexo);
    getValidTelephono("Ingrese el telefono: ", "Debe ingresar un numero de telefono correcto\n", telefono);
    getValidEmail("Ingrese el eMail: ", "El eMail no puede contener caracteres especiales, ni espacios\n", email);

    setSocio(arraySocios,index,codigo,nombre,apellido,sexo,telefono,email,arraySocios[index].dia,arraySocios[index].mes,arraySocios[index].ano);

}

void bajaSocio (eSocio arraySocios[])
{
    int codigo;
    int index;

    codigo = getValidInt("Ingrese el codigo del socio a modificar: ","El codigo del socio debe ser numerico\n", 1, MAX);
    index = buscarSocio(arraySocios, codigo);
    if(index == -1)
    {
        printf("\n\nNO SE ENCUENTRA ESE CODIGO\n");
        getChar("\n\nENTER (para continuar)");
    }
    else
    {
        arraySocios[index].isEmpty = 1;
        printf("El usuario ha sido dado de baja\n");
    }
}

int buscarLibreSocio(eSocio arraySocios[])
{
    for(int i=0; i < MAX; i++)
    {
        if(arraySocios[i].isEmpty == 1) {
            return i;
        }
    }
    return -1;
}

int buscarSocio(eSocio arraySocios[], int codigo)
{
    for(int i=0; i < MAX; i++)
    {
        if(arraySocios[i].isEmpty == 0 && arraySocios[i].codigo == codigo) {
            return i;
        }
    }
    printf("\n\nNO SE ENCUENTRA ESE CODIGO\n");
    getChar("\n\nENTER (para continuar)");
    return -1;
}

void altaAutor(eAutor arrayAutores[])
{
    int indice;
    int codigo;
    char apellido[31];
    char nombre[31];

    indice = buscarLibreAutor(arrayAutores);

    if(indice == -1)
    {
        printf("No hay lugar en el sistema\n\n");
        system("pause");
    }
    else
    {
        system("@cls||clear");
        printf("\n------------  ALTA AUTOR ------------");
        codigo = indice + 1;
        getValidString("Ingrese el nombre: ", "El nombre solamente puede contener letras.\n", nombre);
        getValidString("Ingrese el apellido: ","El nombre debe estar compuesto solo por letras\n", apellido);

        setAutor(arrayAutores,indice,codigo,nombre,apellido);
    }
}

void modificacionAutor(eAutor arrayAutores[])
{
    int codigo;
    int index;
    char apellido[31];
    char nombre[31];

    codigo = getValidInt("Ingrese el codigo del autor a modificar: ","El codigo del autor debe ser numerico\n", 1, MAX);
    index = buscarAutor(arrayAutores, codigo);

    if(index == -1)
    {
        return;
    }

    getValidString("Ingrese el nombre: ", "El nombre solamente puede contener letras.\n", nombre);
    getValidString("Ingrese el apellido: ","El nombre debe estar compuesto solo por letras\n", apellido);
    setAutor(arrayAutores,index,codigo,nombre,apellido);
}

void bajaAutor(eAutor arrayAutores[])
{
    int codigo;
    int index;

    codigo = getValidInt("Ingrese el codigo del autor a borrar: ","El codigo del autor debe ser numerico\n", 1, MAX);
    index = buscarAutor(arrayAutores, codigo);

    if(index == -1)
    {
        printf("\n\nNO SE ENCUENTRA ESE CODIGO\n");
        getChar("\n\nENTER (para continuar)");
    }
    else
    {
        arrayAutores[index].isEmpty = 1;
        printf("El autor ha sido dado de baja\n");
    }
}

int buscarLibreAutor(eAutor arrayAutores[])
{
    for(int i=0; i < MAX; i++)
    {
        if(arrayAutores[i].isEmpty == 1) {
            return i;
        }
    }
    return -1;
}

int buscarAutor(eAutor arrayAutores[], int codigo)
{
    for(int i=0; i < MAX; i++)
    {
        if(arrayAutores[i].isEmpty == 0 && arrayAutores[i].codigo == codigo) {
            return i;
        }
    }
    printf("\n\nNO SE ENCUENTRA ESE CODIGO \n");
    getChar("\n\nENTER (para continuar)");
    return -1;
}

void altaLibro(eLibro arrayLibros[], eAutor arrayAutores[])
{
    int indiceLibro;
    int codigoLibro;
    int indiceAutor;
    int codigoAutor;
    char titulo[51];

    indiceLibro = buscarLibreLibro(arrayLibros);

    if(indiceLibro == -1)
    {
        printf("No hay lugar en el sistema\n\n");
        system("pause");
    }
    else
    {
        system("@cls||clear");
        printf("\n------------  ALTA LIBRO ------------");
        codigoLibro = indiceLibro + 1;
        getValidString("Ingrese el nombre del libro : ", "El nombre del libro solamente puede contener letras.\n", titulo);
        codigoAutor = getValidInt("Ingrese el codigo del autor: ","El codigo del autor debe ser numerico\n", 1, MAX);
        indiceAutor = buscarAutor(arrayAutores, codigoAutor);

        if(indiceAutor == -1)
        {
            printf("\n\nNO SE ENCUENTRA ESE CODIGO\n");
            getChar("\n\nENTER (para continuar)");
        }
        else
        setLibro(arrayLibros,indiceLibro,codigoLibro,titulo,codigoAutor);
    }
}

void modificacionLibro(eLibro arrayLibros[], eAutor arrayAutores[])
{
    int codigoLibro;
    int indiceLibro;
    int indiceAutor;
    char titulo[51];
    int codigoAutor;

    codigoLibro = getValidInt("Ingrese el codigo del libro a modificar: ","El codigo del libro debe ser numerico\n", 1, MAX);
    indiceLibro = buscarLibro(arrayLibros, codigoLibro);

    if(indiceLibro == -1)
        return;

    system("@cls||clear");
    printf("\n------------  MODIFICACION LIBRO ------------");
    getValidString("Ingrese el nombre del libro : ", "El nombre del libro solamente puede contener letras.\n", titulo);
    codigoAutor = getValidInt("Ingrese el codigo del autor: ","El codigo del autor debe ser numerico\n", 1, MAX);
    indiceAutor = buscarAutor(arrayAutores, codigoAutor);

    if(indiceAutor== -1)
    {
        printf("\n\nNO SE ENCUENTRA ESE CODIGO\n");
        getChar("\n\nENTER (para continuar)");
    }
    else
    setLibro(arrayLibros,indiceLibro,codigoLibro,titulo,codigoAutor);

}

void bajaLibro (eLibro arrayLibros[])
{
    int codigo;
    int index;

    codigo = getValidInt("Ingrese el codigo del libro a borrar: ","El codigo del autor debe ser numerico\n", 1, MAX);
    index = buscarLibro(arrayLibros, codigo);

    if(index == -1)
    {
        printf("\n\nNO SE ENCUENTRA ESE CODIGO\n");
        getChar("\n\nENTER (para continuar)");
    }
    else
    {
        arrayLibros[index].isEmpty = 1;
        printf("El libro ha sido dado de baja\n");
    }
}

int buscarLibreLibro(eLibro arrayLibros[])
{
    for(int i=0; i < MAX; i++)
    {
        if(arrayLibros[i].isEmpty == 1) {
            return i;
        }
    }
    return -1;
}

int buscarLibro(eLibro arrayLibros[], int codigo)
{
    for(int i=0; i < MAX; i++)
    {
        if(arrayLibros[i].isEmpty == 0 && arrayLibros[i].codigo == codigo) {
            return i;
        }
    }
    printf("\n\nNO SE ENCUENTRA ESE CODIGO\n");
    getChar("\n\nENTER (para continuar)");
    return -1;
}

void altaPrestamo (ePrestamo arrayPrestamos[], eAutor arrayAutores[], eLibro arrayLibros[], eSocio arraySocios[])
{
    int indice;

    ePrestamo nuevoPrestamo;

    system("@cls||clear");
    printf("------ ALTA PRESTAMO -------\n\n");

    indice = buscarLibrePrestamo(arrayPrestamos);
    if(indice == -1)
    {
        printf("No hay lugar para prestamos\n");
        system("pause");
    }
    else
    {
        nuevoPrestamo.codigoPrestamo = indice +1;
        nuevoPrestamo.codigoLibro = getValidInt("Ingrese el codigo del libro: ", "El codigo puede contener solamente numeros\n",1,MAX);
        nuevoPrestamo.codigoLibro = buscarLibro(arrayLibros, nuevoPrestamo.codigoLibro);

        if(nuevoPrestamo.codigoLibro == -1)
        {
            printf("\nEl codigo ingresado es incorrecto.\n");
            system("pause");

        }
        else
        {   nuevoPrestamo.codigoLibro ++;
            nuevoPrestamo.codigoSocio = getValidInt("Ingrese el codigo del socio: ", "El codigo puede contener solamente numeros\n", 1, MAX);
            nuevoPrestamo.codigoSocio = buscarSocio(arraySocios, nuevoPrestamo.codigoSocio);
            if(nuevoPrestamo.codigoSocio == -1)
            {
                printf("\nEl codigo ingresado es incorrecto.\n");
                system("pause");
            }
            else
            {
                nuevoPrestamo.dia = getValidInt("Ingrese el dia del prestamo: ", "El dia puede contener solamente numeros\n", 1, 31);
                nuevoPrestamo.mes = getValidInt("Ingrese el mes del prestamo: ", "El mes puede contener solamente numeros\n", 1, 12);
                nuevoPrestamo.ano = getValidInt("Ingrese el ano del prestamo: ", "El ano puede contener solamente numeros\n", 2000, 2019);
                arrayPrestamos[indice] = nuevoPrestamo;
                printf("---- PRESTAMO APROBADO ----");
                system("pause");
            }
        }
    }
}

int buscarLibrePrestamo(ePrestamo arrayPrestamos[])
{
    for(int i=0; i < MAX; i++)
    {
        if(arrayPrestamos[i].isEmpty == 1) {
            return i;
        }
    }
    return -1;
}

float totalPrestamosYPromedio(ePrestamo arrayPrestamos[])//1
{
    float total = 0;
    float cantDias = 0;
    ePrestamo aux;
    ePrestamo listado[MAX];
    int i,j;

    for(i=0; i < MAX; i++)
        listado[i] = arrayPrestamos[i];

    // ordenar prestamos por fecha
    for (i=0; i < MAX-1; i++)
    {
        for(j=i+1; j < MAX; j++)
        {
            if((listado[i].ano > listado[j].ano) ||
               (listado[i].ano == listado[j].ano && listado[i].mes > listado[j].mes) ||
               (listado[i].ano == listado[j].ano && listado[i].mes == listado[j].mes && listado[i].dia > listado[j].dia))
            {
                aux = listado[i];
                listado[i] = listado[j];
                listado[j] = aux;
            }
        }
    }

    for (i=0; i < MAX; i++)
    {
        if (listado[i].isEmpty == 1)
            continue;

        total++;
        if (i == 0 || listado[i].ano != listado[i-1].ano
            || listado[i].mes != listado[i-1].mes || listado[i].dia != listado[i-1].dia)
        {
            cantDias++;
        }
    }

    float promedio = total / cantDias;

    int contadorMayorQuePromedio = 0;
    int contadorPorDia;
    int flagYaContado = 0;
    int diaAux = 0;
    int mesAux = 0;
    int anoAux = 0;

    for (i=0; i < MAX; i++)
    {
        if (listado[i].isEmpty == 1)
            continue;

        if (listado[i].ano != anoAux || listado[i].mes != mesAux || listado[i].dia != diaAux)
        {
            contadorPorDia = 1;
            flagYaContado = 0;
            diaAux = listado[i].dia;
            mesAux = listado[i].mes;
            anoAux = listado[i].ano;
        }
        else if (flagYaContado == 1)
        {
            continue;
        }
        else
        {
            contadorPorDia++;
            if (contadorPorDia > promedio) {
                contadorMayorQuePromedio++;
                flagYaContado = 1;
            }
        }
    }

    printf("Total de prestamos: %.0f\n", total);
    printf("Promedio: %.2f\n", promedio);
    printf("Dias que se supera el promedio: %i\n", contadorMayorQuePromedio);
    system("pause");
    return promedio;
}

void diasNoSuperanPromedio(ePrestamo arrayPrestamo[], float promedio)//2
{
}

void listarSociosSegunLibro(ePrestamo arrayPrestamos[], eSocio arraySocios[], eLibro arrayLibros[])//3
{
    int i,j;
    int flag=0;

    int codigoLibro = getValidInt("Ingrese el codigo del libro: ","El codigo del libro debe ser un numero valido. ",1,MAX);
    int indiceLibro = buscarLibro(arrayLibros,codigoLibro);


    for (i=0; i < MAX; i++)
    {
        for(j=0; j < MAX; j++)
        {
            if (arrayPrestamos[j].codigoSocio == arraySocios[i].codigo && codigoLibro == arrayPrestamos[j].codigoLibro)
            {
                flag=1;
                printf("El socio %s solicito el libro.\n", arraySocios[i].nombre);
                break;
            }
        }
    }

    if(flag==0)
    {
        printf("El libro no fue solicitado.\n");
    }
    system("pause");
}

void listarLibrosSegunSocio(ePrestamo arrayPrestamos[],eSocio arraySocios[], eLibro arrayLibros[])//4
{
    int hayResultado = 0;
    int i,j;

    int codigoSocio = getValidInt("Ingrese el codigo del socio: ","El codigo puede contener solamente numeros\n", 1, MAX);
    int indiceSocio = buscarSocio(arraySocios,codigoSocio);

    for (i=0; i < MAX; i++)
    {
        for(j=0; j < MAX; j++)
        {
            if (codigoSocio == arrayPrestamos[j].codigoSocio && arrayLibros[i].codigo == arrayPrestamos[j].codigoLibro)
            {
                hayResultado=1;
                printf("El libro %s fue solicitado.\n", arrayLibros[i].titulo);
                break;
            }
        }
    }

    if (hayResultado == 0) {
        printf("El socio no retiro libros\n");
    }
    system("pause");
}
void libroMenosSolicitado(ePrestamo arrayPrestamos[],eLibro arrayLibros[])//5
{
    int i,j;
    int minimo=MAX, contador;
    for (i=0; i < MAX; i++)
    {
        if(arrayLibros[i].isEmpty == 1)
            continue;

        contador=0;
        for (j=0; j < MAX; j++)
        {
            if(arrayLibros[i].codigo == arrayPrestamos[j].codigoLibro)
                contador++;
        }
        if(contador < minimo)
            minimo = contador;
    }
    printf("Libros menos solicitados: \n");
    for (i=0; i < MAX; i++)
    {
        if(arrayLibros[i].isEmpty == 1)
            continue;

        contador=0;
        for (j=0; j < MAX; j++)
        {
            if(arrayLibros[i].codigo == arrayPrestamos[j].codigoLibro)
                contador++;
        }
        if(contador == minimo)
            printf("%s\n",arrayLibros[i].titulo);
    }
    system("pause");
}
void listarSociosMasSolic(ePrestamo arrayPrestamos[],  eSocio arraySocios[])//6
{
    int i,j;
    int maximo=0, contador;
    for (i=0; i < MAX; i++)
    {
        if(arraySocios[i].isEmpty == 1)
            continue;

        contador=0;
        for (j=0; j < MAX; j++)
        {
            if(arraySocios[i].codigo == arrayPrestamos[j].codigoSocio)
                contador++;
        }
        if(contador > maximo)
            maximo = contador;
    }
    printf("Socios con mas solicitudes: \n");
    for (i=0; i < MAX; i++)
    {
        if(arraySocios[i].isEmpty == 1)
            continue;

        contador=0;
        for (j=0; j < MAX; j++)
        {
            if(arraySocios[i].codigo == arrayPrestamos[j].codigoLibro)
                contador++;
        }
        if(contador == maximo)
            printf("%s %s\n",arraySocios[i].nombre, arraySocios[i].apellido);
    }
    system("pause");
}

void listarLibrosPorFecha(ePrestamo arrayPrestamos[], eLibro arrayLibros[])//7
{
    int i,j,flag=0;

    int dia = getValidInt("Ingrese el dia de la fecha de solicitud a prestamo: ","El dia solicitado no es correcto.",1,31);
    int mes = getValidInt("Ingrese el mes de la fecha de solicitud a prestamo: ","El mes solicitado no es correcto.",1,12);
    int ano = getValidInt("Ingrese el ano de la fecha de solicitud a prestamo: ","El ano solicitado no es correcto.",2000,2019);

    for (i = 0; i < MAX; i++)
    {
        for(j=0; j < MAX; j++)
        {
            if(arrayPrestamos[j].dia == dia && arrayPrestamos[j].mes == mes && arrayPrestamos[j].ano == ano && arrayPrestamos[j].codigoLibro == arrayLibros[i].codigo)
            {
                flag=1;
                printf("Esa fecha el libro %s fue solicitado.\n", arrayLibros[i].titulo);
                break;
            }
        }
    }

    if(flag==0)
    {
        printf("En la fecha solicitada, ningun socio solicito un prestamo.");
    }
    system("pause");
}

void listarSociosPorPrestamosEnFecha(eSocio arraySocios[],ePrestamo arrayPrestamos[])//8
{
    int i,j,flag=0;

    int dia = getValidInt("Ingrese el dia de la fecha de solicitud a prestamo: ","El dia solicitado no es correcto.",1,31);
    int mes = getValidInt("Ingrese el mes de la fecha de solicitud a prestamo: ","El mes solicitado no es correcto.",1,12);
    int ano = getValidInt("Ingrese el ano de la fecha de solicitud a prestamo: ","El ano solicitado no es correcto.",2000,2019);

    for (i = 0; i < MAX; i++)
    {
        for(j=0; j < MAX; j++)
        {
            if(arrayPrestamos[j].dia == dia && arrayPrestamos[j].mes == mes && arrayPrestamos[j].ano == ano && arrayPrestamos[j].codigoSocio == arraySocios[i].codigo)
            {
                flag=1;
                printf("Esa fecha el socio %s solicito un prestamo.\n", &arraySocios[i].nombre);
                break;
            }
        }
    }

    if(flag==0)
    {
        printf("En la fecha solicitada, ningun socio solicito un prestamo.");
    }
    system("pause");
}

void listarTitulosDes(eLibro arrayLibros[])//9
{
    int j,i;
    eLibro aux;
    eLibro listado[MAX];

    for(i=0; i < MAX; i++)
    {
        listado[i] = arrayLibros[i];
    }

    int len = MAX;

    int flagNoEstaOrdenado = 1;

    while (flagNoEstaOrdenado==1)
    {
        flagNoEstaOrdenado = 0;
        for (j = 1; j < len; j++)
        {
            if (strcmp(listado[j].titulo, listado[j-1].titulo) > 0)
            {
                aux = listado[j];
                listado[j] = listado[j-1];
                listado[j-1] = aux;
                flagNoEstaOrdenado = 1;
            }
        }
        len--;
    }

    printf("---Titulos ordenados descendentemente---\n");
    for (j = 0; j < MAX; j++)
        if(listado[j].isEmpty == 0)
        {
            printf("%s\n", listado[j].titulo);
        }
    system("pause");
}

void listarApellidosAsc(eSocio arraySocios[])//10
{
    int i,j;

    eSocio socio;
    eSocio listado[MAX];

    for(i=0; i < MAX; i++)
    {
        listado[i] = arraySocios[i];
    }

    for(i=1; i<MAX; i++)
    {
        socio = listado[i];
        j=i-1;
        while(j>=0 && strcmp(socio.apellido,listado[j].apellido) < 0)
        {
            listado[j+1] = listado[j];
            j--;
        }
        listado[j+1]=socio; // inserción
    }

    printf("---Apellidos ordenados ascendentemente---\n");
    printf("Codigo   Apellido   Nombre  \n");



    for (j = 0; j < MAX; j++)
    {
        if(listado[j].isEmpty == 0)
        {
            printf("   %i      %s\t%s\n", listado[j].codigo, listado[j].apellido, listado[j].nombre);
        }
    }
    system("pause");
}
