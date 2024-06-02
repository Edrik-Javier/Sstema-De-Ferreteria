#include <string>
#include <mysql.h>
#include <mysqld_error.h>
#include "Panel_Admin.h"
#include "Panel_Empleado.h"
#include "Panel_Cliente.h"
#include <iostream>



using namespace std;
MYSQL *obj;


struct Usuarios{
	string id_usuario;
	string Usuario;
	string Password;
	int TipoU;
};

//Menu de logueo
void Pantalla_inicio(){
//Variable de estrucutra
Usuarios user;
string temp_usuario;
string temp_password;
int contador;

//Pintamos mensaje de Bienvenida
	
    do{
    system("cls"); // Limpia la pantalla
	cout << "=========================================\n";
    cout << "              BIENVENIDO"  "\n";    
    cout << "=========================================\n";
    cout << "        FERRETERIA LA FELICIDAD\n";
    cout << "=========================================\n";
	cout << "=========================================\n";
 	cout << "            INICIAR SESION\n";
    cout << "=========================================\n";  
    cout << "\n";
 	cout << "INGRESAR USUARIO:";
 	getline(cin, temp_usuario);
    cout << "\n";  
 	cout << "CONTRASENA: ";
 	getline(cin, temp_password);
 	cout << "\n";  
    cout << "=========================================\n";  
	user.TipoU = 0;

//Funcion de busqueda filtrada usuario
MYSQL *obj;//Creamos el objeto de la base de datos

	
	if(!(obj=mysql_init(0))){
		cout<<"Error al crear el objeto mysql"; //verificamos que la conexion para crear el objeto este correcto
	}
	
	if(!mysql_real_connect(obj,"127.0.0.1", "root", "javier1326.","DB_FERRETERIA",3306,NULL,0)){
		cout<<mysql_error(obj); //validamos que la conexion se haya hecho correctamente, validando (servidor de basededatos, usuario, y nombre de la base de datos si no se logra muestra el error
	}
	string sql_query = "SELECT * FROM USERS WHERE U_User='" + temp_usuario + "' and U_Password='"+temp_password+"';"; //Definimos la consulta de filtrado por usuario
	const char * sql = sql_query.c_str(); //Transformamos el string a un char para que lo acepte el query
	int query = mysql_query(obj, sql);//ejecutamos la consulta

	if(query != 0){
		cout<<"Algo salio mal...";  //Si algo salio mal muestra mensaje de error y lo muestra
		cout<<mysql_error(obj);
	}else{
		
		//Obteniendo datos 
		MYSQL_RES *	resultado = mysql_store_result(obj);
		//se genera el contador
		unsigned long filas_afectadas = mysql_num_rows(resultado);
		
		//Recorrer fila
		MYSQL_ROW fila;
		for(int i=0; i<filas_afectadas; i++){
			fila = mysql_fetch_row(resultado);
			//mostrar
			user.id_usuario = fila[0];
			user.Usuario = fila[1];
			user.Password = fila[2];
			user.TipoU = atoi(fila[3]);
		}
		mysql_free_result(resultado);
		//Validamos que tipo de usuario es
		
		
			switch(user.TipoU){
			case 1:
					user.TipoU =0;
					contador = 0;
					Admin_Menu(user.Usuario);
			cin.ignore();
			break;
			case 2:
					user.TipoU =0;
					contador = 0;
					Empleado_Menu(user.Usuario, user.id_usuario);			
			cin.ignore();
			break;
			case 3:
					user.TipoU =0;
					contador = 0;
					Cliente_Menu(user.Usuario, user.id_usuario);
			cin.ignore();
			break;
			
			
			}
			mysql_close(obj);
		}
		contador++;
	}while(user.TipoU == 0 && contador <3);
	system("cls");
	cout<<"************ SE HA EXEDIDO EL LIMITE DE INTENTOS ***************";
}










