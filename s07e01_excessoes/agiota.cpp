#include <iostream>
#include <sstream>
using namespace std;

void shell(string line){
    stringstream in(line);
    string op;
    in >> op;
    if(op == "add"){
        in >> op;
        if(op == "cli"){
            string nome;
            string fullname;
            in >> nome;
            getline(in, fullname);
            agiota.add(Cliente(nome, fullname));
        }else if(op == "tr"){
            //adicionar transacao
        }
    }else if(op == "show"){
        in >> op;
        if(op == "cli"){
            //mostrar o cliente
        }else if(op == "tr"){
            //mostrar transacoes
        }
    }
}
