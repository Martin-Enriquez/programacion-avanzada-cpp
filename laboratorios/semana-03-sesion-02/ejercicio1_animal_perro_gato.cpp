#include <iostream>
using namespace std;

class Animal {
    private:
        int edad;
        double peso;
    public:
        
        Animal() {
            edad = 0;
            peso = 0;
        }

        Animal(int edad_inicial, double peso_inicial){
            if (!setEdad(edad_inicial)) { edad = 0; }
            if (!setPeso(peso_inicial)) { peso = 0.0; }
        }

        bool setEdad(double nueva_edad){
            if(nueva_edad < 0) { return false; }
            edad = nueva_edad;
            return true;
        }

        bool setPeso(double nuevo_peso){
            if(nuevo_peso <= 0) { return false; }
            peso = nuevo_peso;
            return true;
        }

        double getPeso(){ return peso; }
        int getEdad(){ return edad; }

    void describir() {
        // TODO: imprime "Animal de " + edad + " anios, " + pesoKg + " kg"
        cout<<"Animal de "<<edad<<" anios, "<<pesoKg<<"kg."<<endl;
    }
};

class Gato: public Animal {
    public:
        void maullar() {
            std::cout << "Miuau!" << std::endl;
        }

};


int main(){

    Animal a;
    a.describir();

    Perro p;
    p.setEdad(4);
    p.setPeso(10);

    p.describir();
    p.ladrar();

    Gato g;
    g.setEdad(3);
    g.setPeso(3);
    
    g.describir();
    g.maullar();

    return 0;
}