/*
 * funciones.c
 *
 *  Created on: 12 abr 2022
 *      Author: User
 */

#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int menu()
{
    int opcion;
    int cant;
    int flagKm = 0;
    int flagVuelos = 0;
    int flagCalculos = 0;
	int kilometro;
	float precioAero;
	float precioLatam;
	float rDescuentoA;
	float rDescuentoL;
	float rInteresA;
	float rInteresL;
	float rBitcoinA;
	float rBitcoinL;
	float precioUnitarioA;
	float precioUnitarioL;
	float diferenciaPrecio;
	char salir = 'n';


	do
	{
		if(flagVuelos != 1 && flagKm == 1)
		{
			printf("\n\n!!!Menu de opciones!!!\n\n");
			printf("1- Ingresar kilometros: (km = %d)\n",kilometro);
			printf("2- Ingresar Precio de Vuelos: (Aerolineas = y, Latam = x) \n");
			printf("-Precio vuelo Aerolineas: \n");
			printf("-Precio vuelo Latam: \n");
			printf("3- Calcular todos los costos: \n");
			printf("a) Tarjeta de debito (descuento 10 por ciento)\n");
			printf("b) Tarjeta de credito (interes 25 por ciento)\n");
			printf("c) Bitcoin (1 BTC -> 4606954.55 pesos Argentinos\n");
			printf("d) Mostrar precio por km (precio unitario\n");
			printf("e) Mostrar diferencia de precio ingresada (Latam - Aerolineas)\n");
			printf("4- Informar Resultados\n");
			printf("5- Carga forzada de datos\n");
			printf("6- Salir\n");
		}
		else if(flagVuelos == 1 && flagKm == 1)
		{
			printf("\n\n!!!Menu de opciones!!!\n\n");
			printf("1- Ingresar kilometros: (km = %d)\n",kilometro);
			printf("2- Ingresar Precio de Vuelos: (Aerolineas = %.2f, Latam = %.2f) \n", precioAero, precioLatam);
			printf("-Precio vuelo Aerolineas: %.2f\n", precioAero);
			printf("-Precio vuelo Latam: %.2f\n", precioLatam);
			printf("3- Calcular todos los costos: \n");
			printf("a) Tarjeta de debito (descuento 10 por ciento)\n");
			printf("b) Tarjeta de credito (interes 25 por ciento)\n");
			printf("c) Bitcoin (1 BTC -> 4606954.55 pesos Argentinos\n");
			printf("d) Mostrar precio por km (precio unitario)\n");
			printf("e) Mostrar diferencia de precio ingresada (Latam - Aerolineas)\n");
			printf("4- Informar Resultados\n");
			printf("5- Carga forzada de datos\n");
			printf("6- Salir\n");
	    }
		else
		{
		    printf("\n\n!!!Menu de opciones!!!\n\n");
		    printf("1- Ingresar kilometros: (km = x)\n");
		    printf("2- Ingresar Precio de Vuelos: (Aerolineas = y, Latam = x) \n");
		    printf("-Precio vuelo Aerolineas: \n");
		    printf("-Precio vuelo Latam: \n");
		    printf("3- Calcular todos los costos: \n");
		    printf("a) Tarjeta de debito (descuento 10 por ciento)\n");
		    printf("b) Tarjeta de credito (interes 25 por ciento)\n");
		    printf("c) Bitcoin (1 BTC -> 4606954.55 pesos Argentinos\n");
		    printf("d) Mostrar precio por km (precio unitario\n");
		    printf("e) Mostrar diferencia de precio ingresada (Latam - Aerolineas)\n");
		    printf("4- Informar Resultados\n");
		    printf("5- Carga forzada de datos\n");
		    printf("6- Salir\n");
		}

    printf("Ingrese una opcion: ");
    fflush(stdin);
    cant = scanf("%d", &opcion);
    	if(cant == 0)
    	{
    		opcion = 7;
    	}


    	        switch (opcion)
    	        {
    	        case 1:
    	        	ingreseKm(&flagKm,&kilometro);
    	            break;
    	        case 2:
    	        	ingreseVuelos(flagKm, &flagVuelos, &precioAero, &precioLatam);
    	            break;
    	        case 3:
    	        	calcularCostos(flagKm, flagVuelos, &flagCalculos, precioAero, precioLatam, kilometro, &rDescuentoA, &rDescuentoL, &rInteresA,
    	        			&rInteresL, &rBitcoinA, &rBitcoinL, &precioUnitarioA, &precioUnitarioL, &diferenciaPrecio);
    	            break;
    	        case 4:
    	        	informarResultados(flagKm, flagVuelos, flagCalculos, rDescuentoA, rDescuentoL, rInteresA, rInteresL,
    	        			rBitcoinA, rBitcoinL, precioUnitarioA, precioUnitarioL, diferenciaPrecio);
    	            break;
    	        case 5:
    	        	cargaForzada();
    	            break;
    	        case 6:
    	            confirmar(&salir);
    	            break;
    	        case 7:
    	        	informarNoEsNumero();
    	        	break;
    	        default:
    	            printf("\nOPCION INVALIDA\n");
    	        }
	} while (salir != 's');


    return opcion;
}

