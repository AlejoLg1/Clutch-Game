#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include <string>


//////////////////- - - - - - - - MENÚ PRINCIPAL - - - - - - - -\\\\\\\\\\\\\\\\\\

//ARMA EL MENU PRINCIPAL
void menuPrincipal(); //MUESTRA EL MENÚ PRINCIPAL




//////////////////- - - - - - - - OPCIÓN 1 (JUGAR) - - - - - - - -\\\\\\\\\\\\\\\\\\

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

//ACCIÓN UNO
void accionUno(int [], int [], int [], int, int, std::string [4][5], std::string [], std::string [], int [], int []);

//ACCIÓN DOS
void accionDos(int [], int [], int [], int, int, std::string [4][5], std::string [], std::string [], int [], int []);

//ACCIÓN TRES
void accionTres(int [], int [], int, int, std::string [], std::string [], int [], int []);

//ACCIÓN CUATRO
void accionCuatro(int [], int [], int, int, std::string [], std::string [], int [], int []);

//ACCIÓN CINCO
void accionCinco(int [], int [], int, int);


//ACCIÓN SEIS
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



//////////////////- - - - - - - - OPCIÓN 2 (ESTADÍSTICAS) - - - - - - - -\\\\\\\\\\\\\\\\\\

//ESTADÍSTICAS MAYOR PUNTAJE
int estadisticas(int , std::string);




//////////////////- - - - - - - - OPCIÓN 3 (CRÉDITOS) - - - - - - - -\\\\\\\\\\\\\\\\\\

//CRÉDITOS DEL JUEGO
int creditos();




//////////////////- - - - - - - - OPCIÓN 0 (SALIR) - - - - - - - -\\\\\\\\\\\\\\\\\\

//SALIR DEL JUEGO
int salir();

#endif // FUNCIONES_H_INCLUDED
