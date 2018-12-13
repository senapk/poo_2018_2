#include <functional>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//pattern observer

class Sistema{ //observado
public:
    vector<string> usuarios;

    vector<function<void(string)>> acoes;

    void registrar(function<void(string)> fn){
        acoes.push_back(fn);
    }

    void cadastrar(string user){
        auto it = std::find(usuarios.begin(), usuarios.end(), user);
            if(it == usuarios.end())
                usuarios.push_back(user);
    }

    void remover(string user){
        auto it = std::find(usuarios.begin(), usuarios.end(), user);
        if(it == usuarios.end())
            return;
        usuarios.erase(it);
        for(auto& fn : acoes)
            fn(user);
    }
};

class GerLogin{
    string current;
    Sistema * sistema;
public:
    GerLogin(Sistema * sist){
        current = "";
        sistema = sist;
        sistema->registrar([&](string username){
            if(username == current)
                current = "";
        });
    }
    void login(string user){
        auto & users = sistema->usuarios;
        if(std::find(users.begin(), users.end(), user) == users.end())
            return;
        current = user;
    }
    void logout(){
        current = "";
    }
    string getCurrent(){
        return "[" + current + "]";
    }
};


int main(){

    Sistema sist;
    GerLogin glog(&sist);
    vector<string> removidos;
    sist.registrar([&](string username){
        removidos.push_back(username);
    });

    sist.cadastrar("rui");
    sist.cadastrar("ana");
    sist.cadastrar("bia");
    sist.cadastrar("eva");
    sist.cadastrar("ivo");
    sist.cadastrar("uva");

    glog.login("rex");
    cout << glog.getCurrent() << "\n";
    glog.login("ana");
    cout << glog.getCurrent() << "\n";
    sist.remover("eva");
    sist.remover("bia");
    sist.remover("uva");
    cout << glog.getCurrent() << "\n";
    sist.remover("ana");

    cout << glog.getCurrent() << "\n";
    for(auto nome : removidos)
        cout << nome << " ";


}

