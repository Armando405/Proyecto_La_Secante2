#pragma once
using namespace std;

class Secante {
private:
    double x0;   // Valor inicial x0
    double x1;   // Valor inicial x1
    int iteracionesMaximas;   // NÃºmero mÃ¡ximo de iteraciones

public:
//Inicializamos las variables privadas con puntero this. Parte de la POO.
    Secante(double x0, double x1, int iterMax) {
        this->x0 = x0;
        this->x1 = x1;
        this->iteracionesMaximas = iterMax;
    }
//Evaluamos una vez mas la funcion
    double calcularFuncion(double x) {
        return ((pow(x,2)) - (cos(x)));  
    }

    
    void imprimirEvaluaciones() {

        cout<<endl;

        int iteracion = 0;
        double xAnterior = x0;
        double xActual = x1;
        double errorRelativo = 0.0;

        do {
            double fAnterior = calcularFuncion(xAnterior);
            double fActual = calcularFuncion(xActual);

            double xSiguiente = xActual - ((fActual * (xAnterior - xActual)) / (fAnterior - fActual));
            xAnterior = xActual;
            xActual = xSiguiente;

            iteracion++;
            
            if(iteracion>1){
                errorRelativo = abs((xActual - xAnterior) / xActual);
            }else{
                errorRelativo = 0;
            }
            
            cout<<x1<<endl;
            cout<<x0<<endl;
            cout<<fActual<<endl;
            cout<<fAnterior<<endl;
            cout<<xAnterior<<endl;
            cout<<xActual<<endl;
            cout<<xSiguiente<<endl;
            
            cout<<"x = "<<xAnterior<<" - (("<<fActual<<" * ("<<xAnterior<<" - "<<xAnterior<<")) / ("<<fActual<<" - "<<fAnterior<<"))"<<endl;

            if(iteracion > 1){
                cout<<"ER = (("<<xActual<<" - "<<xAnterior<<") / "<<xActual<<")"<<endl;
            }
            

        } while (iteracion < iteracionesMaximas);

    }
    
//Tabla de resultados con la fórmula aplicada.
    void imprimirTabla() {

        cout<<endl<<endl;

        cout << "Tabla de resultados:" << endl;
        cout << setw(10) << "Iteracion" << setw(15) << "x2" << setw(15) << "f(x2)" << setw(15) << "Error Relativo" << endl;
        cout << "------------------------------------------------------" << endl;
//Igualamos las variables respectivamente al uso que tenga dentro de la formula
        int iteracion = 0;
        double xAnterior = x0;
        double xActual = x1;
        double errorRelativo = 0.0;
//Empezamos a crear el bucle
        do {
//Declaramos las variables de las evaluaciones de f y los igualamos al metodo calcularFuncion mandandole los valores correspondientes para que se evalue en la funcion
            double fAnterior = calcularFuncion(xAnterior);
            double fActual = calcularFuncion(xActual);
//Aplicación de la fórmula de la Secante.
            double xSiguiente = xActual - ((fActual * (xAnterior - xActual)) / (fAnterior - fActual));
            xAnterior = xActual;
            xActual = xSiguiente;
            iteracion++;
//If else para  calcular el error relativo.
            if(iteracion>1){
                errorRelativo = abs((xActual - xAnterior) / xActual);
            }else{
                errorRelativo = 0;
            }
            cout << setw(10) << iteracion << setw(15) << xActual << setw(15) << calcularFuncion(xActual) << setw(15) << errorRelativo << endl;
			
			/*if(errorRelativo == 0){
				cout << "La solucion es el ultimo numero antes del nan." << endl;
			}*/
        } while (iteracion < iteracionesMaximas);

        cout << "------------------------------------------------------" << endl;
        cout << "Solucion: x = " << xActual << endl << endl;
    }
};