int ingreseKm(int* pFlag,int* x)
{
	int okey = 0;

	if(pFlag != NULL)
	{
		printf("ingrese kilometros: ");
		scanf("%d", x);
		okey = 1;
		*pFlag = 1;
	}

	return okey;
}

int ingreseVuelos(int flagKm, int* pFlag, float* y, float* z)
{
	int okey = 0;

	if(pFlag != NULL)
	{
		if(flagKm == 1)
			{
				printf("Ingrese precio vuelo Aerolineas: ");
				scanf("%f", y);
				printf("Ingrese precio vuelo Latam: ");
				scanf("%f", z);
				okey = 1;
				*pFlag = 1;
			}
			else{
			    printf("\nPrimero ingrese los KILOMETROS");
			}
	}
	return okey;
}

int calcularCostos(int flagKm, int flagVuelos,int* pFlag,float y, float z, int x, float* rDescuentoAero,float* rInteresAero,
				float* rDescuentoLatam, float* rInteresLatam, float* rBitcoinAero, float* rBitcoinLatam, float* precioUnitarioAero, float* precioUnitarioLatam, float* difPrecio)
{
    int okey = 0;

    if(pFlag != NULL)
    {
    		if(flagKm == 0)
    	    {
    	        printf("\nPrimero ingrese los KILOMETROS\n");

    	    }
    		else if(flagVuelos == 0)
			{
    	        printf("\nPrimero ingrese el precio de los VUELOS");

    	    }
    	    else
    	    {
    	    	*rDescuentoAero = y - (10 * y / 100);
				*rInteresAero = y * 0.25 + y;
				*rDescuentoLatam = z - (10 * z / 100);
				*rInteresLatam = z * 0.25 + z;
				*rBitcoinAero = y / 4572550.12;
				*rBitcoinLatam = z / 4572550.12;
				*precioUnitarioAero = y / (float)x;
				*precioUnitarioLatam = z / (float) x;
				if(z > y)
				{
					*difPrecio = z - y;
				}
				else
				{
					*difPrecio = y - z;
				}

				okey = 1;
				*pFlag = 1;
    	    }
    }
    return okey;

}

void informarResultados(int flagKm, int flagVuelos, int flagCalculos, float rDesA, float rDesL, float rInteresA, float rInteresL,
		float rBitA, float rBitL, float preUniA, float preUniL, float difPre)
{
	if(flagKm == 0)
	{
		printf("\nPrimero ingrese KILOMETROS\n");
	}
	else if(flagVuelos == 0)
	{
		printf("\nPrimero ingrese precio de los VUELOS\n");
	}
	else if (flagCalculos == 0)
	{
		printf("\nPrimero ingrese a CALCULAR todos los costos\n");
	}
	else
	{
		printf("\nLatam:\n");
		printf("a) Precio con tarjeta de debito: %.2f\n", rDesL);
		printf("b) Precio con tarjeta de credito: %.2f\n", rInteresL);
		printf("c) Precio pagando con bitcoin : %f\n", rBitL);
		printf("d) Precio unitario: %.2f\n", preUniL);
		printf("Aerolineas:\n");
		printf("a) Precio con tarjeta de debito: %.2f\n", rDesA);
		printf("b) Precio con tarjeta de credito: %.2f\n", rInteresA);
		printf("c) Precio pagando con bitcoin : %f\n", rBitA);
		printf("d) Precio unitario: %.2f\n", preUniA);
		printf("La diferencia de precio es : %.2f\n", difPre);
	}
}

void cargaForzada()
{

	float rDescuentoAero = 162965 - (10 * 162965 / 100);
	float rInteresAero = 162965 * 0.25 + 162965;
	float rDescuentoLatam = 159339 - (10 * 159339 / 100);
	float rInteresLatam = 159339 * 0.25 + 159339;
	float rBitcoinAero = 162965 / 4572550.12;
	float rBitcoinLatam = 159339 / 4572550.12;
	float precioUnitarioAero = 162965 /  7090;
	float precioUnitarioLatam = 159339 /  7090;
	float difPrecio = 162965 - 159339;




	printf("\nLatam:\n");
	printf("a) Precio con tarjeta de debito: %.2f\n", rDescuentoLatam);
	printf("b) Precio con tarjeta de credito: %.2f\n", rInteresLatam);
	printf("c) Precio pagando con bitcoin : %f\n", rBitcoinLatam);
	printf("d) Precio unitario: %.2f\n", precioUnitarioLatam);
	printf("Aerolineas:\n");
	printf("a) Precio con tarjeta de debito: %.2f\n", rDescuentoAero);
	printf("b) Precio con tarjeta de credito: %.2f\n", rInteresAero);
	printf("c) Precio pagando con bitcoin : %f\n", rBitcoinAero);
	printf("d) Precio unitario: %.2f\n", precioUnitarioAero);
	printf("La diferencia de precio es : %.2f\n", difPrecio);


}

void confirmar(char *x)
{
    printf("\nConfirme salida:");
    fflush(stdin);
    scanf("%c", x);
}

void informarNoEsNumero()
{
	printf("\nESO NO ES UN NUMERO\n");
}

