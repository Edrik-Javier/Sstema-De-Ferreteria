#include <stdlib.h>
#include <string>
//mysql
#include <mysql.h>
#include <mysqld_error.h>
#include "Lib_Consultas.h"
using namespace std;

//variable de usuario general
string usuario;
MYSQL *data;


void Cabecera(){
	system("cls");
	cout<<"-----------------------------------------\n\n";	
	cout<<"        PANEL DE ADMINISTRADOR         \n";
	cout<<"             USUARIO:"<<usuario<<"\n\n";
	cout<<"-----------------------------------------\n\n";
};

void M_usuarios(){
	//inicializacion de base de datos
	data = mysql_init(0);
	mysql_real_connect(data,"localhost","root","ADMIN","DB_FERRETERIA",3306,NULL,0);
	
	
	//DECLARACION DE VARIALBES DE ENTORNO
	int seleccion, seleccion1;
	//muestreo de opciones
	Cabecera();
	cout<<"==>(1) LISTAR TODOS LOS USUARIOS \n";
	cout<<"==>(2) BUSCAR USUARIO POR ID \n";
	cout<<"==>(3) REGISTRAR UN NUEVO USUARIO \n";
	cin>>seleccion;
	//
	//declaracion de variables
	string idu;
	string usuario, password,tipo;
	
	
	//varialbes de consultas
	string sql,sql1, sql2,sql3,sql4;
	const char *consulta;
	int query;

	switch(seleccion){
		case 1:
			sql= "SELECT * FROM USERS"; 
			cout<<"-----LISTA DE USUARIOS AGREGADOS---------";
			SQL_consulta(sql);
		break;
		case 2:
			cout<<"-----BUSCAR POR ID DE USUARIO-------------\n";
			cout<<"Ingrese el id del usuario: ";
			cin>>idu;
			sql1 = "SELECT * FROM USERS WHERE id_user="+ idu +";";
			SQL_consulta(sql1);
			cout<<"\n 1.Realizar modificacion";
			cout<<"\n 2.Eliminar este registro";
			cout<<"\n 3.Regresar al menu...";
			cin>>seleccion1;
				switch(seleccion1){
					case 1:
						cin.ignore();
						cout<<"==>Ingrese el nombre de usuario\n";
						getline(cin, usuario);
						cout<<"==>Ingrese la contraseña\n";
						getline(cin, password);
						cout<<"==>Ingrese tipo de usuario 1)Administrador 2)Empleado 3)Cliente\n";
						getline(cin, tipo);
						//realizamos consulta
						sql2 = "UPDATE USERS SET U_User ='"+ usuario+"', U_Password='"+password+"', U_Tipe="+tipo+" WHERE id_user ="+idu+";";
						SQL_operaciones(sql2);
						SQL_consulta(sql1);
					break;
					case 2:
						//realizamos consulta de borrado
						sql4="DELETE FROM USERS WHERE id_user="+idu+";";
						SQL_operaciones(sql4);
						SQL_consulta(sql1);
					break;
				}
			break;
		case 3:
			cin.ignore();
			cout<<"-----REALIAR INSERNCION DE DATO------------\n";
			cout<<"==>Ingrese el nombre de usuario\n";
			getline(cin, usuario);
			cout<<"==>Ingrese la contraseña\n";
			getline(cin, password);
			cout<<"==>Ingrese tipo de usuario 1)Administrador 2)Empleado 3)Cliente\n";
			getline(cin, tipo);
			//realizamos la consulta
			sql3 = "INSERT INTO USERS (U_User, U_Password, U_Tipe) VALUES ('" + usuario + "','" + password + "'," + tipo + ");";
			consulta= sql3.c_str();
			query = mysql_query(data,consulta);
			//valuamos la consulta
			if(!query){
				cout<<"Se realizo el registro con exito";
				
			
			}else{cout<<"Algo salio mal..."; 
			cout<<mysql_error(data); }
			
				mysql_close(data);
		break; 
		default:
            cout << "Invalid option selected. Please try again." << endl;
            break;           
	};
	
	
}


//menu con lista de opciones
void Submenu_Admin(){
	//DECLARACION DE VARIALBES DE ENTERNO
	int op;
    cout << "==>(1) USUARIOS" << endl;
    cout << "==>(2) EMPLEADOS" << endl;
    cout << "==>(3) PROVEEDORES" << endl;
    cout << "==>(4) CLIENTES" << endl;
    cout << "==>(5) COMPRAS" << endl;
    cout << "==>(6) VENTAS" << endl;
    cout << "==>(7) PRODUCTOS" << endl;
    cout << "Please select an option: ";
    cin >> op;

    switch(op) {
        case 1:
            cout << "You selected USUARIOS" << endl;
            		M_usuarios();
            break;
        case 2:
            cout << "You selected EMPLEADOS" << endl;
            // Aquí puedes agregar el código correspondiente para EMPLEADOS
            break;
        case 3:
            cout << "You selected PROVEEDORES" << endl;
            // Aquí puedes agregar el código correspondiente para PROVEEDORES
            break;
        case 4:
            cout << "You selected CLIENTES" << endl;
            // Aquí puedes agregar el código correspondiente para CLIENTES
            break;
        case 5:
            cout << "You selected COMPRAS" << endl;
            // Aquí puedes agregar el código correspondiente para COMPRAS
            break;
        case 6:
            cout << "You selected VENTAS" << endl;
            // Aquí puedes agregar el código correspondiente para VENTAS
            break;
        case 7:
            cout << "You selected PRODUCTOS" << endl;
            // Aquí puedes agregar el código correspondiente para PRODUCTOS
            break;
        default:
            cout << "Invalid option selected. Please try again." << endl;
            break;
    }

	//
	
	
	
};

	
	
	
	


void Admin_Menu(string s_Usuario){
	usuario = s_Usuario;
	Cabecera();
	Submenu_Admin();
};


