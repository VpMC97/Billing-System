#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>
#include <iomanip>
#include <windows.h>
#include <time.h>
#include <algorithm>


using namespace std;

//DECLARACIÓN

//Variables
int OP, OP2, OP3, CP, CC, CA, CE, CF, y=5, c, Cod, ca=1, cp=1, ce=1, cf=1, posE;
char R[20];
char M[15];

//Estructuras
struct CLIENTES;
struct EMPLEADOS;
struct ARTICULOS;
struct PROVEEDORES;

//Funciones
int Buscar(char R);
int Buscar2(int Cod);

//Procedimientos
void Menu();
void Submenu();
void SubmenuA();
void SubmenuR();
void SubmenuF();
void gotoxy(int x,int y);

//Procedimientos de Proveedores
void Agregar_P();
void Eliminar_P();
void Modificar_P();
void Buscar_P();
void Reportar_P();

//Procedimientos de Clientes
int Agregar_C();
void Eliminar_C();
void Modificar_C();
void Buscar_C();
void Reportar_C();

//Procedimiento de artículos
void Agregar_A();
void Eliminar_A();
void Modificar_A();
void Buscar_A();
void Reportar_A();
void Traslado_A();

//Procedimientos de Empleados
void Agregar_E();
void Eliminar_E();
void Modificar_E();
void Buscar_E();
void Reportar_E();

//Procedimientos de Factura
void Agregar_F();
void Eliminar_F();
void Modificar_F();
void Buscar_F();
void Reportar_F();

//Procedimientos Reportes
void Articulos_Bodega();
void Articulos_Tienda();
void Top_C();
void Top_E();
void Top_P();
void Top_A();
void Rep_C();

//Programa Principal
int main()
{
	setlocale(LC_ALL,"spanish");

	do 
	{
		Menu();
	}while (OP!=7);		
	
	getch();
	return 0;
}

//ESTRUCTURAS
struct PROVEEDORES
{
	int cod_p;
	char nombre_p[50];
	char NIT_p[10];
	char direccion_p[40];
	int telefono_p;
	int contProveedor;
} A_Proveedores[50];

struct CLIENTES
{
	char nombre_c[50];
	char apellido_c[15];
	char DPI_c[20];
	char direccion_c[40];
	char NIT_c[10];
	int telefono_c;
	int edad_c;
	int contClientes;
} A_Clientes[50];

struct ARTICULOS
{
	int cod_a;
	char nombre_a[50];
	char descripcion_a[80];
	int cantidad_a_T;
	int cantidad_a_B;
	float pUnitario_a;
	int codP_a; // INT;
	int vendidos; //ARTICULOS MÁS VENDIDOS;
} A_Articulos[50];

struct EMPLEADOS
{
	int cod_e;
	char nombre_e[50];
	char apellido_e[20];
	char DPI_e[15];
	int telefono_e;
	int contEmpleados=0;
} A_Empleados[50];

struct Fedetalle
{
	char nombre[30];
	int cod_pr;
	float cantidad;
	float PrecioUnitario;
	float Subtotal;
	float tt;
}A_detal[50];

struct Ffactura
{
	int correlativo;
	char fecha[10];
	char nombre[50];
	char apellido[50];
	char NIT_c[10];
	char direccion[100];
	int codEmpleado;
	int cantidad;
	Fedetalle arregloDetalle[10];
	int numeroCaja;
	float subtotal;
	float iva;
	float total;
	int year;
	int month;
	int day;
	int hour;
	int minute;
	int second;
}A_Fac[50];


Ffactura arregloFacturas[10];

//Menú y submenú
void Menu()
{
	system("cls");
	cout<<"SISTEMA DE FACTURACIÓN"<<endl<<endl;
	
	cout<<"\t1. Proveedores"<<endl;
	cout<<"\t2. Clientes"<<endl;
	cout<<"\t3. Empleados"<<endl;
	cout<<"\t4. Artículos"<<endl;
	cout<<"\t5. Facturación"<<endl;
	cout<<"\t6. Reportes"<<endl;
	cout<<"\t7. Salir"<<endl<<endl;
	cout<<"Ingrese opción: ";
	cin>>OP;

	do
	{
		switch(OP)
		{
			case 1:	
			case 2:
			case 3:
				Submenu();	
			break;
			case 4:
				SubmenuA();
			break;
			case 5:
				SubmenuF();
			break;
			case 6:
				SubmenuR();	
			break;
			case 7:		
				system("cls");
					cout << "\033[1;34m";
				cout<<"Hasta la próxima";
					cout << "\033[1;0m";
				getch();
			break;
			default:
				system("cls");
				cout << "\033[1;31m";
				cout<<"Opción inválida.";
				cout << "\033[1;31m";
				getch();	
			break;		
		}
	} while (OP!=7);
}

void Submenu()
{
	system("cls");
	cout<<"¿Qué desea realizar?"<<endl<<endl;
	
	cout<<"\t1. Ingreso"<<endl;
	cout<<"\t2. Eliminación"<<endl;
	cout<<"\t3. Modificación"<<endl;
	cout<<"\t4. Búsquedas"<<endl;
	cout<<"\t5. Reportes"<<endl;
	cout<<"\t6. Volver a menú principal"<<endl<<endl;
	
	cout<<"Ingrese opción: ";
	cin>>OP2;

	switch(OP2)
	{
		case 1:
			if (OP==1)
				Agregar_P();
			else if (OP==2)
				Agregar_C();
			else if (OP==3)
				Agregar_E();
		break;
		case 2:
			if (OP==1)
				Eliminar_P();
			else if (OP==2)
				Eliminar_C();
			else if (OP==3)
				Eliminar_E();
		break;
		case 3:
			if (OP==1)
				Modificar_P();
			else if (OP==2)
				Modificar_C();
			else if (OP==3)
				Modificar_E();
		break;
		case 4:
			if (OP==1)
				Buscar_P();
			else if (OP==2)
				Buscar_C();
			else if (OP==3)
				Buscar_E();
		break;
		case 5:
			if (OP==1)
				Reportar_P();
			else if (OP==2)
				Reportar_C();
			else if (OP==3)
				Reportar_E();
		break;
		case 6:
			Menu();
		break;
		default:
			system("cls");
			cout << "\033[1;31m";
			cout<<"Opción inválida.";
			cout << "\033[1;0m";
			getch();		
		break;	
	}
}

void SubmenuA()
{
	system("cls");
	cout<<"---------------------ARTICULOS--------------------"<<endl<<endl;
	cout<<"¿Qué desea realizar?"<<endl<<endl;
	
	cout<<"\t1. Ingreso"<<endl;
	cout<<"\t2. Eliminación"<<endl;
	cout<<"\t3. Modificación"<<endl;
	cout<<"\t4. Búsqueda"<<endl;
	cout<<"\t5. Reporte"<<endl;
	cout<<"\t6. Traslado"<<endl;
	cout<<"\t7. Volver a menú principal"<<endl<<endl;
	
	cout<<"Ingrese opción: ";
	cin>>OP2;

	switch(OP2)
	{
		case 1:
			Agregar_A();
		break;
		case 2:
			Eliminar_A();
		break;
		case 3:
			Modificar_A();
		break;
		case 4:
			Buscar_A();		
		break;
		case 5:
			Reportar_A();	
		break;
		case 6:
			Traslado_A();
		break;
		case 7:
			Menu();
		break;
		default:
			system("cls");
			cout << "\033[1;31m";
			cout<<"Opción inválida";
			cout << "\033[1;0m";
			getch();
		break;
	}
}

