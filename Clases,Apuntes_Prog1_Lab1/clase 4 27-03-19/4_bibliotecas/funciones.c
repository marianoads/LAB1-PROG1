/* Funcion usada para verificar el ingreso de caracteres.Chequea para que
solo sean admitidas las letras S o N.
Se ingresa void y devuelve un entero sin signo
0 si se ingreso la N
1 si se ingreso la S
*/
unsigned int verifica(void){
    char letra;

    printf("\nIngrese opcion...S/N?");

    letra = toupper( getche() );

    while( !((letra=='S')||(letra=='N')) ){
        printf("\nHa ingresado opci¢n no valida...Reintente el ingreso(S/N)... ");
        letra = toupper( getche() );
    }

    return ( letra == 'S' );
}
