#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include <cmath>
#include <iomanip>
using std::setw;
using std::setprecision;
using std::setfill;
#include <vector>
using std::vector;
#include <Windows.h>
 
 /*


TABLA DE FUNCIONES MIEMBRO ACCESIBLES POR OBJETOS
-------------------------------------------------
OBJETO    TIPO DE FUNCIÓN
-------------------------------------------------
const     const
static    const , static


*/
 
 
class obj {
	friend inline void setAnswer(obj &, int *);
private:
	int answer;
public:
 
 
	inline void sumar() const;
	inline void restar() const;
	inline void multiplicar() const;
	inline void dividir() const;
	inline void raiz() const;
	inline void potencia() const;
	inline void logaritmo() const;
	
	
	obj() {
		if (answer == 1)
			sumar();
		else
			if (answer == 2)
				restar();
			else
				if (answer == 3)
					multiplicar();
				else
					if (answer == 4)
						dividir();
						else
						if (answer == 5)
							raiz();
						else
							if (answer == 6)
								potencia();
							else
								logaritmo();
	}
	
	
	
		~obj() {/*...*/ }
 
 };
 
 
inline void setAnswer(obj &objRef, int *valor) {
	objRef.answer = *valor;
}
 
 
inline void obj::sumar() const {
	system("cls");
	size_t numero;
	cout << "Cuantos numeros desea sumar? ";
	cin >> numero;
	if (numero < 0) {
		cout << "ERR." << endl;
		cin.get();
	}
	else {
		vector<int>vectNumeros(numero);
		int total = 0;
		for (size_t i = 0; i < numero; ++i) {
			cout << "\nIntroduce un valor (" << i + 1 << "): ";
			cin >> vectNumeros.at(i);
			cin.ignore();
			total += vectNumeros.at(i);
 
 
		}
		cout << "\a\n\n\tTotal: " << total << endl;
		cin.get();
		system("cls");
	}
}
 
 inline void obj::restar() const {
	size_t tamanio;
	cout << "Cuantos numeros deseas restar ? ";
	cin >> tamanio;
	if (tamanio <= 0) {
		cout << "ERR" << endl;
		cin.get();
	}
	else {
		vector<int> vectorNumeros(tamanio);
		int total = 0;
		for (size_t i = 0; i < tamanio; i++) {
			cout << "\nIntroduce un numero(" << i + 1 << ") : ";
			cin >> vectorNumeros.at(i);
			cin.ignore();
			if (i == 0) {
				total += vectorNumeros.at(i);
			}
			else
				total -= vectorNumeros.at(i);
		}
		cout << "\a\n\n\tTotal: " << total;
		cin.get();
		system("cls");
	}
}
 
 
inline void obj::multiplicar() const {
	size_t tamanio;
	cout << "Introduce los numeros que deseas multiplicar : ";
	cin >> tamanio;
	if (tamanio <= 0) {
		cout << "ERR." << endl;
		cin.get();
	}
	else {
		vector<int>vectorNumeros(tamanio);
		static int total = 1;
		for (size_t i = 0; i < tamanio; i++) {
			cout << "\nIntroduce un numero(" << i + 1 << ") : ";
			cin >> vectorNumeros.at(i);
			cin.ignore();
			total *= vectorNumeros.at(i);
		}
		cout << "\a\n\tTotal: " << total;
		cin.get();
		system("cls");
	}
}
 
 
inline void obj::dividir() const {
	size_t tamanio = 2; //Solo dejo dividir dos numeros
	vector<int>almacenNumeros(tamanio);
	for (size_t i = 0; i<tamanio; i++) {
		if (i == 0)
			cout << "Introduce el numerador : ";
		else
			cout << "Introduce el denominador : ";
 
 
		cin >> almacenNumeros.at(i);
	}
	int total = almacenNumeros.at(0) / almacenNumeros.at(1);
	cout << endl << "\n\t\aEl resultado de la division es : " << total << endl;
	cin.get();
	system("cls");
}
inline void obj::raiz() const {
	double resultado;
	double valor;
	cout << "Introduce un numero : ";
	cin >> valor;
	cin.ignore();
	resultado = sqrt(valor);
	cout << "El resultado de la operacion es " << resultado;
	cin.get();
	system("cls");
}
 
 
inline void obj::potencia() const {
	double base;
	int exponente;
	cout << "Introduce la base y el exponente : ";
	cin >> base >> exponente;
	cin.ignore();
	double resultado = pow(base, exponente);
	cout << "\t\aEl resultado es : " << resultado << endl;
	cin.get();
	system("cls");
}
 
 
inline void obj::logaritmo() const {
	double argumento;
	cout << "Introduce el argumento para el logaritmo de base 10: ";
	cin >> argumento;
	cin.ignore();
    double resultado = log10(argumento);
	cout << "\t\aEl resultado del logaritmo en base 10 de " << argumento << " es : " << resultado;
	cin.get();
	system("cls");
}
 

int main(void)
{
	char valorCentinela;
	char *control = &valorCentinela;
	int contador = 0;
	while (valorCentinela != '-') {
 
 
		int respuesta = NULL;
		obj Objeto;
		//MENÚ
 
 
		if (contador>0) {
			system("cls");
			cout << "PULSE '-' PARA SALIR U OTRA TECLA PARA CONTINUAR: ";
			cin >> *control;
			cin.ignore();
			system("cls");
		}
		if (valorCentinela == '-') {
			//...
		}
		else {
			cout << setw(31) << setfill('-') << '-' << " CALCULADORA C++ " << setw(31) << setfill('-') << '-' << endl;
			cout << "\n\t1- SUMA" << endl;
			cout << "\t2- RESTA" << endl;
			cout << "\t3- PRODUCTO" << endl;
			cout << "\t4- COCIENTE" << endl;
			cout << "\t5- RAIZ CUADRADA" << endl;
			cout << "\t6- EXPONENTE" << endl;
			cout << "\t7- LOGARITMO" << endl;
				cout << endl << "\t\tSELECCION: ";
			cin >> respuesta;
			cin.ignore();
			int *respuestaPtr = &respuesta;
			bool comprobadorIlegal = false;
 
 
			if (*respuestaPtr > 0 && *respuestaPtr <= 7)
				comprobadorIlegal = false;
			else
				comprobadorIlegal = true;
 
 
			switch (comprobadorIlegal) {
			case 1: //1 = true
					//case true:  ERR -> value 1 is already used
				cout << "\a\n\tSE INTRODUJO UN VALOR INESPERADO." << endl;
				system("pause");
				return 1;
				break;
 
 
			default:
				setAnswer(Objeto, respuestaPtr);
				break;
			}
			contador++;
		}
	}
 
 
	system("cls");
	cout << "\aCerrando el programa...";
	cin.get();
	return 0;
}
