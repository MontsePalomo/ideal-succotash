//5 programa
//Marlen Montserrat Palomo Parra
//14-05-25
//Define la clase deporte para las actividades que se realizen con un balon
//y se crea 2 subclases derivadas dependiendo de la parte del cuerpo cuando se golpea el balon
#include <stdio.h>
#include <string>

using namespace std;

class Deporte {
public:
    string nombre;
    string tipo_balon;
    
public:
    Deporte(string n, string tb) : nombre(n), tipo_balon(tb) {}
    
    void descripcion() {
        printf("Deporte: %s\n", nombre.c_str());
        printf("Balon utilizado: %s\n", tipo_balon.c_str());
    }
};

class DeportePies : public Deporte {
public:
    string calzado;
    
public:
    DeportePies(string n, string tb, string calz) 
        : Deporte(n, tb), calzado(calz) {}
        
    void golpear() {
        printf("Se golpea el balon con los pies\n");
        printf("Calzado especial: %s\n\n", calzado.c_str());
    }
};

class DeporteManos : public Deporte {
private:
    string proteccion;
    
public:
    DeporteManos(string n, string tb, string prot) 
        : Deporte(n, tb), proteccion(prot) {}
        
    void golpear() {
        printf("Se golpea el balon con las manos\n");
        printf("Proteccion utilizada: %s\n\n", proteccion.c_str());
    }
};

int main() {
    DeportePies futbol("Futbol", "Cuero sintetico", "Tacos profesionales");
    DeporteManos baloncesto("Baloncesto", "Caucho texturizado", "Munequeras");

    printf("=== DEPORTES CON BALON ===\n\n");
    
    futbol.descripcion();
    futbol.golpear();
    
    baloncesto.descripcion();
    baloncesto.golpear();

    return 0;
}
