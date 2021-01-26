#include<iostream>
#include<conio.h>
#include<string.h>
#include <cstdlib>
#include <ctime>
using namespace std;
struct Cliente {
	int dni;
	string Nombre;
	int CodRegalo = 0;
	int numerosTelefono[100];
	int cantNumTelef = 0;
};
struct Nodo {
	struct Cliente* objCliente;
	Nodo* siguiente;
};

struct Lista {
	Nodo* ini;
	Nodo* fin;
	int size;
	Lista() {
		ini = NULL;
		fin = NULL;
		size = 0;
	}
	void Agregar_elementos(Cliente* newObjCliente) {
		Nodo* nuevo = new Nodo();
		nuevo->objCliente = newObjCliente;
		if (ini == NULL) {
			ini = nuevo;
			fin = nuevo;
		}
		else {
			fin->siguiente = nuevo;
			fin = nuevo;
		}
		fin->siguiente = NULL;
		size++;

	}
	
	void MostrarNumerosTelefonicos() {
		Nodo* aux = new Nodo();
		aux = ini;
		if (ini == NULL) { cout << "\nNO HAY ELEMENTOS " << endl; }
		else {
			cout << "DNI" << "\tCLIENTE" << "\tNUM. TELEFONICO" << endl;
			while (aux != NULL) {
				for (int i = 0; i < aux->objCliente->cantNumTelef; i++) {
					cout << aux->objCliente->dni << "\t " <<
						aux->objCliente->Nombre << "\t " <<
						aux->objCliente->numerosTelefono[i] << endl;
				}
				cout << endl;
				aux = aux->siguiente;
			}
		}
	}

	string ObtenerNombreRegalo(int codRegalo) {
		switch (codRegalo)
		{
		case 1: return "RAM";
		case 2: return "SDD";
		case 3: return "HEADPHONES";
		case 4: return "TECLADO MECANICO";
		case 5: return "CPU";
		default: return "NINGUNO";
			break;
		}
	}

	void ReporteRegalos() {
		Nodo* aux = new Nodo();
		aux = ini;
		if (ini == NULL) { cout << "\nNO HAY ELEMENTOS " << endl; }
		else {
			cout << "DNI" << "\tCLIENTE" << "\tREGALO" << endl;
			while (aux != NULL) {
				cout << aux->objCliente->dni << "\t " <<
					aux->objCliente->Nombre << "\t " <<
					ObtenerNombreRegalo(aux->objCliente->CodRegalo) << endl;
				cout << endl;
				aux = aux->siguiente;
			}
		}
	}

	void RegalarAtodos() {
		Nodo* aux = new Nodo();
		srand(time(0));
		aux = ini;
		if (ini == NULL) { cout << "\nNO HAY ELEMENTOS " << endl; }
		else {
			while (aux != NULL) {
				int codRegalo = 0;
				codRegalo = rand() % (5 - 1 + 1) + 1;
				aux->objCliente->CodRegalo = codRegalo;
				aux = aux->siguiente;
			}
		}
	}
	
};

void  Registro_Telefonico(Lista* plista) {	
	Cliente* pCliente = new Cliente();
	cout << "\n\DNI : "; cin >> pCliente->dni;
	cout << "\n\tNOMBRE : "; cin >> pCliente->Nombre;
	int numTelefono = 0;
	int opcCont = 0;
	do
	{
		system("cls");
		cout << "\n\tNum. TELEFONO : "; cin >> pCliente->numerosTelefono[numTelefono];
		numTelefono++;
		cout << "\n\tDesea Continuar ingresando numeros?  " << endl;
		cout << "\t[1]SI" << endl;
		cout << "\t[2]NO" << endl;		
		cin >> opcCont;
	} while (opcCont != 2);

	pCliente->cantNumTelef = numTelefono;

	cout << endl << endl;
	plista->Agregar_elementos(pCliente);
}

void menu() {
	cout << "\n\t\tMENU PRINCIPAL" << endl;
	cout << "\n\t[1]REGISTRAR CLIENTE ";
	cout << "\n\t[2]LISTA DE CLIENTE ";
	cout << "\n\t[3]REPORTE DE REGALOS ";
	cout << "\n\t[4]ASIGNAR REGALOS";
	cout << "\n\t[5]SALIR ";
	cout << "\n\t\tIngrese una de las opciones: ";
}
int main() {
	int opc;
	Lista* plista = new Lista();

	do {
		system("cls");
		menu(); cin >> opc;
		switch (opc)
		{
		case 1: {
			Registro_Telefonico(plista);			
			break;
		}
		case 2: {
			plista->MostrarNumerosTelefonicos();
			system("pause");
			break;
		}
		case 3: {
			plista->ReporteRegalos();
			system("pause");
			break;
		}
		case 4: {
			plista->RegalarAtodos();
			system("pause");
			break;
		}
			  cout << endl;
		}
	} while (opc != 5);

	system("pause");
	system("cls");

	return 0;
}