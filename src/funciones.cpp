#include <iostream>
#include <string> // getline -> PERMITE INGRESAR STRINGS CON ESPACIOS
#include <ctime> // time() -> GENERACIÓN DE NUMS ALEATORIOS
#include <cstdlib> // srand(), rand() -> GENERACIÓN DE NUMS ALEATORIOS
#include <algorithm> // copy() -> IGUALA ARRAY A OTRO

#include <conio.h> // _getch() -> INPUT SIN MOSTRAR TEXTO
#include <stdlib.h> // system() -> EJECUTA COMANDOS
#include <windows.h> // Sleep() -> PAUSA LA EJECUCIÓN DURANTE EL LAPSO DEFINIDO

#include "funciones.h"


using namespace std;


//////////////////- - - - - - - - MENÚ PRINCIPAL - - - - - - - -\\\\\\\\\\\\\\\\\\

//ARMA EL MENU PRINCIPAL
void menuPrincipal(){
    cout << "CLUTCH" << endl;
    cout << "---------------------" << endl;
    cout << "1 - JUGAR" << endl;
    cout << "2 - ESTADÍSTICAS" << endl;
    cout << "3 - CRÉDITOS" << endl;
    cout << "---------------------" << endl;
    cout << "0 - SALIR" << endl;
}



//////////////////- - - - - - - - OPCIÓN 1 (JUGAR) - - - - - - - -\\\\\\\\\\\\\\\\\\

//VALIDA DATO INGRESADO
void opcionIncorrecta(){
    cout << endl << "ERROR: OPCIÓN INCORRECTA" << endl;
}


void cartaFueraDeRango(){
    cout << endl << "ERROR: CARTA FUERA DE RANGO" << endl;
}



//DEFINIR NOMBRES DE LOS JUGADORES
string ingresarPlayerOne(string playerOne){
    system ("CLS");
    cout << "CLUTCH" << endl;
    cout << "------------------------------------------------------------------------" << endl;
    cout << "Antes de comenzar deben registrar sus nombres:" << endl << endl;

    cout << "¿Jugador 1? ";
    getline(cin, playerOne);

    while(playerOne == ""){
        system ("CLS");
        cout << "CLUTCH" << endl;
        cout << "------------------------------------------------------------------------" << endl;
        cout << "Antes de comenzar deben registrar sus nombres:" << endl << endl;

        cout << "¿Jugador 1? ";
        getline(cin, playerOne);

    }

    return playerOne;
}


string ingresarPlayerTwo(string playerTwo, string playerOne){
    cout << endl;
    cout << "¿Jugador 2? ";
    getline(cin, playerTwo);
    cout << endl;

    while(playerTwo == ""){
        system ("CLS");
        cout << "CLUTCH" << endl;
        cout << "------------------------------------------------------------------------" << endl;
        cout << "Antes de comenzar deben registrar sus nombres:" << endl << endl;

        cout << "¿Jugador 1? " << playerOne << endl;
        cout << endl;
        cout << "¿Jugador 2? ";
        getline(cin, playerTwo);
        cout << endl;
    }

    return playerTwo;
}


char confirmarJuego(string playerTwo, string playerOne){
    char confirmar;

    cout << endl;
    cout << "¿Confirmar nombres? (S/N)";
    confirmar = _getch();
    cout << endl;
    cout << "------------------------------------------------------------------------" << endl;

    while((confirmar != 'N' && confirmar != 'n') && (confirmar != 'S' && confirmar != 's')){

        system ("CLS");
        cout << "CLUTCH" << endl;
        cout << "------------------------------------------------------------------------" << endl;
        cout << "Antes de comenzar deben registrar sus nombres:" << endl << endl;
        cout << "¿Nombre? " << playerOne << endl;
        cout << endl;
        cout << "¿Nombre? " << playerTwo << endl;
        cout << endl << endl;
        cout << "¿Confirmar nombres? (S/N)";
        confirmar = _getch();
        cout << endl;
    }
    return confirmar;
}



//ARMAR ESTRUCTURA DEL JUEGO
void headerPartida(int contador, string playerOne, string playerTwo){
    system ("CLS");
    cout << "CLUTCH" << endl;
    cout << "------------------------------------------------------------------------" << endl;
    cout << "RONDA #" << contador << endl;
    cout << playerOne  << " vs " << playerTwo << endl << endl;

}


void mostrarTurno(string playerOne, string playerTwo, int primerTirador, int contRondas){

    if(primerTirador == 1){
        if(contRondas % 2 !=0){
            cout << "TURNO DE " << playerOne << endl;
        }
        else{
            cout << "TURNO DE " << playerTwo << endl;
        }
    }
    else{
        if(contRondas % 2 !=0){
            cout << "TURNO DE " << playerTwo << endl;
        }
        else{
            cout << "TURNO DE " << playerOne << endl;
        }
    }
}


void mostrarCartas(int cartasPO[], int cartasPT[], string bastosCartasPO[],
                    string bastosCartasPT[], string playerOne, string playerTwo){
    int x, i;

    cout << "+-------------------------+" << endl;
    cout << "|                         |" << endl;
    cout << "  " << playerOne << endl;

    for(x = 0; x < 5; x++){
        switch(cartasPO[x]){
            case 1:
                cout << "\t " << "10" << " " << bastosCartasPO[x] << endl;
                break;
            case 2:
                cout << "\t " << "J" << " " << bastosCartasPO[x] << endl;
                break;
            case 3:
                cout << "\t " << "Q" << " " << bastosCartasPO[x] << endl;
                break;
            case 4:
                cout << "\t " << "K" << " " << bastosCartasPO[x] << endl;
                break;
            case 5:
                cout << "\t " << "A" << " " << bastosCartasPO[x] << endl;
                break;
        }
    }
    cout << "|                         |" << endl;
    cout << "+-------------------------+" << endl;
    cout << "|                         |" << endl;
    cout << "  " << playerTwo << endl;
    for(i = 0; i < 5; i++){
        switch(cartasPT[i]){
            case 1:
                cout << "\t " << "10" << " " << bastosCartasPT[i] << endl;
                break;
            case 2:
                cout << "\t " << "J" << " " << bastosCartasPT[i] << endl;
                break;
            case 3:
                cout << "\t " << "Q" << " " << bastosCartasPT[i] << endl;
                break;
            case 4:
                cout << "\t " << "K" << " " << bastosCartasPT[i] << endl;
                break;
            case 5:
                cout << "\t " << "A" << " " << bastosCartasPT[i] << endl;
                break;
        }
    }
    cout << "|                         |" << endl;
    cout << "+-------------------------+" << endl;
}



//DEFINIR CARTAS, BASTOS Y PRIMER TURNO
void repartirCartasPO(int cartasPO[], int contadorCartasRepartidas[]){
    int nro_carta, i;

    srand(time(0));

    for(i=0; i<5; i++){
        nro_carta = (rand() % 5) + 1;

        cartasPO[i] = nro_carta;
        contadorCartasRepartidas[nro_carta - 1] += 1;
    }
}


void repartirCartasPT(int cartasPT[], int contadorCartasRepartidas[]){
    int nro_carta, i;

    srand(time(0) + 1);
    for(i=0; i<5; i++){
        nro_carta = (rand() % 5) + 1;

        while(contadorCartasRepartidas[nro_carta - 1] == 4){
            nro_carta = (rand() % 5) + 1;
        }
        cartasPT[i] = nro_carta;
        contadorCartasRepartidas[nro_carta - 1] += 1;
    }
}


int checkearOrden(int cartasPO[5], int cartasPT[5]){
    int x, i, contCartasOrdenadas = 0;

    for(x = 0; x < 5 ;x++){
        if(cartasPO[x] == x + 1){
            contCartasOrdenadas++;
        }
    }
    if(contCartasOrdenadas == 5){
        return 1;
    }
    else{
        contCartasOrdenadas = 0;
        for(i = 0; i < 5 ;i++){
            if(cartasPT[i] == i + 1){
                contCartasOrdenadas++;
            }
        }
        if(contCartasOrdenadas == 5){
            return 1;
        }
        else{
            return 0;
        }
    }
}


