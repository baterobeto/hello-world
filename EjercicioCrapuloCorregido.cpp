#include <iostream>
using namespace std;

/*

Crápulo
Dado un número entero positivo, su crápulo es un número que se obtiene sumando los dígitos que lo componen,
si el valor de la suma
es menor que 10. Si la suma es mayor que 10, el crápulo es el crápulo de la suma de los dígitos.

Se pide, dados trés números:
Realizar una función que calcule su crápulo.
Realizar una función que permita Imprimir los crápulos de menor a mayor


*/

int crapula(int numero)
{
    int crapulo;
    int unidad, decena, centena;

    for (int i = 0; i < 3; i++)
    {

        cout << "Ingrese un numero: ";
        cin >> numero;

        if (numero > 99)
        {
            unidad = numero % 10;
            decena = (numero % 100) / 10;
            centena = numero / 100;
            crapulo = unidad + decena + centena;

            while (crapulo > 9)
            {
                unidad = crapulo % 10;
                decena = (crapulo % 100) / 10;
                centena = crapulo / 100;
                crapulo = unidad + decena + centena;
            }
            if (crapulo == 10)
            {
                crapulo = 1;
            }
        }
        else
        {
            if ((numero > 10) && (numero < 100))
            {
                unidad = numero % 10;
                decena = numero / 10;
                crapulo = unidad + decena;

                if (crapulo > 9)
                {
                    unidad = crapulo % 10;
                    decena = crapulo / 10;
                    crapulo = unidad + decena;
                }
            }
            else
            {
                if (numero < 10)
                {
                    crapulo = numero;
                }
                return crapulo;
            }
        }
        return crapulo;

        return crapulo;
    }
}

void ordenDeNumeros(int numero, int &mayor, int &mediano, int &menor)
{
    if (numero > mayor)
    {
        menor = mediano;
        mediano = mayor;
        mayor = numero;
    }
    else
    {
        if (numero > mediano)
        {
            menor = mediano;
            mediano = numero;
        }
        else
        {
            menor = numero;
        }
    }
}

int main()
{
    int numero, mayor = 0, mediano = 0, menor, valor;

    for (int i = 0; i < 3; i++)
    {
        numero = crapula(numero);

        cout << numero << endl;

        ordenDeNumeros(numero, mayor, mediano, menor);
    }
    cout << "El crapulo menor es: " << menor << endl
         << "El crapulo mediano es: " << mediano << endl
         << "El crapulo mayor es: " << mayor << endl;
    return 0;
}