void SubmenuR()
{
	int op;
	system("cls");
	cout << "\033[1;31m";
	cout<<"---------------------REPORTES--------------------"<<endl<<endl;
	cout << "\033[1;0m";
	
	cout<<"\t1. Reporte de Facturas"<<endl<<endl;
	cout<<"\t2. Reportes de clientes"<<endl<<endl;
	cout<<"\t3. Reporte de proveedores"<<endl<<endl;
	cout<<"\t4. Reporte de empleados"<<endl<<endl;
	cout<<"\t5. Artículos más vendidos"<<endl<<endl;
	cout<<"\t6. Articulos en bodega"<<endl<<endl;
	cout<<"\t7. Artículos en tienda"<<endl<<endl;
	cout<<"\t8. Volver a menú principal"<<endl<<endl;
	cout<<"Ingrese opción: ";
	cin>>OP2;

	switch(OP2)
	{
		case 1:
			Reportar_F();
		break;
		case 2:
			Rep_C();
		break;	
		case 3:
			cout << "\033[1;34m";
			cout<<endl<<"______________________Reporte de Proveedores______________________"<<endl;
			cout << "\033[1;0m";
			cout<<endl<<"\t1. Listado de proveedores";
			cout<<endl<<"\t2. Proveedores que más artículos proveen";
			cout<<endl<<"\t¿Qué desea realizar? ";
			cin>>op;
		
			if (op==1)
				Reportar_P();
				
			else if (op==2)
				Top_P();

			else
				cout << "\033[1;32m";
				cout<<"Opción inválida"<<endl;
				cout << "\033[1;0m";
		break;	
		case 4:
			cout << "\033[1;34m";
			cout<<endl<<"______________________Reporte de Empleados______________________"<<endl;
			cout << "\033[1;0m";
			cout<<endl<<"\t1. Listado de empleados";
			cout<<endl<<"\t2. Empleados que más artículos venden";
			cout<<endl<<"\t¿Qué desea realizar? ";
			cin>>op;
		
			if (op==1)
				Reportar_E();
				
			else if (op==2)
				Top_E();
			
			else
			cout << "\033[1;31m";
				cout<<"Opción inválida"<<endl;
				cout << "\033[1;0m";
		break;	
		case 5:
			Top_A();
		break;
		case 6:
			Articulos_Bodega();
		break;
		case 7:
			Articulos_Tienda();
		break;
		case 8:
			Menu();
		break;
		default:
			system("cls");
			cout << "\033[1;31m";
			cout<<"Opción inválida";
			cout << "\033[1;0m";
			getch();
		break;
	}
}

void SubmenuF()
{
	system("cls");
	cout << "\033[1;34m";
	cout<<"---------------------FACTURAS--------------------"<<endl<<endl;	
	cout << "\033[1;0m";
	cout<<"¿Qué desea realizar?"<<endl<<endl;
	
	cout<<"\t1. Ingresar factura"<<endl<<endl;
	cout<<"\t2. Eliminar factura"<<endl<<endl;
	cout<<"\t3. Buscar factura"<<endl<<endl;
	cout<<"\t4. Reporte de facturas"<<endl<<endl;
	cout<<"\t5. Volver a menú principal"<<endl<<endl;
	
	cout<<"Ingrese opción: ";
	cin>>OP2;

	switch(OP2)
	{
		case 1:
			Agregar_F();
		break;
		case 2:
			Eliminar_F();
		break;
		case 3:
			Buscar_F();
		break;
		case 4:
			Reportar_F();	
		break;
		case 5:
			Menu();
		break;
		default:
			system("cls");
			cout << "\033[1;31m";
			cout<<"Opción inválida";
			cout << "\033[1;0m";
			getch();
		break;
	}	
}

void Rep_C()
{
	int op;
	cout << "\033[1;34m";
	cout<<endl<<"______________________Reporte de Clientes______________________"<<endl;
	cout << "\033[1;0m";
	cout<<endl<<"\t1. Listado de clientes";
	cout<<endl<<"\t2. Clientes que más productos compran";
	cout<<endl<<"\t¿Qué desea realizar? ";
	cin>>op;
	
	if (op==1)
		Reportar_C();
		
	else if (op==2)
		Top_C();				

	else
	{
		cout << "\033[1;32m";
		cout<<"Opción inválida"<<endl;
		cout << "\033[1;0m";		
	}
	return;
}


//PROCEDIMIENTOS Y FUNCIONES
void gotoxy(int x,int y){  
	HANDLE hcon;  
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
    COORD dwPos; 
    dwPos.X = x;  
    dwPos.Y= y;  
    SetConsoleCursorPosition(hcon,dwPos);  
}

int Buscar(char R[20])
{
	bool encontrado = false;
	int i = 0;

	if (OP==1)
	{
		while (i<CP && !encontrado)
		{
			if (strcmp(A_Proveedores[i].NIT_p, R)==0)
				encontrado = true;
				
			else
				i++;
		}	
	}	

	else if (OP==2)
	{
		while (i<CC && !encontrado)
		{
			if (strcmp(A_Clientes[i].NIT_c, R)==0)
				encontrado = true;
				
			else 
				i++;
		}	
	}
	
	else if (OP==4)
	{
		while (i<CA && !encontrado)
		{
			if (strcmp(A_Articulos[i].nombre_a, R)==0)
				encontrado=true;
			else 
				i++;
		}	
	}
	
	else if (OP==3)
	{
		while (i<CE && !encontrado)
		{
			if (strcmp(A_Empleados[i].DPI_e, R)==0)
				encontrado = true;
				
			else 
				i++;
		}	
	}
	
	if (encontrado)
		return i;
	
	else 
		return -1;
}

int Buscar2(int Cod)
{
	bool encontrado = false;
	int i=0;
	
	if (OP==1)
	{
		while (i<CP && !encontrado)
		{
			if (Cod==A_Proveedores[i].cod_p)
				encontrado = true;
			else
				i++;
		}
	}
	
	if (OP==4)
	{
		while (i<CA && !encontrado)
		{
			if (Cod==A_Articulos[i].cod_a)
				encontrado = true;
				
			else 
				i++;
		}		
	}
	
	if (OP==3)
	{
		while (i<CE && !encontrado)
		{
			if (Cod==A_Empleados[i].cod_e)
				encontrado = true;
			
			else
				i++;
		}
	}

	if (encontrado)
		return i;
	else
		return -1;
}

void Agregar_P()
{
	system("cls");
	fflush(stdin);
	cout << "\033[1;33m";
	cout<<" ------------------------------ AGREGAR PROVEEDOR ------------------------------ "<<endl<<endl;
	cout << "\033[1;0m";
	cout<<"Código de proveedor "<<cp<<endl;
	
	A_Proveedores[CP].cod_p = cp;	
	
	fflush(stdin);
	cout<<endl<<"NIT: ";
	cin>>R;
	
	int P = Buscar(R);
	
	if (P==-1)
	{
		strcpy(A_Proveedores[CP].NIT_p, R);

		fflush(stdin);
		cout<<"Nombre: ";
		cin.getline(A_Proveedores[CP].nombre_p, 30, '\n');
		cout<<"Dirección: ";
		cin.getline(A_Proveedores[CP].direccion_p, 40, '\n');	
		cout<<"Teléfono: ";
		cin>>A_Proveedores[CP].telefono_p;
	
		CP++;
		cp++;	
		getch();		
	}

	else 
	{
		system("cls");
		cout<<"Proveedor ya existente.\nPor favor, inténtelo de nuevo."<<endl<<endl;
		getch();	
	}	
}

int Agregar_C()
{		
	system("cls");
	fflush(stdin);
	cout << "\033[1;33m";
	cout<<" ------------------------------ AGREGAR CLIENTES ------------------------------ "<<endl<<endl;
	cout << "\033[1;0m";
	cout<<"NIT: ";
	cin>>R;	
	
	int P = Buscar(R);	
	
	if (P == -1)
	{
		strcpy(A_Clientes[CC].NIT_c, R);
		
		fflush(stdin);
		cout<<"Nombre: ";
		cin.getline(A_Clientes[CC].nombre_c, 20, '\n');
		cout<<"Apellido: ";
		cin.getline(A_Clientes[CC].apellido_c, 15, '\n');
		cout<<"Dirección: ";
		cin.getline(A_Clientes[CC].direccion_c, 40, '\n');
		cout<<"DPI: ";
		cin>>A_Clientes[CC].DPI_c;	
		cout<<"Teléfono: ";
		cin>>A_Clientes[CC].telefono_c;
		cout<<"Edad: ";
		cin>>A_Clientes[CC].edad_c;
		
		CC++;	
		getch();		
	}

	else 
	{
		system("cls");
		cout<<"Cliente ya existente.\nPor favor, inténtelo de nuevo."<<endl<<endl;
		getch();	
	}
	return P;
}

