//3 programa 
//Marlen Montserrat Palomo Parra
//12-05-25
//Calcula las areas de los triangulos
#include <stdio.h>   
#include <cmath>    
#include <conio.h>

float areaBaseAltura(float base, float altura) {
    return (base * altura) / 2;
}

float areaEquilatero(float lado) {
    return (sqrt(3) / 4) * (lado * lado);
}

float areaEscaleno(float a, float b, float c) {
    float s = (a + b + c) / 2;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

float areaIsosceles(float base, float lado) {
    float altura = sqrt((lado * lado) - ((base/2) * (base/2)));
    return (base * altura) / 2;
}

int main() {
	float a, b, c, area;
    int opcion;
    printf("CALCULADORA DE AREAS DE TRIANGULOS");
    printf("\n1. Triangulo cualquiera (base y altura)");
    printf("\n2. Triangulo equilatero (lado)");
    printf("\n3. Triangulo isosceles (base y lado igual)");
    printf("\n4. Triangulo escaleno (3 lados diferentes)");
    printf("\nSeleccione una opcion: ");
    scanf("%d", &opcion);

    switch(opcion) {
        case 1:
            printf("\nTRIANGULO CUALQUIERA");
            printf("\nIngrese la base: ");
            scanf("%f", &a);
            printf("\nIngrese la altura: ");
            scanf("%f", &b);
            area = areaBaseAltura(a, b);
            break;
            
        case 2:
            printf("\nTRIANGULO EQUILATERO");
            printf("\nIngrese el lado: ");
            scanf("%f", &a);
            area = areaEquilatero(a);
            break;
            
        case 3:
            printf("\nTRIANGULO ISOSCELES");
            printf("\nIngrese la base: ");
            scanf("%f", &a);
            printf("\nIngrese el lado igual: ");
            scanf("%f", &b);
            area = areaIsosceles(a, b);
            break;
            
        case 4:
            printf("\nTRIANGULO ESCALENO");
            printf("\nIngrese los 3 lados (separados por espacio): ");
            scanf("%f %f %f", &a, &b, &c);
            area = areaEscaleno(a, b, c);
            break;
            
        default:
            printf("\nOpcion no valida");
            
    }

    printf("\nEl area del triangulo es: %.2f", area);
    
    getch();
}
