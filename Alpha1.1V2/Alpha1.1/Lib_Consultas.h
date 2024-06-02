#include <iostream>
#include <string>
#include <stdlib.h>
#include <string>
//mysql
#include <mysql.h>
#include <mysqld_error.h>
using namespace std;



//mysql
MYSQL *conn;

void SQL_consulta(string sql1){
	conn = mysql_init(0);
	mysql_real_connect(conn,"localhost","root","ADMIN","DB_FERRETERIA",3306,NULL,0);
	//realizamos la consulta
	string sql_query = sql1;
	const char * sql = sql_query.c_str(); //Transformamos el string a un char para que lo acepte el query
	int query = mysql_query(conn, sql);//ejecutamos la consulta
	
	if(query != 0){
		cout<<"Algo salio mal...";  //Si algo salio mal muestra mensaje de error y lo muestra
		cout<<mysql_error(conn);
	}else{
	//Obteniendo datos 
		MYSQL_RES *	resultado = mysql_store_result(conn);
		//se genera el contador
		unsigned long filas_afectadas = mysql_num_rows(resultado);//Extrae el valor de filas afectadas por la consulta
		unsigned int columnas_afectadas = mysql_num_fields(resultado); //Extrae el valor de columnas afectadas por la consulta
		//Recorrer fila
		MYSQL_ROW fila;//Crea la variable de fila
		MYSQL_FIELD* colum;//Cra la variable de columna
		cout<<endl;
		for(int i=0; i<filas_afectadas; i++){
			//extraemos datos
			fila = mysql_fetch_row(resultado);//Igualamos al valor devuelto por la ejecucion de la consulta row=filas
			for(int j=0; j<columnas_afectadas;j++){
			//mostrar
			colum = mysql_fetch_fields(resultado); //Igualamos al valor devuelto por la ejecucion de la consulta fields=columna
			cout<<colum[j].name<<" "<<j<<" es: "<<fila[j]<<endl;	
			}
			cout<<endl;
		}
		mysql_free_result(resultado);
		
	}
		mysql_close(conn);
		
}

void SQL_operaciones(string sql1){
		conn = mysql_init(0);
		mysql_real_connect(conn,"localhost","root","ADMIN","DB_FERRETERIA",3306,NULL,0);
		//realizamos la consulta
		string sql_query = sql1;
		const char * sql = sql_query.c_str(); //Transformamos el string a un char para que lo acepte el query
		int query = mysql_query(conn, sql);//ejecutamos la consulta
		if(!query){
			cout<<"\nSe ha actualizado con exito... \n";
		}else{
			cout<<"\nAlgo salio mal durante la operacion... \n"<<mysql_error(conn);
		}
		mysql_close(conn);
};
	
	
