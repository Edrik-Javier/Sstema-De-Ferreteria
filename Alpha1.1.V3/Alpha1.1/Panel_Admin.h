#include <stdlib.h>
#include <string>
//mysql
#include <mysql.h>
#include <mysqld_error.h>
#include "Lib_Consultas.h"
#include "Lib_Usuario.h"
#include "Lib_Empleados.h"
#include "Lib_Clientes.h"
#include "Lib_Proveedores.h"
#include "Lib_Compras.h"
#include "Lib_Ventas.h"
#include "Lib_Producto.h"
using namespace std;

//variable de usuario general
string usuario;
MYSQL *data;

void limpiarBuffer() {
    cin.clear(); // Limpia cualquier estado de error
    while (cin.get() != '\n') {}
}

void Cabecera(){
	system("cls");
	cout << "=========================================\n";
    cout << "           BIENVENIDO  " <<usuario<< "\n";    
    cout << "=========================================\n";
    cout << "        FERRETERIA LA FELICIDAD\n";
    cout << "=========================================\n";
	cout << "=========================================\n";
    cout << "           MENU PRINCIPAL\n";
    cout << "=========================================\n";
};




//menu con lista de opciones
void Submenu_Admin(){
	int op;
    do {   
        //DECLARACION DE VARIALBES DE ENTERNO
	Cabecera();
    cout << "1. USUARIOS\n";
    cout << "2. EMPLEADOS\n";
    cout << "3. PROVEEDORES\n";
    cout << "4. CLIENTES\n";
    cout << "5. COMPRAS\n";
    cout << "6. VENTAS\n";
    cout << "7. PRODUCTOS\n";
    cout << "8. Salir\n";
    cout << "=========================================\n";
    cin >> op;

        limpiarBuffer(); // Limpia el buffer después de leer la opción

        switch (op) {
            case 1:
                Cabecera();
                M_usuarios();
                break;
            case 2:
                Cabecera();
                M_Empleados();
                break;
            case 3:
            	Cabecera();
            	M_Proveedores();
                break;
            case 4:
            	Cabecera();
            	M_Cliente();
                break;
            case 5:
                Cabecera();
                M_Compras();
                break;
            case 6:
                Cabecera();
                M_Ventas();
                break;
            case 7:
                Cabecera();
                M_Productos();
                break;
            case 8:
                cout << "Saliendo del Sistema...\n";
                break;
            default:
                cout << "Opcion no valida. Intente de nuevo.\n";
                break;
        }

        if (op != 8) {
            cout << "\nPresiona cualquier tecla para continuar...";
            cin.get(); // Espera a que el usuario presione una tecla
        }

    } while (op != 8);
       
    }


	


void Admin_Menu(string s_Usuario){
	usuario = s_Usuario;
	Submenu_Admin();
};