void Agregar_A()
{
	int OP5;
	system("cls");
	cout << "\033[1;33m";
	cout<<" ------------------------------ AGREGAR ARTÍCULO ------------------------------ "<<endl<<endl;
	cout << "\033[1;0m";
	cout<<"1. Articulo nuevo"<<endl<<"2. Artículo existente"<<endl;
	cin>>OP5;
	
	if (OP5==1)
	{
		fflush(stdin);
		cout<<"\nCódigo de articulo: "<<ca;	
		A_Articulos[CA].cod_a = ca;
		fflush(stdin);
		cout<<"\nNombre: ";
		cin>>R;
			
		int p = Buscar(R);
			
		if (p==-1)
		{
			strcpy(A_Articulos[CA].nombre_a, R);			
			fflush(stdin);
			cout<<"Descripción: ";
			cin.getline(A_Articulos[CA].descripcion_a, 80, '\n');
			cout<<"Precio Unitario: Q. ";
			cin>>A_Articulos[CA].pUnitario_a;
			cout<<"\nIngrese código de proveedor: ";
			cin>>Cod;
		
			OP = 1;
			int b = Buscar2(Cod);
			OP = 4;
						
			if (b==-1)
			{
				system("cls");
				cout<<"Proveedor no existente.\nPor favor, inténtelo de nuevo.";
				getch();
			}
			else
			{
				A_Articulos[CA].codP_a = A_Proveedores[b].cod_p;
				cout<<"Cantidad: ";
				cin>>c;
				do
				{
					cout<<"\n\n¿Dónde desea almacenar el artículo?"<<endl<<endl;
					cout<<"1. Bodega"<<endl;
					cout<<"2. Tienda"<<endl;
					cin>>OP3;
				
					if (OP3==1)
						A_Articulos[CA].cantidad_a_B+=c;
						
					else if (OP3==2)
						A_Articulos[CA].cantidad_a_T+=c;
							
					else 
						cout<<endl<<"Porfavor, ingrese una opción válida."<<endl;
							
				} while ((OP3!=1) && (OP3!=2));
				A_Proveedores[b].contProveedor++;
				CA++;
				ca++;
				getch();
			}			
	
		}
		else 
		{
			system("cls");
			cout<<"Nombre ya existente"<<endl;
			cout<<"\nPor favor, inténtelo de nuevo.";
			getch();
		}
	}
	
	else if (OP5==2)
	{
		fflush(stdin);
		cout<<"\nIngrese código de articulo: ";
		cin>>Cod;
		
		int P = Buscar2(Cod);
				
		if (P!=-1)
		{
			cout<<"\nNombre del artículo: "<<A_Articulos[P].nombre_a<<endl;
			cout<<"Descripción: "<<A_Articulos[P].descripcion_a<<endl;
			cout<<"Precio Unitario: Q. "<< fixed << setprecision(2) <<A_Articulos[P].pUnitario_a<<endl; //DECIMALES
			cout<<"Código de proveedor: "<<A_Articulos[P].codP_a<<endl;
			cout<<"\nIngrese cantidad a almacenar: ";
			cin>>c;
					
			do
			{
				cout<<"\n¿Dónde desea almacenar el artículo?"<<endl<<endl;
				cout<<"1. Bodega"<<endl;
				cout<<"2. Tienda"<<endl;
				cin>>OP3;
			
				if (OP3==1)
					A_Articulos[P].cantidad_a_B+=c;
					
				else if (OP3==2)
					A_Articulos[P].cantidad_a_T+=c;
						
				else 
				{
					cout<<endl<<"Porfavor, ingrese una opción válida."<<endl;
					getch();	
				}		
			} while ((OP3!=1) && (OP3!=2));	
			getch();
		}
		else if(P==-1)
		{
			system("cls");
			cout<<"Código de articulo no exitente.\nPor favor, inténtelo de nuevo";
			getch();
		}
	}
	else 
	{
		system("cls");
		cout<<"Opción inválida";
		getch();
	}
}

void Agregar_E()
{	
	system("cls");
	cout << "\033[1;33m";
	cout<<" ------------------------------ AGREGAR EMPLEADOS ------------------------------ "<<endl<<endl;
	cout << "\033[1;0m";
	fflush(stdin);
	cout<<"Código de empleado: "<<ce<<endl;
	A_Empleados[CE].cod_e = ce;
	
	cout<<endl<<"DPI: ";
	cin>>R;
	
	int P = Buscar(R);
	
	if (P==-1)
	{
		strcpy(A_Empleados[CE].DPI_e, R);
		fflush(stdin);
		cout<<"Nombre: ";
		cin.getline(A_Empleados[CE].nombre_e, 20, '\n');
		cout<<"Apellido: ";
		cin.getline(A_Empleados[CE].apellido_e, 20, '\n');	
		cout<<"Teléfono: ";
		cin>>A_Empleados[CE].telefono_e;
		
		CE++;
		ce++;	
		getch();
	}
	
	else 
	{
		system("cls");
		cout<<"Empleado ya existente.\nPor favor, inténtelo de nuevo."<<endl;
		getch();
	}
}