void definirCartas(int cartasPO[], int cartasPT[], string playerOne, string playerTwo, string palos[4][5],
                    string bastosCartasPO[], string bastosCartasPT[]){

    /*
    EXPLICACIÓN:  Tomo el vector de cartas del jugador N°X, y por cada carta utilizo el índice de la misma
    para acceder a una matriz de strings donde estan incializados los bastos/palos
    disponibles para repartir. Una vez seleccionado, se marca en dicho puesto [n}[n] con una "X" para indicar que ya fue utilzado.
    Además, el basto elegido es ingresado automáticamente
    en un vector de string, en el mismo índice de la carta seleccionada al principio.
     */

    int x, i, j;
    int basto;
    int cont = 0;
    srand(time(0));

    cout << "+-------------------------+" << endl;
    cout << "|                         |" << endl;
    cout << "  " << playerOne << endl;
    for(x = 0; x < 5; x++){
        switch(cartasPO[x]){
            case 1:
                for(j=0; j<1; j++){
                    // NUMERO DEL 0 AL 3 (FUTURA REFERENCIA A LA FILAS DE LA MATRIZ DE BASTOS/PALOS)
                    basto = (rand() % 4);
                }

                while(palos[basto][0] == "X"){
                    for(j=0; j<1; j++){
                        basto = (rand() % 4);
                    }
                }

                cout << "\t 10 " << palos[basto][0] << endl;
                bastosCartasPO[x] = palos[basto][0];
                palos[basto][0] = "X";

                break;
            case 2:
                for(j=0; j<1; j++){
                    basto = (rand() % 4);
                }

                while(palos[basto][1] == "X"){
                    for(j=0; j<1; j++){
                        basto = (rand() % 4);
                    }
                }

                cout << "\t J " << palos[basto][1] << endl;
                bastosCartasPO[x] = palos[basto][1];
                palos[basto][1] = "X";

                break;
            case 3:
                for(j=0; j<1; j++){
                    basto = (rand() % 4);
                }

                while(palos[basto][2] == "X"){
                    for(j=0; j<1; j++){
                        basto = (rand() % 4);
                    }
                }

                cout << "\t Q " << palos[basto][2] << endl;
                bastosCartasPO[x] = palos[basto][2];
                palos[basto][2] = "X";

                break;
            case 4:
                for(j=0; j<1; j++){
                    basto = (rand() % 4);
                }

                while(palos[basto][3] == "X"){
                    for(j=0; j<1; j++){
                        basto = (rand() % 4);
                    }
                }

                cout << "\t K " << palos[basto][3] << endl;
                bastosCartasPO[x] = palos[basto][3];
                palos[basto][3] = "X";

                break;
            case 5:
                for(j=0; j<1; j++){
                    basto = (rand() % 4);
                }

                while(palos[basto][4] == "X"){
                    for(j=0; j<1; j++){
                        basto = (rand() % 4);
                    }
                }

                cout << "\t A " << palos[basto][4] << endl;
                bastosCartasPO[x] = palos[basto][4];
                palos[basto][4] = "X";
                break;
        }
    }
    cout << "|                         |" << endl;
    cout << "+-------------------------+" << endl;
    cout << "|                         |" << endl;
    cout << "  " << playerTwo << endl;
    for(i = 0; i < 5; i++){
        int cont = 0;
        switch(cartasPT[i]){
            case 1:
                for(j=0; j<1; j++){
                    basto = (rand() % 4);
                }

                while(palos[basto][0] == "X"){
                    for(j=0; j<1; j++){
                        basto = (rand() % 4) ;
                    }
                }

                cout << "\t 10 " << palos[basto][0] << endl;
                bastosCartasPT[i] = palos[basto][0];
                palos[basto][0] = "X";

                break;
            case 2:
                for(j=0; j<1; j++){
                    basto = (rand() % 4);
                }

                while(palos[basto][1] == "X"){
                    for(j=0; j<1; j++){
                        basto = (rand() % 4);
                    }
                }

                cout << "\t J " << palos[basto][1] << endl;
                bastosCartasPT[i] = palos[basto][1];
                palos[basto][1] = "X";

                break;
            case 3:
                for(j=0; j<1; j++){
                    basto = (rand() % 4);
                }

                while(palos[basto][2] == "X"){
                    for(j=0; j<1; j++){
                        basto = (rand() % 4) ;
                    }
                }

                cout << "\t Q " << palos[basto][2] << endl;
                bastosCartasPT[i] = palos[basto][2];
                palos[basto][2] = "X";

                break;
            case 4:
                for(j=0; j<1; j++){
                    basto = (rand() % 4);
                }

                while(palos[basto][3] == "X"){
                    for(j=0; j<1; j++){
                        basto = (rand() % 4) ;
                    }
                }

                cout << "\t K " << palos[basto][3] << endl;
                bastosCartasPT[i] = palos[basto][3];
                palos[basto][3] = "X";

                break;
            case 5:
                for(j=0; j<1; j++){
                    basto = (rand() % 4);
                }


                while(palos[basto][4] == "X"){
                    for(j=0; j<1; j++){
                        basto = (rand() % 4) ;
                    }
                }

                cout << "\t A " << palos[basto][4] << endl;
                bastosCartasPT[i] = palos[basto][4];
                palos[basto][4] = "X";
                break;
        }
    }
    cout << "|                         |" << endl;
    cout << "+-------------------------+" << endl;
}


int definirPrimerTurno(int cartasPO[], int cartasPT[]){
    int i;
    int cont10PO = 0, contJPO = 0, contQPO = 0, contKPO = 0, contAPO = 0;
    int cont10PT = 0, contJPT = 0, contQPT = 0, contKPT = 0, contAPT = 0;

    for(i=0; i<5; i++){
        switch(cartasPO[i] - 1){
            case 0:
                cont10PO++;
                break;
            case 1:
                contJPO++;
                break;
            case 2:
                contQPO++;
                break;
            case 3:
                contKPO++;
                break;
            case 4:
                contAPO++;
                break;
        }

        switch(cartasPT[i] - 1){
            case 0:
                cont10PT++;
                break;
            case 1:
                contJPT++;
                break;
            case 2:
                contQPT++;
                break;
            case 3:
                contKPT++;
                break;
            case 4:
                contAPT++;
                break;
        }

    }

    if(contAPO > contAPT){ // COMPARAMOS As
        return 1;
    }
    else if(contAPO == contAPT){
        if(contKPO > contKPT){ // COMPARAMOS Ks
            return 1;
        }
        else if(contKPO == contKPT){
            if(contQPO > contQPT){ // COMPARAMOS Qs
                return 1;
            }
            else if(contQPO == contQPT){
                if(contJPO > contJPT){ // COMPARAMOS Js
                    return 1;
                }
                else if(contJPO == contJPT){
                    if(cont10PO > cont10PT){ // COMPARAMOS 10s
                        return 1;
                    }
                    else if(cont10PO == cont10PT){ // NO HAY UN 1RT TIRADOR DEFINIDO
                        return 3;
                    }
                    else{
                        return 2;
                    }
                }
                else{
                    return 2;
                }
            }
            else{
                return 2;
            }
        }
        else{
            return 2;
        }
    }
    else{
        return 2;
    }
}



/////////- - - - DADO - - - -\\\\\\\\\

//TIRAR EL DADO
int tirarDado(){
    int  numDado;

    srand(time(0));
    numDado = (rand() % 6) + 1;

    cout << endl << "LANZAMIENTO DADO #" << numDado << endl;
    return numDado;
}


