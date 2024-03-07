#include <stdio.h>
#include <stdlib.h>
/** Escribe un programa en C para gestionar una lista de contactos**/
/**Se utiliza struct para hacer esta estructura de datos, lo que hace es reunir un grupo de variables con similitud**/
struct contact {
    /**Se tienen estas variables tipo chart para poder determinar el nombre, el numero de telefono y el correo con unas limitaciones de 51 y 21 caracteres**/
    char nom[51];

    char cell[21];

    char email[51];
};

/** Se utiliza la funcion void para que se pueda agregar un numero de telefono**/
void agregar_contact(struct contact lista[], int *numcontact) {
    if (*numcontact < 5) { /** Esta lista se limita a 5 contactos**/
/**Imprimimos para ingresar el nombre del contacto**/
        printf("Escribe su nombre: ");
        /**escaneamos y con ayuda del puntero se pasa a la lista de contactos**/
        scanf("%50s", lista[*numcontact].nom);
        /**Se pide el numero y tambien se imprime para ingresarlo**/
        printf("Escribe el numero de telefono: ");
        scanf("%20s", lista[*numcontact].cell);
        /**De igual manera se pide el correo y tambien se im`rime para ingresarlo**/
        printf("Dame el correo electronico: ");
        scanf("%50s", lista[*numcontact].email);
        /**Aqui se dice que la lista va a ir aumentando**/
        (*numcontact)++;
        printf("El contacto se agrego correctamente.\n");
    } else {
        /**Ya que la lista esta limitada a 5 contactos imprimimos para decir que esta llena**/
        printf("La lista de contactos esta llena.\n");
    }
}

/** Ponemos nuevamente la función void para mostrar todos los contactos**/
void mostrarcontact(struct contact lista[], int numcontact) {
    printf("Lista de contactos:\n");
    /**Utilizamos el bucle for para poder ingresar la lista de los datos del mismo contacto**/
    for (int i = 0; i < numcontact; i++) {
        printf("Contacto %d:\n", i + 1);
        printf("Nombre: %s\n", lista[i].nom);
        printf("Teléfono: %s\n", lista[i].cell);
        printf("Correo: %s\n", lista[i].email);
        printf("\n");
    }
}
/**Comenzamos con la funcion principal para poder mostrat los datos puestos en la funcion**/
int main() {
    struct contact listacontact[5];/**Agregamos la lista de contactos**/
    int numcontact = 0; /**Agregamos el numero de contactos**/

    int option;
    /**Utilizamos do para cear el menu en el que vamos a ingresar los datos**/
    do {
        printf("Menú:\n");
        printf("1_Agregar contacto\n");
        printf("2_Mostrar contactos\n");
        printf("3_Salir\n");
        printf("Elige una opcion: ");
        scanf("%d", &option);
/**Utilizamos switch para mostrar las opciones validas e invalidas**/
        switch (option) {
            case 1:
                agregar_contact(listacontact, &numcontact);
                break;
            case 2:
                mostrarcontact(listacontact, numcontact);
                break;
            case 3:
                printf("Gracias por tu colaboracion\n");
                break;
            default:
                printf("Intentelo de nuevo.\n");
        }
        /**Utilizamos el bucle while para limitar las tres opciones de los datos ingresados**/
    } while (option != 3);

    return 0;
}

