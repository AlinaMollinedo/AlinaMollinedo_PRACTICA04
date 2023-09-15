// Materia: Programación I, Paralelo 4

// Autor: Alina Mollinedo Dávila

// Fecha creación: 14/09/2023

// Fecha modificación: 14/09/2023

// Número de ejericio: 10

// Problema planteado: Construir las funciones para ordenar un vector de N elementos aleatorios y los ordene por.
// • Por selección
// • Por inserción
// • Por el método burbuja
// • Por el método Shell
// • Por QuickSort

#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;
int n;
void printv(int v);
void fillv(int v);
void copyv(int v);
void selection(int v);
void insertion(int v);
void bubble(int v);

// Imprime la matriz
void printv(int *v){
    cout << endl;
    for(int i = 0; i < n; i++){
        cout << v[i] << " ";
    }
}

// Copia una matriz
void copyv(int *vv, int *v){
    for(int i = 0; i < n; i++){
        vv[i] = v[i];
    }
}

// Ordena el vector por burbuja
void bubble(int *v){
    int vbub[n];
    copyv(vbub, v);
    for(int i = n; i > 0; i--){
        for(int j = 0; j < i - 1; j++){
            if(vbub[j] > vbub[j + 1]){
                int temp = vbub[j];
                vbub[j] = vbub[j + 1];
                vbub[j + 1] = temp;
            }
        }
    }
    printv(vbub);
}

// Ordena el vector por insercion
void insertion(int *v){
    int vins[n];
    copyv(vins, v);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n - 1; j++){
            while(vins[j] > vins[j + 1]){
                int temp = vins[j];
                vins[j] = vins[j + 1];
                vins[j + 1] = temp;
            }
        }
    }
    printv(vins);
}

// Ordena el vector por seleccion
void selection(int *v){
    int vsel[n];
    copyv(vsel, v);
    for(int i = 0; i < n; i++){
        int smallest = 101, pos;
        for(int j = i; j < n; j++){
            if(vsel[j] < smallest){
                smallest = vsel[j];
                pos = j;
            }
        }
        int temp = vsel[i];
        vsel[i] = smallest;
        vsel[pos] = temp;
    }
    printv(vsel);

}

// Llena la matriz con numeros al azar
void fillv(int *v){
    srand(time(NULL));
    for(int i = 0; i < n; i++){
        int x = 0 + rand() % 100;
        v[i] = x;
    }
    printv(v);
}

int main()
{
    cout << "Ingrese la magnitud del vector: ";
    cin >> n;

    int v[n];
    fillv(v);
    cout << "\n\nPor seleccion:";
    selection(v);
    cout << "\n\nPor insercion:";
    insertion(v);
    cout << "\n\nPor burbuja:";
    bubble(v);
    cout << endl;
    return 0;
}
