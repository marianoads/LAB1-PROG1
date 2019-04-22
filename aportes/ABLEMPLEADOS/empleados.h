typedef struct{

    int dia;
    int mes;
    int anio;

}eFecha;


typedef struct{

    int legajo;
    char nombre[20];
    char sexo;
    float sueldo;
    int ocupado;
    int idSector;
    eFecha fechaNac;


}eEmpleado;

typedef struct{

    int id;
    char descripcion[31];


}eSector;

int menu();
void pause();
int getNumero();
char getSexo();
void inicializarEmpleados(eEmpleado vec[],int tam);
void altaEmpleado(eEmpleado emp[], int tam);
int buscarLibre(eEmpleado vec[],int tam);
int buscarEmpleado(int legajo , eEmpleado vec[], int tam);
void obtenerSector(eSector sector[], int tam, int id, char desc[]);
void mostrarEmpleado(eEmpleado emp, eSector sectores, int tam );
void mostrarEmpleados(eEmpleado vec[], int tam);
void modificarEmpleado(eEmpleado vec[], int tam);
void bajaEmpleado(eEmpleado emp[],int tam);
void ordenarEmpleados(eEmpleado emp[],int tam, int flag);
int menuModificar();
char confirmarCambios();
