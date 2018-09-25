/*
create, read, update, delete
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;


struct Pessoa{
    string nome;
    int idade;
    Pessoa(string nome = "", int idade = 0):
        nome(nome), idade(idade){
    }
    string toString(){
        return "[" + nome + ":" + to_string(idade) + "]";
    }
};

#include <map>
int main(){

    vector<int> vet = {1, 4, 3, 65, 7, 2, 7, 9};

    vector<int>::iterator it = std::find(vet.begin(), vet.end(), 65);
    if(it != vet.end())
    
    for(auto it = vet.begin(); it != vet.end(); it++){
        *it += 1;
    }

    map<string, Pessoa> rep;
    rep["maria"] = Pessoa("Maria Lima", 45);
    rep["jose"] = Pessoa("Jose almeida", 70);
    rep["lucas"] = Pessoa("Lucas Pinho", 12);
    rep.insert(make_pair("david", Pessoa("David Sena", 34)));

    cout << rep.at("jose").nome << endl;

    for(pair<string, Pessoa> par : rep){
        cout << "key: " << par.first << " valor: " << par.second.toString() << endl;
    }
    rep.erase("lucas");
    cout << "Depois de kicar o lucas" << endl;
    for(pair<string, Pessoa> par : rep){
        cout << "key: " << par.first << " valor: " << par.second.toString() << endl;
    }

    return 0;
}