void Agregar_F() {
	system("cls");
    fflush(stdin);
    cout << "\033[1;33m";
    cout << " ------------------------------ FACTURA NUEVA ------------------------------ " << endl << endl;
    cout << "\033[1;0m";

	int opc;
    time_t now = time(0);
    struct tm* currentTime = localtime(&now);
    int year = currentTime->tm_year + 1900;
    int month = currentTime->tm_mon + 1;
    int day = currentTime->tm_mday;
    int hour = currentTime->tm_hour;
    int minute = currentTime->tm_min;
    int second = currentTime->tm_sec;
    A_Fac[CF].year= year;
	A_Fac[CF].month = month;
	A_Fac[CF].day= day;
	A_Fac[CF].hour = hour;
	A_Fac[CF].minute = minute;
	A_Fac[CF].second = second;
	
	cout<<"Correlativo de Factura "<<cf<<endl;
	A_Fac[CF].correlativo = cf;	
	
    cout << "Fecha y hora: " << day << "/" << month << "/" << year << " " << hour << ":" << minute << ":" << second << endl;
	
    cout << "Código del empleado: ";
    cin >> A_Fac[CF].codEmpleado;

    bool empleadoEncontrado = false;
    for (int i = 0; i < CE; i++) {
        if (A_Empleados[i].cod_e == A_Fac[CF].codEmpleado) {
            empleadoEncontrado = true;
            posE=i; 
            cout << "Cajero: " << A_Empleados[i].nombre_e << " " << A_Empleados[i].apellido_e << endl;
            break;
        }
    }

    if (!empleadoEncontrado) {
        cout << "Empleado no encontrado. Intente de nuevo." << endl;
        getch();
        return;
    }
    cout << "------------------------------------------------------------" << endl << endl;
    cout << "NIT: ";
    cin >> arregloFacturas[CF].NIT_c;

    int clienteIndex = -1;
    
	bool clienteEnc = false;
	
    for (int e = 0; e < CC; e++) {
        if (strcmp(A_Clientes[e].NIT_c, arregloFacturas[CF].NIT_c) == 0) {
            clienteEnc = true;
            clienteIndex = e;
            cout << "Datos del cliente: " << A_Clientes[e].nombre_c << " " << A_Clientes[e].apellido_c << endl
                << "tel: " << A_Clientes[e].telefono_c << endl;
                strcpy(A_Fac[CF].nombre, A_Clientes[clienteIndex].nombre_c);
                strcpy(A_Fac[CF].apellido, A_Clientes[clienteIndex].apellido_c);
            break;
        }
    
	}

    if (!clienteEnc) {
        cout << "El NIT del cliente no existe. ¿Desea agregar un nuevo cliente? (1: Sí, 0: No): ";
        cin >> opc;

        if (opc == 1) {
			cout <<endl<< "Nuevo Cliente:" << endl<<endl;
			
			OP=2;
			int P = Agregar_C();
			OP=5;
			
			if (P == -1)
			{
				strcpy(arregloFacturas[CF].NIT_c, A_Clientes[CC-1].NIT_c);
				strcpy(A_Fac[CF].nombre, A_Clientes[CC-1].nombre_c);
            	strcpy(A_Fac[CF].apellido, A_Clientes[CC-1].apellido_c);
                clienteIndex = CC-1;
          		cout << "Nuevo cliente agregado." << endl;				
			}
			else
			{
				cout<<"No es posible duplicar clientes";
				getch();
				return;
			}

        } else {
            cout << "Factura anulada." << endl;
            getch();
            return;
        }
    }

    int detalleIndex = 0;

    do {
        int codigoArticulo;
        cout << endl << " " << endl;
		cout << "Código del artículo: ";
        cin >> codigoArticulo;

        int articuloIndex = -1;

        for (int i = 0; i < CA; i++) {
            if (A_Articulos[i].cod_a == codigoArticulo) {
                articuloIndex = i;
                break;
            }
        }

        if (articuloIndex != -1) {
        	
            cout << "Nombre del artículo: " << A_Articulos[articuloIndex].nombre_a << endl;
            cout << "Precio unitario: Q. " << A_Articulos[articuloIndex].pUnitario_a << endl;

            int cantidad;
            cout << "Cantidad: ";
            cin >> cantidad;
            
            A_Empleados[posE].contEmpleados += cantidad;

            float subtotal = cantidad * A_Articulos[articuloIndex].pUnitario_a;

            A_Fac[CF].arregloDetalle[detalleIndex].cod_pr = codigoArticulo;
            strcpy(A_Fac[CF].arregloDetalle[detalleIndex].nombre, A_Articulos[articuloIndex].nombre_a);
            A_Fac[CF].arregloDetalle[detalleIndex].cantidad = cantidad;
            A_Fac[CF].arregloDetalle[detalleIndex].PrecioUnitario = A_Articulos[articuloIndex].pUnitario_a;
            A_Fac[CF].arregloDetalle[detalleIndex].Subtotal = subtotal;

            detalleIndex++;

            cout << "Artículo agregado a la factura." << endl;

            cout << "¿Desea agregar otro artículo? (1: Sí, 0: No): ";
            int agregarMas;
            cin >> agregarMas;

            if (agregarMas == 0) {
                break;
            }
        } else {
            cout << "El artículo no existe. Intente de nuevo." << endl;
            getch();
        }
    } while (true);

    A_Fac[CF].cantidad = detalleIndex;
    A_Fac[CF].subtotal = 0;
    A_Fac[CF].iva = 0;

    for (int i = 0; i < detalleIndex; i++) {
        A_Fac[CF].subtotal += A_Fac[CF].arregloDetalle[i].Subtotal;
    }

    A_Fac[CF].iva = A_Fac[CF].subtotal * 0.12;
    A_Fac[CF].total = A_Fac[CF].subtotal + A_Fac[CF].iva;

    for (int i = 0; i < detalleIndex; i++) {
        int codigoArticulo = A_Fac[CF].arregloDetalle[i].cod_pr;
        int cantidadVenta = A_Fac[CF].arregloDetalle[i].cantidad;

        for (int j = 0; j < CA; j++) {
            if (A_Articulos[j].cod_a == codigoArticulo) {
                if (A_Articulos[j].cantidad_a_T >= cantidadVenta) {
                    A_Articulos[j].cantidad_a_T -= cantidadVenta;
                    A_Articulos[j].vendidos+= cantidadVenta;
                    A_Clientes[clienteIndex].contClientes+= cantidadVenta;
                } else {
                    cout << "Error: No hay suficientes existencias del artículo " << A_Articulos[j].nombre_a << endl;
                    getch();
//                    return;
                }
                break;
            }
        }
    }

    // Mostrar el resumen de la factura
    system("cls");
    cout << endl << " " << endl;
    cout << "\033[1;34m";
    cout << endl << "----------------------------- Resumen de la Factura -----------------------------" << endl;
    cout << "\033[1;0m";
    cout << "Número de Factura: " << A_Fac[CF].correlativo<< endl;
    cout << "Fecha y hora: " << A_Fac[CF].day << "/" << A_Fac[CF].month << "/" << A_Fac[CF].year << " " << A_Fac[CF].hour << ":" << A_Fac[CF].minute << ":" << A_Fac[CF].second << endl;
    cout << "Código de Empleado: " << A_Fac[CF].codEmpleado << endl;
    cout << "Nombre del Cliente: " << A_Fac[CF].nombre<<" "<< A_Fac[CF].apellido<<endl;
    cout << "NIT del Cliente: " << arregloFacturas[CF].NIT_c << endl;
    cout << "Cantidad de Productos diferentes: " << A_Fac[CF].cantidad << endl;
    cout << "Subtotal: Q. " << A_Fac[CF].subtotal << endl;
    cout << "IVA (12%): Q. " << A_Fac[CF].iva << endl;
    cout << "Total: Q. " << A_Fac[CF].total << endl;

    int decisionCompra;
    cout << endl << " " << endl;
    cout << "¿Desea realizar la compra? (1: Sí, 0: No): ";
    cin >> decisionCompra;

    if (decisionCompra == 0) {
        for (int i = 0; i < detalleIndex; i++) {
            int codigoArticulo = A_Fac[CF].arregloDetalle[i].cod_pr;
            int cantidadVenta = A_Fac[CF].arregloDetalle[i].cantidad;

            for (int j = 0; j < CA; j++) {
                if (A_Articulos[j].cod_a == codigoArticulo) {
                    A_Articulos[j].cantidad_a_T += cantidadVenta;
                    A_Articulos[j].vendidos-= cantidadVenta;
               		A_Empleados[posE].contEmpleados-=cantidadVenta;
                  	A_Clientes[clienteIndex].contClientes-= cantidadVenta;
                    break;
                }
            }
        }
		cout << endl << " " << endl;
        cout << "Compra anulada. La cantidad de productos ha sido devuelta al inventario." << endl;
    }
	
	else
	{
		cf++;
	    CF++;
	    cout << "\033[1;32m";
		cout<<endl<<"-------------------Transacción realizada exitósamente-------------------"<<endl;	
		cout << "\033[1;0m";
	}
	
    getch();
}

void Eliminar_P()
{
	system("cls");
	cout << "\033[1;31m";
	cout<<" ------------------------------ ELIMINAR PROVEEDOR ------------------------------ "<<endl<<endl;
	cout << "\033[1;0m";
	cout<<"Ingrese código del proveedor a eliminar: ";
	cin>>Cod;
	
	int P = Buscar2(Cod);
	
	if (P == -1)
	{
		cout << "\033[1;31m";
		cout<<"\nProveedor no encontrado";
		cout << "\033[1;0m";
		getch();
	}
	
	else 
	{
		while (P<CP)
		{
			A_Proveedores[P].cod_p = A_Proveedores[P+1].cod_p;
			strcpy(A_Proveedores[P].direccion_p, A_Proveedores[P+1].direccion_p);
			strcpy(A_Proveedores[P].NIT_p, A_Proveedores[P+1].NIT_p);
			strcpy(A_Proveedores[P].nombre_p, A_Proveedores[P+1].nombre_p);
			A_Proveedores[P].telefono_p=A_Proveedores[P+1].telefono_p;
			P++;
		}
		CP--;
		cout << "\033[1;31m";
		cout<<"\nProveedor eliminado."<<endl<<endl;
		cout << "\033[1;0m";
		getch();
	}
}

void Eliminar_C()
{
	system("cls");
	cout << "\033[1;31m";
	cout<<" ------------------------------ ELIMINAR CLIENTE ------------------------------ "<<endl<<endl;
	cout << "\033[1;0m";
	cout<<"Ingrese NIT del cliente a eliminar: ";
	cin>>R;
	
	int P = Buscar(R);
	
	if (P == -1)
	{
		cout<<"\nCliente no encontrado";
		getch();
	}
	
	else 
	{
		while (P<CC)
		{
			strcpy(A_Clientes[P].apellido_c, A_Clientes[P+1].apellido_c);
			strcpy(A_Clientes[P].direccion_c, A_Clientes[P+1].direccion_c);
			strcpy(A_Clientes[P].NIT_c, A_Clientes[P+1].NIT_c);
			strcpy(A_Clientes[P].DPI_c, A_Clientes[P+1].DPI_c);
			strcpy(A_Clientes[P].nombre_c, A_Clientes[P+1].nombre_c);
			A_Clientes[P].telefono_c = A_Clientes[P+1].telefono_c;
			A_Clientes[P].edad_c = A_Clientes[P+1].edad_c;
			P++;
		}
		CC--;
		cout << "\033[1;31m";
		cout<<"\nCliente eliminado."<<endl<<endl;
		cout << "\033[1;0m";
		getch();
	}
}

void Eliminar_A()
{
	system("cls");
	cout << "\033[1;31m";
	cout<<" ------------------------------ ELIMINAR ARTICULO ------------------------------ "<<endl<<endl;
	cout << "\033[1;0m";
	cout<<"Ingrese código del articulo a eliminar: ";
	cin>>Cod;
	
	int P = Buscar2(Cod);
	
	if (P == -1)
	{
		cout << "\033[1;31m";
		cout<<"\nEl artículo no existe.";
		cout << "\033[1;0m";
		getch();
	}
	
	else 
	{
		while (P<CA)
		{
			A_Articulos[P].cod_a = A_Articulos[P+1].cod_a;
			strcpy(A_Articulos[P].nombre_a, A_Articulos[P+1].nombre_a);
			strcpy(A_Articulos[P].descripcion_a, A_Articulos[P+1].descripcion_a);
			A_Articulos[P].pUnitario_a = A_Articulos[P+1].pUnitario_a;
			A_Articulos[P].codP_a = A_Articulos[P+1].codP_a;
			A_Articulos[P].cantidad_a_B = A_Articulos[P+1].cantidad_a_B;
			A_Articulos[P].cantidad_a_T = A_Articulos[P+1].cantidad_a_T;
			P++;
		}
		CA--;
		cout << "\033[1;31m";
		cout<<"\nArtículo eliminado."<<endl<<endl;
		cout << "\033[1;0m";
		getch();
	}
}

