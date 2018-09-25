#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Pessoa{
    string nome;
    int idade;
    Pessoa(string n, int i){
        nome = n;
        idade = i;
    }
};

bool compara_idade(Pessoa one, Pessoa other){
    if(one.idade == other.idade)
        return one.nome < other.nome;
    return one.idade < other.idade;
}

bool compara_nome(Pessoa one, Pessoa other){
    return one.nome < other.nome;
}


int main(){
//    vector<int> vet = {3, 5, 4, 1, 5, 6, 5, 2};
    

    vector<Pessoa> vp = {Pessoa("ana", 3), Pessoa("carla", 3), 
                         Pessoa("bruno", 3), Pessoa("davi", 2)};

    std::sort(vp.begin(), vp.end(), compara_idade);
    for(auto elem: vp)
        cout << "[" << elem.nome << ", " << elem.idade << "]";
    cout << endl;

    std::sort(vp.begin(), vp.end(), compara_nome);
    for(auto elem: vp)
        cout << "[" << elem.nome << ", " << elem.idade << "]";
    cout << endl;
    return 0;
}