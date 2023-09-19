// Materia: Programación I, Paralelo 4

// Autor: Alina Mollinedo Dávila

// Fecha creación: 19/09/2023

// Fecha modificación: 19/09/2023

// Número de ejericio: 8

// Problema planteado: En una fábrica de computadoras se planea ofrecer a los clientes un descuento que
// dependerá del número de computadoras que compre. Si las computadoras son menos de
// cinco se les dará un 10% de descuento sobre el total de la compra; si el número de
// computadoras es mayor o igual a cinco pero menos de diez se le otorga un 20% de
// descuento; y si son 10 o más se les da un 40% de descuento. El precio de cada
// computadora es un valor que el usuario ingrese desde el teclado. Se debe obtener el
// precio total que el cliente debe pagar y el valor del descuento.

#include <iostream>

using namespace std;

// Calcula el descuento a partir de la cantidad de computadoras
double discount(int n){
    double dscnt;
    dscnt = (n < 5) ? 0.1 : (n >= 5 && n < 10) ? 0.2 : 0.4;
    return dscnt;
}

int main(){
    int price, qnt;
    cout << "Ingrese el precio de la computadora: ";
    cin >> price;
    cout << "Ingrese el numero de computadoras a comprar: ";
    cin >> qnt;

    int total = price * qnt; // Calcula el total
    double dscnt = discount(qnt);

    cout << "\nEl descuento es del " << dscnt * 100 << "%." << endl;
    cout << "Total: " << total * (1 - dscnt) << "Bs." << endl; // Calcula el total a pagar
    return 0;
}