void Eliminar_E()
{
	system("cls");
	cout << "\033[1;31m";
	cout<<" ------------------------------ ELIMINAR EMPLEADO ------------------------------ "<<endl<<endl;
	cout << "\033[1;0m";
	cout<<"Ingrese código de empleado: ";
	cin>>Cod;
	
	int P = Buscar2(Cod);
	
	if (P == -1)
	{
		cout << "\033[1;31m";
		cout<<"\nEmpleado no encontrado";
		cout << "\033[1;0m";
		getch();
	}
	else 
	{
		while (P<CE)
		{
			strcpy(A_Empleados[P].apellido_e, A_Empleados[P+1].apellido_e);
			A_Empleados[P].cod_e = A_Empleados[P+1].cod_e;
			strcpy(A_Empleados[P].DPI_e, A_Empleados[P+1].DPI_e);
			strcpy(A_Empleados[P].nombre_e, A_Empleados[P+1].nombre_e);
			A_Empleados[P].telefono_e = A_Empleados[P+1].telefono_e;
			P++;
		}
		CE--;
		cout << "\033[1;31m";
		cout<<"\nEmpleado eliminado."<<endl<<endl;
		cout << "\033[1;0m";
		getch();
	}
}

void Eliminar_F() {
    system("cls");
	cout << "\033[1;31m";
    cout << " ------------------------------ ELIMINAR FACTURA ------------------------------ " << endl << endl;
    cout << "\033[1;0m";
    cout << "Ingrese el correlativo de la factura a eliminar: ";
    cin >> Cod;

    int facturaIndex = -1;

    for (int i = 0; i < CF; i++) {
        if (A_Fac[i].correlativo == Cod) {
            facturaIndex = i;
            break;
        }
    }

    if (facturaIndex == -1) {
    	cout << "\033[1;31m";
        cout << "\nFactura no encontrada." << endl;
        cout << "\033[1;0m";
        getch();
    } else {
        // Eliminar la factura desplazando los elementos hacia arriba
        for (int i = facturaIndex; i < CF - 1; i++) {
            A_Fac[i] = A_Fac[i + 1];
        }
        CF--;

        cout << "\nFactura eliminada." << endl << endl;
        getch();
    }
}

void Modificar_P()
{
	system("cls");
	cout << "\033[1;36m";
	cout<<" ------------------------------ MODIFICAR PROVEEDOR ------------------------------ "<<endl<<endl;
	cout << "\033[1;0m";
	cout<<"Ingrese código del proveedor a modificar: ";
	cin>>Cod;
	
	int P = Buscar2(Cod);
	
	if (P == -1)
	{
		cout<<"\nProveedor no encontrado";
		getch();
	}
	else 
	{
		cout<<endl<<endl<<"Ingrese los nuevos datos"<<endl<<endl;
		cout<<"Código del proveedor: "<<A_Proveedores[P].cod_p<<endl;
		fflush(stdin);
		cout<<"NIT: ";
		cin>>R;

		strcpy(M, A_Proveedores[P].NIT_p);
		strcpy(A_Proveedores[P].NIT_p, A_Proveedores[CP].NIT_p);
		int p = Buscar(R);
		
		if (p == -1)
		{
			strcpy(A_Proveedores[P].NIT_p, R);
			fflush(stdin);
			cout<<"Nombre: ";
			cin.getline(A_Proveedores[P].nombre_p, 30, '\n');
			cout<<"Dirección: ";
			cin.getline(A_Proveedores[P].direccion_p, 40, '\n');	
			cout<<"Teléfono: ";
			cin>>A_Proveedores[P].telefono_p;			
		}	
	
		else
		{
			strcpy(A_Proveedores[P].NIT_p, M);
			cout<<endl<<"Proveedor ya existente.\nPor favor, inténtelo de nuevo.";
			getch();
		}
	}
}

void Modificar_C()
{
	system("cls");
	cout << "\033[1;36m";
	cout<<" ------------------------------ MODIFICAR CLIENTE ------------------------------ "<<endl<<endl;
	cout << "\033[1;0m";
	cout<<"Ingrese NIT del cliente a modificar: ";
	cin>>R;
	
	int P = Buscar(R);
	
	if (P == -1)
	{
		cout<<"\nCliente no encontrado";
		getch();
	}
	else
	{
		cout<<"\nIngrese los nuevos datos: "<<endl<<endl;
		cout<<"NIT: ";
		cin>>R;
		
		int p = Buscar(R);
		if (p==-1)
		{
			strcpy(A_Clientes[P].NIT_c, R);
			fflush(stdin);
			cout<<"Nombre: ";
			cin.getline(A_Clientes[P].nombre_c, 20, '\n');
			cout<<"Apellido: ";
			cin.getline(A_Clientes[P].apellido_c, 15, '\n');
			cout<<"Dirección: ";
			cin.getline(A_Clientes[P].direccion_c, 40, '\n');
			cout<<"DPI: ";
			cin>>A_Clientes[P].DPI_c;
			cout<<"Teléfono: ";
			cin>>A_Clientes[P].telefono_c;
			cout<<"Edad: ";
			cin>>A_Clientes[P].edad_c;		
		}
		
		else 
		{
			cout<<endl<<"Cliente ya existente, según NIT.\nPor favor, inténtelo de nuevo."<<endl;
			getch();
		}
	}
}

void Modificar_A()
{
	system("cls");
	cout << "\033[1;36m";
	cout<<" ------------------------------ MODIFICAR ARTÍCULO ------------------------------ "<<endl<<endl;
	cout << "\033[1;0m";
	cout<<"Ingrese código del artículo a modificar: ";
	cin>>Cod;
	
	int P = Buscar2(Cod);
	
	if (P == -1)
	{
		cout<<"\nEl artículo no existe.\nPor favor, inténtelo de nuevo. ";
		getch();
	}
	
	else 
	{
		cout<<endl<<endl<<"Ingrese los nuevos datos de <"<<A_Articulos[P].nombre_a<<">"<<endl<<endl;
		fflush(stdin);
		cout<<"Código de proveedor: ";
		cin>>Cod;
		
		OP=1;
		int q = Buscar2(Cod);
		OP=4;
		
		if (q != -1)
		{
			A_Articulos[P].codP_a = A_Proveedores[q].cod_p;
			
			cout<<"Nombre: ";
			cin>>R;
			
			strcpy(M, A_Articulos[P].nombre_a);
			strcpy(A_Articulos[P].nombre_a, A_Articulos[CA].nombre_a);
			
			int p = Buscar(R);
			
			while (p!=-1)
			{
				cout<<endl<<"\nNombre de artículo ya existente, ingrese un nombre no duplicado.";
				cout<<"\nNombre: ";
				cin>>R;
				p = Buscar(R);
			}
			strcpy(A_Articulos[P].nombre_a, R);
			
			fflush(stdin);
			cout<<"Descripción: ";
			cin.getline(A_Articulos[P].descripcion_a, 80, '\n');
			cout<<"Precio unitario: Q.";
			cin>>A_Articulos[P].pUnitario_a;	
			
			cout<<endl<<"¡Articulo modificado corectamente!";		
		}
		else
		{
			system("cls");
			cout<<"Proveedor no existénte.\nPor favor, inténtelo de nuevo.";
		}
		getch();
	}
}

void Modificar_E()
{
	system("cls");
	cout << "\033[1;36m";
	cout<<" ------------------------------ MODIFICAR EMPLEADO ------------------------------ "<<endl<<endl;
	cout << "\033[1;0m";
	cout<<"Ingrese código de empleado a modificar: ";
	cin>>Cod;
	
	int P = Buscar2(Cod);
	
	if (P == -1)
	{
		cout<<"\nEmpleado no encontrado";
		getch();
	}
	
	else
	{
		cout<<"\nIngrese los nuevos datos: "<<endl<<endl;
		cout<<"Código de empleado: "<<A_Empleados[P].cod_e<<endl;
		cout<<"DPI: ";
		cin>>R;
		
		strcpy(M, A_Empleados[P].DPI_e);
		strcpy(A_Empleados[P].DPI_e, A_Empleados[CP].DPI_e);
		int p = Buscar(R);
		
		if (p == -1)
		{
			strcpy(A_Empleados[P].DPI_e, R);
			fflush(stdin);
			cout<<"Nombre: ";
			cin.getline(A_Empleados[P].nombre_e, 20, '\n');
			cout<<"Apellido: ";
			cin.getline(A_Empleados[P].apellido_e, 20, '\n');	
			cout<<"Teléfono: ";
			cin>>A_Empleados[P].telefono_e;		
		}
		
		else 
		{
			strcpy(A_Empleados[P].DPI_e, M);
			cout<<endl<<"Empleado ya existente.\nPor favor, inténtelo de nuevo."<<endl;
			getch();
		}
	}	
}

