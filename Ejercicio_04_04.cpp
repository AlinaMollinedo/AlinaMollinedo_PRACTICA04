// Materia: Programación I, Paralelo 4

// Autor: Alina Mollinedo Dávila

// Fecha creación: 16/09/2023

// Fecha modificación: 17/09/2023

// Número de ejericio: 4

// Problema planteado: Escribir el programa para solicitar al usuario N calificaciones comprendidas en el rango
// de 1 a 100, calcular y presentar la sumatoria y promedio de estas N calificaciones. La
// entrada de valores es para las calificaciones, debe hacerlo mediante una función


#include <iostream>

using namespace std;
int n;

// Suma las notas ingresadas
double suma(int *grades){
    double s = 0;
    for(int i = 0; i < n; i++){
        s += grades[i];
    }
    return s;
}

// Almacena las notas ingresadas en el vector grades
void input(int *grades){
    for(int i = 0; i < n; i++){
        int grade;
        cout << "Ingresar la calificacion #" << i + 1 << ": ";
        cin >> grade;
        grades[i] = grade;
    }
}

int main(){
    int grades[n] = {};
    cout << "Ingrese el numero de calificaciones a ingreaar: ";
    cin >> n;

    input(grades);
    double summ = suma(grades);

    cout << "\nLa sumatoria de las calificaciones es " << summ << endl;
    cout << "El promedio de las calificaciones es " << summ / n << endl; // Calcula e imprime el promedio de las notas
    return 0;
}