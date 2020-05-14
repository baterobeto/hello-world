#include <iostream>
using namespace std;


int calculoCuadrado (int largoLado){

    int respuesta ;
   
    int ancho; 
   
    for (int ancho=0; ancho<largoLado ; ancho++) {
      for (int i=0; i<largoLado ; ++i) {
         cout << "*" ;
      }
      cout << endl;
   }
        return respuesta ; 

   
}

void calculoTriangulo (int baseTriangulo){
    int respuesta ; 

    for (int i=0; i<baseTriangulo; i++)
    {
        for(int j=0; j<=i; j++ )
        {
            cout << " *";
        }
        cout << endl;
    }
    
}

int main(){

string ingresoUsuario = " "; 

int largoLado; 
int baseTriangulo;
int respuesta ; 


cout << "Ingrese la figura que desea dibujar (Cuadrado/Triangulo) : "<<endl;
cin>>ingresoUsuario; 


if (ingresoUsuario == "cuadrado"){

    cout<<"Ingrese el largo del lado : "<<endl; 
    cin>>largoLado; 

calculoCuadrado (largoLado) ;

cout<< respuesta << endl; 

}

if (ingresoUsuario == "triangulo"){

    cout<<"ingrese la base del triangulo : "<<endl; 
    cin>>baseTriangulo;

calculoTriangulo (baseTriangulo);

cout<< respuesta << endl; 

}
  
}