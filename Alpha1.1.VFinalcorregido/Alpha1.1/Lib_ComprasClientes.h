void M_CompraCliente(string idUser){
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
    cout<<"°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°\n";
	cout<<"°1)VER TODAS LAS COMPRAS       °\n";
	cout<<"°2)VER COMPRAS SEGUN FECHA     °\n";
	cout<<"°3)REGRESAR                    °\n";
	cout<<"°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°\n";
	cout<<"INGRESE LA OPCION A REALIZAR: ";
	cin>>seleccion;	
	string sql;
	switch(seleccion){
		case 1:
			sql= "SELECT * FROM Ventas WHERE id_cliente ='"+idUser+"';"; 
			cout<<"-----LISTA DE TODAS LAS VENTAS---------";
			SQL_consulta(sql);
			cin.ignore();
			break;
		case 2:
			sql = "SELECT * FROM Ventas WHERE Fecha ='"+fecha+"' and id_cliente='"+idUser+"';";
			SQL_consulta(sql);
			cin.ignore();
		break;
		case 3:
			cout<<"\nSaliendo al menu...";
		break;
		default:
			cout<<"\nSeleccion una opcion valida:\n";
		break;
	}	
};
