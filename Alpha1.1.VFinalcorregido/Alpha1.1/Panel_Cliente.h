	#include <stdlib.h>
	#include <iostream>
	#include <string>
	#include <ctime>
	//Librerias
	#include "Lib_ComprasClientes.h"
	
	
	using namespace std;
	string usuario2, idusuario1;
	
	
	
	void Submenu_Cliente(){
		int seleccion, seleccion1;
	// Obtener la fecha y hora actual
    time_t ahora = time(NULL);
    
    // Convertir a estructura de tiempo local
    tm* tiempoLocal = localtime(&ahora);

    // Crear un stringstream para construir la cadena de tiempo
    stringstream date, time;
    date << (tiempoLocal->tm_year + 1900) << "-"
         << (tiempoLocal->tm_mon + 1) << "-"
         << tiempoLocal->tm_mday << " ";
    
    time << tiempoLocal->tm_hour << ":"
       	 << tiempoLocal->tm_min << ":"
         << tiempoLocal->tm_sec;
    

    // Almacenar la fecha y hora como string en la variable llamada "tiempo"
    string fecha = date.str();
    string hora = time.str();
		int op;
		string sql1;
		string idu;
		string  idproducto, descripcion, cantidad, total;
		do {   
	        //declaracion de variables
		
		Cabecera();
	    cout << "1. VER LAS COMPRAS REALIZADAS\n";
	    cout << "2. LISTAR PRODUCTOS\n";
	    cout << "3. REALIZAR COMPRA\n";
	    cout << "4. Salir\n";
	    cout << "=========================================\n";
	    cin >> op;
	
	        switch (op) {
	            case 1:
	                Cabecera();
	                M_CompraCliente(idusuario1);
	                break;
	            case 2:
	                Cabecera();
	                sql1 = "SELECT * FROM Productos";
	                SQL_consulta(sql1);
	                cin.ignore();
	                break;
	            case 3:
	            	Cabecera();
	            	cin.ignore();
					cout<<"같같같같같같같같같같같같같같같같\n";
					cout<<"==>Ingrese el id de producto\n";
					cin>>idproducto;
					cin.ignore();
					cout<<"==>Ingrese la descripcion de la compra\n";
					getline(cin, descripcion);
					cout<<"==>Ingrese la cantidad\n";
					cin>>cantidad;
					cout<<"==>Ingrese el total(Q.)\n";
					cin>>total;
					cout<<"같같같같같같같같같같같같같같같같\n";
					//realizamos la consulta
					sql1 = "INSERT INTO Ventas (id_producto,id_cliente, id_empleado, Descripcion, Cantidad, Fecha, Hora, Total) VALUES ("+idproducto+","+idusuario1+", 0, '"+descripcion+"', "+cantidad+", '"+fecha+"','"+hora+"',"+total+");";
					SQL_operaciones(sql1);
					cin.ignore();
	            break;
	            case 4:
	            	cout<<"\nSaliendo del sistema...";
	                break;
	            default:
	                cout << "Opcion no valida. Intente de nuevo.\n";
	                break;
	        }
	
	        if (op != 4) {
	            cout << "\nPresiona cualquier tecla para continuar...";
	            cin.get(); // Espera a que el usuario presione una tecla
	        }
	
	    } while (op != 4);
		
		
	}

void Cliente_Menu(string s_Usuario, string idu1){
	usuario2 = s_Usuario;
	idusuario1 = idu1;
	Submenu_Cliente();
};
