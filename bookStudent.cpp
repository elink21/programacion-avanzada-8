/*Programa que hace uso de las estructuras de datos
Elias Edgardo Segundo Antonio
*/
#include <iostream>
using namespace std;

struct book
{
	int key;
	string auth;
	string title;
	string abstract;
	double price;
};

struct student
{
	int key;
	string name;
	double notes[2];
	string stat;
	double avg;
};

student me;
book test;
int main()
{
	int option;

	while(option!=3)
	{
		cout<<"Que estructura de datos desea probar?\n";
		cout<<"1.-Libro \n2.-Estudiante\n 3.-Salir\n Ingrese: ";
		cin>>option;
		switch(option)
		{
			case 1:
			cout<<"Ingrese el nombre del libro: ";
			cin.get();
			getline(cin,test.title);
			cout<<"Ahora ingrese el autor: ";
			getline(cin,test.auth);
			cout<<"Ingrese la clave del libro: ";
			cin>>test.key;
			cout<<"Finalmente, escriba un reducido resumen: ";
			cin.get();
			getline(cin,test.abstract);
			cout<<"Cuanto cuesta el libro?: ";
			cin>>test.price;

			cout<<"Estos son los datos del libro: \n";
			cout<<"Clave: "<<test.key<<
			"\n Titulo: "<<test.title
			<<"\n Autor: "<<test.auth
			<<"\n Resumen: "<<test.abstract
			<<"\n Precio: "<<test.price<<"\n";

			break;
			case 2:
			cout<<"Ingrese el nombre del estudiante: ";
			cin.get();
			getline(cin,me.name);
			cout<<"Ahora ingrese su clave: ";
			cin>>me.key;
			cout<<"Cual fue la calificacion el primer parcial?: ";
			cin>>me.notes[0];
			cout<<"La del segundo: ";
			cin>>me.notes[1];
			me.avg= (me.notes[0]+me.notes[1])/2.0;
			if(me.avg>=8.0)
			{
				me.stat="EXENTO";
			}
			else if(me.avg>=6.0)
			{
				me.stat="ORDINARIO";
			}
			else me.stat="EXTRAORDINARIO";
			cout<<"\nSu promedio "<<me.name<<" es: "<<me.avg;
			cout<<"\nSu estado con la clave "<<me.key<<" es: "<<me.stat<<"\n";

			break;
			default:
			if(option!=3)
				cout<<"\nInserte una opcion valida\n";
		}
	}


}