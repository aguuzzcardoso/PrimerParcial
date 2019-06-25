#define MAX 100

typedef struct {
    int codigo;
    char apellido[31];
    char nombre[31];
    int isEmpty;
} eAutores;

typedef struct{
    int codigo;
    char titulo;
    int codigoAutor;
    int isEmpty;
} eLibros;

typedef struct {
    int codigo;
    char apellido[31];
    char nombre[31];
    char sexo;
    char telefono[16];
    char email[31];
    int dia;
    int mes;
    int ano;
    int isEmpty;
} eSocios;

typedef struct {
    int codigoPrestamo;
    int codigoLibro;
    int codigoSocio;
    int dia;
    int mes;
    int ano;
    int isEmpty;
} ePrestamos;

int inicializar(eAutores arrayAutores[], eLibros arrayLibros[], eSocios arraySocios[]);

void setAutor(eAutores arrayAutores[], int indice, int idAux, char nombreAux[], char apellidoAux[], int isEmptyAux);
void setLibro(eLibros arrayLibros[], int indice, int idAux, char tituloAux[], int codigoAutorAux,int isEmptyAux);
void setSocio(eSocios arraySocios[], int indice, int idAux, char nombreAux[], char apellidoAux[], char sexoAux, char telefonoAux[], char eMailAux[], int diaAux, int mesAux, int anoAux, int isEmptyAux);


void altaSocio (eSocios arraySocios[]);
void modificarSocio (eSocios arraySocios[]);
void bajaSocio (eSocios arraySocios[]);
void listarSocios (eSocios arraySocios[]);
void listarLibros (eSocios arrayLibros[]);
void listarAutores (eSocios arrayAutores[]);
// void altaPrestamo (arrayPrestamos[]);

int buscarLibre(eSocios arraySocios[]);
