//contem as implementacoes do metodo das classes
#include <iostream>
using namespace std;
#include "veiculo.h"

Veiculo::Veiculo(const char* nome) : nome(nome) {
    cout << "Construtor de Veiculo chamado para " << nome << ": construido"<< endl;
}
Veiculo::~Veiculo() {
    cout << "Destrutor de Veiculo chamado para " << nome << ": destruido" << endl;
}



void Terrestre::setCapacidadeMax(int cap_pass) {
    this->cap_pass = cap_pass;
}
int Terrestre::getCapacidadeMax() {
    return cap_pass;
}



void Aquatico::setCargaMax(float carga_max) {
    this->carga_max = carga_max;
}
float Aquatico::getCargaMax() {
    return carga_max;
}



void Aereo::setVelocidadeMax(float vel_max) {
    this->vel_max = vel_max;
}
float Aereo::getVelocidadeMax() {
    return vel_max;
}




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

