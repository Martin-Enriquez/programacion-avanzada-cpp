// Ejercicio 10: Figura y Circulo (herencia + operator<< juntos)
//
// Completa los metodos marcados con TODO y operator<<. No cambies las firmas
// ni el main().
//
// Compilar: g++ -std=c++20 -Wall -Wextra -g -o ejercicio10 ejercicio10_figura_circulo.cpp
// Ejecutar: ./ejercicio10
//
// Salida esperada:
// Figura 7, radio 5.5

#include <iostream>

class Figura {
private:
    int nombreCodigo;
public:
    bool setNombreCodigo(int n) {
        if(n>=1 && n<=99){
            nombreCodigo=n;
            return true;
        }
        // TODO: valida que n este entre 1 y 99 (ambos incluidos).
        return false;
    }
    int getNombreCodigo() {
        return nombreCodigo;
        // TODO: devuelve nombreCodigo.
        return 0;
    }
};

class Circulo : public Figura {
private:
    double radio;
public:
    bool setRadio(double r) {
        // TODO: valida que r sea mayor a 0 y menor o igual a 1000.
        if(r>0 && r<=100){
            radio=r;
            return true;
        }
        return false;
    }
    double getRadio() {
        return radio;
        // TODO: devuelve radio.
        return 0;
    }
};

std::ostream& operator<<(std::ostream& os, Circulo c) {
    // TODO: escribe en os "Figura " + nombreCodigo (heredado) + ", radio " + radio.
    // Devuelve os.
    os<<"Figura "<<c.getNombreCodigo()<<", radio "<<c.getRadio();
    return os;
}

int main() {
    Circulo c1;
    c1.setNombreCodigo(7);
    c1.setRadio(5.5);
    std::cout << c1 << std::endl;
    return 0;
}
