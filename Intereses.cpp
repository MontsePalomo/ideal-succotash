//7 programa
//Marlen Montserrat Palomo Parra
//26-05-25
//Codigo para calcular la cantidad que se tendria ahorrada despues de 10 años si se depositan
//mil pesos mensualmente a una tasa de interes mensual del 3%, capitalizable cada mes, es decir, que al 
//capital se le agrega los intereses
#include <conio.h>
#include <stdio.h>
#include <math.h>

int main(){
	double deposito_mensual = 1000.0;
	double tasa_mensual = 0.03;
	int meses = 10 * 12;
	
	double factor= pow(1 + tasa_mensual, meses);
	double ahorro_total = deposito_mensual * ((factor - 1) / tasa_mensual);
	
	printf("Ahorro despues de 10 anos: $%.2f", ahorro_total);
	
	getch();
}
