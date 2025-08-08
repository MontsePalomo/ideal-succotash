//6 programa
//21-05-25
//Marlen Montserrat Palomo Parra
#include <cstdio>
#include <cstring>
#include <string>

using namespace std;

string transicion(string estado, char simbolo) {
    if (estado == "S1") {
        if (simbolo == 'a') return "S2";
    } else if (estado == "S2") {
        if (simbolo == 'a') return "S2";
        if (simbolo == 'c') return "S4";
    } else if (estado == "S4") {
        if (simbolo == 'd') return "S3";
        if (simbolo == 'b') return "S4";
    } else if (estado == "S3") {
    }
    return "";
}

int main() {
    string estado = "S1";
    char cadena[100];

    printf("Ingrese la cadena: ");
    scanf("%s", cadena);

    int len = strlen(cadena);

    printf("\nProcesando cadena : %s\n", cadena);
    printf("Estado Inicial: %s\n", estado.c_str());

    for (int i = 0; i < len; i++) {
        char simbolo = cadena[i];
        string sigEstado = transicion(estado, simbolo);

        if (sigEstado == "") {
            printf("Leyendo %c desde %s -> Transicion NO valida. Se detiene.\n", simbolo, estado.c_str());
            printf("Cadena NO valida.\n");
            return 0;
        } else {
            printf("Leyendo %c desde %s -> %s\n", simbolo, estado.c_str(), sigEstado.c_str());
            estado = sigEstado;
        }
    }

    printf("\nEstado final alcanzado: %s\n", estado.c_str());

    if (estado == "S3") {
        printf("Cadena ACEPTADA (termina en S3).\n");
    } else {
        printf("Cadena NO valida (termina en %s).\n", estado.c_str());
    }

    return 0;
}