//ACCIÓN UNO
void accionUno(int cartasPO[5], int cartasPT[5], int contadorCartasRepartidas[], int primerTirador, int contRondas, string palos[4][5], string bastosCartasPO[], string bastosCartasPT[], int cartasBloqueadasPO[5], int cartasBloqueadasPT[5]){

    int x, i, j, cont = 1, numCartaCorral, cartaADevolver, numCartaMazoRobada, bastoCartaMazoRobada, playerCorrespondiente, cartasPlayerCorrespondiente[5];
    string bastosPlayerCorrespondiente[5], bastoADevolver;
    cout << "Elegir una carta de su propio corral (1-5) y robar una carta del mazo." << endl << endl;
    cout << "¿Qué cartas deseas intercambiar?" << endl;
    cout << "Carta de su corral: ";
    cin >> numCartaCorral;

    while(numCartaCorral > 5 || numCartaCorral <= 0){
        cout << endl;
        cartaFueraDeRango();
        cout << "Carta de su corral: ";
        cin >> numCartaCorral;
    }

    ///// DEFINO CUAL SERA EL JUGADOR CUYAS CARTAS SERÁN MODIFICADAS  \\\\\

    // Según quien haya sido el primer tirador, todas las rondas impares le corresponderan a él y las impares al opuesto.

    if(primerTirador == 1){
        if(contRondas % 2 !=0){
            playerCorrespondiente = 1;
            std::copy(cartasPO, cartasPO + 5, cartasPlayerCorrespondiente); // (ARRAY A COPIAR, CANTIDAD ELEMENTOS A COPIAR DEL ARRAY, ARRAY QUE RECIBE LOS ELEMENTOS)
            std::copy(bastosCartasPO, bastosCartasPO + 5, bastosPlayerCorrespondiente);

            cartasBloqueadasPO[numCartaCorral - 1] = 0; // SETTEO EN 0 EL INDICE DE LA CARTA QUE ESTOY CAMBIANDO, POR SI ES QUE ESTABA BLOQUEADA
        }
        else{
            playerCorrespondiente = 2;
            std::copy(cartasPT, cartasPT + 5, cartasPlayerCorrespondiente);
            std::copy(bastosCartasPT, bastosCartasPT + 5, bastosPlayerCorrespondiente);

            cartasBloqueadasPT[numCartaCorral - 1] = 0;
        }
    }
    else{
        if(contRondas % 2 !=0){
            playerCorrespondiente = 2;
            std::copy(cartasPT, cartasPT + 5, cartasPlayerCorrespondiente);
            std::copy(bastosCartasPT, bastosCartasPT + 5, bastosPlayerCorrespondiente);

            cartasBloqueadasPT[numCartaCorral - 1] = 0;
        }
        else{
            playerCorrespondiente = 1;
            std::copy(cartasPO, cartasPO + 5, cartasPlayerCorrespondiente);
            std::copy(bastosCartasPO, bastosCartasPO + 5, bastosPlayerCorrespondiente);

            cartasBloqueadasPO[numCartaCorral - 1] = 0;
        }
    }
    cartaADevolver = cartasPlayerCorrespondiente[numCartaCorral - 1];
    bastoADevolver = bastosPlayerCorrespondiente[numCartaCorral - 1];

    /////  ROBO UNA NUEVA CARTA DEL MAZO ALEATORIAMENTE  \\\\\

    srand(time(0));

    numCartaMazoRobada = (rand() % 5 + 1);

    // VALIDO QUE DICHA CARTA NO SE ENCUENTRE UTILIZADA EN LOS 4 BASTOS/PALOS DISPONIBLES
    while(contadorCartasRepartidas[numCartaMazoRobada - 1] == 4){
        numCartaMazoRobada = (rand() % 5 + 1);
    }

    // ASIGNO LA NUEVA CARTA A LA POSICIÓN QUE SELECCIONÉ PARA REALIZAR EL CAMBIO
    cartasPlayerCorrespondiente[numCartaCorral - 1] = numCartaMazoRobada;

    // SUMO LA CARTA AL CONTADOR DE CARTAS UTILIZADAS
    contadorCartasRepartidas[numCartaMazoRobada - 1] += 1;

    // DEFINO EL BASTO/PALO QUE VA A RECIBIR DICHA NUEVA CARTA
    bastoCartaMazoRobada = (rand() % 4);
    while(palos[bastoCartaMazoRobada][numCartaMazoRobada - 1] == "X"){
        bastoCartaMazoRobada = (rand() % 4);
    }

    // SEGÚN EL RESULTADO ALEATORIO DE LA VARIABLE VALIDADA, SERÁ EL BASTO/PALO QUE RECIBIRÁ NUESTRA CARTA
    switch(bastoCartaMazoRobada){
        case 0:
            bastosPlayerCorrespondiente[numCartaCorral - 1] = "Treboles";
            break;
        case 1:
            bastosPlayerCorrespondiente[numCartaCorral - 1] = "Diamantes";
            break;
        case 2:
            bastosPlayerCorrespondiente[numCartaCorral - 1] = "Corazones";
            break;
        case 3:
            bastosPlayerCorrespondiente[numCartaCorral - 1] = "Picas";
            break;
    }

    // LA DEFINO COMO "NO DISPONIBLE" PARA SELECCIONAR
    palos[bastoCartaMazoRobada][numCartaMazoRobada -1] = "X";

    ///// DEVUELVO MI CARTA AL MAZO  \\\\\

    // DESCUENTO MI CARTA ANTERIOR DEL CONTADOR DE CARTAS UTILIZADAS
    contadorCartasRepartidas[cartaADevolver - 1] -= 1;

    // VUELVO A INGRESAR EL PALO/BASTO QUE UTILIZABA MI CARTA ANTERIOR
    if(bastoADevolver == "Treboles"){
        palos[0][cartaADevolver - 1] = "Treboles";
    }
    else if(bastoADevolver == "Diamantes"){
        palos[1][cartaADevolver - 1] = "Diamantes";
    }
    else if(bastoADevolver == "Corazones"){
        palos[2][cartaADevolver - 1] = "Corazones";
    }
    else{
        palos[3][cartaADevolver - 1] = "Picas";
    }

    //COPIO LAS MOFICIACIONES DEL VECTOR UTILIZADO AL VECTOR DEL JUGADOR CORRESPONDIENTE.
    if(playerCorrespondiente == 1){
        std::copy(cartasPlayerCorrespondiente, cartasPlayerCorrespondiente + 5, cartasPO);
        std::copy(bastosPlayerCorrespondiente, bastosPlayerCorrespondiente + 5, bastosCartasPO);
    }
    else{
        std::copy(cartasPlayerCorrespondiente, cartasPlayerCorrespondiente + 5, cartasPT);
        std::copy(bastosPlayerCorrespondiente, bastosPlayerCorrespondiente + 5, bastosCartasPT);
    }

}



