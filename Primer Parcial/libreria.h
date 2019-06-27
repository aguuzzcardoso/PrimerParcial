#define MAX 100

typedef struct {
    int codigo;
    char apellido[31];
    char nombre[31];
    int isEmpty;
} eAutor;

typedef struct{
    int codigo;
    char titulo[51];
    int codigoAutor;
    int isEmpty;
} eLibro;

typedef struct {
    int codigo;
    char apellido[31];
    char nombre[31];
    char sexo[1];
    char telefono[16];
    char email[31];
    int dia;
    int mes;
    int ano;
    int isEmpty;
} eSocio;

typedef struct {
    int codigoPrestamo;
    int codigoLibro;
    int codigoSocio;
    int dia;
    int mes;
    int ano;
    int isEmpty;
} ePrestamo;

int inicializar(eAutor arrayAutores[], eLibro arrayLibros[], eSocio arraySocios[], ePrestamo arrayPrestamos[]);

void setAutor(eAutor arrayAutores[], int indice, int id, char nombre[], char apellido[]);
void setLibro(eLibro arrayLibros[], int indice, int id, char titulo[], int codigoAutor);
void setSocio(eSocio arraySocios[], int indice, int id, char nombre[], char apellido[], char sexo[], char telefono[], char eMail[], int dia, int mes, int ano);
void setPrestamo(ePrestamo arrayPrestamos[], int indice, int id, int idLibro, int idSocio, int dia, int mes, int ano);

void altaSocio (eSocio arraySocios[]);
void modificarSocio (eSocio arraySocios[]);
void bajaSocio (eSocio arraySocios[]);
void listarSocios (eSocio arraySocios[]);
int buscarLibreSocio(eSocio arraySocios[]);
int buscarSocio(eSocio arraySocios[], int codigo);

void altaAutor (eAutor arrayAutores[]);
void modificacionAutor (eAutor arrayAutores[]);
void bajaAutor (eAutor arrayAutores[]);
void listarAutores (eAutor arrayAutores[]);
int buscarLibreAutor(eAutor arrayAutores[]);
int buscarAutor(eAutor arrayAutores[], int codigo);

void altaLibro (eLibro arrayLibros[], eAutor arrayAutores[]);
void modificacionLibro (eLibro arrayLibros[], eAutor arrayAutores[]);
void bajaLibro (eLibro arrayLibros[]);
void listarLibros (eSocio arrayLibros[]);
int buscarLibreLibro(eLibro arrayLibros[]);
int buscarLibro(eLibro arrayLibros[], int codigo);

void altaPrestamo (ePrestamo arrayPrestamos[], eAutor arrayAutores[], eLibro arrayLibros[], eSocio arraySocios[]);
int buscarLibrePrestamo(ePrestamo arrayPrestamos[]);

float totalPrestamosYPromedio(ePrestamo arrayPrestamo[]);
void diasNoSuperanPromedio(ePrestamo arrayPrestamo[], float promedio);
void listarSociosSegunLibro(ePrestamo arrayPrestamos[], eSocio arraySocios[], eLibro arrayLibros[]);
void listarLibrosSegunSocio(ePrestamo arrayPrestamos[],eSocio arraySocios[], eLibro arrayLibros[]);
void libroMenosSolicitado(ePrestamo arrayPrestamos[], eLibro arrayLibros[]);
void listarSociosMasSolic(ePrestamo arrayPrestamos[], eSocio arraySocios[]);
void listarLibrosPorFecha(ePrestamo arrayPrestamos[], eLibro arrayLibros[]);
void listarSociosPorPrestamosEnFecha(eSocio arraySocios[],ePrestamo arrayPrestamos[]);
void listarTitulosDes(eLibro arrayLibros[]);
void listarApellidosAsc(eSocio arraySocios[]);
