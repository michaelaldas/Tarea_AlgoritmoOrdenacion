#include <iostream>
#include <time.h>
#include<stdlib.h>
using namespace std;
/*
Actividad:
1) Cree un projecto nuevo
2) Pegue estos algoritmos de ordenación en el proyecto creado
3) En el main cree su vector y haga las llamadas necesarias para verificar que los algoritmos funcionan
4) Subir y compartir en github hasta el domingo 15 de agosto/2021 (23:00 horas)
*/

void intercambiar(int &a, int &b)
{
    int aux=a;
    a=b;
    b=aux;
}

int ordenSecuencial(int vector[], int total)
{
    for(int i=0; i<total; i++)
    {
        for(int j=i+1; j<total; j++)
        {
            if(vector[i]>vector[j])
                intercambiar(vector[i], vector[j]);
        }
    }
}


int OrdenamientoQuicksort(int a[], int primerValor, int ultimoValor)
{
    int central, i, j, pivote;
    central= (primerValor+ultimoValor)/2; //Posicion central del arreglo
    pivote= a[central]; //Capturar el valor medio del arreglo
    i = primerValor;
    j = ultimoValor;

    do{
        //Separando en dos partes el arreglo
        while(a[i] < pivote) i++; //Separando los valores menores al pivote
        while(a[j] > pivote) j--; //Separando los valores mayores al pivote
        if(i<=j)
        {
            int temporal;
            //Intercambio de valores
            temporal = a[i];
            a[i] = a[j];
            a[j] = temporal;
            i++;
            j--;
        }
    }while(i<=j);
    if (primerValor < j)
        OrdenamientoQuicksort(a, primerValor, j);
    if (i < ultimoValor)
        OrdenamientoQuicksort(a, i, ultimoValor);
}



void ordenShell(int a[], int n)
{
    int ints,i,aux;
    bool band;
    ints=n;
    while(ints>1){
        ints=(ints/2);
        band=true;
        while(band==true){
            band=false;
            i=0;
            while((i+ints)<n){
                if(a[i]>a[i + ints]){
                    aux=a[i];
                    a[i]=a[i + ints];
                    a[i + ints]=aux;
                    band=true;
                }
                i++;
            }
        }
    }
}



void ordenShell2(int a[], int n){//optimizado
    int i,j,inc;
    int temp;
    for(inc=1;inc<n;inc=inc*3+1);
    while(inc>0){
        for(i=inc;i<n;i++){
            j=i;
            temp=a[i];
            while((j>=inc)&&(a[j-inc]>temp)){
                a[j]=a[j-inc];
                j=j-inc;
            }
            a[j]=temp;
        }
        inc=inc/2;
    }
}

void ordenBurbuja(int v[], int n)
{
    int i=0,j=0;
    int aux;
    for(i=1;i<n;i++)
        for(j=0;j<(n-i);j++)
        {
            if(v[j]>v[j+1])
            {
                aux=v[j];
                v[j]=v[j+1];
                v[j+1]=aux;
            }
        }
}

void burbujaMejorado(int arreglo[], int tamano)
{
    int comparaciones = tamano;
    bool termino = false;
    for (int i = 0; i<(tamano-1) ; i++)
    {
        if (termino)
            break;
        termino = true;
        for (int j = 0; j<comparaciones-1 ; j++)
            if(arreglo[j] > arreglo[j+1])
            {
                intercambiar(arreglo[j],arreglo[j+1]);
                termino = false;
            }
        comparaciones--;
    }
}
void mostrarorden(int vec[], int maximo){
    for(int ar=0; ar < maximo; ar++){
        cout<<vec[ar]<<endl;
    }
}
void leer_vector(int vector[], int tamanio) {
    for (int i = 0; i < tamanio; i++) {
        vector[i] = rand();
    }
}
int main()
{
    //EJERCICIO 1
    cout<<endl<<"...EJERCICIO 1 INTERCAMBIAR...";

    int a,b;

    cout <<endl<< "a = "; cin >> a;
    cout << "b = "; cin >> b;

    cout << "\nValores iniciales:" << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    intercambiar(a, b);

    cout << "\nValores intercambiados:" << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;


    //EJERCICIOS DE ORDENAMIENTO

    cout<<endl<<"...EJERCICIOS DE ORDENAMIENTO...";
    srand(time(NULL));
    int canti;
    cout<<"\nDigite la cantidad de elemtos:  ";
    cin>>canti;
    int numer[canti];

    leer_vector(numer, canti);
    cout<<" Elementos ingresados "<<endl;
    mostrarorden(numer,canti);

    //EJERCCIO 2

    cout<<endl<<"...EJERCCIO 2 ORDEN SECUENCIAL..."<<endl;
    ordenSecuencial(numer,canti);
    mostrarorden(numer,canti);

    //EJERCICIO 3

    cout<<endl<<"...EJERCICIO 3 ORDENAMIENTO QUICKSORT..."<<endl;
    OrdenamientoQuicksort(numer,0,canti-1);
    mostrarorden(numer,canti);

    //EJERCICIO 4

    cout<<endl<<"...EJERCICIO 4 ORDEN SHELL..."<<endl;
    ordenShell(numer,canti);
    mostrarorden(numer,canti);

    //EJERCICIO 5

    cout<<endl<<"...EJERCICIO 5 ORDEN SHELL 2..."<<endl;
    ordenShell2(numer,canti);
    mostrarorden(numer,canti);

    //EJERCICIO 6

    cout<<endl<<"...EJERCICIO 6 ORDEN BURBUJA..."<<endl;
    ordenBurbuja(numer,canti);
    mostrarorden(numer,canti);

    //EJERCICIO 7

    cout<<endl<<"...EJERCICIO 7 ORDEN BURBUJA MEJORADO..."<<endl;
    burbujaMejorado(numer,canti);
    mostrarorden(numer,canti);

    return 0;
}