void Buscar_P()
{
	system("cls");
	cout << "\033[34m";
	cout<<" ------------------------------ BUSCAR PROVEEDOR ------------------------------ "<<endl<<endl;
	cout << "\033[1;0m";
	cout<<"Ingrese código de proveedor: ";
	cin>>Cod;
	
	int P = Buscar2(Cod);
	
	if (P == -1)
	{
		cout<<"\nProveedor no encontrado";
		getch();
	}
	
	else
	{
		cout<<endl<<"Los datos del proveedor son: "<<endl<<endl;
		cout<<"Código No. "<<A_Proveedores[P].cod_p<<endl;
		cout<<"Nombre: "<<A_Proveedores[P].nombre_p<<endl;
		cout<<"NIT: "<<A_Proveedores[P].NIT_p<<endl;
		cout<<"Dirección: "<<A_Proveedores[P].direccion_p<<endl;
		cout<<"Teléfono: "<<A_Proveedores[P].telefono_p<<endl;
		getch();
	}
}

void Buscar_C()
{
	system("cls");
	cout << "\033[34m";
	cout<<" ------------------------------ BUSCAR CLIENTE ------------------------------ "<<endl<<endl;
	cout << "\033[0m";
	cout<<"Ingrese No. NIT del cliente: ";
	cin>>R;
	
	int P = Buscar(R);	
	
	if (P == -1)
	{
		cout<<"\nCliente no encontrado";
		getch();
	}
	
	else 
	{
		cout<<"\nLos datos del cliente son: "<<endl<<endl;
		cout<<"Nombre: "<<A_Clientes[P].nombre_c<<endl;
		cout<<"Apellido: "<<A_Clientes[P].apellido_c<<endl;
		cout<<"DPI: "<<A_Clientes[P].DPI_c<<endl;
		cout<<"NIT: "<<A_Clientes[P].NIT_c<<endl;
		cout<<"Dirección: "<<A_Clientes[P].direccion_c<<endl;
		cout<<"Teléfono: "<<A_Clientes[P].telefono_c<<endl;
		cout<<"Edad: "<<A_Clientes[P].edad_c<<endl;
		getch();		
	}
}

void Buscar_A()
{
	system("cls");
	cout << "\033[34m";
	cout<<" ------------------------------ BUSCAR ARTICULO ------------------------------ "<<endl<<endl;
	cout << "\033[0m";
	cout<<"Ingrese código del artículo: ";
	cin>>Cod;
	
	int P = Buscar2(Cod);	
	
	if (P == -1)
	{
		cout<<"\nArtículo no existente";
		getch();
	}
	
	else 
	{
		cout<<"\nDatos del artículo: "<<endl<<endl;
		cout<<"Código: "<<A_Articulos[P].cod_a<<endl;
		cout<<"Nombre: "<<A_Articulos[P].nombre_a<<endl;
		cout<<"Descripción: "<<A_Articulos[P].descripcion_a<<endl;
		cout<<"Precio Unitario: Q."<< fixed << setprecision(2) <<A_Articulos[P].pUnitario_a<<endl;
		cout<<"Código de proveedor: "<<A_Articulos[P].codP_a<<endl<<endl;
		cout<<"\tExistencias"<<endl;
		cout<<"Tienda: "<<A_Articulos[P].cantidad_a_T<<setw(15)<<"Bodega: "<<A_Articulos[P].cantidad_a_B; 

		getch();		
	}
}

void Buscar_E()
{
	system("cls");
	cout << "\033[34m";	
	cout<<" ------------------------------ BUSCAR EMPLEADO ------------------------------ "<<endl<<endl;
	cout << "\033[0m";
	cout<<"Ingrese código de empleado: ";
	cin>>Cod;
	
	int P = Buscar2(Cod);	
	
	if (P == -1)
	{
		cout<<"\nEmpleado no encontrado";
		getch();
	}
	
	else 
	{
		cout<<"\nLos datos del empleado son: "<<endl<<endl;
		cout<<"Código de empleado: "<<A_Empleados[P].cod_e<<endl;
		cout<<"Nombre: "<<A_Empleados[P].nombre_e<<endl;
		cout<<"Apellido: "<<A_Empleados[P].apellido_e<<endl;
		cout<<"DPI: "<<A_Empleados[P].DPI_e<<endl;
		cout<<"Teléfono: "<<A_Empleados[P].telefono_e<<endl;
		getch();		
	}
}

void Buscar_F()
{
    system("cls");
    cout << "\033[34m";
	cout << " ------------------------------ BUSCAR FACTURA ------------------------------ " << endl << endl;
	cout << "\033[0m";
    int correlativo;
    cout << "Ingrese correlativo de factura: ";
    cin >> correlativo;

    bool facturaEncontrada = false;

    for (int i = 0; i < CF; i++) { 
        if (A_Fac[i].correlativo == correlativo) {
            facturaEncontrada = true;
            cout << "----------------------------- Detalles de la Factura -----------------------------" << endl;
            cout << "Número de Factura: " << A_Fac[i].correlativo << endl;
            cout << "Fecha y hora: " << A_Fac[i].day << "/" << A_Fac[i].month << "/" << A_Fac[i].year << " " << A_Fac[i].hour << ":" << A_Fac[i].minute << ":" << A_Fac[i].second << endl;
            cout << "Código de Empleado: " << A_Fac[i].codEmpleado << endl;
            cout << "Nombre del Cliente: " << A_Fac[i].nombre << " " << A_Fac[i].apellido << endl;
            cout << "NIT del Cliente: " << arregloFacturas[i].NIT_c << endl;
            cout << "Cantidad de Productos diferentes: " << A_Fac[i].cantidad << endl;
            cout << "Subtotal: Q. " << A_Fac[i].subtotal << endl;
            cout << "IVA (12%): Q. " << A_Fac[i].iva << endl;
            cout << "Total: Q. " << A_Fac[i].total << endl;
            getch();
            break;
        }
    }

    if (!facturaEncontrada) {
        cout << "Factura no encontrada." << endl;
    }
}


void Reportar_P()
{
	y = 5;
	system("cls");
	
	cout<<"\n ------------- REPORTE DE PROVEEDORES ------------- "<<endl<<endl;
	
	gotoxy(0,3); cout<<"Código Proveedor";
	gotoxy(20,3); cout<<"Nombre";
	gotoxy(55,3); cout<<"NIT";	
	gotoxy(70,3); cout<<"Teléfono";
	gotoxy(85,3); cout<<"Dirección";
	
	for (int i=0; i<CP; i++)
	{
		gotoxy(0,y); cout<<A_Proveedores[i].cod_p;
		gotoxy(20,y); cout<<A_Proveedores[i].nombre_p;
		gotoxy(55,y); cout<<A_Proveedores[i].NIT_p;
		gotoxy(70,y); cout<<A_Proveedores[i].telefono_p;
		gotoxy(85,y); cout<<A_Proveedores[i].direccion_p<<endl;
		y++;	
	}
	getch();	
}

void Reportar_C()
{
	y = 5;
	system("cls");
	
	cout<<"\n ------------- REPORTE DE CLIENTES ------------- "<<endl<<endl;
	
	gotoxy(0,3); cout<<"Nombre";
	gotoxy(20,3); cout<<"Apellido";
	gotoxy(35,3); cout<<"DPI";
	gotoxy(55,3); cout<<"NIT";
	gotoxy(68,3); cout<<"Teléfono";
	gotoxy(80,3); cout<<"Edad";
	gotoxy(86,3); cout<<"Dirección";
	
	
	for (int i=0; i<CC; i++)
	{
		gotoxy(0,y); cout<<A_Clientes[i].nombre_c;
		gotoxy(20,y); cout<<A_Clientes[i].apellido_c;
		gotoxy(35,y); cout<<A_Clientes[i].DPI_c;
		gotoxy(55,y); cout<<A_Clientes[i].NIT_c;
		gotoxy(68,y); cout<<A_Clientes[i].telefono_c;
		gotoxy(80,y); cout<<A_Clientes[i].edad_c<<endl;
		gotoxy(86,y); cout<<A_Clientes[i].direccion_c;
		y++;	
	}
	getch();
}

