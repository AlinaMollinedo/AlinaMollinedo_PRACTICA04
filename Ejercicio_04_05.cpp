// Materia: Programación I, Paralelo 4

// Autor: Alina Mollinedo Dávila

// Fecha creación: 18/09/2023

// Fecha modificación: 20/09/2023

// Número de ejericio: 5

// Problema planteado: Elabore un programa para registro académico de la UCB, que solicite el nombre de una
// materia, el paralelo, el docente y sus correspondientes notas de periodo. Al final, se
// muestra la nota final y si aprobó o reprobo el curso. (realizar con estructuras)

#include <iostream>
#include <string>

using namespace std;
int n;

struct Studentdata{
    string subject, proff;
    int parallel, grades;
};

int main(){
    Studentdata student;
    cout << "Ingrese el nombre de la materia: ";
    getline(cin, student.subject);
    cin.ignore(256, '\n');

    cout << "Ingrese el paralelo: ";
    cin >> student.parallel;

    cout << "Ingrese el nombre del docente: ";
    getline(cin, student.proff);
    cin.ignore(256, '\n');

    cout << "Ingrese el paralelo: ";
    cin >> student.grades;


    return 0;
}