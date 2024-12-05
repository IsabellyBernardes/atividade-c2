#include <iostream>
using namespace std;
#include "veiculo.h"

int main(){

    Veiculo *terr = new Terrestre("VT1");
    dynamic_cast<Terrestre*>(terr)->setCapacidadeMax(45);
    terr->mover();
    cout << "Capacidade maxima de passageiros: " << dynamic_cast<Terrestre*>(terr)->getCapacidadeMax() << endl << endl;


    Veiculo *aqua = new Aquatico("VQ1");
    dynamic_cast<Aquatico*>(aqua)->setCargaMax(12.5);
    aqua->mover();
    cout << "Capacidade maxima de carga: " << dynamic_cast<Aquatico*>(aqua)->getCargaMax() << endl << endl ;


    Veiculo *aereo = new Aereo("VA1");
    aereo->mover();
    dynamic_cast<Aereo*>(aereo)->setVelocidadeMax(1040.5);
    cout << "Velocidade maxima: " << dynamic_cast<Aereo*>(aereo)->getVelocidadeMax() << endl << endl ;


    Veiculo *anfi = new Anfibio("Veiculo Anfibio");
    anfi->mover();


    delete terr;
    delete aqua;
    delete aereo;
    delete anfi;

    //Veiculo v1 ("Moto");
    //Terrestre terrestre ("Carro");
    //Aquatico aquatico ("Barco");
    //Aereo aereo("Aviao");
    return 0;
};