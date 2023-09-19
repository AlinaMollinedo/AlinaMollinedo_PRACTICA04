// Materia: Programación I, Paralelo 4

// Autor: Alina Mollinedo Dávila

// Fecha creación: 19/09/2023

// Fecha modificación: 19/09/2023

// Número de ejericio: 11

// Problema planteado: Realice una función que enviándole dos numero calcule el máximo común divisor con el
// algoritmo de Euclides.

#include <iostream>

using namespace std;

// Calcula el MCD utilizando el algoritmo de Euclides
int MCD(int a, int b){
    int mcd;
    while(a % b != 0){
        int temp = a;
        a = b;
        b = temp % b;
        mcd = b;
    }
    return mcd;
}

int main(){
    int a, b;
    cout << "Ingrese el primer numero: ";
    cin >> a;
    cout << "Ingrese el segundo numero: ";
    cin >> b;

    int bigger = (a > b) ? a : b, smaller = (bigger = a) ? b : a; // Determina el mayor entre a y b
    int mcd = MCD(bigger, smaller);

    cout << "\nEl Maximo Comun Divisor es: " << mcd << endl;
    return 0;
}