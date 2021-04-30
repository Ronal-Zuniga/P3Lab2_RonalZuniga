#include <iostream>
#include <ctime>
#include <cstdlib>
#include <math.h>
using namespace std;
int menu();
int numero_random(int inicio, int limite);
void triangulo_pascal(int n, int max_n, int res_anterior[], int salida[]);
void desviacion_estandar();
void grafico_barras();

int main() {
	int opcion;
	while((opcion = menu()) != 4) {
		switch(opcion) {
			case 1: {
				int max_n;
				cout << endl;
				cout << "**Triangulo de Pascal**" << endl;
				cout << "Ingrese el numero de iteraciones: ";
				cin >> max_n;
				cout << endl;
				while(max_n > 99 || max_n < 1) {
					cout << "Las iteraciones deben ser entre 1 y 99" << endl;
					cout << "Ingrese el numero de iteraciones: ";
					cin >> max_n;
					cout << endl;
				}
				int res_anterior[100] = {0};
				int salida[100] = {0};
				triangulo_pascal(0, max_n, res_anterior, salida);
				cout << endl;
				cout << endl;
				break;
			}

			case 2: {
				cout << endl;
				cout << "**Desviacion Estandar**" << endl;
				desviacion_estandar();
				cout << endl;
				break;
			}

			case 3: {
				cout << endl;
				cout << "**Grafico de Barras**" << endl;
				grafico_barras();
				cout << endl;
				break;
			}
		}//fin del switch
	}//fin del while
	return 0;
}

int menu() {
	int opcion;
	cout << "----MENU----" << endl;
	cout << "1. Triangulo de Pascal" << endl;
	cout << "2. Desviacion Estandar" << endl;
	cout << "3. Grafico de Barra" << endl;
	cout << "4. Salir" << endl;
	cout << endl;
	cout << "Ingrese la opcion: ";
	cin >> opcion;
	cout << endl;
	while(opcion > 4 || opcion <= 0) {
		cout << "La opcion debe de estar dentro del rango" << endl;
		cout << "Ingrese la opcion: ";
		cin >> opcion;
		cout << endl;
	}
	return opcion;
}

int numero_random(int inicio, int limite) {
	return inicio + (rand() % (limite - inicio));
}

void desviacion_estandar() {
	double desviacion;
	int elementos[20] = {0};
	double suma = 0;
	double promedio;
	srand ((unsigned)time(0));
	cout << endl;
	cout << "El arreglo generado es: [";
	for(int i = 0; i < 20; i++) {
		elementos[i] = numero_random(1, 100);
		suma += elementos[i];
		if(i == 19) {
			cout << elementos[i];
		} else {
			cout << elementos[i] << ",";
		}
	}
	cout << "]" << endl;
	promedio = suma/20;
	double sumatoria = 0;
	for(int i = 0; i < 20; i++) {
		double resta = elementos[i] - promedio;
		if(resta < 0) {
			resta = resta*-1;
		}
		double cuadrado = pow(resta, 2);
		sumatoria += cuadrado;
	}
	desviacion = sqrt(sumatoria/20);
	cout << "La desviacion estandar es = " << desviacion << endl;
	cout << endl;
}

void grafico_barras() {
	int primer_arreglo[10] = {0};
	int segundo_arreglo[10] = {0};
	char car1 = 177;
	char car2 = 178;
	srand ((unsigned)time(0));
	cout << endl;
	cout << "El primer arreglo generado es: [";
	for (int i = 0; i < 10; i++) {
		primer_arreglo[i] = numero_random(1, 20);
		if(i == 9) {
			cout << primer_arreglo[i];
		} else {
			cout << primer_arreglo[i] << ",";
		}
	}
	cout << "]" << endl;
	cout << endl;
	cout << "El segundo arreglo generado es: [";
	for (int i = 0; i < 10; i++) {
		segundo_arreglo[i] = numero_random(1, 20);
		if(i == 9) {
			cout << segundo_arreglo[i];
		} else {
			cout << segundo_arreglo[i] << ",";
		}
	}
	cout << "]" << endl;
	cout << endl;
	for (int i = 0; i < 10; i++) {
		if(i+1 == 10) {
			cout << i + 1 << " ";
		} else {
			cout << i + 1 << "  ";
		}
		for (int x = 0; x < primer_arreglo[i]; x++)
			cout << car1 << " ";
		cout << endl;
		cout << "   ";
		for (int y = 0; y < segundo_arreglo[i]; y++)
			cout << car2 << " ";
		cout << endl;
		cout << endl;
	}
}

void triangulo_pascal(int n, int max_n, int res_anterior[], int salida[]) {
	int arreglo[] = {0};
	if(n <= max_n) {
		salida[0] = 1;
		int aux = 0;
		for(int i = 1; i < n; i++) {
			salida[i] = res_anterior[aux] + res_anterior[i];
			aux++;
		}
		salida [n] = 1;
		cout << endl;
		for(int x = 0; x <= n; x++) {
			if(salida[x] != 0) {
				cout << salida[x] << " ";
			}
		}
		triangulo_pascal(n + 1, max_n, salida, arreglo);
	} else{
		return;
	}
}