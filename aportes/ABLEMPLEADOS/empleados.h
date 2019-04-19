typedef struct{

    int dia;
    int mes;
    int anio;

}eFecha;


typedef struct{

    char nombre[20];
    char sexo;
    int legajo;
    float sueldo;
    int ocupado;
    eFecha fechaNac;


}eEmpleado;

int menu();
void pause();
int getNumero();
char getSexo();
void inicializarEmpleados(eEmpleado vec[],int tam);
void altaEmpleado(eEmpleado emp[], int tam);
int buscarLibre(eEmpleado vec[],int tam);
int buscarEmpleado(int legajo , eEmpleado vec[], int tam);
void mostrarEmpleado(eEmpleado emp);
void mostrarEmpleados(eEmpleado vec[], int tam);
void modificarEmpleado(eEmpleado vec[], int tam);
void bajaEmpleado(eEmpleado emp[],int tam);
int menuModificar();
char confirmarCambios();
