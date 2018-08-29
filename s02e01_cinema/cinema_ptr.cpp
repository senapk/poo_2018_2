#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

struct Cliente{
    string id;
    string fone;

    Cliente(string id = "fulano", string fone = "0000"){
        this->id = id;
        this->fone = fone;
    }
    string toString(){
        stringstream ss;
        ss << this->id << ":" << this->fone;
        return ss.str();
    }
};

struct Sala{
    vector<Cliente*> cadeiras;

    /*
    Sala(int qtd = 0){
        for(int i = 0; i < qtd; i++)
            cadeiras.push_back(nullptr);
    }*/

    Sala(int qtd = 0):
        cadeiras(qtd, nullptr)
    {
    }

   ~Sala(){
        for(Cliente * cli : cadeiras)
            delete(cli);
    }

    bool reservar(Cliente * cliente, int ind){
        int qtd = cadeiras.size();
        if((ind < 0) || (ind >= qtd)){
            cout << "fail: essa cadeira nao existe" << endl;
            return false;
        } 
        if(cadeiras[ind] != nullptr){ 
            cout << "fail: essa cadeira ja esta ocupada" << endl; 
            return false;
        }
        for(int i = 0; i < (int) cadeiras.size(); i++){
            if((cadeiras[i] != nullptr) && (cadeiras[i]->id == cliente->id)){
                cout << "fail: voce ja esta no cinema" << endl;
                return false;
            }
        }
        cadeiras[ind] = cliente;
        return true;
    }

    string toString(){
        stringstream ss;
        ss << "[ ";
        for(Cliente * cliente : cadeiras)
            if(cliente == nullptr)
                ss << "- ";
            else
                ss << cliente->toString() << " ";
        ss << "]";
        return ss.str();
    }
};

int main(){ 
    Sala sala;
    string op;
    while(true){
        cin >> op;
        if(op == "end")
            break;
        if(op == "help"){
            cout << "show; init _qtd; reservar _id _fone _ind; cancelar _id" << endl;
        }else if(op == "show"){
            cout << sala.toString() << endl;
        }else if(op == "init"){
            int qtd;
            cin >> qtd;
            sala = Sala(qtd);
            cout << "sala criada com " << qtd << " cadeiras" << endl;
        }else if(op == "reservar"){
            string nome, fone;
            int ind;
            cin >> nome >> fone >> ind;
            if(sala.reservar(new Cliente(nome, fone), ind))
                cout << "done" << endl;
        }
    }
}