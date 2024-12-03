#ifndef VEICULO_H
#define VEICULO_H
//contem as definicoes de classes
using namespace std;

class Veiculo {
protected:
    string nome;
public:
    Veiculo(const char *nome);
    virtual ~Veiculo();
    virtual void mover() = 0;
};

class Terrestre : public virtual Veiculo {
private:
    int cap_pass;
protected:
    Terrestre() : Veiculo("Default"), cap_pass(5) {
        cout << "Veiculo terrestre " <<nome<< " construido " << endl;
    }


public:
    Terrestre(const char *nome, int cap_pass = 5) : Veiculo(nome), cap_pass(cap_pass){}
    //virtual ~Terrestre() {
    //    cout << "Veiculo " << nome << " destruido " << endl;
    //}
    void setCapacidadeMax(int cap_pass);
    int getCapacidadeMax();
    void mover() override {
        cout << "Veiculo terrestre " << nome << " se movendo " << endl;
    };

};


class Aquatico : public virtual Veiculo {
private:
    float carga_max;

protected:
    Aquatico() : Veiculo("Default"), carga_max(10.0) {
        cout << "Veiculo aquatico " <<nome<< " construido " << endl << endl;
    }

public:
    Aquatico(const char *nome, int carga_max = 10.0) : Veiculo(nome), carga_max(carga_max) {}
    //Aquatico(const char *nome, float carga_max = 10) : Veiculo(nome), carga_max(carga_max) {

    //}

    //virtual ~Aquatico() {
    //    cout << "Veiculo " << nome << " destruido " << endl;
    //}

    void setCargaMax(float carga_max);
    float getCargaMax();
    void mover() override {
        cout << "Veiculo aquatico " << nome << " se movendo " << endl;
    };

};


class Aereo : public Veiculo {
private:
    float vel_max;
protected:
    Aereo() : Veiculo("Default"), vel_max(100) {
        cout << "Veiculo aereo " <<nome<< " construido " << endl;
    }

public:
    Aereo(const char *nome, float vel_max = 100) : Veiculo(nome), vel_max(vel_max){}
    //virtual ~Aereo() {
    //    cout << "Veiculo " << nome << " destruido " << endl;
    //}

    void setVelocidadeMax(float vel_max);
    float getVelocidadeMax();
    void mover() override {
        cout << "Veiculo aereo " << nome << " se movendo " << endl;
    };

};

class Anfibio : public virtual Veiculo,public virtual Terrestre, public virtual Aquatico {

    //A herança virtual evita a duplicação de sub-objetos Veiculo dentro de Anfibio, do contrário o compilador criaria duas cópias e haveria ambiguidade sobre qual usar.
    public: // inicializacao do subobjeto virtual
    Anfibio (const char * nome) : Veiculo(nome), Terrestre(), Aquatico() {}



    void mover() override {
            Terrestre::mover();
            Aquatico::mover();
        }

};


#endif //VEICULO_H
