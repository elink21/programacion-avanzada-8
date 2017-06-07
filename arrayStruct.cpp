/*
Programa de registro de pasajeros
Elias Edgardo Segundo Antonio
*/
#include <iostream>
#include <vector>
#include <iomanip>
#include <fstream>
using namespace std;

struct traveller{
	int key;
	string name;
	string origin;
	string destiny;
	double price;
};
vector<traveller> travellers(10);

//Prototype section
void setup();
void read();
void showData();
void getData();
bool insertData(traveller);
int findPlace();
string chSpace(string);
string chSharp(string);
void write();
void menu();

int main()
{
	setup();
	int option;
	while(option!=3)
	{
		menu();
		cin>>option;
		switch(option)
		{
			case 1:
				getData();
				break;
			case 2:
				showData();
				break;
			default:
				if(option!=3)
					cout<<"\nIngrese una opcion valida\n";
		}
	}
}
void menu()
{
	cout<<"Ingrese el numero de la opcion deseada: \n"
	<<"1.-Registrar Un pasajero\n"
	<<"2.-Mostrar datos del archivo\n"
	<<"3.- Salir\n"
	<<"Ingrese: ";
}

void showData()
{
	read();
	cout<<setw(6)<<"Clave"<<setw(40)<<"Nombre"<<
	setw(30)<<"Origen"<<setw(30)<<"Destino"<<setw(12)<<"Pasaje\n";
	for(traveller t: travellers)
	{
		if(t.key!=-1)
		{
			cout<<setw(6);
			cout<<t.key;
			cout<<setw(40);
			cout<<chSharp(t.name);
			cout<<setw(30);
			cout<<chSharp(t.origin);
			cout<<setw(30);
			cout<<chSharp(t.destiny);
			cout<<setw(12);
			cout<<t.price<<" \n";	
		}
		
	}
}

void read()
{
	setup();
	ifstream in("passengers.txt",ios::in);
	int pos=0;
	while(in>>travellers[pos].key>>travellers[pos].name>>
		travellers[pos].origin>>travellers[pos].destiny>>
		travellers[pos].price
		)
	{
		pos++;
	}
}


void write()
{
	ofstream out("passengers.txt",ios::out);
	if(out)
	{
		for(traveller t: travellers)
		{
			if(t.key!=-1)
			out<<t.key<<" "<<chSpace(t.name)<<" "
			<<chSpace(t.origin)<<" "
			<<chSpace(t.destiny)<<" "
			<<t.price<<" ";
		}
		out.close();
	}
	else cout<<"Error al abrir el archivo";
}

string chSharp(string s)
{
	for(int i=0;i<s.size();i++)
		if(s[i]=='#')s[i]=' ';
	return s;
}

string chSpace(string s)
{
	for(int i=0;i<s.size();i++)
		if(s[i]==' ')s[i]='#';
	return s;
}

int findPlace()
{
	for(int i=0;i<travellers.size();i++)
	{
		if(travellers[i].key==-1)return i;
	}
	cout<<"debug\n";
	return -1;
}

bool insertData(traveller temp)
{
	int placeEmpty=findPlace();
	if(placeEmpty!=-1)
	{
		travellers[placeEmpty]=temp;
		return true;
	}
	else return false;

}

void getData()
{
	cin.get();
	traveller temp;
	cout<<"Introduzca el nombre del pasajero: ";
	getline(cin,temp.name);
	cout<<"Introduzca la clave del pasajero: ";
	cin>>temp.key;
	cin.get();
	cout<<"Ahora introduzca el origen: ";
	getline(cin,temp.origin);
	cout<<"Introduzca el destino: ";
	getline(cin,temp.destiny);
	cout<<"Finalmente introduzca el precio del viaje: ";
	cin>>temp.price;
	cin.get();
	if(insertData(temp))
	{
		write();
		cout<<"\nRegistro exitoso!\n";

	} else cout<<"\nNo hay lugares\n";

}

void setup()
{
	traveller empty;
	empty.key=-1;
	empty.name="";
	empty.origin="";
	empty.destiny="";
	empty.price=0;
	for(int i=0;i<travellers.size();i++)
	{
		travellers[i]=empty;
	}
}
