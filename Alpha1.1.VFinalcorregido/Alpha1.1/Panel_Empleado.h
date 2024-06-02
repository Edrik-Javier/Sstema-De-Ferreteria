	#include <stdlib.h>
	#include <iostream>
	#include <string>
	//Librerias
	#include "Lib_VentasEmpleados.h"
	#include "Lib_Kardex.h"
	
	
	using namespace std;
	string usuario1, idusuario;
	
	
	
	void Submenu_Empleado(){
		int op;
		string sql;
		do {   
	        //DECLARACION DE VARIALBES DE ENTERNO
		Cabecera();
	    cout << "1. VENTAS DE EMPLEADO (VER VENTAS, REGISTRAR VENTA)\n";
	    cout << "2. LISTAR PRODUCTOS\n";
	    cout << "3. LISTAR CLIENTES\n";
	    cout << "4. REPORTE DE VENTAS\n";
	    cout << "5. Salir\n";
	    cout << "=========================================\n";
	    cin >> op;
	
	        switch (op) {
	            case 1:
	                Cabecera();
	                M_Ventaempleado(idusuario);
	                break;
	            case 2:
	                Cabecera();
	                sql = "SELECT * FROM Productos";
	                SQL_consulta(sql);
	                cin.ignore();
	                break;
	            case 3:
	            	Cabecera();
	            	sql="SELECT * FROM Clientes";
	            	SQL_consulta(sql);
	                cin.ignore();
					break;
	            case 4:
	            	Cabecera();
	            	M_Kardex(idusuario);
	                break;
	            case 5:
	            	cout<<"\nSaliendo del sistema...";
	                break;
	            default:
	                cout << "Opcion no valida. Intente de nuevo.\n";
	                break;
	        }
	
	        if (op != 5) {
	            cout << "\nPresiona cualquier tecla para continuar...";
	            cin.get(); // Espera a que el usuario presione una tecla
	        }
	
	    } while (op != 5);
		
		
	}

void Empleado_Menu(string s_Usuario, string idu1){
	usuario1 = s_Usuario;
	idusuario = idu1;
	Submenu_Empleado();
};
