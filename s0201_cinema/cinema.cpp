#include <iostream>
#include <vector>
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
};

struct Sala{
    vector<Cliente> cadeiras;
    Sala(int qtd){
        for(int i = 0; i < qtd; i++)
            cadeiras.push_back(Cliente("", "", false));
    }
};

int main(){
    Cliente davi("davi", "3131");
    davi.id = "davi";
    Cliente lucas;
}