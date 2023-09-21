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
void calcav(Studentdata &student);

struct Studentdata{
    string subject, proff;
    int parallel, grades[3] = {}, average = 0;
};

// Calcula el promedio del estudiante
void calcav(Studentdata &student){
    for(int i = 0; i < 3; i++){
        student.average += student.grades[i];
    }
    student.average /= 3;
}

int main(){
    Studentdata student;
    cout << "Ingrese el nombre de la materia: ";
    cin.ignore(256, '\n');
    getline(cin, student.subject);

    cout << "Ingrese el paralelo: ";
    cin >> student.parallel;

    cout << "Ingrese el nombre del docente: ";
    getline(cin, student.proff);
    cin.ignore(256, '\n');

    cout << "Ingrese la nota de su primera nota: ";
    cin >> student.grades[0];
    cout << "Ingrese la nota de su segunda nota: ";
    cin >> student.grades[1];
    cout << "Ingrese la nota de su tercera nota: ";
    cin >> student.grades[2];

    calcav(student);

    // Determina si el estudiante esta aprobado o repobrado a partir de su promedio
    if(student.average < 52){
        cout << "\nReprobado." << endl;
    }
    else{
        cout << "\nAprobado" << endl;
    }
    return 0;
}