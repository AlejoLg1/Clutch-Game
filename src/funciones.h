#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include <string>


//////////////////- - - - - - - - MEN� PRINCIPAL - - - - - - - -\\\\\\\\\\\\\\\\\\

//ARMA EL MENU PRINCIPAL
void menuPrincipal(); //MUESTRA EL MEN� PRINCIPAL




//////////////////- - - - - - - - OPCI�N 1 (JUGAR) - - - - - - - -\\\\\\\\\\\\\\\\\\

//VALIDA DATO INGRESADO
void opcionIncorrecta();
void cartaFueraDeRango();

//DEFINIR NOMBRES DE LOS JUGADORES
std::string ingresarPlayerOne(std::string);
std::string ingresarPlayerTwo(std::string, std::string);
char confirmarJuego(std::string, std::string);

//ARMAR ESTRUCTURA DEL JUEGO
void headerPartida(int, std::string, std::string); //MUSTRA EL HEADER DE LA PARTIDA
void mostrarTurno(std::string, std::string, int, int); //MUESTRA EL NOMBRE DE LA PERSONA QUE COMIENZA TIRANDO EL DADO
void mostrarCartas(int [], int [], std::string [], std::string [], std::string, std::string); //MUESTRA LAS CARTAS OBTENIDAS

//DEFINIR CARTAS, BASTOS Y PRIMER TURNO
void repartirCartasPO(int [], int []); //DEFINE LAS CARTAS DEL PLAYER ONE
void repartirCartasPT(int [], int []); //DEFINE LAS CARTAS DEL PLAYER TWO
int checkearOrden(int [], int []); //CHECKEA QUE NO SE REPARTAN EN ORDEN
void definirCartas(int [], int [], std::string, std::string, std::string [4][5], std::string [], std::string []); //VINCULA ALEATORIAMENTE LAS CARTAS DEL JUGADOR CON LOS BASTOS
int definirPrimerTurno(int [], int []); //DEFINE QUEIN COMIENZA TIRANDO EL DADO



/////////- - - - DADO - - - -\\\\\\\\\

//TIRAR EL DADO
int tirarDado();

//ACCI�N UNO
void accionUno(int [], int [], int [], int, int, std::string [4][5], std::string [], std::string [], int [], int []);

//ACCI�N DOS
void accionDos(int [], int [], int [], int, int, std::string [4][5], std::string [], std::string [], int [], int []);

//ACCI�N TRES
void accionTres(int [], int [], int, int, std::string [], std::string [], int [], int []);

//ACCI�N CUATRO
void accionCuatro(int [], int [], int, int, std::string [], std::string [], int [], int []);

//ACCI�N CINCO
void accionCinco(int [], int [], int, int);


//ACCI�N SEIS
int accionSeis();



/////////- - - - PUNTAJE - - - -\\\\\\\\\

//AVERIGUA JUGADOR ACTUAL
int averiguarJugador(int, int);

//DEFINE GANADOR
int ganador(int [], int []);

//CONTEO DE PUNTOS
int contarPuntos(int [], int , std::string, std::string, int , int , int , int [] , int [] , bool , bool , bool , bool , int , int );

//EMPATE
void mostrarEmpate();



//////////////////- - - - - - - - OPCI�N 2 (ESTAD�STICAS) - - - - - - - -\\\\\\\\\\\\\\\\\\

//ESTAD�STICAS MAYOR PUNTAJE
int estadisticas(int , std::string);




//////////////////- - - - - - - - OPCI�N 3 (CR�DITOS) - - - - - - - -\\\\\\\\\\\\\\\\\\

//CR�DITOS DEL JUEGO
int creditos();




//////////////////- - - - - - - - OPCI�N 0 (SALIR) - - - - - - - -\\\\\\\\\\\\\\\\\\

//SALIR DEL JUEGO
int salir();

#endif // FUNCIONES_H_INCLUDED
