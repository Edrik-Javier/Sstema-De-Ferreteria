USE  DB_FERRETERIA
CREATE TABLE USERS(
id_user int not null auto_increment,
U_User char(30) not null,
U_Password char(20) not null,
U_Tipe int not null,
primary key(id_user)
)
CREATE TABLE TIPOUSUARIO(
id_TipoU int not null auto_increment,
T_Descripcion char(50) not null,
primary key(id_TipoU)
);

INSERT INTO TIPOUSUARIO (T_Descripcion) VALUES ('Administrador');
INSERT INTO TIPOUSUARIO (T_Descripcion) VALUES ('Personal');
INSERT INTO TIPOUSUARIO (T_Descripcion) VALUES ('Cliente');
SELECT * FROM TIPOUSUARIO
CREATE DATABASE DB_FERRETERIA

Create table Empleados(
id_empleado int not null auto_increment,
Nombre char(50) not null,
Fecha_de_Nacimiento date not null,
Genero char(20) not null,
Direccion char(100) not null,
Puesto char(30) not null,
Telefono char(10) not null,
Correo_corporativo char(40) not null,
Salario char(50) not null, 
primary key(id_empleado)
);
drop table Empleados;
SELECT * FROM Empleados
INSERT INTO Empleados (Nombre, Fecha_de_Nacimiento, Edad, Genero, Direccion, Puesto, Telefono, Correo_corporativo, Salario)
VALUES ('', STR_TO_DATE('', '%d-%m-%Y'), 20, '', '', '', '', '');
Alter table Empleados Drop column Edad

CREATE TABLE Clientes(
id_cliente int not null auto_increment,
Nombre char(50) not null,
Fecha_de_Nacimiento date not null,
Genero char(20) not null,
Direccion char(30) not null,
Telefono char(10) not null,
Correo char(40) not null,
Saldo char(50) not null,
primary key(id_cliente)
);
CREATE TABLE Proveedores(
id_proveedor int not null auto_increment,
Nombre char(40) not null,
Direccion char(30) not null,
Telefono char(10) not null,
Correo char(60) not null,
Saldo char(50) not null,
primary key(id_proveedor)
);
create table Compras(
id_compra int not null auto_increment,
id_proveedor int not null,
Descripcion varchar(100) not null,
Cantidad int not null,	
Fecha date not null,
Hora time not null,
Total double,
primary key(id_compra)
);	
drop table Compras
create table Ventas(
id_venta int not null auto_increment,
id_producto int not null,
id_cliente int not null,
id_empleado int not null,
Descripcion VARchar(100) not null,
Cantidad int not null,
Fecha date not null,
Hora time not null,
Total double,
primary key(id_venta)
);
create table Productos(
id_producto int not null auto_increment,
Descripcion varchar(100) not null,
Stock int not null,
Precio double not null,
primary key(id_producto)
);
