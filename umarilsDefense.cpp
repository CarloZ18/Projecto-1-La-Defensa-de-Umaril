#include <iostream>
#include <cstdlib>
#include <math.h>
#include <cmath>

using namespace std;

int main()
{

    //---Declaración de Variables Principales---

    // Referentes al ambiente
    float gravedad = 9.81;

    // Referentes al canon
    int numeroDeCanones = 0;
    char IDcanon;
    int posicionX = 0;
    int posicionY = 0;
    int Vo = 0;
    int theta = 0;
    float thetaRadian = 0;

    // Referentes a la bala
    int alturaMax = 0;
    int tiempoVuelo = 0;
    float tiempoImpacto = 0.0;

    // Referentes al Objetivo
    int numeroDeObjetivos = 0;
    int IDobj = 0;
    float posicionXObj = 0;
    float posicionYObj = 0;

    // Contadores o Iteradores
    int i = 0; // contador de canones
    int j = 0; // contador de Objetivos

    //---Primera Etapa - ENTRADA DE DATOS: Numero de Canones---
    cout << "Ingresa el numero de canones ";
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
            IDcanon = char(i + 65);
            // Entrada de la configuracion de cada canon
            cout << "Ingresa las coordenadas del canon ";
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
                cout << "Ingresa la velocidad inicial y el angulo con la horizontal ";
                cin >> Vo;
                cin >> theta; // Entrada de la Velocidad Inicial y el Angulo con la horizontal

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
                    alturaMax = ceil((pow(Vo, 2) * pow(sin(thetaRadian), 2)) / (2 * gravedad));

                    // Calculo del tiempo de vuelo
                    tiempoVuelo = ceil((2 * Vo * sin(thetaRadian)) / gravedad);

                    // // Salida altura maxima de los proyectiles
                    cout << "Los proyectiles del canon " << IDcanon << " subiran hasta " << alturaMax << " metros antes de comenzar a caer. ";

                    // Salida tiempo de impacto de los proyectiles
                    cout << "Estos impactaran contra el suelo pasados " << tiempoVuelo << " segundos luego de ser disparados." << endl;

                    // Definicion de objetivos del canon actual y su respectivo For Loop
                    cout << "Ingresa el numero de objetivos ";
                    cin >> numeroDeObjetivos;

                    // For Loop de cada objetivo
                    for (j; j < numeroDeObjetivos; j++)
                    {
                        cout << "Ingresa las coordenadas del objetivo ";
                        cin >> posicionXObj;
                        cin >> posicionYObj; // Entrada de la posicion del objetivo actual

                        // Validacion de la posicion del objetivo
                        if (posicionYObj < 0)
                        {
                            cout << "Datos de entrada invalidos ";
                            break;
                        }

                        else
                        {
                            // VALIDACION DE CASOS ESPECIALES

                            //(ANGEL)

                            // ETAPA 3 - ENTRADAS VALIDAS; CALCULO DE FORMULAS FISICAS

                            //(Vo * sin(thetaRadian) + sqrt(pow(Vo, 2) * pow(sin(thetaRadian), 2) + (2 * gravedad * posicionY))) / gravedad;

                            // Calculo del Tiempo de Impacto
                            tiempoImpacto = (posicionXObj) / (Vo * cos(thetaRadian));

                            // Impresion de Salidas

                            //(CARLOS)
                        }
                    }
                }
            }
        }
    }

    return 0;
}
