#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Declaracion de vectores globales
vector<string> nombres;
vector<string> apellidos;
vector<string> contrasenas;
vector<int> notas;

// Funcion para ofuscar nombres y apellidos
void ofuscar() {
    for (int i = 0; i < 10; i++) {
        string nombreOfuscado = nombres[i];
        string apellidoOfuscado = apellidos[i];

        // Codigo de ofuscacion segun las reglas dadas
        replace(nombreOfuscado.begin(), nombreOfuscado.end(), 'A', '4');
        replace(nombreOfuscado.begin(), nombreOfuscado.end(), 'a', '4');
        replace(nombreOfuscado.begin(), nombreOfuscado.end(), 'E', '3');
        replace(nombreOfuscado.begin(), nombreOfuscado.end(), 'e', '3');
        replace(nombreOfuscado.begin(), nombreOfuscado.end(), 'I', '1');
        replace(nombreOfuscado.begin(), nombreOfuscado.end(), 'i', '1');
        replace(nombreOfuscado.begin(), nombreOfuscado.end(), 'O', '0');
        replace(nombreOfuscado.begin(), nombreOfuscado.end(), 'o', '0');
        replace(nombreOfuscado.begin(), nombreOfuscado.end(), 'S', '5');
        replace(nombreOfuscado.begin(), nombreOfuscado.end(), 's', '5');
        replace(nombreOfuscado.begin(), nombreOfuscado.end(), 'T', '7');
        replace(nombreOfuscado.begin(), nombreOfuscado.end(), 't', '7');

        replace(apellidoOfuscado.begin(), apellidoOfuscado.end(), 'A', '4');
        replace(apellidoOfuscado.begin(), apellidoOfuscado.end(), 'a', '4');
        replace(apellidoOfuscado.begin(), apellidoOfuscado.end(), 'E', '3');
        replace(apellidoOfuscado.begin(), apellidoOfuscado.end(), 'e', '3');
        replace(apellidoOfuscado.begin(), apellidoOfuscado.end(), 'I', '1');
        replace(apellidoOfuscado.begin(), apellidoOfuscado.end(), 'i', '1');
        replace(apellidoOfuscado.begin(), apellidoOfuscado.end(), 'O', '0');
        replace(apellidoOfuscado.begin(), apellidoOfuscado.end(), 'o', '0');
        replace(apellidoOfuscado.begin(), apellidoOfuscado.end(), 'S', '5');
        replace(apellidoOfuscado.begin(), apellidoOfuscado.end(), 's', '5');
        replace(apellidoOfuscado.begin(), apellidoOfuscado.end(), 'T', '7');
        replace(apellidoOfuscado.begin(), apellidoOfuscado.end(), 't', '7');

        contrasenas[i] = nombreOfuscado + apellidoOfuscado;
    }
}

// Funcion para calcular estadisticas
void calcular() {
    // Calcular promedio, mayor y menor aqui
    double promedio = 0.0;
    int suma = 0;
    int mayor = notas[0];
    int menor = notas[0];

    for (int i = 0; i < 10; i++) {
        suma += notas[i];
        if (notas[i] > mayor) {
            mayor = notas[i];
        }
        if (notas[i] < menor) {
            menor = notas[i];
        }
    }

    promedio = static_cast<double>(suma) / 10.0;

    // Imprimir resultados
    cout << "Promedio de nota es: " << promedio << endl;
    cout << "Mayor: " << mayor << endl;
    cout << "Menor: " << menor << endl;

    // Evaluar el estado (aprobado o reprobado)
    if (promedio >= 51) {
        cout << "Estado: Aprobado" << endl;
    } else {
        cout << "Estado: Reprobado" << endl;
    }
}

// Funcion para imprimir datos
void imprimir() {
    cout << "Nombre\tApellido\tNota\tContrasena" << endl;
    for (int i = 0; i < 10; i++) {
        cout << nombres[i] << "\t" << apellidos[i] << "\t" << notas[i] << "\t" << contrasenas[i] << endl;
    }
}

// Funcion principal
int main() {
    // Inicializar vectores
    nombres = {"Alejandro", "Sofia", "Lucas", "Valentina", "Mateo", "Emma", "Nicolas", "Isabella", "Daniel", "Camila"};
    apellidos = {"Rodriguez", "Martinez", "Garcia", "Lopez", "Fernandez", "Perez", "Sanchez", "Torres", "Ramirez", "Gonzalez"};
    contrasenas.resize(10);
    notas.resize(10);

    // Llenar notas aleatorias
    for (int i = 0; i < 10; i++) {
        notas[i] = rand() % 100 + 1; // Puntaje entre 1 y 100
    }

    char opcion;

    do {
        // Mostrar menu
        cout << "MENU Trabajo Practico 4" << endl;
        cout << "(1) - Llenar nombres, apellidos y notas de forma aleatoria." << endl;
        cout << "(2) - Ofuscar nombres y apellidos para llenar las contrasenas." << endl;
        cout << "(3) - Sacar la media, el mayor y menor de todas las notas." << endl;
        cout << "(4) - Imprimir datos." << endl;
        cout << "(s/S) - Salir" << endl;

        cin >> opcion;

        // Evaluar opcion ingresada
        switch (opcion) {
            case '1':
                // Llenar nombres, apellidos y notas con valores especificos
                // Aqui se puede pedir al usuario ingresar datos o dejarlos fijos
                break;

            case '2':
                // Ofuscar nombres y apellidos para llenar las contrasenas
                ofuscar();
                cout << "Contrasenas generadas." << endl;
                break;

            case '3':
                // Sacar la media, el mayor y menor de todas las notas
                // Imprimir datos llamando a la funcion de imprimir
                imprimir();
                calcular();
                break;

            case '4':
                // Imprimir datos
                imprimir();
                break;

            case 's':
            case 'S':
                break;

            default:
                cout << "Opcion invalida" << endl;
        }

    } while (opcion != 's' && opcion != 'S');

    return 0;
}