//ACCIÓN DOS
void accionDos(int cartasPO[5], int cartasPT[5], int contadorCartasRepartidas[], int primerTirador, int contRondas, string palos[4][5], string bastosCartasPO[], string bastosCartasPT[], int cartasBloqueadasPO[5], int cartasBloqueadasPT[5]){
    int x, cont = 1, numCartaCorral, cartaADevolver, numCartaMazoRobada, bastoCartaMazoRobada, playerCorrespondiente, cartasPlayerCorrespondiente[5], contCartasDisponibles = 0;
    string bastosPlayerCorrespondiente[5], bastoADevolver;
    bool hayCartasDisponibles = true;
    cout << "Elegir una carta del corral del contrario (1-5) y robar una carta del mazo." << endl << endl;
    cout << "¿Qué carta deseas intercambiar?" << endl;


    ///// DEFINO CUAL SERA EL JUGADOR CUYAS CARTAS SERÁN MODIFICADAS  \\\\\

    // playerCorrespondiente = Jugador cuyas cartas serán modificadas, el opuesto es el jugador que está realizando la acción.

    if(primerTirador == 1){
        if(contRondas % 2 !=0){
            playerCorrespondiente = 2;

            std::copy(cartasPT, cartasPT + 5, cartasPlayerCorrespondiente); // (ARRAY A COPIAR, CANTIDAD ELEMENTOS A COPIAR DEL ARRAY, ARRAY QUE RECIBE LOS ELEMENTOS)
            std::copy(bastosCartasPT, bastosCartasPT + 5, bastosPlayerCorrespondiente);

            for(x = 0; x < 5; x++){
                if(cartasBloqueadasPT[x] == 0){
                    contCartasDisponibles++;
                }
            }

            if(contCartasDisponibles > 0){
                cout << "Carta del corral contrario: ";
                cin >> numCartaCorral;

                while(numCartaCorral > 5 || numCartaCorral <= 0){
                    cout << endl;
                    cartaFueraDeRango();
                    cout << "Carta del corral contrario: ";
                    cin >> numCartaCorral;
                }

                // VERIFICO QUE LA CARTA ELEGIDA NO HAYA SIDO BLOQUEADA POR EL CONTRARIO SI ESTÉ FUERA DE RANGO
                while(cartasBloqueadasPT[numCartaCorral - 1] == 1){
                    cout << endl << endl <<"ERROR: LA CARTA SE ENCUENTRA BLOQUEADA " << endl;
                    cout << "Carta del corra contrario: ";
                    cin >> numCartaCorral;

                    while(numCartaCorral > 5 || numCartaCorral <= 0){
                        cout << endl;
                        cartaFueraDeRango();
                        cout << "Carta del corral contrario: ";
                        cin >> numCartaCorral;
                    }
                }
            }
            else{
                hayCartasDisponibles = false;
                cout << endl <<"Carta del corral contrario: NO HAY CARTAS DISPONIBLES, TODAS BLOQUEADAS";
                Sleep(3000);
            }
        }
        else{
            playerCorrespondiente = 1;

            std::copy(cartasPO, cartasPO + 5, cartasPlayerCorrespondiente);
            std::copy(bastosCartasPO, bastosCartasPO + 5, bastosPlayerCorrespondiente);

            for(x = 0; x < 5; x++){
                if(cartasBloqueadasPO[x] == 0){
                    contCartasDisponibles++;
                }
            }

            if(contCartasDisponibles > 0){
                cout << "Carta del corral contrario: ";
                cin >> numCartaCorral;

                while(numCartaCorral > 5 || numCartaCorral <= 0){
                    cout << endl;
                    cartaFueraDeRango();
                    cout << "Carta del corral contrario: ";
                    cin >> numCartaCorral;
                }



                while(cartasBloqueadasPO[numCartaCorral - 1] == 1){
                    cout << endl << endl <<"ERROR: LA CARTA SE ENCUENTRA BLOQUEADA " << endl;
                    cout << "Carta del corral contrario: ";
                    cin >> numCartaCorral;

                    while(numCartaCorral > 5 || numCartaCorral <= 0){
                        cout << endl;
                        cartaFueraDeRango();
                        cout << "Carta del corral contrario: ";
                        cin >> numCartaCorral;
                    }
                }
            }
            else{
                hayCartasDisponibles = false;
                cout << endl <<"Carta del corral contrario: NO HAY CARTAS DISPONIBLES, TODAS BLOQUEADAS";
                Sleep(3000);
            }
        }
    }
    else{
        if(contRondas % 2 !=0){
            playerCorrespondiente = 1;

            std::copy(cartasPO, cartasPO + 5, cartasPlayerCorrespondiente);
            std::copy(bastosCartasPO, bastosCartasPO + 5, bastosPlayerCorrespondiente);

            for(x = 0; x < 5; x++){
                if(cartasBloqueadasPO[x] == 0){
                    contCartasDisponibles++;
                }
            }

            if(contCartasDisponibles > 0){

                cout << "Carta del corral contrario: ";
                cin >> numCartaCorral;

                while(numCartaCorral > 5 || numCartaCorral <= 0){
                    cout << endl;
                    cartaFueraDeRango();
                    cout << "Carta del corral contrario: ";
                    cin >> numCartaCorral;
                }

                while(cartasBloqueadasPO[numCartaCorral - 1] == 1){
                    cout << endl << endl <<"ERROR: LA CARTA SE ENCUENTRA BLOQUEADA " << endl;
                    cout << "Carta del corral contrario: ";
                    cin >> numCartaCorral;

                    while(numCartaCorral > 5 || numCartaCorral <= 0){
                        cout << endl;
                        cartaFueraDeRango();
                        cout << "Carta del corral contrario: ";
                        cin >> numCartaCorral;
                    }
                }
            }
            else{
                hayCartasDisponibles = false;
                cout << endl <<"Carta del corral contrario: NO HAY CARTAS DISPONIBLES, TODAS BLOQUEADAS";
                Sleep(3000);
            }
        }
        else{
            playerCorrespondiente = 2;

            std::copy(cartasPT, cartasPT + 5, cartasPlayerCorrespondiente);
            std::copy(bastosCartasPT, bastosCartasPT + 5, bastosPlayerCorrespondiente);

            for(x = 0; x < 5; x++){
                if(cartasBloqueadasPT[x] == 0){
                    contCartasDisponibles++;
                }
            }

            if(contCartasDisponibles > 0){

                cout << "Carta del corral contrario: ";
                cin >> numCartaCorral;

                while(numCartaCorral > 5 || numCartaCorral <= 0){
                    cout << endl;
                    cartaFueraDeRango();
                    cout << "Carta del corral del contrario: ";
                    cin >> numCartaCorral;
                }

                while(cartasBloqueadasPT[numCartaCorral - 1] == 1){
                    cout << endl << endl <<"ERROR: LA CARTA SE ENCUENTRA BLOQUEADA " << endl;
                    cout << "Carta del corral contrario: ";
                    cin >> numCartaCorral;

                    while(numCartaCorral > 5 || numCartaCorral <= 0){
                        cout << endl;
                        cartaFueraDeRango();
                        cout << "Carta del corral contrario: ";
                        cin >> numCartaCorral;
                    }
                }
            }
            else{
                hayCartasDisponibles = false;
                cout << endl <<"Carta del corral contrario: NO HAY CARTAS DISPONIBLES, TODAS BLOQUEADAS";
                Sleep(3000);
            }
        }
    }

    if(hayCartasDisponibles == true){

        cartaADevolver = cartasPlayerCorrespondiente[numCartaCorral - 1];
        bastoADevolver = bastosPlayerCorrespondiente[numCartaCorral - 1];

        /////  ROBO UNA NUEVA CARTA DEL MAZO ALEATORIAMENTE  \\\\\

        srand(time(0));

        numCartaMazoRobada = (rand() % 5 + 1);

        // VALIDO QUE DICHA CARTA NO SE ENCUENTRE UTILIZADA EN LOS 4 BASTOS/PALOS DISPONIBLES
        while(contadorCartasRepartidas[numCartaMazoRobada - 1] == 4){
            numCartaMazoRobada = (rand() % 5 + 1);
        }

        // ASIGNO LA NUEVA CARTA A LA POSICIÓN QUE SELECCIONÉ PARA REALIZAR EL CAMBIO
        cartasPlayerCorrespondiente[numCartaCorral - 1] = numCartaMazoRobada;

        // DEFINO EL BASTO/PALO QUE VA A RECIBIR DICHA NUEVA CARTA
        bastoCartaMazoRobada = (rand() % 4);
        while (palos[bastoCartaMazoRobada][numCartaMazoRobada - 1] == "X"){
            bastoCartaMazoRobada = (rand() % 4);
        }

        // SUMO LA CARTA AL CONTADOR DE CARTAS UTILIZADAS
        contadorCartasRepartidas[numCartaMazoRobada - 1] += 1;

        // SEGÚN EL RESULTADO ALEATORIO DE LA VARIABLE VALIDADA, SERÁ EL BASTO/PALO QUE RECIBIRÁ NUESTRA CARTA
        switch(bastoCartaMazoRobada){
            case 0:
                bastosPlayerCorrespondiente[numCartaCorral - 1] = "Treboles";
                break;
            case 1:
                bastosPlayerCorrespondiente[numCartaCorral - 1] = "Diamantes";
                break;
            case 2:
                bastosPlayerCorrespondiente[numCartaCorral - 1] = "Corazones";
                break;
            case 3:
                bastosPlayerCorrespondiente[numCartaCorral - 1] = "Picas";
                break;
        }

        // LA DEFINO COMO "NO DISPONIBLE" PARA SELECCIONAR
        palos[bastoCartaMazoRobada][numCartaMazoRobada -1] = "X";

        ///// DEVUELVO MI CARTA AL MAZO  \\\\\

        // DESCUENTO LA CARTA ANTERIOR DEL CONTADOR DE CARTAS UTILIZADAS
        contadorCartasRepartidas[cartaADevolver - 1] -= 1;

        // VUELVO A INGRESAR EL PALO/BASTO QUE UTILIZABA LA CARTA ANTERIOR
        if(bastoADevolver == "Treboles"){
            palos[0][cartaADevolver - 1] = "Treboles";
        }
        else if(bastoADevolver == "Diamantes"){
            palos[1][cartaADevolver - 1] = "Diamantes";
        }
        else if(bastoADevolver == "Corazones"){
            palos[2][cartaADevolver - 1] = "Corazones";
        }
        else{
            palos[3][cartaADevolver - 1] = "Picas";
        }
    }

    // COPIO LAS MODIFICACIONES DEL VECTOR UTILIZADO AL VECTOR DEL JUGADOR CORRESPONDIENTE
    if(playerCorrespondiente == 1){
        std::copy(cartasPlayerCorrespondiente, cartasPlayerCorrespondiente + 5, cartasPO);
        std::copy(bastosPlayerCorrespondiente, bastosPlayerCorrespondiente + 5, bastosCartasPO);
    }
    else{
        std::copy(cartasPlayerCorrespondiente, cartasPlayerCorrespondiente + 5, cartasPT);
        std::copy(bastosPlayerCorrespondiente, bastosPlayerCorrespondiente + 5, bastosCartasPT);
    }

}



