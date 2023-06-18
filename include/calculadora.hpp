#pragma once
using namespace std;

class calculadora {
private:
    double inicio;
    double fin;
    int numPuntos;
    int numFix;

public:
//Inicio del programa, esto es lo primero que ve el usuario.
    void ingresarRango() {
    	cout << "Hola, bienvenido al método numérico de la secante para resolver ecuaciones no lineales.\n"<<
		"El programa empieza tabulando asi que debe elegir su rango de tabulacion. Sugerencia de 3 a -3\n\n";  
		cout << "Funcion a evaluar: f(x) = (x^2 - (cos(x))"<<endl;
        cout << "Ingresa el numero positivo: ";
        cin >> inicio;
        cout << "Ingresa el numero negativo: ";
        cin >> fin;
        cout << "Ingresa las tabulaciones que deseas ver: ";
        cin >> numPuntos;
        cout << "Numero de decimales(fix): ";
        cin >> numFix;

        cout << endl;
    }

//Aquí se cambia la función a evaluar.
    double calcularFuncion(double x) {
        return (pow(x,2)) - (cos(x));
    }

//Impresion de resultados de tabulacion.
    void imprimirTabla() {
        cout<< "Resultados de tabulacion: "<<endl;

        cout <<  endl;
        cout << setw(10) << "x" << setw(15) << "f(x)" << endl;  //setw estructura la tabla, el numero indica los espacios que ocupa.
        cout << "----------------------------" << endl;

        double paso = (fin - inicio) / (numPuntos - 1);     //aqui se calcula el tamaño del paso entre cada punto del rango, esto nos da la distancia entre cada valor consecutivo de x
        double x = inicio;      //Inicialización de la variable x con el valor inicial "inicio"

        cout << fixed;      //cout para configurar la salida decimal fija
        cout << setprecision(numFix);       //Aplicación del 'Fix'.

        for (int i = 0; i < numPuntos; i++) {       //Inicio del for para calcular la funcion con el valor de x.
            double resultado = calcularFuncion(x);
            cout << setw(10) << x << setw(15) << resultado << endl;
            x += paso;
        }
    }
};