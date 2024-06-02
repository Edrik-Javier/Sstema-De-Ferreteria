

void M_Ventaempleado(string idUser){
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
	cout<<"°1)VER VENTAS DE EMPLEADO       °\n";
	cout<<"°2)REGISTRAR VENTA              °\n";
	cout<<"°3)REGRESAR                    °\n";
	cout<<"°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°\n";
	cout<<"INGRESE LA OPCION A REALIZAR: ";
	cin>>seleccion;	
	
	//declaracion de variables
	string idu;
	string  idproducto, idcliente, descripcion, cantidad, total;
	//variables de consulta
	string sql,sql1;
	switch(seleccion){
		case 1:
			sql= "SELECT * FROM Ventas WHERE id_empleado ='"+idUser+"';"; 
			cout<<"-----LISTA DE TODAS LAS VENTAS---------";
			SQL_consulta(sql);
			cin.ignore();
			break;
		case 2:
			cin.ignore();
			cout<<"°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°\n";
			cout<<"==>Ingrese el id de producto\n";
			cin>>idproducto;
			cout<<"==>Ingrese el id de cliente\n";
			cin>>idcliente;
			cin.ignore();
			cout<<"==>Ingrese la descripcion de la compra\n";
			getline(cin, descripcion);
			cout<<"==>Ingrese la cantidad\n";
			cin>>cantidad;
			cout<<"==>Ingrese el total(Q.)\n";
			cin>>total;
			cout<<"°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°\n";
			//realizamos la consulta
			sql1 = "INSERT INTO Ventas (id_producto,id_cliente, id_empleado, Descripcion, Cantidad, Fecha, Hora, Total) VALUES ("+idproducto+","+idcliente+", "+idUser+", '"+descripcion+"', "+cantidad+", '"+fecha+"','"+hora+"',"+total+");";
			SQL_operaciones(sql1);
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
