#include <iostream>
#include <vector>

using namespace std;

class Cat{
protected:
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

    string miar(){
        return "miau";
    }

    friend ostream& operator<<(ostream &os, Cat& cat);
};

class LittleCat : public Cat{
public: 
    LittleCat(string nome = ""):
        Cat(nome){
        vidas = 3;
    }

    string miar(){
        return "miuauauaua";
    }
};

ostream& operator<<(ostream &os, Cat& cat){
    os << ("[nome: " + cat.nome + " vidas:" + to_string(cat.vidas) + "]");
    os << "\n{ ";
    for(auto coisa : cat.bucho)
        os << coisa + " ";
    os << "}";
    return os;
}


class Zumbi{
public:
    Zumbi(){};
    vector<Cat*> barriga;
    void comer(Cat * cat){
        barriga.push_back(cat);
    }
};

ostream& operator<<(ostream& os, Zumbi z){
    os << "Barriga" << endl;
    for(Cat* cat : z.barriga){
        os << (*cat) << endl;
    }
    return os;
}

class LittleCatZumbi :  public LittleCat, public Zumbi {
public:
    LittleCatZumbi(string nome = ""):
        LittleCat(nome)
    {
    }
};

int main(){

    Cat garf("Garfiudi");
    garf << "chiclete" << "piper" << "cheetos";
    
    LittleCat chaninha("Morena");
    chaninha << "danone" << "cerveja" << "uiski";

    LittleCatZumbi jason("Jason");
    Zumbi maicou;
    maicou.comer(&garf);
    maicou.comer(&chaninha);
    maicou.comer(&jason);
    jason.comer(&chaninha);
    jason.comer(&garf);

    cout << garf.miar() << endl << chaninha.miar() << endl;
    cout << garf << endl << chaninha << endl;

    cout << maicou;
    cout << (*(Cat*)&jason);
    cout << (*(Zumbi*)&jason);
}