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

bool SQL_consulta(string sql1) {
	conn = mysql_init(0);
	mysql_real_connect(conn, "localhost", "root", "javier1326.", "DB_FERRETERIA", 3306, NULL, 0);
	// Realizamos la consulta
	string sql_query = sql1;
	const char* sql = sql_query.c_str(); // Transformamos el string a un char para que lo acepte el query
	int query = mysql_query(conn, sql); // Ejecutamos la consulta
	
	if(query != 0) {
		cout << "Algo salio mal...";  // Si algo salió mal, muestra mensaje de error y lo muestra
		cout << mysql_error(conn);
		mysql_close(conn);
		return false;
	} else {
		// Obteniendo datos 
		MYSQL_RES* resultado = mysql_store_result(conn);
		// Se genera el contador
		unsigned long filas_afectadas = mysql_num_rows(resultado); // Extrae el valor de filas afectadas por la consulta
		unsigned int columnas_afectadas = mysql_num_fields(resultado); // Extrae el valor de columnas afectadas por la consulta
		// Recorrer fila
		MYSQL_ROW fila; // Crea la variable de fila
		MYSQL_FIELD* colum; // Crea la variable de columna
		cout << endl;
		if(filas_afectadas != 0) {
			for(int i = 0; i < filas_afectadas; i++) {
				// Extraemos datos
				cout<<"°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°\n";
				fila = mysql_fetch_row(resultado); // Igualamos al valor devuelto por la ejecución de la consulta row=filas
				for(int j = 0; j < columnas_afectadas; j++) {
					// Mostrar
					colum = mysql_fetch_fields(resultado); // Igualamos al valor devuelto por la ejecución de la consulta fields=columna
					cout <<"o=> "<<colum[j].name << " " << " es: " << fila[j] << endl;	
				}
				cout << endl;
			}
			cout<<"°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°\n";
			mysql_free_result(resultado);
			mysql_close(conn);
			return true;
		} else {
			mysql_free_result(resultado);
			mysql_close(conn);
			return false;
		}
	}
}


bool SQL_operaciones(string sql1){
		conn = mysql_init(0);
		mysql_real_connect(conn,"localhost","root","javier1326.","DB_FERRETERIA",3306,NULL,0);
		//realizamos la consulta
		string sql_query = sql1;
		const char * sql = sql_query.c_str(); //Transformamos el string a un char para que lo acepte el query
		int query = mysql_query(conn, sql);//ejecutamos la consulta
		if(!query){
			cout<<"\nSe ha completado con exito... \n";
			return true;
		}else{
			cout<<"\nAlgo salio mal durante la operacion... \n"<<mysql_error(conn);
			return false;
		}
		mysql_close(conn);
};
bool SQL_verificador(string sql1) {
    bool validado = false;
    conn = mysql_init(0);
    if (conn) {
        if (mysql_real_connect(conn, "localhost", "root", "ADMIN", "DB_FERRETERIA", 3306, NULL, 0)) {
            const char *sql = sql1.c_str();
            int query = mysql_query(conn, sql);
            if (!query) {
                MYSQL_RES *res = mysql_store_result(conn);
                if (res) {
                    if (mysql_num_rows(res) > 0) {
                        cout << "\nEl usuario ya existe, intente con otro...\n";
                        validado = false;
                    } else {
                        cout << "\n\nUsuario válido...\n";
                        validado = true;
                    }
                    mysql_free_result(res);
                } else {
                    cout << "\nError al obtener el resultado de la consulta.\n";
                    validado = false;
                }
            } else {
                cerr << "\nError en la consulta SQL: " << mysql_error(conn) << "\n";
                validado = false;
            }
            mysql_close(conn);
        } else {
            cerr << "Error: No se pudo conectar a la base de datos.\n";
            validado = false;
        }
    } else {
        cerr << "Error: No se pudo inicializar la conexión a la base de datos.\n";
        validado = false;
    }
    return validado;
}
