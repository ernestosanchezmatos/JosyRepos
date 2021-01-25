/*EJERCICIO PROPUESTO#1 COLAS
/*Una tienda dispone de 5 repartidores, para las entregas a domicilio, genere un programa que simule:
el despacho de cada repartidor, sabiendo que si la entrega se realiza después de 30 minutos de realizada la orden,
al cliente se le aplica un 30% de descuento sobre la compra. El programa debe mostrar:
el total de entregas por repartidor, el monto de la ganancia, y las pérdidas, en concepto de entregas tardías. */
#include<iostream>
#include<conio.h>
#include<string.h>
#include <cstdlib>
#include <ctime>
using namespace std;
struct repartidor {
	int codigo;
	string nombre;
}
repartidor1 = { 1001,"Luis Gonzales" },
repartidor2= { 1002,"Ana Garcia" },
repartidor3 = { 1003,"Lourdes Perez" },
repartidor4 = { 1004,"Paul Quispe" },
repartidor5 = { 1005,"Raul Roque" };
struct venta {
	int cod_venta;
	struct repartidor obj_repartidor;
	char producto[50];
	int tiempo;
	double precio;
	double descuento;
	double importe;
	double ganancia;
	double perdida;
	int cantPedidos;
};
struct nodo {
	struct venta *P_venta;
	nodo* siguiente;
};
int numcodigo = 0;
struct lista {
	nodo* ini;
	nodo* fin;
	int size;
	lista() {
		ini = NULL;
		fin = NULL;
		size = 0;
	}
	void Agregar_elementos(venta* obj_venta) {
		nodo* nuevo = new nodo();
		nuevo->P_venta = obj_venta;
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
	void Sacar_elementos() {
		nodo* aux = new nodo();
		aux = ini;
		while (aux != NULL) {
			if (size == 1) {
				ini = NULL;
				fin = NULL;
			}
			else {
				aux = ini;
				ini = ini->siguiente;
				delete aux;
			}
			aux = aux->siguiente;
			size--;
		}
	}	
	void mostrar_elementos() {
		nodo* aux = new nodo();
		char v; int codigo;
		double time = 0;
		aux = ini;
		cout << "COD REPARTIDOR" << "\tNOMBRE" << "\tPRODUCTO" << "\tPRECIO" << "\tTIEMPO(ENTREGA)" << "\DESCUENTO" << "\tIMP FINAL" <<endl;
		while (aux!=NULL) {	
			cout <<aux->P_venta->obj_repartidor.codigo<< "\t "<<
				 aux->P_venta->obj_repartidor.nombre << "\t "
				<< "\t " << aux->P_venta->producto<< "\t" << 
				aux->P_venta->precio<<"\t" << aux->P_venta->tiempo<<"\t"
				<< aux->P_venta->descuento << "\t" 
				<< (aux->P_venta->precio)-(aux->P_venta->descuento);
			cout << endl;
			aux = aux->siguiente;

		}

	}
	void ReporteFinal(lista *plista) {

		cout << " \n\t\tREPORTE GENERAL DE VENTAS ";
		cout << "CODIGO " << "\t" << "NOMBRE " << "\t" << "N°VENTAS" << endl;
		cout << repartidor1.codigo << "\t" << repartidor1.nombre <<"\t" << plista->;
	}
	
};
/*
double Tiempo_transaccion(char o) {
	double tiempo = 0.0;
	switch (o) {
	case 'R': {
		tiempo = 4;
		break;
	}
	case 'D':
	{
		tiempo = 2;
		break;
	}
	case 'C': {
		tiempo = 3.5;
		break;
	}
	case 'A':
	{
		tiempo = 5;
		break;
	}
	case 'P':
	{
		tiempo = 2;
		break;
	}
	}
	return tiempo;
}*/
void  Registro_transacciones(lista* plista) {
	int opc, choose;
	srand(time(0));
	//double timeSumador=0;
	//repartidor obj_cliente;		
	choose = 1;
	//do {
		venta* p_venta = new venta();
		//cout << "\nIngrese su DNI: "; cin >> obj_cliente.dni;
		//cout << "\nIngrese su nombre : "; cin >> obj_cliente.nombre;
		//cout << "\n\t\tIngrese la fecha, por ejemplo->(DIA MES AÑO)(010921) : ";
		//cin >> p_transaccion->fecha_hora;
		numcodigo++;
		p_venta->cod_venta = numcodigo;
		cout << "\n\tPRODUCTO : "; cin >> p_venta->producto;
		cout << "\n\tPRECIO : "; cin >> p_venta->precio;		
		p_venta->importe += p_venta->precio;
		p_venta->tiempo = rand() % (60 - 15 + 1) + 15;
		if ((p_venta->tiempo) > 30) {
			p_venta->descuento = p_venta->precio*0.30;

		}else {
			p_venta->descuento = 0;
		}
		p_venta->perdida += p_venta->descuento;
		p_venta->ganancia += (p_venta->precio - p_venta->descuento);

			//do {
				system("cls");
				cout << "\n\t\tQuien realiza el delivery? ";
				cout << "\n\t[1]Repartidor 1 : ";
				cout << "\n\t[2]Repartidor 2 : ";
				cout << "\n\t[3]Repartidor 3 : ";
				cout << "\n\t[4]Repartidor 4 : ";
				cout << "\n\t[5]Repartidor 5 : ";				
				cout << "\n\t\tIngrese una de las opciones : "; cin >> opc;

				switch (opc) {
				case 1: {
					p_venta->cantPedidos += 1;
					p_venta->obj_repartidor = repartidor1;
					system("pause");
					break;
				}
				case 2: {
					p_venta->cantPedidos += 1;
					p_venta->obj_repartidor = repartidor2;
					system("pause");
					break;
				}
				case 3: {
					p_venta->cantPedidos += 1;
					p_venta->obj_repartidor = repartidor3;
					system("pause");
					break;
				}
				case 4: {
					p_venta->cantPedidos += 1;
					p_venta->obj_repartidor = repartidor4;
					system("pause");
					break;
				}
				case 5: {
					p_venta->cantPedidos += 1;
					p_venta->obj_repartidor = repartidor5;
					system("pause");
					break;
				}
				}
			//} while (opc != 6);			
			plista->Agregar_elementos(p_venta);
			//timeSumador = 0;
			/*cout << "Desea continuar agregando elementos : " << endl;
			cout << "[1] SI " << endl;
			cout << "[2] NO" << endl;
			cout << "Ingresa la opcion : "; cin >> choose;*/

	//} while (choose != 2);

}
void menu() {
	cout << "\n\t\tMENU PRINCIPAL" << endl;
	cout << "\n\t[1]REGISTRAR VENTA ";
	cout << "\n\t[2]LISTA DE VENTAS ";
	cout << "\n\t[3]REPORTE GENERAL DE VENTAS ";
	cout << "\n\t[4]SALIR ";
	cout << "\n\t\tIngrese una de las opciones: ";
}
int main(){
	int opc;
	lista* plista= new lista();
	menu(); cin >> opc;
	switch (opc)
	{
	case 1: {
			Registro_transacciones(plista);
		break;
	}
	case 2: {
			plista;
		break;
	}
	case 3: {
		break;
	}

	default:
		cout << "\n\t\tOPCION NO VALIDA...!!!";
		break;
	}
	
	
	//cout << endl;
	
	return 0;
}
