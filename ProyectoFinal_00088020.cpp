#include <iostream>
#include <stdio.h>

using namespace std;

const int longCad = 20;

struct costoPorArticulo{
char nombreArticulo[longCad + 1];
int cantidad;
float precioUnitario;
float precioTotal;
};

//Prototipos de Funciones
void PedirDatos(costoPorArticulo [], int);
void CalcularTotal(costoPorArticulo [], int);
void MostrarDatos(costoPorArticulo [], int);
float SumaTotal(costoPorArticulo [], int);

int main(){
	int n;
	cout<<"Digite el numero de elementos a procesar: ";
	cin>>n;
	cout<<endl;
	costoPorArticulo productos[n];//Se inicializa el arreglo con los elementos especificos
	
	PedirDatos(productos,n);
	CalcularTotal(productos, n);
	MostrarDatos(productos,n);
	
	cout<<"\nEl total de compra es: $"<<SumaTotal(productos, n);
	
	return 0;
}

void PedirDatos(costoPorArticulo productos[], int n){
	
	for(int i=0;i<n;i++){
		fflush(stdin);//Limpia el buffer para que no se llene y colapse
		cout<<"Ingrese el nombre del articulo "<<i+1<<": ";
		cin.getline(productos[i].nombreArticulo,longCad+1,'\n');
		cout<<"Ingrese la cantidad de productos: ";
		cin>>productos[i].cantidad;
		cout<<"Ingrese el precio del producto: ";
		cin>>productos[i].precioUnitario;
		cout<<endl;
	}
	
}

void CalcularTotal(costoPorArticulo productos[], int n){
	
	for(int i=0;i<n;i++){
		productos[i].precioTotal=productos[i].precioUnitario*productos[i].cantidad;//se obtiene el total por producto
	}
	
}

void MostrarDatos(costoPorArticulo productos[], int n){
	for(int i=0;i<n;i++){
		cout<<"\t"<<productos[i].cantidad<<" "<<productos[i].nombreArticulo<<"($"<<productos[i].precioUnitario<<")"<<"--> $"<<productos[i].precioTotal<<endl;
		//Muestra los 4 datos de la estructura
		//cantidad-nombre (precio de un elemento) ---> precio total	
	}
}

float SumaTotal(costoPorArticulo productos[], int n){
	float total=0;
	
	for(int i=0;i<n;i++){
		total+=productos[i].precioTotal;//suma cada uno de los precios de los diferentes productos
	}
	
	return total;//los envia.
}
