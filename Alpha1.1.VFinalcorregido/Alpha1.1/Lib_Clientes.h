void M_Cliente(){
	
	
	//DECLARACION DE VARIALBES DE ENTORNO
	int seleccion, seleccion1;
	//muestreo de opciones
	
	cout<<"°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°\n";
	cout<<"°1)VER TODOS LOS CLIENTES      °\n";
	cout<<"°2)BUSCAR POR ID               °\n";
	cout<<"°3)AGREGAR NUEVO CLIENTE       °\n";
	cout<<"°4)REGRESAR                    °\n";
	cout<<"°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°\n";
	cout<<"INGRESE LA OPCION A REALIZAR: ";
	cin>>seleccion;
	//
	//declaracion de variables
	string idu;
	string nombre,fecha,genero;
	string direccion,puesto,telefono,correo,saldo;
	
	
	//varialbes de consultas
	string sql,sql1, sql2,sql3,sql4;//variables que contiene la consulta sql
	int query;
	bool result;

	switch(seleccion){
		case 1:
			sql= "SELECT * FROM Clientes"; 
			cout<<"-----LISTA DE CLIENTES AGREGADOS---------";
			SQL_consulta(sql);
			cin.ignore();
		break;
		case 2:
			cout<<"-----BUSCAR POR ID DE CLIENTES-------------\n";
			cout<<"Ingrese el id del clientes: ";
			cin>>idu;
			sql1 = "SELECT * FROM Clientes WHERE id_cliente="+ idu +";";
				if(SQL_consulta(sql1) == true){
					cout<<"\n 1.Realizar modificacion";
					cout<<"\n 2.Eliminar este registro";
					cout<<"\n 3.Regresar al menu...";
					cin>>seleccion1;
						switch(seleccion1){
							case 1:
								cin.ignore();
								cout<<"°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°\n";
								cout<<"==>Ingrese el nombre del cliente\n";
								getline(cin, nombre);
								cout<<"==>Ingrese la fecha del cliente\n";
								getline(cin, fecha);
								cout<<"==>Ingrese el genero (Masculino o Femenino)\n";
								getline(cin, genero);
								cout<<"==>Ingrese la direccion\n";
								getline(cin,direccion);
								cout<<"==>Ingrese el telefono\n";
								getline(cin,telefono);
								cout<<"==>Ingrese el correo\n";
								getline(cin,correo);
								cout<<"==>Ingrese el saldo de cliente (Q.)\n";
								getline(cin,saldo);
								cout<<"°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°\n";
								//realizamos consulta
								sql2 = "UPDATE Clientes SET Nombre ='"+ nombre+"', Fecha_de_Nacimiento='"+fecha+"', Genero='"+genero+"', Direccion='"+direccion+"', Telefono='"+telefono+"', Correo='"+correo+"', Saldo='"+saldo+"' WHERE id_cliente='"+idu+"';";
								SQL_operaciones(sql2);
								SQL_consulta(sql1);
								cin.ignore();
							break;
							case 2:
								//realizamos consulta de borrado
								sql4="DELETE FROM Cliente WHERE id_cliente="+idu+";";
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
			cout<<"==>Ingrese la fecha del cliente\n";
			getline(cin, fecha);
			cout<<"==>Ingrese el genero (Masculino o Femenino)\n";
			getline(cin, genero);
			cout<<"==>Ingrese la direccion\n";
			getline(cin,direccion);
			cout<<"==>Ingrese el telefono\n";
			getline(cin,telefono);
			cout<<"==>Ingrese el correo\n";
			getline(cin,correo);
			cout<<"==>Ingrese el saldo de cliente (Q.)\n";
			getline(cin,saldo);
			cout<<"°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°\n";
			//realizamos la consulta
			sql3 = "INSERT INTO Clientes (Nombre, Fecha_de_Nacimiento, Genero, Direccion, Telefono, Correo, Saldo) VALUES ('"+nombre+"', STR_TO_DATE('"+fecha+"', '%d-%m-%Y'),'"+genero+"', '"+direccion+"', '"+telefono+"', '"+correo+"', '"+saldo+"');";
			SQL_operaciones(sql3);
		break; 
		default:
            cout << "Algo salio mal, seleccione denuevo..." << endl;
            break;           
	};
	
	
}	
