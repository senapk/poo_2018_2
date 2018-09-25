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

struct Pet{
    string nome;
    string raca;
    Pet(string nome, string raca):
        nome(nome), raca(raca){
    }
};

template<typename T>
struct Repositorio{
    map<string, T> data;

    void add(string key, T elem){
        if(!exists(key))
            data[key] = elem;
        else
            throw "chave duplicada";
    }
    
    bool exists(string key){
        return data.find(key) != data.end();
    }

    T& get(string key){
        auto it = data.find(key);
        if(it != data.end())
            return it->second;
        else
            throw "chave nao existe";
    }

    void rm(string key){
        if(!exists(key))
            throw "chave nao existe";
        data.erase(key);
    }

    vector<T> getValues(){
        vector<T> vp;
        for(auto& par : data)
            vp.push_back(par.second);
        return vp;
    }

    vector<string> getKeys(){
        vector<string> vp;
        for(auto& par : data)
            vp.push_back(par.first);
        return vp;
    }
};


#include <map>
int main(){
    Repositorio<Pessoa> rpes;
    //Repositorio<Pet> rpet;

    rpes.add("david", Pessoa("David Sena", 50));
    try{
        rpes.add("david", Pessoa("David", 50));
    }catch(const char* e){
        cout << e << endl;
    }
    rpes.add("lucar", Pessoa("Lucas Sena", 5));
    rpes.add("lulua", Pessoa("Lulua", 5));
    
    for(auto& pessoa : rpes.getValues())
        cout << pessoa.toString() << endl;

    rpes.rm("lucar");

    for(auto& pessoa : rpes.getValues())
        cout << pessoa.toString() << endl;
    try{
        rpes.rm("luana");
    }catch(const char* e){
        cout << e << endl;
    }

    return 0;



}

