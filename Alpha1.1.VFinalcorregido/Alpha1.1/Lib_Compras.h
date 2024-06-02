#include <ctime>
#include <sstream>

void M_Compras(){
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
	cout<<"°1)VER TODOS LOS COMPRAS       °\n";
	cout<<"°2)BUSCAR POR ID               °\n";
	cout<<"°3)REALIZAR COMPRA             °\n";
	cout<<"°4)REGRESAR                    °\n";
	cout<<"°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°\n";
	cout<<"INGRESE LA OPCION A REALIZAR: ";
	cin>>seleccion;
	//
	//declaracion de variables
	string idu;
	string descripcion, idproveedor, cantidad, total;
	
	
	
	//varialbes de consultas
	string sql,sql1, sql2,sql3,sql4;//variables que contiene la consulta sql
	int query;

	switch(seleccion){
		case 1:
			sql= "SELECT * FROM Compras"; 
			cout<<"-----LISTA DE TODAS LAS COMPRAS---------";
			SQL_consulta(sql);
			cin.ignore();
		break;
		case 2:
			cout<<"-----BUSCAR POR ID DE COMPRA-------------\n";
			cout<<"Ingrese el id de la compra: ";
			cin>>idu;
			sql1 = "SELECT * FROM Compras WHERE id_compra="+ idu +";";
				if(SQL_consulta(sql1) == true){
					cout<<"\n 1.Realizar modificacion";
					cout<<"\n 2.Eliminar este registro";
					cout<<"\n 3.Regresar al menu...";
					cin>>seleccion1;
						switch(seleccion1){
							case 1:
								cin.ignore();
								cout<<"°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°\n";
								cout<<"==>Ingrese el id de proveedor\n";
								cin>>idproveedor;
								cout<<"==>Ingrese la descripcion de la compra\n";
								getline(cin, descripcion);
								cout<<"==>Ingrese la cantidad\n";
								cin>>cantidad;
								cout<<"==>Ingrese el total(Q.)\n";
								cin>>total;
								cout<<"°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°\n";
								//realizamos consulta
								sql2 = "UPDATE Compras SET id_proveedor="+idproveedor+", Descripcion ='"+ descripcion+"', Cantidad="+cantidad+", total="+total+" WHERE id_compra ='"+idu+"';";
								SQL_operaciones(sql2);
								SQL_consulta(sql1);
								cin.ignore();
							break;
							case 2:
								//realizamos consulta de borrado
								sql4="DELETE FROM Compras WHERE id_compra="+idu+";";
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
			cout<<"==>Ingrese el id de proveedor\n";
			cin>>idproveedor;
			cin.ignore();
			cout<<"==>Ingrese la descripcion de la compra (esto tomando en cuanto su unidad de medida y unidad de compra)\n";
			getline(cin, descripcion);
			cout<<"==>Ingrese la cantidad\n";
			getline(cin, cantidad);
			cout<<"==>Ingrese el total (Q.)\n";
			getline(cin, total);
			cout<<"°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°\n";
			//realizamos la consulta
			sql3 = "INSERT INTO Compras (id_proveedor,Descripcion, Cantidad, Fecha,Hora, Total) VALUES ('"+idproveedor+"','"+descripcion+"', '"+cantidad+"', '"+fecha+"', '"+hora+"', '"+total+"');";
			SQL_operaciones(sql3);
		break; 
		default:
            cout << "Algo salio mal, seleccione denuevo..." << endl;
            break;           
	};	
}	
