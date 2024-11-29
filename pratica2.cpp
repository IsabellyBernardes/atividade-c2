#include "veiculo.h"

int main() {
    //ta usando ponteiro por causa do dynamic
    Veiculo* terr = new Terrestre("VT1", 4);
    dynamic_cast<Terrestre*>(terr)->setCapacidadeMax(45);
    terr->mover();

    Veiculo* aqua = new Aquatico("VQ1", 0);
    //dynamic_cast e usado para garantir que o objeto seja do tipo de destino ou parecido
    //ele previne erros de conversao
    dynamic_cast<Aquatico*>(aqua)->setCargaMax(12.5);
    aqua->mover();

    Veiculo* aereo = new Aereo("VA1", 0);
    dynamic_cast<Aereo*>(aereo)->setVelocidadeMax(1040.5);
    aereo->mover();

    Veiculo* anfi = new Anfibio("VA2");
    anfi->mover();

    delete terr;
    delete aqua;
    delete aereo;
    delete anfi;

    return 0;
}