//ACCIÓN TRES
void accionTres(int cartasPO[5], int cartasPT[5], int primerTirador, int contRondas, string bastosCartasPO[], string bastosCartasPT[], int cartasBloqueadasPO[5], int cartasBloqueadasPT[5]){

    int x, numCartaCorral, numCartaCorralContrario, cartaPropiaSeleccionadaPlayer, contCartasDisponibles = 0;
    string BastoCartaPropiaSeleccionadaPlayer;

    cout << "Elegir una carta del corral propio (1-5) e intercambiarla por una carta del corral del contrario (1-5)" << endl << endl;
    cout << "¿Qué cartas deseas intercambiar?" << endl;
    cout << "Carta de su corral: ";
    cin >> numCartaCorral;

    while(numCartaCorral > 5 || numCartaCorral <= 0){
        cout << endl;
        cartaFueraDeRango();
        cout << "Carta de su corral: ";
        cin >> numCartaCorral;
    }

    ///// DEFINO EL JUGADOR DE TURNO Y MUEVO LAS CARTAS SEGÚN CORRESPONDA\\\\\

    if(primerTirador == 1){
        if(contRondas % 2 !=0){
            // Player One
            for(x = 0; x < 5; x++){
                if(cartasBloqueadasPT[x] == 0){
                    contCartasDisponibles++;
                }
            }

            if(contCartasDisponibles > 0){

                cout << "Carta del corral del contrario: ";
                cin >> numCartaCorralContrario;

                while(numCartaCorralContrario > 5 || numCartaCorralContrario <= 0){
                    cout << endl;
                    cartaFueraDeRango();
                    cout << "Carta del corral del contrario: ";
                    cin >> numCartaCorralContrario;
                }

                while(cartasBloqueadasPT[numCartaCorralContrario - 1] == 1){
                    cout << endl << endl << "ERROR: LA CARTA SE ENCUENTRA BLOQUEADA " << endl;
                    cout << "Carta del corral del contrario: ";
                    cin >> numCartaCorralContrario;

                    while(numCartaCorralContrario > 5 || numCartaCorralContrario <= 0){
                        cout << endl;
                        cartaFueraDeRango();
                        cout << "Carta del corral del contrario: ";
                        cin >> numCartaCorralContrario;
                    }
                }

                // REINICIO EL BLOQUEO DE MI CARTA, POR SI ESTABA BLOQUEADA
                cartasBloqueadasPO[numCartaCorral - 1] = 0;

                // GUARDO LA CARTA Y EL BASTO DE LA CARTA SELECCIONADA PARA CAMBIAR
                cartaPropiaSeleccionadaPlayer = cartasPO[numCartaCorral - 1];
                BastoCartaPropiaSeleccionadaPlayer = bastosCartasPO[numCartaCorral - 1];

                // ROBO LA CARTA DE MI CONTRINCANTE Y ME LA GUARDO
                cartasPO[numCartaCorral - 1] = cartasPT[numCartaCorralContrario - 1];
                bastosCartasPO[numCartaCorral - 1] = bastosCartasPT[numCartaCorralContrario - 1];

                // LE DOY A MI CONTRINCANTE MI CARTA SELECCIONADA PARA EL CAMBIO
                cartasPT[numCartaCorralContrario - 1] = cartaPropiaSeleccionadaPlayer;
                bastosCartasPT[numCartaCorralContrario - 1] = BastoCartaPropiaSeleccionadaPlayer;
            }
            else{
                cout << "Carta del corral contrario: NO HAY CARTAS DISPONIBLES, TODAS BLOQUEADAS";
                Sleep(3000);
            }
        }
        else{
            // Player Two
            for(x = 0; x < 5; x++){
                if(cartasBloqueadasPO[x] == 0){
                    contCartasDisponibles++;
                }
            }

            if(contCartasDisponibles > 0){

                cout << "Carta del corral del contrario: ";
                cin >> numCartaCorralContrario;

                while(numCartaCorralContrario > 5 || numCartaCorralContrario <= 0){
                    cout << endl;
                    cartaFueraDeRango();
                    cout << "Carta del corral del contrario: ";
                    cin >> numCartaCorralContrario;
                }

                while(cartasBloqueadasPO[numCartaCorralContrario - 1] == 1){
                    cout << endl << endl << "ERROR: LA CARTA SE ENCUENTRA BLOQUEADA " << endl;
                    cout << "Carta del corral del contrario: ";
                    cin >> numCartaCorralContrario;

                    while(numCartaCorralContrario > 5 || numCartaCorralContrario <= 0){
                        cout << endl;
                        cartaFueraDeRango();
                        cout << "Carta del corral del contrario: ";
                        cin >> numCartaCorralContrario;
                    }
                }
                cartasBloqueadasPT[numCartaCorral - 1] = 0;

                cartaPropiaSeleccionadaPlayer = cartasPT[numCartaCorral - 1];
                BastoCartaPropiaSeleccionadaPlayer = bastosCartasPT[numCartaCorral - 1];

                cartasPT[numCartaCorral - 1] = cartasPO[numCartaCorralContrario - 1];
                bastosCartasPT[numCartaCorral - 1] = bastosCartasPO[numCartaCorralContrario - 1];

                cartasPO[numCartaCorralContrario - 1] = cartaPropiaSeleccionadaPlayer;
                bastosCartasPO[numCartaCorralContrario - 1] = BastoCartaPropiaSeleccionadaPlayer;
            }
            else{
                cout << "Carta del corral contrario: NO HAY CARTAS DISPONIBLES, TODAS BLOQUEADAS";
                Sleep(3000);
            }

        }
    }
    else{
        if(contRondas % 2 !=0){
            // Player Two
            for(x = 0; x < 5; x++){
                if(cartasBloqueadasPO[x] == 0){
                    contCartasDisponibles++;
                }
            }

            if(contCartasDisponibles > 0){

                cout << "Carta del corral del contrario: ";
                cin >> numCartaCorralContrario;

                while(numCartaCorralContrario > 5 || numCartaCorralContrario <= 0){
                    cout << endl;
                    cartaFueraDeRango();
                    cout << "Carta del corral del contrario: ";
                    cin >> numCartaCorralContrario;
                }

                while(cartasBloqueadasPO[numCartaCorralContrario - 1] == 1){
                    cout << endl << endl << "ERROR: LA CARTA SE ENCUENTRA BLOQUEADA " << endl;
                    cout << "Carta del corral del contrario: ";
                    cin >> numCartaCorralContrario;

                    while(numCartaCorralContrario > 5 || numCartaCorralContrario <= 0){
                        cout << endl;
                        cartaFueraDeRango();
                        cout << "Carta del corral del contrario: ";
                        cin >> numCartaCorralContrario;
                    }
                }
                cartasBloqueadasPT[numCartaCorral - 1] = 0;

                cartaPropiaSeleccionadaPlayer = cartasPT[numCartaCorral - 1];
                BastoCartaPropiaSeleccionadaPlayer = bastosCartasPT[numCartaCorral - 1];

                cartasPT[numCartaCorral - 1] = cartasPO[numCartaCorralContrario - 1];
                bastosCartasPT[numCartaCorral - 1] = bastosCartasPO[numCartaCorralContrario - 1];

                cartasPO[numCartaCorralContrario - 1] = cartaPropiaSeleccionadaPlayer;
                bastosCartasPO[numCartaCorralContrario - 1] = BastoCartaPropiaSeleccionadaPlayer;
            }
            else{
                cout << "Carta del corral contrario: NO HAY CARTAS DISPONIBLES, TODAS BLOQUEADAS";
                Sleep(3000);
            }
        }
        else{
            // Player One
            for(x = 0; x < 5; x++){
                if(cartasBloqueadasPT[x] == 0){
                    contCartasDisponibles++;
                }
            }

            if(contCartasDisponibles > 0){

                cout << "Carta del corral del contrario: ";
                cin >> numCartaCorralContrario;

                while(numCartaCorralContrario > 5 || numCartaCorralContrario <= 0){
                    cout << endl;
                    cartaFueraDeRango();
                    cout << "Carta del corral del contrario: ";
                    cin >> numCartaCorralContrario;
                }

                while(cartasBloqueadasPT[numCartaCorralContrario - 1] == 1){
                    cout << endl << endl << "ERROR: LA CARTA SE ENCUENTRA BLOQUEADA " << endl;
                    cout << "Carta del corral del contrario: ";
                    cin >> numCartaCorralContrario;

                    while(numCartaCorralContrario > 5 || numCartaCorralContrario <= 0){
                        cout << endl;
                        cartaFueraDeRango();
                        cout << "Carta del corral del contrario: ";
                        cin >> numCartaCorralContrario;
                    }
                }
                cartasBloqueadasPO[numCartaCorral - 1] = 0;

                cartaPropiaSeleccionadaPlayer = cartasPO[numCartaCorral - 1];
                BastoCartaPropiaSeleccionadaPlayer = bastosCartasPO[numCartaCorral - 1];

                cartasPO[numCartaCorral - 1] = cartasPT[numCartaCorralContrario - 1];
                bastosCartasPO[numCartaCorral - 1] = bastosCartasPT[numCartaCorralContrario - 1];

                cartasPT[numCartaCorralContrario - 1] = cartaPropiaSeleccionadaPlayer;
                bastosCartasPT[numCartaCorralContrario - 1] = BastoCartaPropiaSeleccionadaPlayer;
            }
            else{
                cout << "Carta del corral contrario: NO HAY CARTAS DISPONIBLES, TODAS BLOQUEADAS";
                Sleep(3000);
            }

        }
    }
}



