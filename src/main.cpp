#include <iostream>
#include <cmath>
#include <iomanip>
#include <calculadora.hpp>
#include <Secante.hpp>

using namespace std;

int main() {
//Invocación de las funciones.
    calculadora calcu;
    calcu.ingresarRango();
    calcu.imprimirTabla();

//Declaramos variables para la clase Secante y empezamos a pedirle los valores al usuario.
    double x0, x1;
    int iteraciones;

    cout << endl;
	cout << "Escriba los valores de f(x) cuyo signo cambie de un lugar a otro." <<endl;;
    cout << "Valor de x0: ";
    cin >> x0;
    cout << "Valor de x1: ";
    cin >> x1;
    cout << "No. de iteraciones: ";
    cin >> iteraciones;
//Invocación de funciones, secante se lleva con ella tres variables.
    Secante secante(x0, x1, iteraciones);
    secante.imprimirEvaluaciones();
    secante.imprimirTabla();

	cout << "El programa ha terminado."<<endl;
	cout << "Para evaluar una funcion diferente debe cambiar la funcion en el codigo fuente en las lineas 19, 34 y 75.\n";
	cout << "Hasta la proxima :D";
    return 0;
}