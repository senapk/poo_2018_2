#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//static int a; //tem visibilidade apenas desse arquivo

void contar(){
    static int cont = 0; //persistente ao escopo
    cont++;
    cout << cont << endl;
}

class Animal{ //abstrato
public:
    string nome;
    Animal(string nome = ""){
        this->nome = nome;
    }
    virtual string fazerBarulho() = 0; //abstrato
    virtual string morrer() = 0;

    static bool somar(int a, int b){ //chamado a partir da classe
                                    // sem precisar criar um objeto
        return a + b;
    }
};

ostream& operator<<(ostream& os, Animal& animal){
    os << "[" << animal.nome << ":" << animal.fazerBarulho() << "]";
    return os;
}

class Gato : public Animal{ //concreta
    int vidas {2};
public:
    Gato(string nome):Animal("Gato " + nome){}
    virtual string morrer(){
        vidas -= 1;
        if(vidas < 0)
            return "morri";
        return "nao morri";
    }

    virtual string fazerBarulho(){
        return "miau";
    }
};

class Cobra : public Animal{
public:
    Cobra():Animal("Cobra"){
    };
    virtual string morrer(){
        return "mordida";
    }
    virtual string fazerBarulho(){
        return "sssss";
    }
};

class Rato : public Animal{ //concreta
public:
    static int cont;
    Rato():Animal("Rato " + to_string(cont)){
        Rato::cont += 1;
    };
    virtual string morrer(){
        return "ploc";
    }
    virtual string fazerBarulho(){
        return "skiiik";
    }
};
int Rato::cont = 0;

int main(){
    vector<Animal*> sacola;
    sacola.push_back(new Gato("hugo"));
    sacola.push_back(new Gato("princesa"));
    sacola.push_back(new Gato("romeu"));
    
    sacola.push_back(new Rato());
    sacola.push_back(new Rato());
    sacola.push_back(new Rato());
    sacola.push_back(new Cobra());

    for(auto* elem : sacola)
        cout << *elem << endl;
    cout << endl;

    std::random_shuffle(sacola.begin(), sacola.end());

    for(auto* elem : sacola)
        cout << *elem << endl;
    cout << endl;

    for(auto* elem : sacola){
        if(Gato * gato = dynamic_cast<Gato*>(elem)){
            cout << *gato << " " << gato->morrer() << endl;
        }else{
            cout << *elem << " nao eh gato" << endl;
        }
    }

    for(auto* elem : sacola){
        if(Gato * gato = dynamic_cast<Gato*>(elem)){
            cout << *gato << " " << gato->morrer() << endl;
        }else{
            cout << *elem << " nao eh gato" << endl;
        }
    }

    for(auto* elem : sacola){
        if(Gato * gato = dynamic_cast<Gato*>(elem)){
            cout << *gato << " " << gato->morrer() << endl;
        }else{
            cout << *elem << " nao eh gato" << endl;
        }
    }
}