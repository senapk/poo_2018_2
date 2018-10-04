#include <iostream>
#include <vector>

using namespace std;
class Cat{
    string nome;
    int vidas;
    vector<string> bucho;
    public:
    Cat(string nome = ""){
        this->nome = nome;
        vidas = 7;
    }

    Cat& operator<<(string comida){
        bucho.push_back(comida);
        if(comida == "chumbinho")
            vidas -= 1;
        return *this;
    }

    void operator~(){
        cout << "miau" << endl;
    }

    friend ostream& operator<<(ostream &os, Cat cat);

};

ostream& operator<<(ostream &os, Cat cat){
    os << ("[nome: " + cat.nome + " vidas:" + to_string(cat.vidas) + "]");
    os << "\n{ ";
    for(auto coisa : cat.bucho)
        os << coisa + " ";
    os << "}";

    return os;
}

int main(){

    Cat garf("Garfiudi");

    garf.operator<<("xuxu");
    garf.operator<<("lasanha");
    garf << "chiclete" << "piper" << "cheetos";
    cout << garf << endl;
}