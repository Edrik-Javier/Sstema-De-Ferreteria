#include <ctime>
#include <sstream>

void M_Ventas(){
	int seleccion, seleccion1;
	// Obtener la fecha y hora actual
    time_t ahora = time(NULL);
    
    // Convertir a estructura de tiempo local
    tm* tiempoLocal = localtime(&ahora);

    // Crear un stringstream para construir la cadena de tiempo
    stringstream ss;
    ss << (tiempoLocal->tm_year + 1900) << "-"
       << (tiempoLocal->tm_mon + 1) << "-"
       << tiempoLocal->tm_mday << " "
       << tiempoLocal->tm_hour << ":"
       << tiempoLocal->tm_min << ":"
       << tiempoLocal->tm_sec;

    // Almacenar la fecha y hora como string en la variable llamada "tiempo"
    string tiempo = ss.str();
    
	
	cout<<"°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°\n";
	cout<<"°1)VER TODOS LOS VENTAS        °\n";
	cout<<"°2)BUSCAR POR ID               °\n";
	cout<<"°3)REALIZAR VENTAS             °\n";
	cout<<"°4)REGRESAR                    °\n";
	cout<<"°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°\n";
	cout<<"INGRESE LA OPCION A REALIZAR: ";
	cin>>seleccion;
	//
	//declaracion de variables
	string idu;
	string  idproducto, idcliente, idempleado, descripcion, cantidad, total;
	
	
	
	//varialbes de consultas
	string sql,sql1, sql2,sql3,sql4;//variables que contiene la consulta sql
	int query;

	switch(seleccion){
		case 1:
			sql= "SELECT * FROM Ventas"; 
			cout<<"-----LISTA DE TODAS LAS VENTAS---------";
			SQL_consulta(sql);
			cin.ignore();
		break;
		case 2:
			cout<<"-----BUSCAR POR ID DE VENTAS-------------\n";
			cout<<"Ingrese el id de la venta: ";
			cin>>idu;
			sql1 = "SELECT * FROM Ventas WHERE id_venta="+ idu +";";
				if(SQL_consulta(sql1) == true){
					cout<<"\n 1.Realizar modificacion";
					cout<<"\n 2.Eliminar este registro";
					cout<<"\n 3.Regresar al menu...";
					cin>>seleccion1;
						switch(seleccion1){
							case 1:
								cin.ignore();
								cout<<"°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°\n";
								cout<<"==>Ingrese el id de producto\n";
								cin>>idproducto;
								cout<<"==>Ingrese el id de cliente\n";
								cin>>idcliente;
								cout<<"==>Ingrese el id de empleado\n";
								cin>>idempleado;
								cout<<"==>Ingrese la descripcion de la compra\n";
								getline(cin, descripcion);
								cout<<"==>Ingrese la cantidad\n";
								cin>>cantidad;
								cout<<"==>Ingrese el total(Q.)\n";
								cin>>total;
								cout<<"°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°\n";
								//realizamos consulta
								sql2 = "UPDATE Ventas SET id_producto="+idproducto+", id_cliente ="+ idcliente+", id_empleado="+idempleado+", Descripcion='"+descripcion+"', Cantidad="+total+", Total="+total+" WHERE id_venta ='"+idu+"';";
								SQL_operaciones(sql2);
								SQL_consulta(sql1);
							break;
							case 2:
								//realizamos consulta de borrado
								sql4="DELETE FROM Venta WHERE id_venta="+idu+";";
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
			cout<<"==>Ingrese el id de producto\n";
			cin>>idproducto;
			cout<<"==>Ingrese el id de cliente\n";
			cin>>idcliente;
			cout<<"==>Ingrese el id de empleado\n";
			cin>>idempleado;
			cin.ignore();
			cout<<"==>Ingrese la descripcion de la compra\n";
			getline(cin, descripcion);
			cout<<"==>Ingrese la cantidad\n";
			cin>>cantidad;
			cout<<"==>Ingrese el total(Q.)\n";
			cin>>total;
			cout<<"°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°\n";
			//realizamos la consulta
			sql3 = "INSERT INTO Ventas (id_producto,id_cliente, id_empleado, Descripcion, Cantidad, Fecha_hora, Total) VALUES ("+idproducto+","+idcliente+", "+idempleado+", '"+descripcion+"', "+cantidad+", '"+tiempo+"',"+total+");";
			SQL_operaciones(sql3);
			cin.ignore();
		break; 
		default:
            cout << "Algo salio mal, seleccione denuevo..." << endl;
            break;           
	};
	
	
}	
