#ifndef VEICULO_H
#define VEICULO_H

#include <iostream>
#include <string>


class Veiculo {
    //protected porque as classes filhas poderao acessar os valores
protected:
    std::string nome;

public:
<<<<<<< HEAD
    Veiculo(const std::string& nome, int num_rodas)
        : nome(nome), num_rodas(num_rodas) { //isso aqui são os parametros do construtor
=======
    virtual Veiculo(const std::string& nome)
        : nome(nome) {
>>>>>>> f5dab5b (continuar)
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

    
};


class Terrestre : public virtual Veiculo {
private:
    int cap_pass;

public:
    Terrestre(const std::string& nome, int cap_pass = 5)
        : Veiculo(nome), cap_pass(cap_pass) {
        std::cout << "Veiculo terrestre " << getNome() << " construido." << std::endl;
    }

    virtual ~Terrestre() {
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
<<<<<<< HEAD
    Aquatico(const std::string& nome, int num_rodas, float carga_max = 10)
    //o nome certo disso são parametros?
    //sim
        : Veiculo(nome, num_rodas), carga_max(carga_max) {
=======
    Aquatico(const std::string& nome,  float carga_max = 10)
        : Veiculo(nome), carga_max(carga_max) {
>>>>>>> f5dab5b (continuar)
        std::cout << "Veiculo aquatico " << getNome() << " construido." << std::endl;
    }

    virtual ~Aquatico() {
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

<<<<<<< HEAD
//A UNICA CLASSE PAI E VEICULO
=======

>>>>>>> f5dab5b (continuar)
class Aereo : public Veiculo {
private:
    float vel_max;

public:
    Aereo(const std::string& nome, float vel_max = 100)
        : Veiculo(nome), vel_max(vel_max) {
        std::cout << "Veiculo aereo " << getNome() << " construido." << std::endl;
    }

    virtual ~Aereo() {
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

<<<<<<< HEAD
//DEPOIS DO : EU VOU FALO QUEM SÃO OS PAIS DA CLASSE
=======

>>>>>>> f5dab5b (continuar)
class Anfibio : public Terrestre, public Aquatico {
public:
    Anfibio(const std::string& nome)
        : Veiculo(nome), Terrestre(nome), Aquatico(nome) {
        std::cout << "Veiculo anfibio " << Veiculo::getNome() << " construido." << std::endl;
    }

    virtual ~Anfibio() {
        std::cout << "Veiculo anfibio " << Veiculo::getNome() << " destruido." << std::endl;
    }
    //pega o metodo do pai e utiliza na classe filha
    void mover() override {
        Terrestre::mover();
        Aquatico::mover();
    }
};

#endif // VEICULO_H
