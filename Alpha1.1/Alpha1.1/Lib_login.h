#include <string>
#include <mysql.h>
#include <mysqld_error.h>
#include "Panel_Admin.h"
#include <iostream>



using namespace std;
MYSQL *obj;


struct Usuarios{
	int id_usuario;
	string Usuario;
	string Password;
	int TipoU;
};

//espacios en blanco para centrar
void espaciosT(){
	for(int i=0; i<15; i++){
		cout<<" ";
	}
}
void espaciosST(){
	for(int i=0; i<10; i++){
		cout<<" ";
	}
}
void espaciosTX(){
	for(int i=0; i<7; i++){
		cout<<" ";
	}
}

//Menu de logueo
void Pantalla_inicio(){
//Variable de estrucutra
Usuarios user;
string temp_usuario;
string temp_password;

//Pintamos mensaje de Bienvenida
espaciosT();
cout<<"BIENVENDIO :D"<<endl;
espaciosST();
cout<<"ingrese los datos para ingresar";
cout<<endl<<endl<<endl;

//Solicitamos los datos
espaciosTX();
cout<<"Usuario: ";
getline(cin, temp_usuario);
espaciosTX();
cout<<"Password: ";
getline(cin, temp_password);


//Funcion de busqueda filtrada usuario
MYSQL *obj;//Creamos el objeto de la base de datos

	
	if(!(obj=mysql_init(0))){
		cout<<"Error al crear el objeto mysql"; //verificamos que la conexion para crear el objeto este correcto
	}
	
	if(!mysql_real_connect(obj,"localhost","root","ADMIN","DB_FERRETERIA",3306,NULL,0)){
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
			user.id_usuario = atoi(fila[0]);
			user.Usuario = fila[1];
			user.Password = fila[2];
			user.TipoU = atoi(fila[3]);
		}
		mysql_free_result(resultado);
		//Validamos que tipo de usuario es
		
		if(user.TipoU == 1){
			Admin_Menu(user.Usuario);
		}
	}
	mysql_close(obj);
	
}









