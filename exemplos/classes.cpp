//requisitos: parametros default, ponteiros, vector, referencia, const
#include <iostream>

struct Pessoa{
    int idade;
    std::string nome;
    float * f;
    
    //cria os recursos
    Pessoa(int idade = 0, std::string nome = "-", float f = 0){
        this->idade = idade;
        this->nome = nome;
        this->f = new float(f);
    }

    Pessoa(const Pessoa& other):
        idade(other.idade), nome(other.nome) //lista de inicializacao
    { //descescessario se não há atributos estaticos
        this->f = new float(*other.f); //o novo f possui uma nova memoria
    }

    //desaloca os recursos
    ~Pessoa(){ //desnessessário se não há herança ou atributos dinâmicos
        delete f;
    }
};

std::ostream& operator<<(std::ostream &os, const Pessoa& p){
    os << "Pessoa (nome: " << p.nome << ", idade: " << p.idade << ")";
    return os;
}

int main(){
    Pessoa dummy; //idade 0, nome ""
    Pessoa david(34, "David");
    Pessoa *p;
    p = new Pessoa(15, "Fulano");

    std::cout << dummy << '\n' << david << '\n' << (*p) << '\n';
    return 0;
}