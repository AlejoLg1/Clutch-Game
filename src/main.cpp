#include <iostream>

#include "funciones.h"

#include <string> // PERMITE VARIABLES STRINGS

#include <conio.h> // _getch() -> INPUT SIN MOSTRAR TEXTO
#include <stdlib.h> // system() -> EJECUTA COMANDOS
#include <windows.h> // Sleep() -> PAULA LA EJECUCIÓN DURANTE EL LAPSO DEFINIDO


using namespace std;

int main() {
    setlocale(LC_ALL, "Spanish");

    //// - - - - MENÚ PRINCIPAL - - - - \\\\

    int opcionSeleccionadaMP;



    //// - - - - OPCIÓN 1 (JUGAR) - - - - \\\\

    //DURANTE PARTIDA
    //INT
    int x, i, j, k;
    int primerTirador, resultadoCheckeo;
    int dado, respuestaOp6;
    int contRondas = 1, Ganador = 0;
    int cartasPO[5] = {}, cartasPT[5] = {}, cartasBloqueadasPO[5] = {}, cartasBloqueadasPT[5] = {}, contadorCartasRepartidas[5] = {};

    //STRING
    string playerOne, playerTwo;
    string bastosCartasPO[5], bastosCartasPT[5];
    string palos[4][5] = {
    {"Treboles", "Treboles", "Treboles", "Treboles", "Treboles"},
    {"Diamantes", "Diamantes", "Diamantes", "Diamantes", "Diamantes"},
    {"Corazones", "Corazones", "Corazones", "Corazones", "Corazones"},
    {"Picas", "Picas", "Picas", "Picas", "Picas"}
    };

    //CHAR
    char confirmacion;


    //CONTEO DE PUNTOS

    //INT
    int jugador, jugadorRobando, ultRondaRobo;
    int opcionSeleccionadaTrasGanar;
    int puntajeTotal = 0, mayorPuntuacion = 0;
    int puntajes[5] = {};
    bool ordenInverso = false;

    //STRING
    string playerGanador;


    //BOOL
    bool pasaTurnoPO = false, pasaTurnoPT = false;
    bool robadoPO = false, robadoPT = false;



    //// - - - - OPCIÓN 2 (ESTADÍSTICAS) - - - - \\\\

    //INT
    int opcionSeleccionadaOp2;


    //// - - - - OPCIÓN 3 (CRÉDITOS) - - - - \\\\

    //INT
    int opcionSeleccionadaOp3;



    //// - - - - OPCIÓN 0 (SALIR) - - - - \\\\

    //INT
    int opcionSeleccionadaOp0;


    menuPrincipal();

    opcionSeleccionadaMP = _getch();

    while(true){

        switch(opcionSeleccionadaMP){
            case 49: //JUGAR
                // INGRESAMOS LOS NOMBRES DE LOS JUGADORES Y CONFIRMAMOS
                playerOne = ingresarPlayerOne(playerOne);
                playerTwo = ingresarPlayerTwo(playerTwo, playerOne);
                confirmacion = confirmarJuego(playerTwo, playerOne);

                // VALIDACIÓN SOBRE CONFIRMACIÓN
                while(confirmacion == 'N' || confirmacion == 'n'){
                    playerOne = ingresarPlayerOne(playerOne);
                    playerTwo = ingresarPlayerTwo(playerTwo, playerOne);
                    confirmacion = confirmarJuego(playerTwo, playerOne);
                }

                // MOSTRAMOS EL HEADER DEL JUEGO Y REPARTIMOS CARTAS DE MANERA ALEATORIA
                headerPartida(contRondas, playerOne, playerTwo);
                repartirCartasPO(cartasPO, contadorCartasRepartidas);
                repartirCartasPT(cartasPT, contadorCartasRepartidas);
                resultadoCheckeo = checkearOrden(cartasPO, cartasPT);

                // Si SE REPARTIERON ORDENADAS VOLVEMOS A REPARTIR
                while(resultadoCheckeo == 1){
                    for (j = 0; j < 5; j++) {
                        cartasPO[j] = 0;
                        cartasPT[j] = 0;
                        contadorCartasRepartidas[j] = 0;
                    }
                    system("CLS");
                    headerPartida(contRondas, playerOne, playerTwo);
                    repartirCartasPO(cartasPO, contadorCartasRepartidas);
                    repartirCartasPT(cartasPT, contadorCartasRepartidas);
                    resultadoCheckeo = checkearOrden(cartasPO, cartasPT);
                }

                // DEFINIMOS QUIEN SERÁ EL PRIMER TIRADOR
                primerTirador = definirPrimerTurno(cartasPO, cartasPT);
                // SI NO HAY UN 1ER TIRADOR DEFINIDO VOLVEMOS A REPARTIR Y CHECKEAR
                while(primerTirador == 3){
                    repartirCartasPO(cartasPO, contadorCartasRepartidas);
                    repartirCartasPT(cartasPT, contadorCartasRepartidas);
                    resultadoCheckeo = checkearOrden(cartasPO, cartasPT);

                    while(resultadoCheckeo == 1){
                        for (k = 0; k < 5; k++) {
                            cartasPO[k] = 0;
                            cartasPT[k] = 0;
                            contadorCartasRepartidas[k] = 0;
                        }
                        system("CLS");
                        headerPartida(contRondas, playerOne, playerTwo);
                        repartirCartasPO(cartasPO, contadorCartasRepartidas);
                        repartirCartasPT(cartasPT, contadorCartasRepartidas);

                        resultadoCheckeo = checkearOrden(cartasPO, cartasPT);
                    }
                    primerTirador = definirPrimerTurno(cartasPO, cartasPT);
                }

                //MOSTRAMOS EL TURNO DEL JUGADOR CORRESP Y DEFINIMOS LOS PALOS/BASTOS DE LAS CARTAS ALEATORIAMENTE
                mostrarTurno(playerOne, playerTwo, primerTirador, contRondas);
                definirCartas(cartasPO, cartasPT, playerOne, playerTwo, palos, bastosCartasPO, bastosCartasPT);

                while(Ganador == 0){

                    dado = tirarDado();

                    ///// DEVS MODE \\\\\

                    //EN CASO DE TESTEO, SELECCIONE EL NÚMERO DEL DADO QUE DESEE (1 - 6)
                    //dado = 6;
                    //cout << endl << "LANZAMIENTO DADO #" << dado << endl;

                    //////////\\\\\\\\\\

                    switch(dado){
                        // EJECUTO ACCIÓN, SUMO RONDA, BORRO LA PANTALLA, MUESTRO EL HEADER, EL TURNO Y LAS CARTAS NUEVAMENTE.
                        case 1:
                            accionUno(cartasPO, cartasPT, contadorCartasRepartidas, primerTirador, contRondas, palos, bastosCartasPO, bastosCartasPT, cartasBloqueadasPO, cartasBloqueadasPT);
                            contRondas++;
                            system ("CLS");
                            headerPartida(contRondas, playerOne, playerTwo);
                            mostrarTurno(playerOne, playerTwo, primerTirador, contRondas);
                            mostrarCartas(cartasPO, cartasPT, bastosCartasPO, bastosCartasPT, playerOne, playerTwo);

                            break;
                        case 2:
                            accionDos(cartasPO, cartasPT, contadorCartasRepartidas, primerTirador, contRondas, palos, bastosCartasPO, bastosCartasPT, cartasBloqueadasPO, cartasBloqueadasPT);
                            contRondas++;
                            system ("CLS");
                            headerPartida(contRondas, playerOne, playerTwo);
                            mostrarTurno(playerOne, playerTwo, primerTirador, contRondas);
                            mostrarCartas(cartasPO, cartasPT, bastosCartasPO, bastosCartasPT, playerOne, playerTwo);
                            break;
                        case 3:
                            accionTres(cartasPO, cartasPT, primerTirador, contRondas, bastosCartasPO, bastosCartasPT, cartasBloqueadasPO, cartasBloqueadasPT);
                            // DEFINO A QUIEN LE ROBARON UNA CARTA Y SI ES LA ÚLTIMA RONDA (CONTEO DE PUNTOS)
                            jugadorRobando = averiguarJugador(primerTirador, contRondas);
                            ultRondaRobo = contRondas;
                            // EL JUGADOR ROBANDO, LE ROBA AL OPUESTO
                            if(jugadorRobando == 1){
                                robadoPT = true;
                            }
                            else{
                                robadoPO = true;
                            }
                            contRondas++;
                            system ("CLS");
                            headerPartida(contRondas, playerOne, playerTwo);
                            mostrarTurno(playerOne, playerTwo, primerTirador, contRondas);
                            mostrarCartas(cartasPO, cartasPT, bastosCartasPO, bastosCartasPT, playerOne, playerTwo);
                            break;
                        case 4:
                            accionCuatro(cartasPO, cartasPT, primerTirador, contRondas, bastosCartasPO, bastosCartasPT, cartasBloqueadasPO, cartasBloqueadasPT);
                            contRondas++;
                            system ("CLS");
                            headerPartida(contRondas, playerOne, playerTwo);
                            mostrarTurno(playerOne, playerTwo, primerTirador, contRondas);
                            mostrarCartas(cartasPO, cartasPT, bastosCartasPO, bastosCartasPT, playerOne, playerTwo);
                            break;
                        case 5:
                            accionCinco(cartasBloqueadasPO, cartasBloqueadasPT, primerTirador, contRondas);
                            contRondas++;
                            system ("CLS");
                            headerPartida(contRondas, playerOne, playerTwo);
                            mostrarTurno(playerOne, playerTwo, primerTirador, contRondas);
                            mostrarCartas(cartasPO, cartasPT, bastosCartasPO, bastosCartasPT, playerOne, playerTwo);
                            break;
                        case 6:
                            // EL USUARIO SELECCIONA LA ACCIÓN QUE DESEE
                            respuestaOp6 = accionSeis();
                            switch(respuestaOp6){
                                case 48: //Acción 0 - Pasar turno
                                    jugador = averiguarJugador(primerTirador, contRondas);
                                    contRondas++;
                                    // VALIDAMOS SI EL JUGADOR PASÓ EL TURNO DURANTE LA PARTIDA
                                    if(jugador == 1){
                                        pasaTurnoPO = true;
                                    }
                                    else{
                                        pasaTurnoPT = true;
                                    }
                                    system ("CLS");
                                    headerPartida(contRondas, playerOne, playerTwo);
                                    mostrarTurno(playerOne, playerTwo, primerTirador, contRondas);
                                    mostrarCartas(cartasPO, cartasPT, bastosCartasPO, bastosCartasPT, playerOne, playerTwo);
                                    break;
                                case 49: //Acción 1
                                    system ("CLS");
                                    headerPartida(contRondas, playerOne, playerTwo);
                                    mostrarTurno(playerOne, playerTwo, primerTirador, contRondas);
                                    mostrarCartas(cartasPO, cartasPT, bastosCartasPO, bastosCartasPT, playerOne, playerTwo);
                                    accionUno(cartasPO, cartasPT, contadorCartasRepartidas, primerTirador, contRondas, palos, bastosCartasPO, bastosCartasPT, cartasBloqueadasPO, cartasBloqueadasPT);
                                    contRondas++;
                                    system ("CLS");
                                    headerPartida(contRondas, playerOne, playerTwo);
                                    mostrarTurno(playerOne, playerTwo, primerTirador, contRondas);
                                    mostrarCartas(cartasPO, cartasPT, bastosCartasPO, bastosCartasPT, playerOne, playerTwo);
                                    break;
                                case 50: //Acción 2
                                    system ("CLS");
                                    headerPartida(contRondas, playerOne, playerTwo);
                                    mostrarTurno(playerOne, playerTwo, primerTirador, contRondas);
                                    mostrarCartas(cartasPO, cartasPT, bastosCartasPO, bastosCartasPT, playerOne, playerTwo);
                                    accionDos(cartasPO, cartasPT, contadorCartasRepartidas, primerTirador, contRondas, palos, bastosCartasPO, bastosCartasPT, cartasBloqueadasPO, cartasBloqueadasPT);
                                    contRondas++;
                                    system ("CLS");
                                    headerPartida(contRondas, playerOne, playerTwo);
                                    mostrarTurno(playerOne, playerTwo, primerTirador, contRondas);
                                    mostrarCartas(cartasPO, cartasPT, bastosCartasPO, bastosCartasPT, playerOne, playerTwo);
                                    break;
                                case 51: //Acción 3
                                    system ("CLS");
                                    headerPartida(contRondas, playerOne, playerTwo);
                                    mostrarTurno(playerOne, playerTwo, primerTirador, contRondas);
                                    mostrarCartas(cartasPO, cartasPT, bastosCartasPO, bastosCartasPT, playerOne, playerTwo);
                                    accionTres(cartasPO, cartasPT, primerTirador, contRondas, bastosCartasPO, bastosCartasPT, cartasBloqueadasPO, cartasBloqueadasPT);
                                    jugadorRobando = averiguarJugador(primerTirador, contRondas);
                                    ultRondaRobo = contRondas;
                                    if(jugadorRobando == 1){
                                        robadoPT = true;
                                    }
                                    else{
                                        robadoPO = true;
                                    }
                                    contRondas++;
                                    system ("CLS");
                                    headerPartida(contRondas, playerOne, playerTwo);
                                    mostrarTurno(playerOne, playerTwo, primerTirador, contRondas);
                                    mostrarCartas(cartasPO, cartasPT, bastosCartasPO, bastosCartasPT, playerOne, playerTwo);
                                    break;
                                case 52: //Acción 4
                                    system ("CLS");
                                    headerPartida(contRondas, playerOne, playerTwo);
                                    mostrarTurno(playerOne, playerTwo, primerTirador, contRondas);
                                    mostrarCartas(cartasPO, cartasPT, bastosCartasPO, bastosCartasPT, playerOne, playerTwo);
                                    accionCuatro(cartasPO, cartasPT, primerTirador, contRondas, bastosCartasPO, bastosCartasPT, cartasBloqueadasPO, cartasBloqueadasPT);
                                    contRondas++;
                                    system ("CLS");
                                    headerPartida(contRondas, playerOne, playerTwo);
                                    mostrarTurno(playerOne, playerTwo, primerTirador, contRondas);
                                    mostrarCartas(cartasPO, cartasPT, bastosCartasPO, bastosCartasPT, playerOne, playerTwo);
                                    break;
                                case 53: //Acción 5
                                    system ("CLS");
                                    headerPartida(contRondas, playerOne, playerTwo);
                                    mostrarTurno(playerOne, playerTwo, primerTirador, contRondas);
                                    mostrarCartas(cartasPO, cartasPT, bastosCartasPO, bastosCartasPT, playerOne, playerTwo);
                                    accionCinco(cartasBloqueadasPO, cartasBloqueadasPT, primerTirador, contRondas);
                                    contRondas++;
                                    system ("CLS");
                                    headerPartida(contRondas, playerOne, playerTwo);
                                    mostrarTurno(playerOne, playerTwo, primerTirador, contRondas);
                                    mostrarCartas(cartasPO, cartasPT, bastosCartasPO, bastosCartasPT, playerOne, playerTwo);
                                    break;
                            }
                            break;
                    }

                    //DEFINIMOS EL GANADOR DE LA PARTIDA
                    Ganador = ganador(cartasPO, cartasPT);

                    ///// DEVS MODE \\\\\

                    // EN CASO DE TESTEO, SELECCIONE EL NÚMERO DEL GANADOR QUE DESEE ( 1 -> PLAYER ONE / 2 -> PLAYER TWO)
                    //Ganador = 3;

                    //////////\\\\\\\\\\

                    if(Ganador == 1 || Ganador == 2){
                        // HACEMOS EL CONTEO DE PUNTOS
                        puntajeTotal = contarPuntos(puntajes, Ganador, playerOne, playerTwo, contRondas, jugadorRobando, ultRondaRobo, cartasPO , cartasPT , pasaTurnoPO, pasaTurnoPT, robadoPO, robadoPT, dado, respuestaOp6);
                        cout << "Presionar 0 para continuar...";
                        opcionSeleccionadaTrasGanar = _getch();
                        // VALIDAMOS QUE SE SELECCIONE "0" PARA AVANZAR
                        while(opcionSeleccionadaTrasGanar != 48){
                            for(x = 0; x < 5; x++){
                                puntajes[x] = 0;
                            }
                            system("CLS");
                            puntajeTotal = contarPuntos(puntajes, Ganador, playerOne, playerTwo, contRondas, jugadorRobando, ultRondaRobo, cartasPO , cartasPT , pasaTurnoPO, pasaTurnoPT, robadoPO, robadoPT, dado, respuestaOp6);
                            cout << "Presionar 0 para continuar...";
                            opcionSeleccionadaTrasGanar = _getch();
                        }

                        // VALIDAMOS SI HAY ALGÚN REGISTRO DE GANADOR Y SOBREESCRIBIMOS EN LAS ESTADISTICAS SEGÚN CORRESPONDA
                        if(mayorPuntuacion == 0){
                            mayorPuntuacion = puntajeTotal;
                            if(Ganador == 1){
                                playerGanador = playerOne;
                            }
                            else{
                                playerGanador = playerTwo;
                            }
                        }
                        else{
                            if(puntajeTotal > mayorPuntuacion){
                                mayorPuntuacion = puntajeTotal;
                                if(Ganador == 1){
                                playerGanador = playerOne;
                                }
                                else{
                                    playerGanador = playerTwo;
                                }
                            }
                        }
                        system ("CLS");
                        menuPrincipal();

                        opcionSeleccionadaMP = _getch();
                    }
                    else if(Ganador == 3){
                        system ("CLS");
                        mostrarEmpate();
                        cout << "Presionar 0 para continuar...";

                        opcionSeleccionadaTrasGanar = _getch();
                        // VALIDAMOS QUE SE SELECCIONE "0" PARA AVANZAR
                        while(opcionSeleccionadaTrasGanar != 48){
                            system("CLS");
                            mostrarEmpate();
                            cout << "Presionar 0 para continuar...";
                            opcionSeleccionadaTrasGanar = _getch();
                        }
                        system ("CLS");
                        menuPrincipal();

                        opcionSeleccionadaMP = _getch();
                    }

                }

                //RESETEO TODAS LAS KEYS UTILIZADAS DURANTE LA PARTIDA PARA PODER VOLVER A JUGAR

                //STRINGS
                playerOne = "";
                playerTwo = "";

                //INTS
                Ganador = 0;
                contRondas = 1;
                opcionSeleccionadaOp3 = 0;
                opcionSeleccionadaOp0 = 0;

                for (i = 0; i < 5; i++) {
                    cartasPO[i] = 0;
                    cartasPT[i] = 0;
                    contadorCartasRepartidas[i] = 0;
                    puntajes[i] = 0;
                }

                primerTirador = 0;
                dado = 0;
                respuestaOp6 = 0;
                jugador = 0;
                jugadorRobando = 0;
                ultRondaRobo = 0;
                opcionSeleccionadaTrasGanar = 0;
                x = 0;

                //BOOLS
                pasaTurnoPO = false;
                pasaTurnoPT = false;
                robadoPO = false;
                robadoPT = false;

                //VECS Y MATRICES
                for (int i = 0; i < 5; i++) {
                bastosCartasPO[i] = "";
                bastosCartasPT[i] = "";
                }

                for(int f = 0; f < 4; f++){
                    for(int c = 0; c < 5; c++){
                        if(f == 0){
                            palos[f][c] = "Treboles";
                        }
                        else if(f == 1){
                            palos[f][c] = "Diamantes";
                        }
                        else if(f == 2){
                            palos[f][c] = "Corazones";
                        }
                        else{
                            palos[f][c] = "Picas";
                        }
                    }
                }
                break;
            case 50: //ESTADÍSTICAS
                system ("CLS");
                opcionSeleccionadaOp2 = estadisticas(mayorPuntuacion, playerGanador);

                // VALIDAMOS QUE SE SELECCIONE ESC PARA VOLVER ATRAS
                while(opcionSeleccionadaOp2 != 27){
                    system ("CLS");
                    opcionSeleccionadaOp2 = estadisticas(mayorPuntuacion, playerGanador);
                }

                system ("CLS");
                menuPrincipal();

                opcionSeleccionadaMP = _getch();

                break;
            case 51: //CRÉDITOS
                system ("CLS");
                opcionSeleccionadaOp3 = creditos();

                // VALIDAMOS QUE SE SELECCIONE ESC PARA VOLVER ATRAS
                while(opcionSeleccionadaOp3 != 27){
                    system ("CLS");
                    opcionSeleccionadaOp3 = creditos();
                }

                system ("CLS");
                menuPrincipal();

                opcionSeleccionadaMP = _getch();

                break;
            case 48: //SALIR
                opcionSeleccionadaOp0 = salir();
                if(opcionSeleccionadaOp0 != 110 && opcionSeleccionadaOp0 != 78){
                    if(opcionSeleccionadaOp0 != 115 && opcionSeleccionadaOp0 != 83){
                        cout << endl;
                        opcionIncorrecta();
                        Sleep(500);
                        opcionSeleccionadaOp0 = salir();
                    }
                    else{
                        return 0;
                    }
                }
                else{
                    system ("CLS");
                    menuPrincipal();
                    opcionSeleccionadaMP = _getch();
                }
                break;
            default:
                opcionIncorrecta();

                Sleep(500);
                system ("CLS");

                menuPrincipal();

                opcionSeleccionadaMP = _getch();
                break;
        }
    }
    return 0;
}

