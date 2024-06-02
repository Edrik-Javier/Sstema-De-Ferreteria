void M_Kardex(string idempleado){
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
    //variables de enotrno
    int seleccion;
    string sql, idventa;//consulta
    cout<<"°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°\n";
	cout<<"°1)VER VENTAS DEL DIA          °\n";
	cout<<"°2)VER SEGUN FECHA             °\n";
	cout<<"°3)BUSCAR POR ID DE VENTA      °\n";
	cout<<"°4)REGRESAR                    °\n";
	cout<<"°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°\n";
	cout<<"INGRESE LA OPCION A REALIZAR: ";
	cin>>seleccion;	   	
	
	switch(seleccion){
		case 1:
			sql = "SELECT * FROM Ventas WHERE id_empleado='"+idempleado+"' and Fecha='"+fecha+"';";
			SQL_consulta(sql);
			cin.ignore();
		break;
		case 3:
			cout<<"\no==>Ingrese el id de la venta: ";
			cin>>idventa;
			sql = "SELECT * FROM Ventas WHERE id_venta= '"+idventa+"';";
			SQL_consulta(sql);
			cin.ignore();
		break;
		case 2:
			cout<<"\no==>Ingrese la fecha de busqueda (siga el formato 'year-month-day'): ";
			cin>>fecha;
			sql = "SELECT * FROM Ventas WHERE id_empleado='"+idempleado+"' and Fecha='"+fecha+"';";
			SQL_consulta(sql);
			cin.ignore();
		break;
		case 4:
			cout<<"\nSaliendo...";
		break;
		default:
			cout<<"\nSeleccione un opcion valida...";
		break;
	}
};
