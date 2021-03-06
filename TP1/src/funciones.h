/*
 * funciones.h
 *
 *  Created on: 12 abr 2022
 *      Author: User
 */

#ifndef FUNCIONES_H_
#define FUNCIONES_H_

/// @brief Inicializa el menu de opciones
///
/// @return Retorna la opcion ingresada por el usuario
int menu();


/// @brief Confirma la salida del usuario
///
/// @param x Retorna la letra ingresada por el usuario
void confirmar(char *x);


/// @brief Informa al usuario que lo que ingreso no es un numero
///
void informarNoEsNumero();


/// @brief Solicita el ingreso de un numero
///
/// @param pFlag Puntero que devuelve 1 o NULL en caso de error
/// @param x Puntero que recive un numero y lo devuelve
/// @return	Retorna 1 o 0 en caso de error
int ingreseKm(int* pFlag, int* x);


/// @brief Solicita el ingreso de dos numeros
///
/// @param flagKm Recive un 1 o 0
/// @param pFlag Puntero que devuelve 1 o NULL en caso de error
/// @param y Puntero que recive un numero y lo devuelve
/// @param z Puntero que recive un numero y lo devuelve
/// @return Retorna 1 o 0 en caso de error
int ingreseVuelos(int flagKm, int* pFlag, float* y, float* z);


/// @brief Calcula todos los costos
///
/// @param flagKm Recive un 1 o 0
/// @param flagVuelos Recive un 1 o 0
/// @param pFlag Puntero que devuelve 1 o NULL en caso de error
/// @param y Recive un numero
/// @param z Recive un numero
/// @param x Recive un numero
/// @param rDescuentoAero Realiza un calculo para conseguir el descuento del 10 por ciento
/// @param rInteresAero Realiza un calculo para conseguir el interes del 25 por ciento
/// @param rDescuentoLatam Realiza un calculo para conseguir el descuento del 10 por ciento
/// @param rInteresLatam Realiza un calculo para conseguir el interes del 25 por ciento
/// @param rBitcoinAero Realiza un calculo para conseguir el precio en bitcoin
/// @param rBitcoinLatam Realiza un calculo para conseguir el precio en bitcoin
/// @param precioUnitarioAero  Realiza un calculo para conseguir el precio unitario
/// @param precioUnitarioLatam Realiza un calculo para conseguir el precio unitario
/// @param difPrecio Realiza un calculo para conseguir la diferencia de precios
/// @return Retorna un 1 o 0 en caso de error
int calcularCostos(int flagKm, int flagVuelos,int* pFlag,float y, float z, int x, float* rDescuentoAero,float* rInteresAero, float* rDescuentoLatam, float* rInteresLatam, float* rBitcoinAero, float* rBitcoinLatam, float* precioUnitarioAero, float* precioUnitarioLatam, float* difPrecio);


/// @brief Informa los resultados de los calculos
///
/// @param flagKm Recive un 1 o 0
/// @param flagVuelos Recive un 1 o 0
/// @param flagCalculos Recive un 1 o 0
/// @param rDesA Resultado del descuento
/// @param rDesL Resultado del descuento
/// @param rInteresA Resultado del interes
/// @param rInteresL Resultado del interes
/// @param rBitA Precio en bitcoin
/// @param rBitL Precio en bitcoin
/// @param preUniA Precio unitario
/// @param preUniL Precio unitario
/// @param difPre La diferencia de precios
void informarResultados(int flagKm, int flagVuelos, int flagCalculos, float rDesA, float rDesL, float rInteresA, float rInteresL, float rBitA, float rBitL, float preUniA, float preUniL, float difPre);


/// @brief Realiza una carga forzada de datos hardcodeados
///
void cargaForzada();

#endif /* FUNCIONES_H_ */