//ACCIÓN CUATRO
void accionCuatro(int cartasPO[5], int cartasPT[5], int primerTirador, int contRondas, string bastosCartasPO[], string bastosCartasPT[], int cartasBloqueadasPO[5], int cartasBloqueadasPT[5]){

    int numPrimerCartaCorral, numSegundaCartaCorral, primerCartaSeleccionadaPlayer, valorBloqueoPrimeraCartaCorral;
    string PrimerBastoCartaSeleccionadaPlayer;

    cout << "Intercambiar dos cartas del propio corral" << endl << endl;
    cout << "¿Qué cartas deseas intercambiar?" << endl;
    cout << "Primer carta: ";
    cin >> numPrimerCartaCorral;
    while(numPrimerCartaCorral > 5 || numPrimerCartaCorral <= 0){
        cout << endl;
        cartaFueraDeRango();
        cout << "Primer carta: ";
        cin >> numPrimerCartaCorral;
    }

    cout << "Segunda Carta: ";
    cin >> numSegundaCartaCorral;

    while(numSegundaCartaCorral > 5 || numSegundaCartaCorral <= 0){
        cout << endl;
        cartaFueraDeRango();
        cout << "Segunda Carta: ";
        cin >> numSegundaCartaCorral;
    }

    // VALIDO QUE NO SE ELIJA UNA ÚNICA CARTA
    while(numSegundaCartaCorral == numPrimerCartaCorral){
        cout << endl << endl << "ERROR: LA CARTA YA HA SIDO SELECCIONADA" << endl;
        cout << "Segunda Carta: ";
        cin >> numSegundaCartaCorral;

        while(numSegundaCartaCorral > 5 || numSegundaCartaCorral <= 0){
            cout << endl;
            cartaFueraDeRango();
            cout << "Segunda Carta: ";
            cin >> numSegundaCartaCorral;
        }

    }

    ///// DEFINO EL JUGADOR DE TURNO Y MUEVO LAS CARTAS SEGÚN CORRESPONDA\\\\\

    if(primerTirador == 1){
        if(contRondas % 2 !=0){
            // Player One

            // GUARDO LA PRIMERA CARTA, EL PALO/BASTO Y EL VALOR DE BLOQUEO DE LA MISMA
            primerCartaSeleccionadaPlayer = cartasPO[numPrimerCartaCorral - 1];
            PrimerBastoCartaSeleccionadaPlayer = bastosCartasPO[numPrimerCartaCorral - 1];
            valorBloqueoPrimeraCartaCorral = cartasBloqueadasPO[numPrimerCartaCorral - 1];

            // ASIGNO EN LAS POSICIONES DE LA PRIMERA CARTA, LOS VALORES DE LA SEGUNDA CARTA SELECCIOANDA (CARTA, PALO/BASTO, VALOR DE BLOQUEO)
            cartasPO[numPrimerCartaCorral - 1] = cartasPO[numSegundaCartaCorral - 1];
            bastosCartasPO[numPrimerCartaCorral - 1] = bastosCartasPO[numSegundaCartaCorral - 1];
            cartasBloqueadasPO[numPrimerCartaCorral - 1] = cartasBloqueadasPO[numSegundaCartaCorral - 1];

            // ASIGNO EN LAS POSICIONES DE LA SEGUNDA CARTA, LOS VALORES DE LA PRIMERA CARTA (CARTA, PALO/BASTO, VALOR DE BLOQUEO)
            cartasPO[numSegundaCartaCorral - 1] = primerCartaSeleccionadaPlayer;
            bastosCartasPO[numSegundaCartaCorral - 1] = PrimerBastoCartaSeleccionadaPlayer;
            cartasBloqueadasPO[numSegundaCartaCorral - 1] = valorBloqueoPrimeraCartaCorral;
        }
        else{
            // Player Two
            primerCartaSeleccionadaPlayer = cartasPT[numPrimerCartaCorral - 1];
            PrimerBastoCartaSeleccionadaPlayer = bastosCartasPT[numPrimerCartaCorral - 1];
            valorBloqueoPrimeraCartaCorral = cartasBloqueadasPT[numPrimerCartaCorral - 1];

            cartasPT[numPrimerCartaCorral - 1] = cartasPT[numSegundaCartaCorral - 1];
            bastosCartasPT[numPrimerCartaCorral - 1] = bastosCartasPT[numSegundaCartaCorral - 1];
            cartasBloqueadasPT[numPrimerCartaCorral - 1] = cartasBloqueadasPT[numSegundaCartaCorral - 1];

            cartasPT[numSegundaCartaCorral - 1] = primerCartaSeleccionadaPlayer;
            bastosCartasPT[numSegundaCartaCorral - 1] = PrimerBastoCartaSeleccionadaPlayer;
            cartasBloqueadasPT[numSegundaCartaCorral - 1] = valorBloqueoPrimeraCartaCorral;
        }
    }
    else{
        if(contRondas % 2 !=0){
            // Player Two
            primerCartaSeleccionadaPlayer = cartasPT[numPrimerCartaCorral - 1];
            PrimerBastoCartaSeleccionadaPlayer = bastosCartasPT[numPrimerCartaCorral - 1];
            valorBloqueoPrimeraCartaCorral = cartasBloqueadasPT[numPrimerCartaCorral - 1];

            cartasPT[numPrimerCartaCorral - 1] = cartasPT[numSegundaCartaCorral - 1];
            bastosCartasPT[numPrimerCartaCorral - 1] = bastosCartasPT[numSegundaCartaCorral - 1];
            cartasBloqueadasPT[numPrimerCartaCorral - 1] = cartasBloqueadasPT[numSegundaCartaCorral - 1];

            cartasPT[numSegundaCartaCorral - 1] = primerCartaSeleccionadaPlayer;
            bastosCartasPT[numSegundaCartaCorral - 1] = PrimerBastoCartaSeleccionadaPlayer;
            cartasBloqueadasPT[numSegundaCartaCorral - 1] = valorBloqueoPrimeraCartaCorral;
        }
        else{
            // Player One
            primerCartaSeleccionadaPlayer = cartasPO[numPrimerCartaCorral - 1];
            PrimerBastoCartaSeleccionadaPlayer = bastosCartasPO[numPrimerCartaCorral - 1];
            valorBloqueoPrimeraCartaCorral = cartasBloqueadasPO[numPrimerCartaCorral - 1];

            cartasPO[numPrimerCartaCorral - 1] = cartasPO[numSegundaCartaCorral - 1];
            bastosCartasPO[numPrimerCartaCorral - 1] = bastosCartasPO[numSegundaCartaCorral - 1];
            cartasBloqueadasPO[numPrimerCartaCorral - 1] = cartasBloqueadasPO[numSegundaCartaCorral - 1];

            cartasPO[numSegundaCartaCorral - 1] = primerCartaSeleccionadaPlayer;
            bastosCartasPO[numSegundaCartaCorral - 1] = PrimerBastoCartaSeleccionadaPlayer;
            cartasBloqueadasPO[numSegundaCartaCorral - 1] = valorBloqueoPrimeraCartaCorral;
        }
    }
}



