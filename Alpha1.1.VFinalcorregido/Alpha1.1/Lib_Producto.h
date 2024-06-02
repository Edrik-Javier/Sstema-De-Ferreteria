#include <ctime>
#include <sstream>

void M_Productos(){
	int seleccion, seleccion1;	
	cout<<"°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°\n";
	cout<<"°1)VER TODOS LOS PRODUCTOS        °\n";
	cout<<"°2)BUSCAR POR ID               °\n";
	cout<<"°3)REGISTRAR PRODUCTO             °\n";
	cout<<"°4)REGRESAR                    °\n";
	cout<<"°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°\n";
	cout<<"INGRESE LA OPCION A REALIZAR: ";
	cin>>seleccion;
	//
	//declaracion de variables
	string idu;
	string  descripcion, stock, precio;
	
	//varialbes de consultas
	string sql,sql1, sql2,sql3,sql4;//variables que contiene la consulta sql
	int query;

	switch(seleccion){
		case 1:
			sql= "SELECT * FROM Productos"; 
			cout<<"-----LISTA DE TODAS LOS PRODUCTOS---------";
			SQL_consulta(sql);
			cin.ignore();
		break;
		case 2:
			cout<<"-----BUSCAR POR ID DE PRODUCTO-------------\n";
			cout<<"Ingrese el id del producto: ";
			cin>>idu;
			sql1 = "SELECT * FROM Productos WHERE id_producto="+ idu +";";
				if(SQL_consulta(sql1) == true){
					cout<<"\n 1.Realizar modificacion";
					cout<<"\n 2.Eliminar este registro";
					cout<<"\n 3.Regresar al menu...";
					cin>>seleccion1;
						switch(seleccion1){
							case 1:
								cin.ignore();
								cout<<"°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°\n";
								cout<<"==>Ingrese la descripcion de la compra\n";
								getline(cin, descripcion);
								cout<<"==>Ingrese la cantidad\n";
								cin>>stock;
								cout<<"==>Ingrese el Precio(Q.)\n";
								cin>>precio;
								cout<<"°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°\n";
								//realizamos consulta
								sql2 = "UPDATE Productos SET Descripcion='"+descripcion+"', Stock ="+ stock+", Precio="+precio+" WHERE id_producto ='"+idu+"';";
								SQL_operaciones(sql2);
								SQL_consulta(sql1);
								cin.ignore();
							break;
							case 2:
								//realizamos consulta de borrado
								sql4="DELETE FROM Productos WHERE id_producto="+idu+";";
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
			cout<<"==>Ingrese la descripcion de la compra\n";
			getline(cin, descripcion);
			cout<<"==>Ingrese la cantidad\n";
			cin>>stock;
			cout<<"==>Ingrese el Precio(Q.)\n";
			cin>>precio;
			//realizamos la consulta
			sql3 = "INSERT INTO Productos (Descripcion, Stock, Precio) VALUES ('"+descripcion+"',"+stock+", "+precio+");";
			SQL_operaciones(sql3);
			cin.ignore();
		break; 
		default:
            cout << "Algo salio mal, seleccione denuevo..." << endl;
            break;           
	};	
}	
