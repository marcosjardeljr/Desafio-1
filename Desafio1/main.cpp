/*
Desafio 1
Presentado y desarrollado por:
Marcos Jardel Murillo Hernández - C.C.1017238240
Juan Escalante
*/

#include <iostream>


using namespace std;
int** generarMatriz(int);
void imprimirMatriz(int**, int );
void liberarMemoria(int**, int);
int** rotarMatrizAntihorario90(int** , int );
int** rotarMatrizAntihorario180(int** , int );
int** rotarMatrizAntihorario270(int** , int );
void validarReglaK(int *datos, int cantidad);
void generar_clave_x(int *datos, int cantidad);

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
            int **matriz = generarMatriz(n);

            // Imprimir la matriz original
            cout << "Matriz original:" << endl;
            imprimirMatriz(matriz, n);

            // Rotar la matriz 90 grados en sentido antihorario
            int **matriz_rotada90 = rotarMatrizAntihorario90(matriz, n);
            cout << "\nMatriz rotada 90 grados en sentido antihorario:" << endl;
            imprimirMatriz(matriz_rotada90, n);

            // Rotar la matriz 180 grados en sentido antihorario
            int **matriz_rotada180 = rotarMatrizAntihorario180(matriz, n);
            cout << "\nMatriz rotada 180 grados en sentido antihorario:" << endl;
            imprimirMatriz(matriz_rotada180, n);

            // Rotar la matriz 270 grados en sentido antihorario
            int **matriz_rotada270 = rotarMatrizAntihorario270(matriz, n);
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
            int cantidad_cerraduras;
            cout << "Ingrese la cantidad de cerraduras que desea configurar: ";
            cin >> cantidad_cerraduras;

            for (int i = 0; i < cantidad_cerraduras; ++i) {
                int tam;
                cout << "Ingrese el tamaño impar para la cerradura " << i + 1 << ": ";
                cin >> tam;
                while (tam % 2 == 0) {
                    cout << "El tamaño debe ser impar. Ingrese nuevamente: ";
                    cin >> tam;
                }

                // Generar la cerradura
                int **cerradura = generarMatriz(tam);

                // Imprimir la cerradura
                cout << "Cerradura " << i + 1 << ":" << endl;
                imprimirMatriz(cerradura, tam);

                // Liberar la memoria
                liberarMemoria(cerradura, tam);

                cout << endl; // Imprimir una línea en blanco entre cada cerradura
            }


            break;

        }
        case 4:
        {
            int cantidad;
            cout << "Ingrese la cantidad de datos: ";
            cin >> cantidad;
            // Validar que se ingresen al menos 3 datos
            while (cantidad < 3) {
                cout << "La cantidad de datos debe ser mayor o igual a tres. Ingrese nuevamente: ";
                cin >> cantidad;
            }

            // Crear un arreglo dinámico para almacenar los datos
            int *datos = new int[cantidad];
            // Pedir al usuario que ingrese los datos
            cout << "Ingrese los datos:" << endl;
            cout << "Dato 1: ";
            cin >> datos[0];
            cout << "Dato 2: ";
            cin >> datos[1];

            // Validar que los primeros dos datos sean positivos
            while (datos[0] <= 0 || datos[1] <= 0) {
                cout << "El dato 1 y 2 deben ser positivos. Ingrese nuevamente el dato 1: ";
                cin >> datos[0];
                cout << "Ingrese nuevamente el dato 2: ";
                cin >> datos[1];
            }

            // Pedir al usuario que ingrese el resto de los datos
            for (int i = 2; i < cantidad; ++i) {
                cout << "Dato " << i + 1 << ": ";
                cin >> datos[i];
            }



            // Liberar la memoria del arreglo dinámico
            delete[] datos;

            return 0;
        }
        case 5:
        {

            int cantidad;
            cout << "Ingrese la cantidad de datos: ";
            cin >> cantidad;
            // Validar que se ingresen al menos 3 datos
            while (cantidad < 3) {
                cout << "La cantidad de datos debe ser mayor o igual a tres. Ingrese nuevamente: ";
                cin >> cantidad;
            }

            // Crear un arreglo dinámico para almacenar los datos
            int *datos = new int[cantidad];
            // Pedir al usuario que ingrese los datos
            cout << "Ingrese los datos:" << endl;
            cout << "Dato 1: ";
            cin >> datos[0];
            cout << "Dato 2: ";
            cin >> datos[1];

            // Validar que los primeros dos datos sean positivos
            while (datos[0] <= 0 || datos[1] <= 0) {
                cout << "El dato 1 y 2 deben ser positivos. Ingrese nuevamente el dato 1: ";
                cin >> datos[0];
                cout << "Ingrese nuevamente el dato 2: ";
                cin >> datos[1];

            }

            // Pedir al usuario que ingrese el resto de los datos
            for (int i = 2; i < cantidad; ++i) {
                cout << "Dato " << i + 1 << ": ";
                cin >> datos[i];

            }

            generar_clave_x(datos, cantidad);


            // Liberar la memoria del arreglo dinámico
            delete[] datos;


            break;
        }
        case 6:
        {

            int cantidad;
            cout << "Ingrese la cantidad de datos: ";
            cin >> cantidad;
            // Validar que se ingresen al menos 3 datos
            while (cantidad < 3) {
                cout << "La cantidad de datos debe ser mayor o igual a tres. Ingrese nuevamente: ";
                cin >> cantidad;
            }
            // Crear un arreglo dinámico para almacenar los datos
            int *datos = new int[cantidad];
            // Pedir al usuario que ingrese los datos
            cout << "Ingrese los datos:" << endl;
            cout << "Dato 1: ";
            cin >> datos[0];
            cout << "Dato 2: ";
            cin >> datos[1];

            // Validar que los primeros dos datos sean positivos
            while (datos[0] <= 0 || datos[1] <= 0) {
                cout << "El dato 1 y 2 deben ser positivos. Ingrese nuevamente el dato 1: ";
                cin >> datos[0];
                cout << "Ingrese nuevamente el dato 2: ";
                cin >> datos[1];

            }

            // Pedir al usuario que ingrese el resto de los datos
            for (int i = 2; i < cantidad; ++i) {
                cout << "Dato " << i + 1 << ": ";
                cin >> datos[i];

            }

            // Llamamos a la función para validar los datos ingresados
            validarReglaK(datos, cantidad);

            // Extraer los primeros dos datos
            int dato1 = datos[0];
            int dato2 = datos[1];


            // Determinar cuál es el mayor
            int mayor, n;
            if (dato1 >= dato2) {
                mayor = dato1;
            } else {
                mayor = dato2;
            }

            // Verificar si el mayor es par o impar
            n = mayor;
            if (n % 2 == 0) {
                n = mayor + 1; // Si es par, sumar 1
            }
            int valoresX[cantidad - 1];
            valoresX[0] = n; // Guardamos el tamaño de la matriz en la primera posición de valoresX
            for(int i = 2, j = 0, k = 1; j < cantidad - 1; i++, j++, k++) {

                int valor_inicial, valor_rotado_90, valor_rotado_180, valor_rotado_270;

                // Generar la matriz y las matrices rotadas
                int **matriz = generarMatriz(n);
                int **matriz_rotada90 = rotarMatrizAntihorario90(matriz, n);
                int **matriz_rotada180 = rotarMatrizAntihorario180(matriz, n);
                int **matriz_rotada270 = rotarMatrizAntihorario270(matriz, n);

                // Obtener los valores en las posiciones iniciales
                valor_inicial = matriz[dato1 - 1][dato2 - 1];
                valor_rotado_90 = matriz_rotada90[dato1 - 1][dato2 - 1];
                valor_rotado_180 = matriz_rotada180[dato1 - 1][dato2 - 1];
                valor_rotado_270 = matriz_rotada270[dato1 - 1][dato2 - 1];
                //cout << valor_inicial <<"   "<< valor_rotado_90 <<"   "<<valor_rotado_180 <<"   "<<valor_rotado_270;

                // Lógica para asignar valores a valoresX
                if (datos[i] == 1) {
                    if (valor_inicial > valor_rotado_90 || valor_inicial > valor_rotado_180 || valor_inicial > valor_rotado_270) {
                        valoresX[k] = n;
                    } else {
                        n += 2;
                    }
                } else if (datos[i] == -1) {
                    if (valor_inicial < valor_rotado_90 || valor_inicial < valor_rotado_180 || valor_inicial < valor_rotado_270) {
                        valoresX[k] = n;
                    } else {
                        n += 2;
                    }
                } else if (datos[i] == 0) {
                    if (valor_inicial == valor_rotado_90 || valor_inicial == valor_rotado_180 || valor_inicial == valor_rotado_270) {
                        valoresX[k] = n;
                    } else {
                        n += 2;
                    }
                }
                else {
                    // Incrementar el tamaño de la matriz en 2 unidades
                    n += 2;
                    // Volver a generar la matriz y las matrices rotadas con el nuevo tamaño
                    liberarMemoria(matriz, n - 2); // Liberar memoria de la matriz anterior
                    liberarMemoria(matriz_rotada90, n - 2); // Liberar memoria de la matriz rotada 90
                    liberarMemoria(matriz_rotada180, n - 2); // Liberar memoria de la matriz rotada 180
                    liberarMemoria(matriz_rotada270, n - 2); // Liberar memoria de la matriz rotada 270
                    matriz = generarMatriz(n); // Generar la nueva matriz
                    matriz_rotada90 = rotarMatrizAntihorario90(matriz, n); // Generar la nueva matriz rotada 90
                    matriz_rotada180 = rotarMatrizAntihorario180(matriz, n); // Generar la nueva matriz rotada 180
                    matriz_rotada270 = rotarMatrizAntihorario270(matriz, n); // Generar la nueva matriz rotada 270
                    // Actualizar los valores iniciales y rotados con la nueva matriz
                    valor_inicial = matriz[dato1 + j][dato2 + j];
                    valor_rotado_90 = matriz_rotada90[dato1 + j][dato2 + j];
                    valor_rotado_180 = matriz_rotada180[dato1 + j][dato2 + j];
                    valor_rotado_270 = matriz_rotada270[dato1 + j][dato2 + j];
                    valoresX[j+1] = n ; // Por ejemplo, incrementar en 2
                }
                imprimirMatriz(matriz, n);
                imprimirMatriz(matriz_rotada90, n);
                imprimirMatriz(matriz_rotada180, n);
                imprimirMatriz(matriz_rotada270, n);

                // Liberar la memoria de las matrices
                liberarMemoria(matriz, n);
                liberarMemoria(matriz_rotada90, n);
                liberarMemoria(matriz_rotada180, n);
                liberarMemoria(matriz_rotada270, n);
            }
            // Imprimir los valores asignados a valoresX
            cout << "Valores asignados a valoresX:" << endl;
            for (int i = 0; i < cantidad - 1 ; i++) {
                cout << valoresX[i] << " ";
            }
            cout << endl;


            // Liberar la memoria del arreglo dinámico
            delete[] datos;


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
int** rotarMatrizAntihorario90(int** MATRIZ, int n) {
    // Crear una nueva matriz para almacenar la matriz rotada
    int **matriz_rotada;
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
int** rotarMatrizAntihorario180(int** MATRIZ, int n) {
    int **matriz_rotada;
    matriz_rotada = new int*[n];
    for (int i = 0; i < n; ++i) {
        matriz_rotada[i] = new int[n];
    }

    // Rotar la matriz 180 grados es equivalente a rotarla 90 grados dos veces
    int **matriz_temporal = rotarMatrizAntihorario90(MATRIZ, n);
    matriz_rotada = rotarMatrizAntihorario90(matriz_temporal, n);
    liberarMemoria(matriz_temporal, n);

    return matriz_rotada;
}

// Función para rotar la matriz 270 grados en sentido antihorario
int** rotarMatrizAntihorario270(int** MATRIZ, int n) {
    int **matriz_rotada;
    matriz_rotada = new int*[n];
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



void validarReglaK(int *datos, int cantidad) {
    // Verificar que las primeras dos posiciones sean positivas
    if (datos[0] <= 0 || datos[1] <= 0) {
        cout << "El dato 1 y 2 deben ser positivos. Ingrese nuevamente el dato 1: ";
        cin >> datos[0];
        cout << "Ingrese nuevamente el dato 2: ";
        cin >> datos[1];
        return;
    }
    // Verificar que las demás posiciones sean -1, 0 o 1
    for (int i = 2; i < cantidad; ++i) {
        while (datos[i] != -1 && datos[i] != 0 && datos[i] != 1) {
            cout << "Error: El dato ingresado en la posición " << i + 1 << " debe ser -1, 0 o 1." << endl;
            cout << "Ingrese nuevamente el dato en la posición " << i + 1 << ": ";
            cin >> datos[i];
        }
    }
    // Si pasa todas las validaciones, imprimir éxito
    cout << "Regla K validada correctamente." << endl;
}

void generar_clave_x(int *datos, int cantidad) {
    // Llamamos a la función para validar los datos ingresados
    validarReglaK(datos, cantidad);

    // Extraer los primeros dos datos
    int dato1 = datos[0];
    int dato2 = datos[1];
    int dato3 = datos[2];

    // Determinar cuál es el mayor
    int mayor, mayor1;
    if (dato1 >= dato2) {
        mayor = dato1;
    } else {
        mayor = dato2;
    }

    // Verificar si el mayor es par o impar
    if (mayor % 2 == 0) {
        mayor += 1; // Si es par, sumar 1
    }
    int valor_inicial, valor_rotado_90;
    int **matriz = generarMatriz(mayor);
    int **matriz_rotada90 = rotarMatrizAntihorario90(matriz, mayor);
    valor_inicial = matriz[dato1-1][dato2-1];
    valor_rotado_90 = matriz_rotada90[dato1-1][dato2-1];
    if((valor_inicial > valor_rotado_90) && (dato3 == 1)){
        mayor1 = mayor;
    }
    else
        mayor1 = mayor+2;
    cout << "Valor en la posicion inicial: " << valor_inicial << "------" << valor_rotado_90 << endl;
    //generarMatriz(mayor);
    imprimirMatriz(matriz, mayor);
    imprimirMatriz(matriz_rotada90, mayor);
    //liberarMemoria(matriz, mayor);
    cout << "X(" << mayor << "," << mayor1 <<")"  << endl;
}




