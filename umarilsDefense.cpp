#include <iostream>
#include <cstdlib>
#include <math.h>
#include <cmath>

using namespace std;

float gravedad = 9.81;

// Función para redondear numeros
int redondear_num(float num)
{

    return float(num - floor(num)) >= 0.5 ? round(num) : floor(num);
};

// Función para pasar de radianes a angulos
int de_radian_a_angulo(int radian)
{
    return radian * 180 / M_PI;
}

// Ajustar el ángulo del cañón
int calcular_angulo(int Vo, int distancia)
{
    int discriminante = pow(Vo, 4) - (gravedad * (gravedad * pow(distancia, 2)));
    if (discriminante < 0)
    {
        // No hay ángulo que nos permita alcanzar al objetivo
        return -1;
    }

    int angulo1 = atan((pow(Vo, 2) + sqrt(discriminante)) / (gravedad * distancia));
    int angulo2 = atan((pow(Vo, 2) - sqrt(discriminante)) / (gravedad * distancia));

    // Convertir ángulos a grados
    angulo1 = de_radian_a_angulo(angulo1) / 2;
    angulo2 = de_radian_a_angulo(angulo2) / 2;

    // Elegir el ángulo positivo más cercano al ángulo original
    if (angulo1 >= 0 && angulo1 <= 90)
    {
        return angulo1;
    }
    else
    {
        return angulo2;
    }
}

int main()
{

    //---Declaración de Variables Principales---

    // Referentes al ambiente

    // Referentes al canon
    int numeroDeCanones = 0;
    char IDcanon;
    int posicionX = 0;
    int posicionY = 0;
    int Vo = 0;
    int theta = 0;
    float thetaRadian = 0;
    // Referentes a la bala
    float alturaMax = 0;
    float tiempoVuelo = 0;
    int tiempoImpacto = 0;

    // Referentes al Objetivo
    int numeroDeObjetivos = 0;
    int IDobj = 0;
    float posicionXObj = 0;
    float posicionYObj = 0;

    // Contadores o Iteradores
    int i = 0; // contador de canones
    int j = 0; // contador de Objetivos

    //---Primera Etapa - ENTRADA DE DATOS: Numero de Canones---
    cin >> numeroDeCanones;
    cout << endl;

    // Validacion del Numero de Canones
    if (numeroDeCanones <= 0 || numeroDeCanones > 26)
    {
        cout << "Datos de entrada invalidos ";
    }

    else
    {

        //---Segunda Etapa - For Loop para cada canon---
        for (i; i < numeroDeCanones; i++)
        {

            // Letra que identifica al cañon
            IDcanon = char(i + 65);

            // Entrada de la configuracion de cada canon
            cin >> posicionX;
            cin >> posicionY; // Entrada de la Posicion Inicial del cañon

            // Validacion de la posicion del canon
            if (posicionY < 0 || posicionY > 50)
            {
                cout << "Datos de entrada invalidos ";
                break;
            }

            else
            {
                // Entrada de la Velocidad Inicial y el Angulo con la horizontal
                cin >> Vo;
                cin >> theta;

                // Validacion Velocidad Maxima y angulo de disparo
                if (Vo <= 0 || Vo > 500 || theta > 180 || theta < 0)
                {
                    cout << "Datos de entrada invalidos ";
                    break;
                }
                else
                {

                    // Conversion de Theta a Radianes para uso de Seno / Coseno
                    thetaRadian = theta * M_PI / 180;

                    // Calculo de Altura Maxima
                    alturaMax = redondear_num((pow(Vo, 2) * pow(sin(thetaRadian), 2)) / (2 * gravedad));

                    // Calculo del tiempo de vuelo
                    tiempoVuelo = redondear_num((2 * Vo * sin(thetaRadian)) / gravedad);

                    // // Salida altura maxima de los proyectiles
                    cout << "Los proyectiles del canon " << IDcanon << " subiran hasta " << alturaMax << " metros antes de comenzar a caer. ";

                    // Salida tiempo de impacto de los proyectiles
                    cout << "Estos impactaran contra el suelo pasados " << tiempoVuelo << " segundos luego de ser disparados." << endl;

                    // Definicion de objetivos del canon actual y su respectivo For Loop
                    cin >> numeroDeObjetivos;

                    // For Loop de cada objetivo
                    for (j; j < numeroDeObjetivos; j++)
                    {
                        // Identificador del objetivo
                        IDobj = j + 1;

                        cin >> posicionXObj;
                        cin >> posicionYObj; // Entrada de la posicion del objetivo actual

                        int distMax;
                        distMax = pow(Vo, 2) * sin(2 * thetaRadian) / gravedad;

                        // Validacion de la posicion del objetivo
                        if (posicionYObj == posicionY && posicionXObj == posicionX)
                        {
                            cout << "Canon destruido";
                            break;
                        }
                        else if ((posicionXObj < posicionX && theta < 90) || (posicionXObj > posicionX && theta > 90))
                        {
                            cout << "Posicion Comprometida";
                        }
                        else if ((posicionXObj == posicionX) && (posicionYObj != posicionY))
                        {
                            cout << "Enemigos en las murallas";
                        }
                        else if (distMax < posicionXObj)
                        {
                            // VALIDACION DE CASOS ESPECIALES

                            int nuevoAngulo = calcular_angulo(Vo, distMax);

                            cout << "Reajuste de " << nuevoAngulo << " grados requeridos en el canon " << IDcanon << endl;
                        }
                        else
                        {
                            // Calculo del Tiempo de Impacto
                            tiempoImpacto = redondear_num((posicionXObj) / (Vo * cos(thetaRadian)));

                            // // Salida destrucción de los objetivos
                            cout << "Objetivo " << IDobj << " destruido por el canon " << IDcanon << " en " << tiempoImpacto << " segundos." << endl;
                        }
                    }
                    j = 0;
                }
            }
        }
    }

    return 0;
}
