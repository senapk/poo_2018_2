#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

struct Cliente{
    bool existe;
    string id;
    string fone;
/*     Cliente(){
        id = "xuxa";
        fone = "ilarie";
    } */
    Cliente(string id = "fulano", string fone = "0000", bool existe = true){
        this->existe = existe;
        this->id = id;
        this->fone = fone;
    }
    string toString(){
        stringstream ss;
        if(!existe)
            ss << "-";
        else
            ss << this->id << ":" << this->fone;
        return ss.str();
    }
};

struct Sala{
    vector<Cliente*> cadeiras;

    Sala(int qtd = 0){
        for(int i = 0; i < qtd; i++)
            cadeiras.push_back(Cliente("", "", false));
    }

    bool reservar(Cliente cliente, int ind){
        int qtd = cadeiras.size();
        if((ind < 0) || (ind >= qtd)){
            cout << "fail: essa cadeira nao existe" << endl;
            return false;
        } 
        if(cadeiras[ind].existe){ 
            cout << "fail: essa cadeira ja esta ocupada" << endl; 
            return false;
        }
        for(int i = 0; i < (int) cadeiras.size(); i++){
            if(cadeiras[i].existe && (cadeiras[i].id == cliente.id)){
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
        for(Cliente cliente : cadeiras)
            ss << cliente.toString() << " ";
        ss << "]";
        return ss.str();
    }
};

int main(){
    Sala sala;
    string op;
    while(true){
        cin >> op;
        if(op == "show"){
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
            if(sala.reservar(Cliente(nome, fone), ind))
                cout << "done" << endl;
        }
    }
}