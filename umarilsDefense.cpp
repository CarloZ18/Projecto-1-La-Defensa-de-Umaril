#include<iostream>
#include<stdlib>
#include<math.h>
#include<cmath>

using namespace std;

int main () {

    //---Declaración de Variables Principales---
    
    //Referentes al canon
    int numeroDeCanones = 0;
    int IDcanon = 0;
    int posicionX = 0;
    int posicionY = 0;
    int Vo = 0;
    int theta = 0;

    //Referentes a la bala
    int alturaMax = 0;
    int tiempoVuelo = 0;

    //Referentes al Objetivo
    int numeroDeObjetivos = 0;
    int IDobj = 0;
    float posicionXObj = 0;
    float posicionYObj = 0;

    //Contadores o Iteradores
    int i = 0; //contador de canones
    int j = 0; //contador de Objetivos

    //---Primera Etapa - ENTRADA DE DATOS: Numero de Canones---
    cin>> numeroDeCanones ; cout << endl;

    //Validacion del Numero de Canones
    if (numeroDeCanones <= 0 || numeroDeCanones > 26) {
        cout << "Datos de entrada invalidos";
    }

    else {
        
        //---Segunda Etapa - For Loop para cada canon---
        for (i; i <= numeroDeCanones; i++) {

            //Entrada de la configuracion de cada canon
            cin>> posicionX ; cin>> posicionY; //Entrada de la Posicion Inicial del cañon

            // Validacion de la posicion del canon
            if ( posicionY < 0 || posicionY > 50){
                cout << "Datos de entrada invalidos";
                break;
            }

            else {
                
                cin>> Vo ; cin>> theta;  // Entrada de la Velocidad Inicial y el Angulo con la horizontal

                //Validacion Velocidad Maxima y angulo de disparo
                if (Vo <= 0 || Vo > 500 || theta > 180 || theta < 0) {
                    cout << "Datos de entrada invalidos";
                    break;
                }
                else {

                    //Definicion de objetivos del canon actual y su respectivo For Loop
                    cin >> numeroDeObjetivos;

                    // For Loop de cada objetivo
                    for (j; j <= numeroDeObjetivos; j++) {

                        cin>> posicionXObj ; cin >> posicionYObj; // Entrada de la posicion del objetivo actual

                        //Validacion de la posicion del objetivo
                        if (posicionYObj < 0) {
                            cout << "Datos de entrada invalidos";
                            break;
                        }

                        else {
                            

                        }
                    }   
                }
            }
        }    
    }

    return 0;
}