void Reportar_A()
{
	system("cls");
	y=5;
	
    cout<< "\n\tREPORTE DE INVENTARIO";
    cout<< "\n========================================================"<<endl;

    gotoxy (0,3); cout<< "CÓDIGO";
    gotoxy (10,3); cout<< "NOMBRE";
	gotoxy (30,3); cout<< "PRECIO"; 
	gotoxy (40,3); cout<< "TIENDA";
	gotoxy (50,3); cout<< "BODEGA";

    cout<< "\n========================================================"<<endl;

    for (int i = 0; i < CA; i++)
    {
    	gotoxy (0,y); cout<< A_Articulos[i].cod_a;
        gotoxy (10,y); cout<< A_Articulos[i].nombre_a;
        gotoxy (30, y); cout<< fixed << setprecision(2) << A_Articulos[i].pUnitario_a;
        gotoxy (40, y); cout<< A_Articulos[i].cantidad_a_T;
        gotoxy (50, y); cout<< A_Articulos[i].cantidad_a_B<<endl;
        y++;
    }	
	getch();
}


void Reportar_E(){
	y = 5;
	system("cls");
	
	cout<<"\n ------------- REPORTE DE EMPLEADOS ------------- "<<endl<<endl;

	gotoxy(0,3); cout<<"Código Empleado";	
	gotoxy(20,3); cout<<"Nombre";
	gotoxy(45,3); cout<<"Apellido";
	gotoxy(70,3); cout<<"DPI";
	gotoxy(85,3); cout<<"Teléfono";
	
	for (int i=0; i<CE; i++)
	{
		gotoxy(0,y); cout<<A_Empleados[i].cod_e;
		gotoxy(20,y); cout<<A_Empleados[i].nombre_e;
		gotoxy(45,y); cout<<A_Empleados[i].apellido_e;
		gotoxy(70,y); cout<<A_Empleados[i].DPI_e;
		gotoxy(85,y); cout<<A_Empleados[i].telefono_e;
		y++;	
	}
	getch();
}


void Reportar_F() {
    system("cls");
    y = 5;

    cout << "\n ------------- REPORTE DE FACTURAS ------------- " << endl << endl;

    gotoxy(0, 3);
    cout << "Correlativo";
    gotoxy(20, 3);
    cout << "Cliente";
    gotoxy(45, 3);
    cout << "NIT";
    gotoxy(70, 3);
    cout << "Fecha";
    gotoxy(90, 3);
    cout << "Total";

    for (int i = 0; i < CF; i++) {
        gotoxy(0, y);
        cout << A_Fac[i].correlativo;
        gotoxy(20, y);
        cout << A_Fac[i].nombre << " " << A_Fac[i].apellido;
        gotoxy(45, y);
        cout << arregloFacturas[i].NIT_c;
        gotoxy(70, y);
        cout << A_Fac[i].day << "/" << A_Fac[i].month << "/" << A_Fac[i].year << " " << A_Fac[i].hour << ":" << A_Fac[i].minute << ":" << A_Fac[i].second;
        gotoxy(90, y);
        cout << A_Fac[i].total;
        y++;
    }

    getch();
}



void Traslado_A()
{
	int OP4;
	int Cod;
	system("cls");
	cout<<" ------------- TRASLADO DE ARTICULOS ------------- "<<endl;
	
	cout<<"Ingrese código de artículo: ";
	cin>>Cod;
	
	int P = Buscar2(Cod);
	
	if (P==-1)
	{
		system("cls");
		cout<<"El artículo no existe. Por favor, inténtelo de nuevo.";
		getch();
	}
	else
	{
		cout<<"\n\nTraslado de "<<A_Articulos[P].nombre_a<<endl<<endl;
		cout<<"Cantidad existente: "<<endl;
		cout<<"Tienda: "<<A_Articulos[P].cantidad_a_T<<endl<<"Bodega: "<<A_Articulos[P].cantidad_a_B<<endl<<endl;
	
		cout<<"\tTRASLADO "<<endl;
		cout<<"1. Bodega a Tienda"<<endl;
		cout<<"2. Tienda a Bodega"<<endl;
		cout<<"Ingrese el traslado que desea realizar: ";
		cin>>OP4;
		
		switch (OP4)
		{
			case 1:
				cout<<"\n\nIngrese la cantidad a trasladar: ";
				cin>>c;
				
				if (A_Articulos[P].cantidad_a_B>=c)
				{
					A_Articulos[P].cantidad_a_B-=c;	
					A_Articulos[P].cantidad_a_T+=c;	
				}
				else if (A_Articulos[P].cantidad_a_B<c)
				{
					system("cls");
					cout<<"\nNo hay suficientes articulos existentes para realizar la transacción"<<endl;
					cout<<"Por favor, inténtelo de nuevo.";
					getch();
				}
				else if (c<=0)
				{
					system("cls");
					cout<<"Cantidad inválida.\nPor favor, inténtelo de nuevo.";
					getch();
				}
			break;
			case 2:	
				cout<<"\n\nIngrese la cantidad a trasladar: ";
				cin>>c;
				
				if (A_Articulos[P].cantidad_a_T>=c)
				{
					A_Articulos[P].cantidad_a_T-=c;	
					A_Articulos[P].cantidad_a_B+=c;
					cout<<"Traslado realizado correctamente...";	
				}
				else if (A_Articulos[P].cantidad_a_T<c)
				{
					system("cls");
					cout<<"\nNo hay suficientes articulos existentes para realizar la transacción"<<endl;
					cout<<"Por favor, inténtelo de nuevo.";
					getch();
				}
				else if (c<=0)
				{
					system("cls");
					cout<<"Cantidad inválida.\nPor favor, inténtelo de nuevo.";
					getch();
				}
			break;
			default:
				system("cls");
				cout<<"Opción inválida.";
				getch();
			break;
		}
		getch();
	}
}


//REPORTES

void Articulos_Bodega()
{
	y=5;
	float costo=0;
	system("cls");
	cout<<" ------------- INVENTARIO EN BODEGA ------------- "<<endl<<endl;
	
	gotoxy(0, 3); cout<<"Cod.Articulo";
	gotoxy(15, 3); cout<<"Cantidad";
	gotoxy(25, 3); cout<<"Nombre";
	gotoxy(45, 3); cout<<"Descripción";
	gotoxy(70, 3); cout<<"Precio Unitario";
	gotoxy(90, 3); cout<<"Costo: ";
	
	for (int i=0; i<CA; i++)
	{
		if (A_Articulos[i].cantidad_a_B !=0)
		{
			gotoxy(5, y); cout<<A_Articulos[i].cod_a;
			gotoxy(18, y); cout<<A_Articulos[i].cantidad_a_B;
			gotoxy(25, y); cout<<A_Articulos[i].nombre_a;	
			gotoxy(45, y); cout<<A_Articulos[i].descripcion_a;
			gotoxy(75, y); cout<<fixed<<setprecision(2)<<A_Articulos[i].pUnitario_a;
			gotoxy(90, y); cout<<fixed<<setprecision(2)<<A_Articulos[i].cantidad_a_B*A_Articulos[i].pUnitario_a;
			
			costo+=A_Articulos[i].cantidad_a_B*A_Articulos[i].pUnitario_a;	
			y++;			
		}
	}
	gotoxy(0, y+1); cout<<"COSTO TOTAL DE INVENTARIO EN BODEGA: Q."<<fixed<<setprecision(2)<<costo;
	getch();
}


void Articulos_Tienda()
{
	y=5;
	float costo=0;
	system("cls");
	cout<<" ------------- INVENTARIO EN TIENDA ------------- "<<endl<<endl;
	
	gotoxy(0, 3); cout<<"Cod.Articulo";
	gotoxy(15, 3); cout<<"Cantidad";
	gotoxy(25, 3); cout<<"Nombre";
	gotoxy(45, 3); cout<<"Descripción";
	gotoxy(70, 3); cout<<"Precio Unitario";
	gotoxy(90, 3); cout<<"Costo: ";
	
	for (int i=0; i<CA; i++)
	{
		if (A_Articulos[i].cantidad_a_T != 0)
		{
			gotoxy(5, y); cout<<A_Articulos[i].cod_a;
			gotoxy(18, y); cout<<A_Articulos[i].cantidad_a_T;
			gotoxy(25, y); cout<<A_Articulos[i].nombre_a;	
			gotoxy(45, y); cout<<A_Articulos[i].descripcion_a;
			gotoxy(75, y); cout<<fixed<<setprecision(2)<<A_Articulos[i].pUnitario_a;
			gotoxy(90, y); cout<<fixed<<setprecision(2)<<A_Articulos[i].cantidad_a_T*A_Articulos[i].pUnitario_a;
			
			costo+=A_Articulos[i].cantidad_a_T*A_Articulos[i].pUnitario_a;	
			y++;		
		}

	}
	gotoxy(0, y+1); cout<<"COSTO TOTAL DE INVENTARIO EN TIENDA: Q."<<fixed<<setprecision(2)<<costo;
	getch();
}


