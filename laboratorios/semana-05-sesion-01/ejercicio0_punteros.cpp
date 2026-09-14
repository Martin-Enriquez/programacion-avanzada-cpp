#include <iostream>
using namespace std;

int main(){
    int numero=10;
    int *ptr_numero=&numero;

    cout<<"Direccion de memoria: "<<ptr_numero<<endl;
    cout<<"Valor de memoria: "<<*ptr_numero<<endl;

    int notas [5] = {80,90,60,71};
    int *ptr_notas=notas;
    cout<<"Direccion de memoria: "<<ptr_notas<<endl;
    cout<<"Valor de memoria: "<<*ptr_notas<<endl;
    for(int i=0;i<4;i++){
        cout<<"Valor de memoria, posicion "<<i+1<<": "<<*(ptr_notas+i)<<endl;
    }
    return 0;
}