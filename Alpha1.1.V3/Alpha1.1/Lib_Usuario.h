void M_usuarios(){
	
	
	//DECLARACION DE VARIALBES DE ENTORNO
	int seleccion, seleccion1;
	//muestreo de opciones
	
	cout<<"°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°\n";
	cout<<"°1)VER TODOS LOS USUARIOS      °\n";
	cout<<"°2)BUSCAR POR ID               °\n";
	cout<<"°3)AGREGAR NUEVO USUARIO       °\n";
	cout<<"°4)REGRESAR                    °\n";
	cout<<"°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°\n";
	cout<<"INGRESE LA OPCION A REALIZAR: ";
	cin>>seleccion;
	//
	//declaracion de variables
	string idu;
	string usuario, password,tipo;
	
	
	//varialbes de consultas
	string sql,sql1, sql2,sql3,sql4;//variables que contiene la consulta sql
	int query;
	bool result;

	switch(seleccion){
		case 1:
			sql= "SELECT * FROM USERS"; 
			cout<<"-----LISTA DE USUARIOS AGREGADOS---------";
			SQL_consulta(sql);
			cin.ignore();
		break;
		case 2:
			cout<<"-----BUSCAR POR ID DE USUARIO-------------\n";
			cout<<"Ingrese el id del usuario: ";
			cin>>idu;
			sql1 = "SELECT * FROM USERS WHERE id_user="+ idu +";";
				if(SQL_consulta(sql1) == true){
					cout<<"\n 1.Realizar modificacion";
					cout<<"\n 2.Eliminar este registro";
					cout<<"\n 3.Regresar al menu...";
					cin>>seleccion1;
						switch(seleccion1){
							case 1:
								cin.ignore();
								cout<<"°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°\n";
								cout<<"==>Ingrese el nombre de usuario\n";
								getline(cin, usuario);
								cout<<"==>Ingrese la contraseña\n";
								getline(cin, password);
								cout<<"==>Ingrese tipo de usuario 1)Administrador 2)Empleado 3)Cliente\n";
								getline(cin, tipo);
								cout<<"°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°\n";
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
								cin.ignore();
							break;
						}
				}else { cout<<"\n*****NO se encontro el registro...\n****** "; 
					cin.ignore();
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
			SQL_operaciones(sql3);
		break; 
		default:
            cout << "Algo salio mal, seleccione denuevo..." << endl;
            break;           
	};
	
	
}
