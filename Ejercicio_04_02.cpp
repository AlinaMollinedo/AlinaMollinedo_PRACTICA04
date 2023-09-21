// Materia: Programación I, Paralelo 4

// Autor: Alina Mollinedo Dávila

// Fecha creación: 18/09/2023

// Fecha modificación: 20/09/2023

// Número de ejericio: 2

// Problema planteado: Lee por teclado la fecha actual y la fecha de nacimiento de una persona y calcula su edad.

#include <iostream>

using namespace std;
Date calcage(Date today, Date birthday);
void indate(Date &x);

struct Date{
    int day, month, year;
};

// Calcula la edad
Date calcage(Date today, Date birthday){
    Date age;
    age.day = today.day - birthday.day;
    age.month = today.month - birthday.month;
    age.year = today.year - birthday.year;
    
    age.day = (age.day < 0) ? 30 + age.day : age.day;
    if(age.month <= 0){
        age.month = 12 + age.month;
        age.year -= 1;
    }
    return age;
}

// Permite ingresar los datos de una fecha
void indate(Date &x){
    cout << "Ingrese el dia: ";
    cin >> x.day;
    cout << "Ingrese el mes: ";
    cin >> x.month;
    cout << "Ingrese el anhio: ";
    cin >> x.year;
}

int main(){
    Date today, birthday;

    cout << "Para la fecha actual" << endl;
    indate(today);
    cout << "\nPara su fecha de nacimiento" << endl;
    indate(birthday);

    Date age;
    age = calcage(today, birthday);
    
    cout << "\nTiene " << age.year << " anhios, " << age.month << " meses y " << age.day << " dias." << endl;
    return 0;
}