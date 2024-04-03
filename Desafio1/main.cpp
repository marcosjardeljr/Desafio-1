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
void validar();
int** rotarMatrizAntihorario90(int** , int );
int** rotarMatrizAntihorario180(int** , int );
int** rotarMatrizAntihorario270(int** , int );

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
            int n;
            cout << "Ingrese un numero impar para el tamaño de la matriz: ";
            cin >> n;

            // Verificar si el tamaño ingresado es impar, si no, pedir al usuario que ingrese nuevamente
            while (n % 2 == 0) {
                cout << "El tamaño de la matriz debe ser un numero impar. Ingrese nuevamente: ";
                cin >> n;
            }

            // Generar la matriz
            int matriz = generarMatriz(n);

            // Imprimir la matriz original
            cout << "Matriz original:" << endl;
            imprimirMatriz(matriz, n);

            // Rotar la matriz 90 grados en sentido antihorario
            int matriz_rotada90 = rotarMatrizAntihorario90(matriz, n);
            cout << "\nMatriz rotada 90 grados en sentido antihorario:" << endl;
            imprimirMatriz(matriz_rotada90, n);

            // Rotar la matriz 180 grados en sentido antihorario
            int matriz_rotada180 = rotarMatrizAntihorario180(matriz, n);
            cout << "\nMatriz rotada 180 grados en sentido antihorario:" << endl;
            imprimirMatriz(matriz_rotada180, n);

            // Rotar la matriz 270 grados en sentido antihorario
            int matriz_rotada270 = rotarMatrizAntihorario270(matriz, n);
            cout << "\nMatriz rotada 270 grados en sentido antihorario:" << endl;
            imprimirMatriz(matriz_rotada270, n);

            // Liberar la memoria
            liberarMemoria(matriz, n);
            liberarMemoria(matriz_rotada90, n);
            liberarMemoria(matriz_rotada180, n);
            liberarMemoria(matriz_rotada270, n);

            break;
        }
        case 3:
        {


            break;

        }
        case 4:
        {
            validar();

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

// Función para rotar la matriz 90 grados en sentido antihorario
int rotarMatrizAntihorario90(int MATRIZ, int n) {
    // Crear una nueva matriz para almacenar la matriz rotada
    int matriz_rotada;
    matriz_rotada = new int*[n];
    for (int i = 0; i < n; ++i) {
        matriz_rotada[i] = new int[n];
    }

    // Rotar la matriz intercambiando filas y columnas
    for (int fila = 0; fila < n; fila++) {
        for (int columna = 0; columna < n; columna++) {
            matriz_rotada[fila][columna] = MATRIZ[columna][n - fila - 1];
        }
    }

    return matriz_rotada;
}


// Función para rotar la matriz 180 grados en sentido antihorario
int rotarMatrizAntihorario180(int MATRIZ, int n) {
    int matriz_rotada;
    matriz_rotada = new int[n];
    for (int i = 0; i < n; ++i) {
        matriz_rotada[i] = new int[n];
    }

    // Rotar la matriz 180 grados es equivalente a rotarla 90 grados dos veces
    int matriz_temporal = rotarMatrizAntihorario90(MATRIZ, n);
    matriz_rotada = rotarMatrizAntihorario90(matriz_temporal, n);
    liberarMemoria(matriz_temporal, n);

    return matriz_rotada;
}

// Función para rotar la matriz 270 grados en sentido antihorario
int rotarMatrizAntihorario270(int MATRIZ, int n) {
    int matriz_rotada;
    matriz_rotada = new int[n];
    for (int i = 0; i < n; ++i) {
        matriz_rotada[i] = new int[n];
    }

    // Rotar la matriz 270 grados es equivalente a rotarla 90 grados una vez
    // y luego reflejarla verticalmente (invierte el orden de las filas)
    int **matriz_temporal = rotarMatrizAntihorario180(MATRIZ, n);
    for (int fila = 0; fila < n; fila++) {
        for (int columna = 0; columna < n; columna++) {
            matriz_rotada[fila][columna] = matriz_temporal[n - fila - 1][columna];
        }
    }
    liberarMemoria(matriz_temporal, n);

    return matriz_rotada;
}

void validar() {
    int fila, columna;
    int fila_columna[2]; // Arreglo para almacenar los valores de fila y columna
    int validacion[100]; // Arreglo para almacenar los valores de validación de k
    int num_valores_k = 0; // Contador de valores de k


    // Validar si fila y columna son positivos
    do {
        cout << "Ingrese un valor para fila: ";
        cin >> fila;
        if (fila <= 0)
            cout << "El valor de fila debe ser positivo Inténtelo nuevamente." << endl;
    } while (fila <= 0);

    do {
        cout << "Ingrese un valor para columna: ";
        cin >> columna;
        if (columna <= 0)
            cout << "El valor de columna debe ser positivo Inténtelo nuevamente." << endl;
    } while (columna <= 0);


    fila_columna[0] = fila;
    fila_columna[1] = columna;

    char respuesta;
    do {
        int k;
        do {
            cout << "Ingrese un valor para k (1, -1, 0): ";
            cin >> k;

            // Validar el valor de k
            if (k != 1 && k != -1 && k != 0) {
                cout << "El valor de k debe ser 1, -1 o 0." << endl;
                continue;
            }
        } while (k != 1 && k != -1 && k != 0);

        // Agregar el valor de k al arreglo de validación
        validacion[num_valores_k++] = k;

        cout << "¿Desea ingresar otro valor para k? (y/n): ";
        cin >> respuesta;
    } while (respuesta == 'y' || respuesta == 'Y');


    // Mostrar los arreglos finales
    cout << "Valores de fila y columna: ";
    for (int i = 0; i < 2; ++i) {
        cout << fila_columna[i] << " ";
    }
    cout << endl;

    cout << "Valores de validación de k: ";
    for (int i = 0; i < num_valores_k; ++i) {
        cout << validacion[i] << " ";
    }
    cout << endl;
}