//ACCIÓN CINCO
void accionCinco(int cartasBloqueadasPO[5], int cartasBloqueadasPT[5], int primerTirador, int contRondas){

    int x, cartaBloqueada, contCartasDisponibles = 0;

    cout << "Bloquear una carta del corral" << endl << endl;
    cout << "¿Qué carta deseas bloquear?" << endl;

    ///// DEFINO EL JUGADOR DE TURNO Y BLOQUEO LA CARTA SELECCIONADA \\\\\

    if(primerTirador == 1){
        if(contRondas % 2 !=0){
            // Player One

            // VALIDAMOS QUE HAYA CARTAS DISPONIBLES PARA BLOQUEAR
            for(x = 0; x<5; x++){
                if(cartasBloqueadasPO[x] == 0){
                    contCartasDisponibles++;
                }
            }

            if(contCartasDisponibles > 0){
                cout << "Carta de su corral: ";
                cin >> cartaBloqueada;

                while(cartaBloqueada > 5 || cartaBloqueada <= 0){
                    cout << endl;
                    cartaFueraDeRango();
                    cout << "Carta de su corral: ";
                    cin >> cartaBloqueada;
                }

                // VALIDAMOS QUE LA CARTA ELEGIDA NO ESTUVIESE BLOQUEADA
                while(cartasBloqueadasPO[cartaBloqueada - 1] == 1){
                    cout << endl << endl << "ERROR: LA CARTA YA SE ENCUENTRA BLOQUEADA " << endl;
                    cout << "Carta de su corral: ";
                    cin >> cartaBloqueada;
                    while(cartaBloqueada > 5 || cartaBloqueada <= 0){
                        cout << endl;
                        cartaFueraDeRango();
                        cout << "Carta de su corral: ";
                        cin >> cartaBloqueada;
                    }
                }

                // BLOQUEAMOS LA CARTA
                cartasBloqueadasPO[cartaBloqueada - 1] = 1;
            }
            else{
                cout << endl <<"Carta de su corral: NO HAY CARTAS DISPONIBLES PARA BLOQUEAR";
                Sleep(3000);
            }
        }
        else{
            // Player Two
            for(x = 0; x<5; x++){
                if(cartasBloqueadasPT[x] == 0){
                    contCartasDisponibles++;
                }
            }
            if(contCartasDisponibles > 0){
                cout << "Carta de su corral: ";
                cin >> cartaBloqueada;

                while(cartaBloqueada > 5 || cartaBloqueada <= 0){
                    cout << endl;
                    cartaFueraDeRango();
                    cout << "Carta de su corral: ";
                    cin >> cartaBloqueada;
                }

                while(cartasBloqueadasPT[cartaBloqueada - 1] == 1){
                    cout << endl << endl << "ERROR: LA CARTA YA SE ENCUENTRA BLOQUEADA " << endl;
                    cout << "Carta de su corral: ";
                    cin >> cartaBloqueada;
                    while(cartaBloqueada > 5 || cartaBloqueada <= 0){
                        cout << endl;
                        cartaFueraDeRango();
                        cout << "Carta de su corral: ";
                        cin >> cartaBloqueada;
                    }
                }
                cartasBloqueadasPT[cartaBloqueada - 1] = 1;
            }
            else{
                cout << endl << "Carta de su corral: NO HAY CARTAS DISPONIBLES PARA BLOQUEAR";
                Sleep(3000);
            }
        }
    }
    else{
        if(contRondas % 2 !=0){
            // Player Two
            for(x = 0; x<5; x++){
                if(cartasBloqueadasPT[x] == 0){
                    contCartasDisponibles++;
                }
            }
            if(contCartasDisponibles > 0){
                cout << "Carta de su corral: ";
                cin >> cartaBloqueada;

                while(cartaBloqueada > 5 || cartaBloqueada <= 0){
                    cout << endl;
                    cartaFueraDeRango();
                    cout << "Carta de su corral: ";
                    cin >> cartaBloqueada;
                }

                while(cartasBloqueadasPT[cartaBloqueada - 1] == 1){
                    cout << endl << endl << "ERROR: LA CARTA YA SE ENCUENTRA BLOQUEADA " << endl;
                    cout << "Carta de su corral: ";
                    cin >> cartaBloqueada;
                    while(cartaBloqueada > 5 || cartaBloqueada <= 0){
                        cout << endl;
                        cartaFueraDeRango();
                        cout << "Carta de su corral: ";
                        cin >> cartaBloqueada;
                    }
                }
                cartasBloqueadasPT[cartaBloqueada - 1] = 1;
            }
            else{
                cout << endl << "Carta de su corral: NO HAY CARTAS DISPONIBLES PARA BLOQUEAR";
                Sleep(3000);
            }
        }
        else{
            // Player One
            for(x = 0; x<5; x++){
                if(cartasBloqueadasPO[x] == 0){
                    contCartasDisponibles++;
                }
            }
            if(contCartasDisponibles > 0){
                cout << "Carta de su corral: ";
                cin >> cartaBloqueada;

                while(cartaBloqueada > 5 || cartaBloqueada <= 0){
                    cout << endl;
                    cartaFueraDeRango();
                    cout << "Carta de su corral: ";
                    cin >> cartaBloqueada;
                }

                while(cartasBloqueadasPO[cartaBloqueada - 1] == 1){
                    cout << endl << endl << "ERROR: LA CARTA YA SE ENCUENTRA BLOQUEADA " << endl;
                    cout << "Carta de su corral: ";
                    cin >> cartaBloqueada;
                    while(cartaBloqueada > 5 || cartaBloqueada <= 0){
                        cout << endl;
                        cartaFueraDeRango();
                        cout << "Carta de su corral: ";
                        cin >> cartaBloqueada;
                    }
                }
                cartasBloqueadasPO[cartaBloqueada - 1] = 1;
            }
            else{
                cout << endl << "Carta de su corral: NO HAY CARTAS DISPONIBLES PARA BLOQUEAR";
                Sleep(3000);
            }
        }
    }

}



//ACCIÓN SEIS
int accionSeis(){
    int opcionSeleccionada = 0;
    cout << "Elegir cualquiera de las acciones disponibles o pasar el turno." << endl << endl;
    cout <<"Elegir acción: " << endl;
    cout << "---------------------" << endl;
    cout << "1 - Elegir una carta de su propio corral (1-5) y robar una carta del mazo." << endl;
    cout << "2 - Elegir una carta del corral del contrario (1-5) y robar una carta del mazo." << endl;
    cout << "3 - Elegir una carta del corral propio (1-5) e intercambiarla por una carta del corral del contrario (1-5)" << endl;
    cout << "4 - Intercambiar dos cartas del propio corral" << endl;
    cout << "5 - Bloquear una carta del corral" << endl;
    cout << "---------------------" << endl;
    cout << "0 - Pasar el turno" << endl;

    opcionSeleccionada = _getch();

    while(opcionSeleccionada < 48 || opcionSeleccionada > 53){
        cout << endl << endl << "ERROR: ACCIÓN ERRÓNEA" << endl;
        opcionSeleccionada = _getch();
    }

    return opcionSeleccionada;
}



/////////- - - - PUNTAJE - - - -\\\\\\\\\

//AVERIGUA JUGADOR ACTUAL
int averiguarJugador(int primerTirador, int contRondas){

    int playerCorrespondiente;

    if(primerTirador == 1){
        if(contRondas % 2 !=0){
            playerCorrespondiente = 1;

        }
        else{
            playerCorrespondiente = 2;

        }
    }
    else{
        if(contRondas % 2 !=0){
            playerCorrespondiente = 2;
        }
        else{
            playerCorrespondiente = 1;
        }
    }

    return playerCorrespondiente;
}



//DEFINE GANADOR
int ganador(int cartasPO[5], int cartasPT[5]){
    int x, contCartasOrdenadasPO = 0, contCartasOrdenadasPT = 0, jugadorGanador = 0;

    // VALIDAMOS ORDEN ASCENDENTE
    for (int x = 0; x < 5; x++) {
        if (cartasPO[x] == x + 1) {
            contCartasOrdenadasPO++;
        }
        if (cartasPT[x] == x + 1) {
            contCartasOrdenadasPT++;
        }
    }

    if(contCartasOrdenadasPO == 5){
        if(contCartasOrdenadasPT == 5){
            jugadorGanador = 3;  // Empate
        }
        else{
            jugadorGanador = 1;
        }
    }
    else if(contCartasOrdenadasPT == 5){
        jugadorGanador = 2;
    }

    return jugadorGanador;
}




