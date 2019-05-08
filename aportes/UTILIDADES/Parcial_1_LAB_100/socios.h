typedef struct{

    int dia;
    int mes;
    int anio;

}eFecha;

typedef struct{
    int codigoAutor;
    char apellido[31];
    char nombre[31];

}eAutores;

typedef struct{
    int codigoLibro;
    char titulo[51];
    int codigoAutor;


}eLibros;

typedef struct{
   int codigoSocio;
   char apellido[40];
   char nombre[40];
   char sexo;
   char telefono[40];
   char email[40];
   int isEmpty;
   eFecha fechaAsociado;

}eSocios;

typedef struct{
    int codigoPrestamo;
    int codigoLibro;
    int codigoSocio;
    eFecha fechaPrestamo;
    int isEmpty;


}ePrestamos;

void initAutores(eAutores autores[], int tamAutores);
void initLibros(eLibros libros[], int tamLibros);
void initSocios(eSocios socios[] , int tamSocios);
void initPrestamos(ePrestamos prestamos[], int tamPrestamos);
void altaPrestamo(ePrestamos prestamos[], int tamPrestamo, eSocios socios[], int tamSocios, eLibros libros[], int tamLibros);
int menuBiblioteca();
int buscarEspacioEnElSistema(eSocios socios[], int tamSocios);
void asignarCodigoSocio(eSocios socios[] , int tamSocios, int indice);
void altaSocio(eSocios socios[], int tamSocios);
int buscarSocio(eSocios socios[], int tamSocio, int codigoSocio);
int buscarPrestamos(ePrestamos prestamos[], int tamPrestamos);
void altaPrestamo(ePrestamos prestamos[], int tamPrestamo, eSocios socios[], int tamSocios, eLibros libros[], int tamLibros);
void bajaSocio(eSocios socios[], int tamSocio);
void mostrarSocios(eSocios socios, int tamSocios);
void listarSocios(eSocios socios[], int tamSocios);
void listarAutores(eAutores autores[], int tamAutores);
void listarLibros(eLibros libros[], int tamLibros);
void modificarSocio(eSocios socios[], int tamSocios);
void modificarApellido(eSocios socios[], int tamSocios, int indice);
void modificarNombre(eSocios socios[], int tamSocios, int indice);
void modificarSexo(eSocios socios[], int tamSocios, int indice);
void modificarTelefono(eSocios socios[], int tamSocios, int indice);
void modificarEmail(eSocios socios[], int tamSocios, int indice);
int menuModificar();
