//8 programa
//Marlen Montserrat Palomo Parra
//26-05-25
//Codigo para calcular la cantidad que se tendria ahorrada de 15 años si se depositan quince
//mil pesos a una tasa de interes de 3.7% mensual, capitalizable cada mes
#include <conio.h>
#include <stdio.h>
#include <math.h>

int main() {
    double deposito_mensual = 15000.0;
    double tasa_interes = 0.037;
    int meses = 15 * 12;

    double factor = pow(1 + tasa_interes, meses);
    double valor_futuro = deposito_mensual * ((factor - 1) / tasa_interes);

    printf("La cantidad ahorrada despues de 15 anos es: %.2f pesos", valor_futuro);

    getch();
}
