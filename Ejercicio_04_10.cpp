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
void printv(int *v);
void fillv(int *v);
void copyv(int *v);
void selection(int *v);
void insertion(int *v);
void bubble(int *v);
void shellSort(int *v);
void quickSort(int *v);
void arrange(int pivot, int *v, int*vv);
int findelem(int x, int *v);
void arrange(int pivot, int *v, int*vv);

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

// Da la posicion de un elemento en un vector
int findelem(int x, int *v){
    int pos;
    for(int i = 0; i < n; i++){
        if(x == v[i]){
            pos = i;
            break;
        }
    }
    return pos;
}

// Pone los elementos menores al pivote a la izquierda y los mayores a la derecha
void arrange(int pivot, int *v, int*vv){
    int pos = 0;
    for(int i = 0; i < n; i++){
        if(v[i] <= pivot){
            vv[pos] = v[i];
            pos++;
        }
    }
    for(int i = 0; i < n; i++){
        if(v[i] > pivot){
            vv[pos] = v[i];
            pos++;
        }
    }
}

// Ordena el vector por quick sort
void quickSort(int *v){
    int vquick[n], vvquick[n];
    arrange(v[n - 1], v, vquick);

    int posPiv = findelem(v[n - 1], vquick);

    for(int i = posPiv - 1; i > -1; i--){
        copyv(vvquick, vquick);
        arrange(vquick[i], vvquick, vquick);
    }
    for(int i = n - 1; i > posPiv; i--){
        copyv(vvquick, vquick);
        arrange(vquick[i], vvquick, vquick);
        printv(vquick);
    }
    printv(vquick);
}


// Ordena el vector por shell sort
void shellSort(int *v){
    int vshell[n], piv = n / 2;
    copyv(vshell, v);
    while(piv != 1){
        for(int i = 0; i < n; i++){
            if(i + piv < n){
                if(vshell[i] > vshell[i + piv]){
                    swap(vshell[i], vshell[i + piv]);
                }
            }
        }
        piv /= 2;
    }
    bool flag = true;
    while(flag){
        flag = false;
        for(int i = 0; i < n - 1; i++){
            if(vshell[i] > vshell[i + piv]){
                swap(vshell[i], vshell[i + piv]);
                flag = true;
            }
        }
    }
    printv(vshell);
}

// Ordena el vector por burbuja
void bubble(int *v){
    int vbub[n];
    copyv(vbub, v);
    for(int i = n; i > 0; i--){
        for(int j = 0; j < i - 1; j++){
            if(vbub[j] > vbub[j + 1]){
                swap(vbub[j], vbub[j + 1]);
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
                swap(vins[j], vins[j + 1]);
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
        swap(vsel[i], vsel[pos]);
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
    cout << "\n\nPor shell sort:";
    shellSort(v);
    cout << "\n\nPor quick sort:";
    quickSort(v);
    cout << endl;
    return 0;
}
