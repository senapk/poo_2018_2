#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <sstream>
using namespace std;

class Emb{ 
public:
    virtual string getId() = 0;
    virtual string toString() = 0;
    virtual ~Emb(){};
};

class Pass: public Emb {
    string id;
public:
    Pass(string id = ""):
        id(id){}
    virtual ~Pass(){
    }
    virtual string getId(){
        return id;
    }
    virtual string toString(){
        return id;
    }
};

/* class Carga: public Emb {
    getPeso();
}; */

class Vagao{ //contratos
public:
    virtual bool embarcar(Emb * emb) = 0;
    virtual ~Vagao(){};
    //virtual bool desembar(string idPass) = 0;
    //virtual bool exists(string idPass) = 0;
    virtual string toString() = 0;
};

/* class VagaoCarga : public Vagao {
    float capacidade;
    map<string, Carga*> elementos;
}; */

class VagaoPessoas : public Vagao {
    vector<Pass*> passageiros;
public:
    VagaoPessoas(int capacidade):
        passageiros(capacidade, nullptr)
    {}
    ~VagaoPessoas(){
        for(size_t i = 0; i < passageiros.size(); i++){
            if(passageiros[i] != nullptr)
                delete passageiros[i];
        }
    }

    virtual bool embarcar(Emb * emb){
        if(Pass * pass = dynamic_cast<Pass*>(emb)){
            for(size_t i = 0; i < passageiros.size(); i++){
                if(passageiros[i] == nullptr){
                    passageiros[i] = pass;
                    return true;
                }
            }
        }
        return false;
    }
    /* virtual bool desembar(string idPass) = 0;
    virtual bool exists(string idPass) = 0; */

    virtual string toString(){
        stringstream ss;
        ss << "[ ";
        for(auto* pass : passageiros){
            if(pass == nullptr)
                ss << "- ";
            else
                ss << pass->toString() << " ";
        }
        ss << "]";
        return ss.str();
    }
};

class Trem{
    vector<Vagao*> vagoes;
    int forca;
public:
    Trem(int forca = 0){
        this->forca = forca;
    }
    ~Trem(){
        for(auto * vagao : vagoes)
            delete vagao;
    }
    bool addVagao(Vagao * vagao){
        if((int) vagoes.size() < forca){
            vagoes.push_back(vagao);
            return true;
        }
        return false;
    }

    bool embarcar(Emb * emb){
        for(auto* vagao : vagoes){
            if(vagao->embarcar(emb))
                return true;
        }
        return false;
    }
//    desembar(idPass);
    string toString(){
        stringstream ss;
        ss << "Trem: ";
        for(auto * vagao : vagoes)
            ss << vagao->toString() << " ";
        return ss.str();
    }
};

template<class T>
T read(stringstream& ss){
    T t;
    ss >> t;
    return t;
}

class Controller{
    Trem trem;
public:
    Controller(){}

    void shell(string line){
        stringstream ss(line);
        string op;
        ss >> op;
        if(op == "init"){ //_forca
            trem = Trem(read<int>(ss));
        }else if(op == "addvp"){
            Vagao * vagao = new VagaoPessoas(read<int>(ss));
            if(!trem.addVagao(vagao))
                delete vagao;
        }else if(op == "embp"){//nome
            Pass * pass = new Pass(read<string>(ss));
            if(!trem.embarcar(pass))
                delete pass;
        }else if(op == "show"){
            cout << trem.toString() << endl;
        }else
            cout << "fail: comando invalido" << endl;
    }

    void exec(){
        string line;
        while(true){
            getline(cin, line);
            cout << "$" << line << endl;
            if(line == "end")
                return;
            shell(line);
        }
    }
};

int main(){
    Controller cont;
    cont.exec();
}
/*
init 3
addvp 2
addvp 3
addvp 1
addvp 4
embp davi
embp rui
embp rufus
embp ioda
embp grievous
embp tim_maia
embp zeca









*/