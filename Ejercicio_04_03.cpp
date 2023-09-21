// Materia: Programación I, Paralelo 4

// Autor: Alina Mollinedo Dávila

// Fecha creación: 16/09/2023

// Fecha modificación: 16/09/2023

// Número de ejericio: 3

// Problema planteado: Leer los datos de doce personas como son: nombre, edad, estatura, peso, posteriormente
// indicar cuál es el nombre de la persona de menor edad, el promedio de las estaturas y el
// de los pesos. (realizar con estructuras)


#include <iostream>
#include <string>

using namespace std;
double weightAv(Person *n);
double heightAv(Person *n);
int youngest(Person *n);

// Estructura para almacenar los datos de cada persona
struct Person{
    string name;
    int age, height, weight;
};

// Saca el promedio de los pesos
double weightAv(Person *n){
    int suma = 0;
    double average;
    for(int i = 0; i < 12; i++){
        suma += n[i].weight;
    }
    average = suma / 12.0;
    return average;
}

// Saca el promedio de las alturas
double heightAv(Person *n){
    int suma = 0;
    double average;
    for(int i = 0; i < 12; i++){
        suma += n[i].height;
    }
    average = suma / 12.0;
    return average;
}

// Saca la posicion en el vector p de la persona de menor edad
int youngest(Person *n){
    int x = 120, pos;
    for(int i = 0; i < 12; i++){
        if(n[i].age < x){
            x = n[i].age;
            pos = i;
        }
    }
    return pos;
}


int main(){
    Person p[12];

    // Pide los datos de las 12 personas
    for(int i = 0; i < 12; i++){
        cout << "\nPersona #" << i + 1 << endl;
        cout << "Nombre: ";
        cin.ignore(256, '\n');
        getline(cin, p[i].name);
        cout << "Edad: ";
        cin >> p[i].age;
        cout << "Altura: ";
        cin >> p[i].height;
        cout << "Peso: ";
        cin >> p[i].weight;
    }   

    int pos = youngest(p);
    double haverage = heightAv(p), waverage = weightAv(p);
    cout << "/nLa persona mas joven es " << p[pos].name << endl;
    cout << "El promedio de alturas es " << haverage << endl;
    cout << "El promedio de pesos es " << waverage << endl;
    return 0;
}