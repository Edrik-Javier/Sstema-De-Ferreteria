void M_Proveedores(){
	
	
	//DECLARACION DE VARIALBES DE ENTORNO
	int seleccion, seleccion1;
	//muestreo de opciones
	
	cout<<"°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°\n";
	cout<<"°1)VER TODOS LOS PROVEEDORES   °\n";
	cout<<"°2)BUSCAR POR ID               °\n";
	cout<<"°3)AGREGAR NUEVO PROVEEDOR     °\n";
	cout<<"°4)REGRESAR                    °\n";
	cout<<"°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°\n";
	cout<<"INGRESE LA OPCION A REALIZAR: ";
	cin>>seleccion;
	//
	//declaracion de variables
	string idu;
	string nombre;
	string direccion,telefono,correo,saldo;
	
	
	//varialbes de consultas
	string sql,sql1, sql2,sql3,sql4;//variables que contiene la consulta sql
	int query;
	bool result;

	switch(seleccion){
		case 1:
			sql= "SELECT * FROM Proveedores"; 
			cout<<"-----LISTA DE CLIENTES PROVEEDORES---------";
			SQL_consulta(sql);
			cin.ignore();
		break;
		case 2:
			cout<<"-----BUSCAR POR ID DE PROVEEDORES-------------\n";
			cout<<"Ingrese el id del proveedor: ";
			cin>>idu;
			sql1 = "SELECT * FROM Proveedores WHERE id_proveedor="+ idu +";";
				if(SQL_consulta(sql1) == true){
					cout<<"\n 1.Realizar modificacion";
					cout<<"\n 2.Eliminar este registro";
					cout<<"\n 3.Regresar al menu...";
					cin>>seleccion1;
						switch(seleccion1){
							case 1:
								cin.ignore();
								cout<<"°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°\n";
								cout<<"==>Ingrese el nombre del proveedor\n";
								getline(cin, nombre);
								cout<<"==>Ingrese la direccion\n";
								getline(cin,direccion);
								cout<<"==>Ingrese el telefono\n";
								getline(cin,telefono);
								cout<<"==>Ingrese el saldo de cliente (Q.)\n";
								getline(cin,saldo);
								cout<<"°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°\n";
								//realizamos consulta
								sql2 = "UPDATE Proveedores SET Nombre ='"+ nombre+"', Direccion='"+direccion+"', Telefono='"+telefono+"', Correo='"+correo+"', Saldo='"+saldo+"' WHERE id_proveedor='"+idu+"';";
								SQL_operaciones(sql2);
								SQL_consulta(sql1);
								cin.ignore();
							break;
							case 2:
								//realizamos consulta de borrado
								sql4="DELETE FROM Proveedores WHERE id_proveedor="+idu+";";
								SQL_operaciones(sql4);
								SQL_consulta(sql1);
							break;
						}
				}else { cout<<"\n*****No se encontro el registro...\n****** "; 
					cin.ignore();
				}
			
			break;
		case 3:
			cin.ignore();
			cout<<"°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°\n";
			cout<<"==>Ingrese el nombre del cliente\n";
			getline(cin, nombre);
			cout<<"==>Ingrese la direccion\n";
			getline(cin,direccion);
			cout<<"==>Ingrese el telefono\n";
			getline(cin,telefono);
			cout<<"==>Ingrese el correo\n";
			getline(cin,correo);
			cout<<"==>Ingrese el saldo de con el proveedor (Q.)\n";
			getline(cin,saldo);
			cout<<"°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°\n";
			//realizamos la consulta
			sql3 = "INSERT INTO Proveedores (Nombre,Direccion, Telefono, Correo, Saldo) VALUES ('"+nombre+"','"+direccion+"', '"+telefono+"', '"+correo+"', '"+saldo+"');";
			SQL_operaciones(sql3);
		break; 
		default:
            cout << "Algo salio mal, seleccione denuevo..." << endl;
            break;           
	};
	
	
}	
