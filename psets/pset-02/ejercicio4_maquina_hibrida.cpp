// Ejercicio 4: Maquina, MaquinaElectrica, MaquinaTermica e Hibrida
// (herencia multiple con el problema del diamante, ya resuelto con herencia virtual)
//
// Completa los metodos marcados con TODO. No cambies las firmas, la jerarquia
// de herencia ni el main(). Fijate que MaquinaElectrica y MaquinaTermica heredan
// de Maquina con "public virtual": por eso Hibrida termina con una sola copia
// de Maquina en vez de dos copias ambiguas.
//
// Compilar: g++ -std=c++20 -Wall -Wextra -g -o ejercicio4 ejercicio4_maquina_hibrida.cpp
// Ejecutar: ./ejercicio4
//
// Salida esperada:
// Potencia: 3200
// Voltaje: 220
// Temperatura maxima: 450
// Modo electrico: true

#include <iostream>

class Maquina {
private:
    double potenciaWatts;
public:
    bool setPotenciaWatts(double p) {
        if(p>=0 && p<=5000){
            potenciaWatts=p;
            return true;
        }
        // TODO: valida que p sea mayor a 0 y menor o igual a 5000.
        return false;
    }
    double getPotenciaWatts() {
        return potenciaWatts;
        // TODO: devuelve potenciaWatts.
        return 0;
    }
};

class MaquinaElectrica : public virtual Maquina {
private:
    double voltaje;
public:
    bool setVoltaje(double v) {
        if(v>=0 && v<=240){
            voltaje=v;
            return true;
        }
        // TODO: valida que v sea mayor a 0 y menor o igual a 240.
        return false;
    }
    double getVoltaje() {
        return voltaje;
        // TODO: devuelve voltaje.
        return 0;
    }
};

class MaquinaTermica : public virtual Maquina {
private:
    double temperaturaMaxima;
public:
    bool setTemperaturaMaxima(double t) {
        if(t>=0&&t<=1000){
            temperaturaMaxima=t;
            return true;
        }
        // TODO: valida que t sea mayor a 0 y menor o igual a 1000.
        return false;
    }
    double getTemperaturaMaxima() {
        return temperaturaMaxima;
        // TODO: devuelve temperaturaMaxima.
        return 0;
    }
};

class Hibrida : public MaquinaElectrica, public MaquinaTermica {
private:
    bool modoElectrico;
public:
    void setModoElectrico(bool m) {
        modoElectrico=m;
        // TODO: asigna modoElectrico. No hay invariante que validar.
    }
    bool getModoElectrico() {
        return modoElectrico;
        // TODO: devuelve modoElectrico.
        return false;
    }
};

int main() {
    Hibrida h1;
    h1.setPotenciaWatts(3200);
    h1.setVoltaje(220);
    h1.setTemperaturaMaxima(450);
    h1.setModoElectrico(true);
    std::cout << "Potencia: " << h1.getPotenciaWatts() << std::endl;
    std::cout << "Voltaje: " << h1.getVoltaje() << std::endl;
    std::cout << "Temperatura maxima: " << h1.getTemperaturaMaxima() << std::endl;
    std::cout << "Modo electrico: " << std::boolalpha << h1.getModoElectrico() << std::endl;
    return 0;
}
