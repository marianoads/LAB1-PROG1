typedef struct{

    int dia;
    int mes;
    int anio;

}eFecha;
typedef struct{

    int legajo; //autoincremental
    char nombre[55];
    char apellido[55];
    char sexo;
    float salario;
    eFecha fechaIngreso;
    int idSector;
    int isEmpty;


}eEmpleado;

typedef struct{

    int id; // autoincremental
    char descripcion[51];

}eSector;

typedef struct{
    int codigoAlmuerzo;
    int codigoMenu; //fk
    int legajoEmpleado; //fk
    int isEmpty;
    eFecha fecha;


}eAlmuerzo;


typedef struct{

    int codigoMenu;//autoincremental
    char descripcion[51];
    int importe;
}eMenu;

int menuComedor();
//void pause();
void inicializarSector(eSector sectores[], int tam);
void inicializarMenues(eMenu  menu[], int tam);
void inicializarEmpleados(eEmpleado empleado[] , int tam);
void inicializarAlmuerzos(eAlmuerzo almuerzo [], int tam);
int buscarEspacioEnElSistema(eEmpleado empleado[], int tam);
int buscarEspacionEnElRegistro(eAlmuerzo almuerzo[], int tam);
int buscarMenu(eMenu menu[], int tamMenu, int codigoMenu);
char opcionSalir();
void altaEmpleado(eEmpleado empleado[] , int tamEmpleado, eSector sector[],int tamSector);
void altaAlmuerzo(eEmpleado empleado[], int tamEmpleado, eMenu menu[], int tamMenu, eAlmuerzo almuerzo[], int tamAlmuerzo, eSector sector[], int tamSector);
int asignarSector(eSector sector[], int tamSector, char descripcion[], int idSector);
void asignarLegajo(eEmpleado empleado[] , int tam, int indice);
void asignarCodigoAlmuerzo(eAlmuerzo almuerzo[], int tamAlmuerzo, int indice);
int menuModificar();
void modificarEmpleado(eEmpleado empleado[] , int tamEmpleado);
void modificarNombre(eEmpleado empleado[], int tam );
void modificarApellido(eEmpleado empleado[], int tam);
void modificarFechaDeIngreso(eEmpleado empleado[] , int tam);
void modificarSalario(eEmpleado empleado[], int tam);
void modificarSector(eEmpleado empleado[], int tam );
void modificarSexo(eEmpleado empleado[], int tam);
void bajaEmpleado(eEmpleado empleado[] , int tam);
void mostrarEmpleado(eEmpleado empleado, eSector sector[], int tamSector);
void listarEmpleados(eEmpleado empleado[], int tamEmpleado, eSector sector[], int tamSector);
void listarEmpleadosPorSector(eEmpleado empleado[], int tamEmpleado, eSector sector[], int tamSector);
void listarMenues(eMenu menu[], int tamMenu);
void listadoMenuPorEmpleado ( eEmpleado empleados[], eMenu menues[], eAlmuerzo almuerzos[], int cantEmp, int cantMenu );