//CONTEO DE PUNTOS
int contarPuntos(int puntajes[5], int Ganador, string playerOne, string playerTwo, int contRondas, int jugadorRobando, int ultRondaRobo, int cartasPO[] , int cartasPT[] , bool pasaTurnoPO, bool pasaTurnoPT, bool robadoPO, bool robadoPT, int dado, int respuestaOp6){

    int x, i, contCartasMalUbicadas = 0, puntajeTotal = 0;
    system("CLS");
    cout << "CLUTCH" << endl;
    cout << "------------------------------------------------------------------------" << endl << endl;

    if(Ganador == 1){ //GANADOR Player One
        cout << "HITO                                                " << playerOne << endl;
        cout << "------------------------------------------------------------------------" << endl;
        cout << "Ganar la partida                                    +15 PDV" << endl;
        puntajes[0] += 15;

        // VALIDAMOS SI EL ÚLTIMO MOVIEMIENTO FUE UN ROBO DE CARTA
        cout << "Robo última carta al jugador rival                  +";
        if(ultRondaRobo == contRondas-1){
            // VALIDAMOS SI EL ROBO FUE DE PARTE DEL GANADOR HACIA EL CONTRINCANTE
            if(jugadorRobando == Ganador){
                cout << "10 PDV" << endl;
                // SUMAMOS 10 PDV
                puntajes[1] += 10;
            }
            else{
                cout << "0 PDV" << endl;
            }
        }
        else{
            cout << "0 PDV" << endl;
        }

        // HACEMOS EL CONTEO DE CARTAS MAL UBICADAS DEL CONTRINCANTE
        for(x = 0; x < 5; x++){
            if(cartasPT[x] != x + 1){
                contCartasMalUbicadas++;
            }
        }
        cout << "Cartas mal ubicadas del rival x " << contCartasMalUbicadas << "                   +" << (contCartasMalUbicadas * 5) << " PDV" << endl;
        // SUMAMOS LOS PDV CORRESPONDIENTES
        puntajes[2] += (contCartasMalUbicadas * 5);


        // VALIDAMOS SI EL GANADOR PASO DE TURNO O NO DURANTE LA PARTIDA
        cout <<"Sin pasar de turno                                  +";
        if(pasaTurnoPO == false){
            cout << "10 PDV" << endl;
            // SUMAMOS 10 PDV
            puntajes[3] += 10;
        }
        else{
            cout << "0 PDV" << endl;
        }

        // VALIDAMOS SI EL GANADOR SUFRIÓ ( O NO ) UN ROBO DURANTE LA PARTIDA
        cout << "Sin haber sufrido un robo del rival                 +";
        if(robadoPO == false){
            cout << "5 PDV" << endl;
            // SUMAMOS 5 PDV
            puntajes[4] += 5;
        }
        else{
            cout << "0 PDV" << endl;
        }

        for(i = 0; i < 5; i++){
            puntajeTotal += puntajes[i];
        }
        cout << "------------------------------------------------------------------------" << endl;
        cout << "TOTAL                                               " << puntajeTotal << " PDV" << endl << endl;

        cout << "GANADOR: " << playerOne << " con " << puntajeTotal << " puntos de victoria." << endl << endl;
    }
    else{ //GANADOR PT
        cout << "HITO                                                " << playerTwo << endl;
        cout << "------------------------------------------------------------------------" << endl;
        cout << "Ganar la partida                                    +15 PDV" << endl;
        puntajes[0] += 15;


        cout << "Robo última carta al jugador rival                  +";
        if(ultRondaRobo == contRondas-1){
            if(jugadorRobando == Ganador){
                cout << "10 PDV" << endl;
                puntajes[1] += 10;
            }
            else{
                cout << "0 PDV" << endl;
            }
        }
        else{
            cout << "0 PDV" << endl;
        }




        for(x = 0; x < 5; x++){
            if(cartasPO[x] != x + 1){
                contCartasMalUbicadas++;
            }
        }
        cout << "Cartas mal ubicadas del rival x " << contCartasMalUbicadas << "                   +" << (contCartasMalUbicadas * 5) << " PDV" << endl;
        puntajes[2] += (contCartasMalUbicadas * 5);



        cout <<"Sin pasar de turno                                  +";
        if(pasaTurnoPT == false){
            cout << "10 PDV" << endl;
            puntajes[3] += 10;
        }
        else{
            cout << "0 PDV" << endl;
        }


        cout << "Sin haber sufrido un robo del rival                 +";
        if(robadoPT == false){
            cout << "5 PDV" << endl;
            puntajes[4] += 5;
        }
        else{
            cout << "0 PDV" << endl;
        }

        for(i = 0; i < 5; i++){
            puntajeTotal += puntajes[i];
        }
        cout << "------------------------------------------------------------------------" << endl;
        cout << "TOTAL                                               " << puntajeTotal << " PDV" << endl << endl;

        cout << "GANADOR: " << playerTwo << " con " << puntajeTotal << " puntos de victoria." << endl << endl;
        }

        return puntajeTotal;
}



//MUESTRA LOS PUNTOS EN CASO DE EMPATE
void mostrarEmpate(){
    cout << "HITO                                                EMPATE" << endl;
    cout << "------------------------------------------------------------------------" << endl;
    cout << "Ganar la partida                                    +0 PDV" << endl;
    cout << "Robo última carta al jugador rival                  +0 PDV" << endl;
    cout << "Cartas mal ubicadas del rival x0                    +0 PDV" << endl;
    cout << "Sin pasar de turno                                  +0 PDV" << endl;
    cout << "Sin haber sufrido un robo del rival                 +0 PDV" << endl;
    cout << "------------------------------------------------------------------------" << endl;
    cout << "TOTAL                                                0 PDV" << endl << endl;
    cout << "GANADOR: La partida fue declarada EMPATE" << endl << endl;
}


//////////////////- - - - - - - - OPCIÓN 2 (ESTADÍSTICAS) - - - - - - - -\\\\\\\\\\\\\\\\\\

//ESTADÍSTICAS MAYOR PUNTAJE
int estadisticas(int mayorPuntuacion, string playerGanador){
    int opcionSeleccionada;

    cout << "CLUTCH" << endl;
    cout << "------------------------------------------------------------------------" << endl << endl;

    if(mayorPuntuacion != 0){
        cout << "+------------------------------------+"<< endl;
        cout << "|            ESTADISTICAS            |"<< endl;
        cout << "+-----------------+------------------+"<< endl;
        cout << "|Jugador          |  " << playerGanador << endl;
        cout << "+-----------------+" << endl;
        cout << "|Puntaje          |  " << mayorPuntuacion << " PDV" << endl;;
        cout << "+-----------------+" << endl;
    }
    else{
        cout << "+------------------------------------+"<< endl;
        cout << "|            ESTADISTICAS            |"<< endl;
        cout << "+------------------------------------+"<< endl;
        cout << " ERROR : NO HAY JUGADORES REGISTRADOS ";
    }

    cout << endl << endl << endl << endl;
    cout << " <-- Presione ESC para volver al menu princiapal ";
    opcionSeleccionada = _getch();

    return opcionSeleccionada;
}




//////////////////- - - - - - - - OPCIÓN 3 (CRÉDITOS) - - - - - - - -\\\\\\\\\\\\\\\\\\

//CRÉDITOS DEL JUEGO
int creditos(){
    int opcionSeleccionada;
    cout << "* * * *  * * *       *      * * * *   *      *      * * * *                   # # # # # # DESARROLLADOR # # # # # #" << endl;
    cout << "*        *    *     * *     *               * *     *                         #                                   #" << endl;
    cout << "*   * *  * * *     *   *    *         *    *   *    * * * *                   #       LEGNAME, ALEJO GASTÓN       #" << endl;
    cout << "*     *  *   *    * * * *   *         *   * * * *         *                   #              27004                #" << endl;
    cout << "* * * *  *    *   *     *   * * * *   *   *     *   * * * *                   # # # # # # # # # # # # # # # # # # #" << endl;
    cout << endl;
    cout << "* * *   * * * *   * * *"<< endl;
    cout << "*   *   *     *   *    *" << endl;
    cout << "* * *   *     *   * * * " << endl;
    cout << "*       *     *   *   *" << endl;
    cout << "*       * * * *   *    *" << endl;
    cout << endl;
    cout << "      *   *     *   * * * *      *      * * *" << endl;
    cout << "      *   *     *   *           * *     *    *" << endl;
    cout << "      *   *     *   *   * *    *   *    * * *" << endl;
    cout << "*     *   *     *   *     *   * * * *   *   *" << endl;
    cout << "* * * *   * * * *   * * * *   *     *   *    *" << endl;

    cout << endl << endl << endl << endl;
    cout << " <-- Presione ESC para volver al menu princiapal ";
    opcionSeleccionada = _getch();

    return opcionSeleccionada;
}




//////////////////- - - - - - - - OPCIÓN 0 (SALIR) - - - - - - - -\\\\\\\\\\\\\\\\\\

//SALIR DEL JUEGO
int salir(){
    int opcionSeleccionada;
    system("CLS");
    cout << "¿Confirmar salir del juego? (S/N)";
    opcionSeleccionada = _getch();

    return opcionSeleccionada;
}
