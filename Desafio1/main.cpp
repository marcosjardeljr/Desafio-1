/*
Desafio 1
Presentado y desarrollado por:
Marcos Jardel Murillo Hernández - C.C.1017238240
Juan Escalante
*/

#include <iostream>
#include <math.h>
#include <vector>

using namespace std;
int** generarMatriz(int);
void imprimirMatriz(int**, int );
void liberarMemoria(int**, int);

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
            int n;
                cout << "Ingrese un numero impar para el tamanio de la matriz: ";
                cin >> n;

                // Verificar si el tamaño ingresado es impar, si no, pedir al usuario que ingrese nuevamente
                while (n % 2 == 0) {
                    cout << "El tamaño de la matriz debe ser un numero impar. Ingrese nuevamente: ";
                    cin >> n;
                }

                // Generar la matriz
                int **matriz = generarMatriz(n);

                // Imprimir la matriz
                imprimirMatriz(matriz, n);

                // Liberar la memoria
                liberarMemoria(matriz, n);
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


// Función para generar la matriz con un tamaño dado
int** generarMatriz(int n) {
    int **MATRIZ; // Declaración de la matriz como puntero doble

    // Reservar memoria para las filas
    MATRIZ = new int*[n];

    // Reservar memoria para cada columna en cada fila
    for (int i = 0; i < n; ++i) {
        MATRIZ[i] = new int[n];
    }

    // Calcular las coordenadas del centro de la matriz
    int centro_fila = n / 2;
    int centro_columna = n / 2;

    // Rellenar la matriz con valores
    int valor = 1;
    for (int fila = 0; fila < n; fila++) {
        for (int columna = 0; columna < n; columna++) {
            if (fila == centro_fila && columna == centro_columna) {
                MATRIZ[fila][columna] = 0; // Insertar el cero en el centro
            } else {
                MATRIZ[fila][columna] = valor++; // Incrementar y asignar el siguiente valor
            }
        }
    }

    return MATRIZ; // Devolver la matriz generada
}

// Función para imprimir la matriz
void imprimirMatriz(int** MATRIZ, int n) {
    cout << "Matriz generada:" << endl;
    for (int fila = 0; fila < n; fila++) {
        for (int columna = 0; columna < n; columna++) {
            cout << MATRIZ[fila][columna] << "\t"; // Imprimir elemento de la matriz seguido de un tabulador
        }
        cout << endl; // Imprimir una nueva línea después de imprimir cada fila completa
    }
}
// Función para liberar la memoria de la matriz
void liberarMemoria(int** MATRIZ, int n) {
    for (int i = 0; i < n; ++i) {
        delete[] MATRIZ[i];
    }
    delete[] MATRIZ;
}





