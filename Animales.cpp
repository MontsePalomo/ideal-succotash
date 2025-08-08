//4 programa
//Marlon Emiliano Olvera Gallegos
//14-05-25
//Crear clases y objetos de animales
#include <stdio.h>
#include <string>

using namespace std;

class Animales {
public:
    string color;
    string raza;
    string patas;
    string colas;
};

class Vertebrado : public Animales {
public:
    Vertebrado() {
        patas = "4";
        colas = "1";
    }
};

class Invertebrado : public Animales {
public:
    Invertebrado() {
        patas = "0";
        colas = "0";
    }
};

int main() {
    Vertebrado perro;
    perro.color = "Cafe";
    perro.raza = "Chihuahua";
    
    Invertebrado caracol;
    caracol.color = "Cafe";
    caracol.raza = "Caracol de jardin";

    printf("\nVERTEBRADO");
    printf("\nRaza: %s", perro.raza.c_str());
    printf("\nColor: %s", perro.color.c_str());
    printf("\nPatas: %s", perro.patas.c_str());
    printf("\nColas: %s", perro.colas.c_str());

    printf("\nINVERTEBRADO");
    printf("\nRaza: %s", caracol.raza.c_str());
    printf("\nColor: %s", caracol.color.c_str());
    printf("\nPatas: %s", caracol.patas.c_str());
    printf("\nColas: %s", caracol.colas.c_str());

    return 0;
}
