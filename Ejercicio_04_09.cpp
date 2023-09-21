// Materia: Programación I, Paralelo 4

// Autor: Alina Mollinedo Dávila

// Fecha creación: 19/09/2023

// Fecha modificación: 19/09/2023

// Número de ejericio: 9

// Problema planteado: A un trabajador se le paga según las horas que trabaja en la semana, una tarifa de
// pago por hora. Si la cantidad de horas trabajadas es mayor a 40, la tarifa se incrementa
// en un 50%. Calcular el salario total del trabajador, además considere que si existe un
// anticipo se debe restar este valor al salario total. Al total debe descontar un 10% para
// el pago de impuestos. Se debe obtener:
// - Total ganado
// - Total descuentos
// - Pago neto

#include <iostream>

using namespace std;
int calctotal(int n, int m);

// Calcula el total ganado por el trabajador
int calctotal(int n, int m){
    m = (n > 40) ? m * 1.5 : m;
    int total = n * m;
    return total;
}

int main(){
    int payph, weeklyhours;
    double advance;
    cout << "Ingrese su tarifa de pago por hora: ";
    cin >> payph;
    cout << "Ingrese la cantidad de horas trabajadas esta semana: ";
    cin >> weeklyhours;
    cout << "Ingrese el porcentaje del anticipo (si no hay anticipo, ingrese 0): ";
    cin >> advance;

    int tearned = calctotal(weeklyhours, payph);
    advance = (advance != 0) ? advance * tearned / 100: advance; // Calcula el anticipo
    double taxes = tearned * 0.1; // Calcula los impuestos

    cout << "Total ganado: " << tearned << " Bs." << endl;
    cout << "Total descuentos: " << advance + taxes << " Bs." << endl;
    cout << "Pago neto: " << tearned - advance - taxes << " Bs." << endl;
    return 0;
}