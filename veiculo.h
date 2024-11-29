#ifndef VEICULO_H
#define VEICULO_H

#include <iostream>
#include <string>


class Veiculo {
    //protected porque as classes filhas poderao acessar os valores
protected:
    std::string nome;
    int num_rodas;

public:
    Veiculo(const std::string& nome, int num_rodas)
        : nome(nome), num_rodas(num_rodas) { //isso aqui são os parametros do construtor
        std::cout << "Veiculo " << nome << " construido." << std::endl;
    }
    //PORQUE USO VIRTUAL PARA DELETAR O OBJETO?
    //Explicação do professor: assim o código sempre deletara o objeto certo

    virtual ~Veiculo() {
        std::cout << "Veiculo " << nome << " destruido." << std::endl;
    }

    virtual void mover() = 0;

    void setNome(const std::string& nome) {
        this->nome = nome;
    }

    std::string getNome() const {
        return nome;
    }

    void setNumRodas(int num_rodas) {
        this->num_rodas = num_rodas;
    }

    int getNumRodas() const {
        return num_rodas;
    }
};


class Terrestre : public virtual Veiculo {
private:
    int cap_pass;

public:
    Terrestre(const std::string& nome, int num_rodas, int cap_pass = 5)
        : Veiculo(nome, num_rodas), cap_pass(cap_pass) {
        std::cout << "Veiculo terrestre " << getNome() << " construido." << std::endl;
    }

    ~Terrestre() {
        std::cout << "Veiculo terrestre " << getNome() << " destruido." << std::endl;
    }

    void setCapacidadeMax(int cap_pass) {
        this->cap_pass = cap_pass;
    }

    int getCapacidadeMax() const {
        return cap_pass;
    }

    void mover() override {
        std::cout << "Veiculo terrestre " << getNome() << " moveu." << std::endl;
    }
};


class Aquatico : public virtual Veiculo {
private:
    float carga_max;

public:
    Aquatico(const std::string& nome, int num_rodas, float carga_max = 10)
    //o nome certo disso são parametros?
    //sim
        : Veiculo(nome, num_rodas), carga_max(carga_max) {
        std::cout << "Veiculo aquatico " << getNome() << " construido." << std::endl;
    }

    ~Aquatico() {
        std::cout << "Veiculo aquatico " << getNome() << " destruido." << std::endl;
    }

    void setCargaMax(float carga_max) {
        this->carga_max = carga_max;
    }

    float getCargaMax() const {
        return carga_max;
    }
    //AQUI MOSTRA QUE CLARAMENTE É UMA CLASSE FILHA
    void mover() override {
        std::cout << "Veiculo aquatico " << getNome() << " moveu." << std::endl;
    }
};

//A UNICA CLASSE PAI E VEICULO
class Aereo : public Veiculo {
private:
    float vel_max;

public:
    Aereo(const std::string& nome, int num_rodas, float vel_max = 100)
        : Veiculo(nome, num_rodas), vel_max(vel_max) {
        std::cout << "Veiculo aereo " << getNome() << " construido." << std::endl;
    }

    ~Aereo() {
        std::cout << "Veiculo aereo " << getNome() << " destruido." << std::endl;
    }

    void setVelocidadeMax(float vel_max) {
        this->vel_max = vel_max;
    }

    float getVelocidadeMax() const {
        return vel_max;
    }

    void mover() override {
        std::cout << "Veiculo aereo " << getNome() << " moveu." << std::endl;
    }
};

//DEPOIS DO : EU VOU FALO QUEM SÃO OS PAIS DA CLASSE
class Anfibio : public Terrestre, public Aquatico {
public:
    Anfibio(const std::string& nome)
        : Veiculo(nome, 0), Terrestre(nome, 0), Aquatico(nome, 0) {
        std::cout << "Veiculo anfibio " << Veiculo::getNome() << " construido." << std::endl;
    }

    ~Anfibio() {
        std::cout << "Veiculo anfibio " << Veiculo::getNome() << " destruido." << std::endl;
    }
    //pega o metodo do pai e utiliza na classe filha
    void mover() override {
        Terrestre::mover();
        Aquatico::mover();
    }
};

#endif // VEICULO_H
