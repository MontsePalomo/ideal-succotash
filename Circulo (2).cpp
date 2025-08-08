//1 programa 
//Marlen Montserrat Palomo Parra
//9-05-25
//Calcula el perimetro o el area del circulo
#include <stdio.h>
#include <conio.h>
#include <math.h>

int main(){
    float area, radio, perimetro;
    char opcion;
    
    printf("Ingrese 'p' para calcular el perimetro o 'a' para el area: ");
    opcion = getchar();
    
    printf("Ingrese el radio: ");
    scanf("%f", &radio);
    
    switch(opcion) {
        case 'p':
        perimetro = 2 * M_PI * radio;
        printf("El perimetro del circulo es: %.2f", perimetro);
        break;

        case 'a':
        area = M_PI * radio * radio;
        printf("El area del circulo es: %.2f", area);
        break;
		   
        default:
        printf("Opcion no valida. Debe ingresar 'p' o 'a'.");
    }
    
    getch();
}

