// Materia: Programación I, Paralelo 4

// Autor: Alina Mollinedo Dávila

// Fecha creación: 20/09/2023

// Fecha modificación: 20/09/2023

// Número de ejericio: 13

// Problema planteado: Una empresa efectúa el control de asistencia de sus empleados mediante un lector
// biométrico, el horario en la entrada es a las 8:00 a.m y la salida es a las 16:00 p.m. El empleado
// tiene una tolerancia de 10 minutos en la entrada, si llega más allá de los 10 minutos de tolerancia
// se penaliza todos los minutos de atraso (es decir si llega a las 8:12 se penalizan los 12 minutos).
// De igual forma no puede salir antes del horario establecido en la salida, (si lo hace se penaliza
// los minutos faltantes), pero si el empleado entra antes o sale después de sus horarios el sistema
// solo toma en cuenta las 8 horas laborales de trabajo. 

#include <iostream>
#include <string>

using namespace std;
int out(int n, int m);
int in(int n, int m);


// Calcula la penalizacion de salida
int out(int n, int m){
    int pen;
    pen = (n < 16) ? (60 - m) : 0;
    return pen;
}

// Calcula la penalizacion de entrada
int in(int n, int m){
    int pen;
    pen = (n == 8 && m > 10) ? m : 0;
    return pen;
}

int main(){
    int code, inhour, inmin, outhour, outmin;
    string date;
    cout << "Ingrese su codigo de identificacion: ";
    cin >> code;
    cout << "Ingrese su hora de entrada: ";
    cin >> inhour;
    cout << "Ingrese su minuto de entrada: ";
    cin >> inmin;
    cout << "Ingrese su hora de salida: ";
    cin >> outhour;
    cout << "Ingrese su minuto de salida: ";
    cin >> outmin;
    cout << "Ingrese la fecha (dd/mm/yyyy): ";
    cin.ignore(256, '\n');
    getline(cin, date);

    int penin = in(inhour, inmin);
    int penout = out(outhour, outmin);

    cout << "\nPenalizacion: " << penin + penout << endl; // Suma las penalizaciones
    cout << "Fecha: " << date << endl;
    return 0;
}