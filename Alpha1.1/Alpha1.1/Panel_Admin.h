#include <iostream>
#include <string>
#include <stdlib.h>
#include <string>
//mysql
#include <mysql.h>
#include <mysqld_error.h>
#include "Lib_Consultas.h"
using namespace std;

//variable de usuario general
string usuario;

void Cabecera(){
	system("cls");
	cout<<"-----------------------------------------\n\n";	
	cout<<"        PANEL DE ADMINISTRADOR         \n";
	cout<<"             USUARIO:"<<usuario<<"\n\n";
	cout<<"-----------------------------------------\n\n";
};

void M_usuarios(){
	system("cls");
	//DECLARACION DE VARIALBES DE ENTORNO
	
	
	
	//muestreo de opciones
	Cabecera();
	cout<<"==>(1) LISTAR TODOS LOS USUARIOS \n";
	cout<<"==>(2) BUSCAR USUARIO POR ID \n";
	cout<<"==>(3) REGISTRAR UN NUEVO USUARIO \n";
	
	
}

//menu con lista de opciones
void Submenu_Admin(){
	//DECLARACION DE VARIALBES DE ENTERNO
	int op;
	cout<<"==>(1) USUARIOS"<<endl;
	cout<<"==>(2) EMPLEADOS"<<endl;
	cout<<"==>(3) PROVEEDORES"<<endl;
	cout<<"==>(4) CLIENTES"<<endl;
	cout<<"==>(5) COMPRAS"<<endl;
	cout<<"==>(6) VENTAS"<<endl;
	cout<<"==>(7) PRODUCTOS"<<endl;
	cout<<"Please select an opcion: ";	
	cin>> op;
	
	
	
	
	//
	string sql = "SELECT * FROM USERS";
	SQL_consulta(sql);
	
	
};


void Admin_Menu(string s_Usuario){
	usuario = s_Usuario;
	Cabecera();
	Submenu_Admin();
};


