#include <iostream>
using namespace std;

class Dispositivo {
    private:
        int numeroSerie;
        bool encendido;
    public:
        Dispositivo() {
            numeroSerie = 0;
            encendido = false;
        }

        bool setNumeroSerie(int nuevoNumero) {
            if (nuevoNumero <= 0) { return false; }
            numeroSerie = nuevoNumero;
            return true;
        }

        void encender() {
            encendido = true;
        }

        void describir() {
            std::cout << "Dispositivo #" << numeroSerie << ", encendido: " << (encendido ? "si" : "no") << std::endl;
        }
};

// TODO: Cartucho todavia no existe. Agregala con:
// - un atributo privado nivelTintaPorc (int), que empieza en 100
// - bool tieneTinta(): devuelve si nivelTintaPorc > 0
// - void consumir(int porcentaje): reduce nivelTintaPorc en ese porcentaje,
//   sin bajar de 0
// - int getNivelTintaPorc(): devuelve el nivel actual
class Cartucho{
    private:
        int nivelTintaPorc;
    public:
        Cartucho(){
            nivelTintaPorc=100;
        }
        bool tieneTinta(){
            return nivelTintaPorc>0;
        }
        void consumir(int porcentaje){
            int reducirPorcentaje;
            nivelTintaPorc-=porcentaje;
            if(nivelTintaPorc<0){
                nivelTintaPorc=0;
            }
        }
        int getNivelTintaPorc(){
            return nivelTintaPorc;
        }


};

// Un companero propone "class Impresora: public virtual Dispositivo, public Cartucho".
// Antes de escribir el codigo, responde en el README por que ese diseno
// es forzado, igual que Carro heredando de Motor en el Ejercicio 1.

/* NO ES ADECUADO POR QUE IMPRESORA, "NO ES UN CARTUCHO", SI NO "TIENE UN CARTUCHO
 POR LO QUE SERIA ADECUADO IMPLEMENTAR COMPOSICION, PARA USAR LOS METODOS ESPECIFICOS
 DE CARTUCHO"*/

// TODO: Impresora hereda con virtual de Dispositivo (igual que la sesion
// pasada) y tiene un atributo privado Cartucho. Agrega:
// bool imprimir(int paginas): si el cartucho no tiene tinta, imprime
//   "Sin tinta, no se puede imprimir" y devuelve false; si tiene, imprime
//   "Imprimiendo <paginas> paginas a <paginasPorMinuto> paginas por minuto",
//   consume (paginas * 2) de tinta, y devuelve true.
// int getNivelTintaPorc(): devuelve el nivel de tinta del cartucho.
class Impresora: public virtual Dispositivo {
    private:
        int paginasPorMinuto;
        //int paginas;
        Cartucho cartucho;
    public:
        Impresora() {
            paginasPorMinuto = 0;
            //paginas=100;
        }

        bool setPaginasPorMinuto(int nuevasPpm) {
            if (nuevasPpm <= 0) { return false; }
            paginasPorMinuto = nuevasPpm;
            return true;
        } 
        bool imprimir(int paginas){
            if(!cartucho.tieneTinta()){
                cout<<"Sin tinta, no se puede imprimir"<<endl;
                return false;
            }else{
                cout<<"Imprimiendo "<<paginas<<" paginas a "<<paginasPorMinuto<<" paginas por minuto"<<endl;
                cartucho.consumir((2*paginas));
                return true;
            }
        }
        int getNivelTintaPorc(){
           return cartucho.getNivelTintaPorc();
        }
        // TODO
};

int main() {
    Impresora i;
    i.setNumeroSerie(500);
    i.encender();
    i.setPaginasPorMinuto(20);
    i.imprimir(10);
    std::cout << "Tinta restante: " << i.getNivelTintaPorc() << "%" << std::endl;
    i.imprimir(45);
    std::cout << "Tinta restante: " << i.getNivelTintaPorc() << "%" << std::endl;
    i.imprimir(10);
    return 0;
}
