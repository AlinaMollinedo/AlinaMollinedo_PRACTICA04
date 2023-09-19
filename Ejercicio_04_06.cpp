// Materia: Programación I, Paralelo 4

// Autor: Alina Mollinedo Dávila

// Fecha creación: 18/09/2023

// Fecha modificación: 19/09/2023

// Número de ejericio: 6

// Problema planteado: Escriba un programa que mediante una función determine el pago por el servicio de
// estacionamiento de coches en un parqueo, teniendo en cuenta que la primera hora de
// estadía se paga 8 Bs., y las restantes 3 Bs. c/hora. Si el uso del servicio es menor a una
// hora se cobra por la hora y de igual manera si excede la hora se cobra por la hora
// siguiente.


#include <iostream>

using namespace std;

// Calcula el monto a partir de la cantidad de horas estacionadas
int howmuch(double n){
    int total = 8;
    if(n > 1){
        for(int i = 0; i < n - 1; i++){
            total += 3;
        }
    }
    return total;
}

// Transforma valores de minutos a horas
double mintohours(double n, double x){
    n /= 60.0;
    x += n;
    return x;
}

int main(){

    double inhour, inmin, outhour, outmin;
    cout << "Ingrese la hora de entrada: ";
    cin >> inhour;
    cout << "Ingrese el minuto de entrada: ";
    cin >> inmin;
    cout << "Ingrese la hora de salida: ";
    cin >> outhour;
    cout << "Ingrese el minuto de salida: ";
    cin >> outmin;
    
    inhour = mintohours(inmin, inhour);
    outhour = mintohours(outmin, outhour);

    double n = outhour - inhour;
    int total = howmuch(n);

    cout << "\nDebe " << total << " Bs." << endl;
    return 0;
}