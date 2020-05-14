#include <iostream>
using namespace std;

/*CELULAR
    Puede enviar mensajes de texto de hasta 256 caracteres
    Puede realizar llamadas telefónicas
    Puede tomar fotos.
    Este prototipo posee una batería cuya duración, es un valor entero entre 1 y 100, configurable al momento de iniciar el celular.


    Los consumos de batería son los siguientes:
    1-Por cada mensaje enviado, la batería se consume en un 1% sobre el total actual.
    2-Por cada llamada realizada, la batería se consume en una cantidad fija, determinada por la siguiente fórmula: cantidad de
    minutos * 0,08
    3-Por cada foto tomada, la batería consume 6% sobre el total actual.


    a) Cuál fue la llamada de mayor duración.
    b) El porcentaje de mensajes que superan los 10 caracteres por sobre el total de mensajes enviados.

    Nota: se recomienda el uso de funciones para simular el comportamiento del prototipo, por ejemplo enviarMensaje, realizarLlamada,
    tomarFoto

Revisar los consumos de batería que no son correctos. Por ejemplo en el envío del mensaje es un 1% del total 
actual eso no significa que sea 1 como entero.
* En la función tomar foto no se solicita la cantidad de fotos y el consumo de batería es un 6% sobre el total de la batería.
* Para la siguiente secuencia no me da ningún resultado:
* tomar 3 fotos
* llamada de 200 minutos
Como salida debería mostrar que la llamada de mayor duración fue de 200 minutos y 
que el porcentaje de mensajes cuya longitud es mayor a 10 es 0%
    
    */

void enviarMensaje(int &bateriaActual, float &calculoMensajes, int &contadorMensajesGrandes, int &contadorMensajesEnviados)
{

    
    int cantCaracteres;

    cout << "Cuantos caracteres contiene su mensaje? : ";
    cin >> cantCaracteres;

    if (cantCaracteres >= 10)
    {
        contadorMensajesGrandes = contadorMensajesGrandes + 1;
    }

    contadorMensajesEnviados = contadorMensajesEnviados + 1;

    bateriaActual = bateriaActual - (bateriaActual * 0.01);
}

void realizarLlamada(int &bateriaActual, int &llamadaMayor)
{
    int cantMinutos;

    cout << "Duracion de la mada en minutos: ";
    cin >> cantMinutos;

    bateriaActual = bateriaActual - (cantMinutos * 0.08);

    if (cantMinutos > llamadaMayor)
    {
        llamadaMayor = cantMinutos;
    }
}
void tomarFoto(int &bateriaActual)
{

    bateriaActual = bateriaActual - (bateriaActual * 0.06);
}

int main()
{

    int bateria;
    int bateriaActual;
    float consumo;

    int llamadaMayor = 0;
    float calculoMensajes = 0;

    int contadorMensajesGrandes = 0;
    int contadorMensajesEnviados = 0;

    string accion, mensaje;

    cout << "Por favor, ingrese su porcentaje de bateria: ";
    cin >> bateria;

    mensaje = "Funcionando";

    bateriaActual = bateria;

    while (mensaje == "Funcionando")
    {
        cout << "Que accion desea realizar? ('foto' / 'llamar' / 'mensaje' ) : " << endl;
        cin >> accion;

        if (accion == "foto")
        {

            tomarFoto(bateriaActual);
        }
        else
        {
            if (accion == "llamar")
            {

                realizarLlamada(bateriaActual, llamadaMayor);
            }
            else
            {
                if (accion == "mensaje")
                {

                    enviarMensaje(bateriaActual, calculoMensajes, contadorMensajesGrandes, contadorMensajesEnviados);
                }
            }
        }

        bateria = bateriaActual;

        if (bateria > 0)
        {
            cout << "Porcentaje de bateria : " << bateria << endl;

            mensaje = "Funcionando";
        }
        else
        {
            bateria = 0;
            cout << bateria << " %" << endl;
            calculoMensajes = ((contadorMensajesGrandes * 100) / (contadorMensajesEnviados));
            cout << "La llamada de mayor duracion fue de " << llamadaMayor << " minutos" << endl;
            cout << "El porcentaje de mensajes mayores a 10 caracteres es : " << calculoMensajes << "%" << endl;
            mensaje = "bateria insuficiente, apagando...";
            cout << endl;
            cout << mensaje;
        }

        mensaje;
    }
    return 0;
}