void Top_C()
{
		system("cls");
	cout<<"----------TOP 3 CLIENTES QUE MÁS PRODUCTOS COMPRAN----------"<<endl;
	int k, w, V;
	y=6;
	
	struct TOP_C
	{
		int posicion;
		int comprado;
	}clientes[CC];
	
	for (int i=0; i<CC; i++)
	{
		clientes[i].posicion = i;
		clientes[i].comprado = A_Clientes[i].contClientes;
	}
	
	for (int i=0; i<CC; i++)
	{
		for (int j=0; j<CC-1; j++)
		{
			if (clientes[j].comprado < clientes[j+1].comprado)
			{
				w = clientes[j].posicion;
				k = clientes[j].comprado;
				
				clientes[j].posicion = clientes[j+1].posicion;
				clientes[j].comprado = clientes[j+1].comprado;
				
				clientes[j+1].posicion = w;
				clientes[j+1].comprado = k;
			}
		}
	}
	
	gotoxy(0,3); cout<<"NIT	 Clien.";
	gotoxy(15,3); cout<<"Nombre";
	gotoxy(30,3); cout<<"Total de Productos comprados";
	
	for (int i=0; i<3; i++)
	{
		if (A_Clientes[clientes[i].posicion].contClientes !=0)
		{
			gotoxy(0,y-1); cout<<"#"<<i+1<<"_____________________________________________________________________________"<<endl;
			gotoxy(2, y); cout<<A_Clientes[clientes[i].posicion].NIT_c<<endl;
			gotoxy(15, y); cout<<A_Clientes[clientes[i].posicion].nombre_c<<endl;
			gotoxy(45, y); cout<<A_Clientes[clientes[i].posicion].contClientes<<endl;

			y+=3;	
		}
	}

	getch();
	return;	
}

void Top_E()
{
	system("cls");
	cout<<"----------TOP 3 EMPLEADODS QUE MÁS ARTICULOS VENDEN----------"<<endl;
	int k, w, V;
	y=6;
	
	struct TOP_E
	{
		int posicion;
		int vendido;
	}empleados[CE];
	
	for (int i=0; i<CE; i++)
	{
		empleados[i].posicion = i;
		empleados[i].vendido = A_Empleados[i].contEmpleados;
	}
	
	for (int i=0; i<CE; i++)
	{
		for (int j=0; j<CE-1; j++)
		{
			if (empleados[j].vendido < empleados[j+1].vendido)
			{
				w = empleados[j].posicion;
				k = empleados[j].vendido;
				
				empleados[j].posicion = empleados[j+1].posicion;
				empleados[j].vendido = empleados[j+1].vendido;
				
				empleados[j+1].posicion = w;
				empleados[j+1].vendido = k;
			}
		}
	}
	
	gotoxy(0,3); cout<<"Cod. Emp.";
	gotoxy(15,3); cout<<"Nombre";
	gotoxy(30,3); cout<<"Total de Productos vendidos";
	
	for (int i=0; i<3; i++)
	{
		if (A_Empleados[empleados[i].posicion].contEmpleados !=0)
		{
			gotoxy(0,y-1); cout<<"#"<<i+1<<"_____________________________________________________________________________"<<endl;
			gotoxy(5, y); cout<<A_Empleados[empleados[i].posicion].cod_e<<endl;
			gotoxy(15, y); cout<<A_Empleados[empleados[i].posicion].nombre_e<<endl;
			gotoxy(45, y); cout<<A_Empleados[empleados[i].posicion].contEmpleados<<endl;	
			y+=3;	
		}
	}
	getch();	
}

void Top_P()
{
	system("cls");
	cout<<"----------TOP 3 PROVEEDORES QUE MÁS ARTICULOS PROVEEN----------"<<endl;
	
	int w, k;
	y = 6;
	
	struct TOP_P
	{
		int posicion;
		int contador;
	}proveedores[CP];

	for (int i=0; i<CP; i++)
	{
		proveedores[i].posicion = i;
		proveedores[i].contador = A_Proveedores[i].contProveedor;
	}	
	
	for (int i=0; i<CP; i++)
	{
		for (int j=0; j<CP-1; j++)
		{
			if (proveedores[j].contador < proveedores[j+1].contador)
			{
				w = proveedores[j].posicion;
				k = proveedores[j].contador;
				
				proveedores[j].posicion = proveedores[j+1].posicion;
				proveedores[j].contador = proveedores[j+1].contador;
				
				proveedores[j+1].posicion = w;
				proveedores[j+1].contador = k;
			}
			
		}
	}
	
	gotoxy(0,3); cout<<"Cod. Prov.";
	gotoxy(15,3); cout<<"Nombre";
	gotoxy(30,3); cout<<"Total de Articulos";
	gotoxy(52,3); cout<<"Articulos proveídos";
	
	for (int i=0; i<3; i++)
	{
		if (A_Proveedores[proveedores[i].posicion].contProveedor !=0)
		{
			gotoxy(0,y-1); cout<<"#"<<i+1<<"_____________________________________________________________________________"<<endl;
			gotoxy(5, y); cout<<A_Proveedores[proveedores[i].posicion].cod_p<<endl;
			gotoxy(15, y); cout<<A_Proveedores[proveedores[i].posicion].nombre_p<<endl;
			gotoxy(45, y); cout<<A_Proveedores[proveedores[i].posicion].contProveedor<<endl;
			
			for (int j=0; j<CA; j++)
			{
				if (A_Articulos[j].codP_a == A_Proveedores[proveedores[i].posicion].cod_p)
				{
					gotoxy(52, y); cout<<A_Articulos[j].nombre_a<<endl;
					y++;
				}
			}
			y+=3;	
		}
	}

	getch();
}

void Top_A()
{
	system("cls");
	cout<<"------------------TOP 10 ARTICULOS MÁS VENDIDOS------------------"<<endl;
	int k;
	int w;
	y=6;
	
	struct TOP
	{
		int posicion;
		int vendido;
	}articulos[CA];
	
	for (int i=0; i<CA; i++)
	{
		articulos[i].posicion = i;
		articulos[i].vendido = A_Articulos[i].vendidos;
	}
	
	for (int i=0; i<CA; i++)
	{
		for (int j=0; j<CA-1; j++)
		{
			if (articulos[j].vendido < articulos[j+1].vendido)
			{
				w = articulos[j].posicion;
				k = articulos[j].vendido;
				
				articulos[j].posicion = articulos[j+1].posicion;
				articulos[j].vendido = articulos[j+1].vendido;
				
				articulos[j+1].posicion = w;
				articulos[j+1].vendido = k;
			}
		}
	}
	
	gotoxy(0,3); cout<<"Cod. Art.";
	gotoxy(15,3); cout<<"Nombre";
	gotoxy(30,3); cout<<"Descripción";
	gotoxy(50,3); cout<<"Precio U.";
	gotoxy(65,3); cout<<"Cantidad de produc. vendidos";
	
	for (int i=0; i<10; i++)
	{
		if (A_Articulos[articulos[i].posicion].vendidos !=0)
		{
			gotoxy(0,y-1); cout<<"#"<<i+1<<"_______________________________________________________________________________________"<<endl;
			gotoxy(5, y); cout<<A_Articulos[articulos[i].posicion].cod_a<<endl;
			gotoxy(15, y); cout<<A_Articulos[articulos[i].posicion].nombre_a<<endl;
			gotoxy(30, y); cout<<A_Articulos[articulos[i].posicion].descripcion_a<<endl;
			gotoxy(50, y); cout<<fixed<<setprecision(2)<<A_Articulos[articulos[i].posicion].pUnitario_a<<endl;
			gotoxy(70, y); cout<<A_Articulos[articulos[i].posicion].vendidos<<endl<<endl<<endl;
			y+=3;	
		}
	}
	getch();
}

