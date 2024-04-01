/*
Desafio 1
Presentado y desarrollado por:
Marcos Jardel Murillo Hernández - C.C.1017238240
Juan Escalante
*/

#include <iostream>
#include <math.h>

using namespace std;

int main ()
{
    int opcion = 1;
    cout << "************Solucion Desafio 1************" << endl;
    while (opcion != 0)
    {
        cout << endl;
        cout << "Seleccione una opcion:" << endl;
        cout << "1.  Creacion de estructuras de tamanio variable" << endl;
        cout << "2.  Rotacion de estructuras de datos" << endl;
        cout << "3.  Configurar cerraduras en cantidad y tamanio" << endl;
        cout << "4.  Validar regla de apertura sobre la cerradura" << endl;
        cout << "5.  Generar configuracion para generar regla" << endl;
        cout << "0. Para SALIR!" << endl;
        cin >> opcion;
        switch(opcion)
        {
        case 1:
        {

            break;
        }
        case 2:
        {

            break;
        }
        case 3:
        {

            break;

        }
        case 4:
        {

            break;
            }
        case 5:
        {



            break;
        }

        default:
            if(opcion != 0)
                cout << "Seleccione una opcion valida!!!!" << endl;
        }
    }
    return 0;
}

