// Materia: Programación I, Paralelo 4

// Autor: Alina Mollinedo Dávila

// Fecha creación: 14/09/2023

// Fecha modificación: 14/09/2023

// Número de ejericio: 1

// Problema planteado: Lee por teclado un año y calcula y muestra si es bisiesto

#include <iostream>
#include <locale.h>

using namespace std;
void leapyear(int year);

void leapyear(int year){
    if((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0)){
        cout << "Es bisiesto." << endl;
    }
    else{
        cout << "No es bisiesto." << endl;
    }
}

int main()
{
    int year;

    setlocale(LC_ALL, "");

    cout << "Ingrese un año: ";
    cin >> year;

    leapyear(year);

    return 0;
}
