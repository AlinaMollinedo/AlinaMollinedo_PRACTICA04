// Materia: Programación I, Paralelo 4

// Autor: Alina Mollinedo Dávila

// Fecha creación: 19/09/2023

// Fecha modificación: 19/09/2023

// Número de ejericio: 7

// Problema planteado: Escribir un programa que lea el salario de un empleado y mediante una función
// efectué un incremento salarial en base a la siguiente escala:
// • Si el salario es menor < 1000 Bs. incremente en un 20%
// • Si el salario es mayor o igual a 1000 pero es menor a 3000 Bs. Incremente en
// un 15%
// • Si el salario es mayor o igual a 3000 pero es menor a 6000 Bs. Incremente en
// un 10%
// • Si el salario es mayor o igual a 6000 Bs. Incremente en un 5%
// La función debe obtener el incremento y el nuevo salario.


#include <iostream>

using namespace std;
double increment(int n);

// Calcula el incremento a partir del salario ingresado
double increment(int n){
    double pct;
    pct = (n < 1000) ? 0.2 : (n >= 1000 && n < 3000) ? 0.15 : (n >= 3000 && n < 6000) ? 0.1 : 0.05;
    return pct;
}

int main(){
    int salary;
    cout << "Ingrese su salario: ";
    cin >> salary;

    double pct = increment(salary);

    cout << "\nEl incremento es del " << pct * 100 << "%." << endl;
    cout << "Nuevo salario: " << salary * (1 + pct) << "Bs." << endl; // Calcula e imprime el nuevo salario
    return 0;
}