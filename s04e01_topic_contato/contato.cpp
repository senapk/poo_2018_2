#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

struct Fone{
    string id;
    string fone;
    Fone(string id = "", string fone = ""):
        id(id), fone(fone)
    {
    }
    string toString(){
        stringstream ss;
        ss << "[" << id << ":" << fone << "]";
        return ss.str();
    }
};

class Contato{
private:
    string id;
    vector<Fone> fones;
public:
    Contato(string id = "zeh maneh"):
        id(id)
    {
    }

    void add(Fone fone){
        for(auto telefone : fones)
            if(telefone.id == fone.id){
                cout << "failure: id duplicado";
                return;
            }
        fones.push_back(fone);
    }

    void rm(string foneId){
        for(int i = 0; i < (int) fones.size(); i++)
            if(fones[i].id == foneId){
                fones.erase(fones.begin() + i);
            }
    }

    string toString(){
        stringstream ss;
        ss << id << " ";
        for(auto fone : fones)
            ss << fone.toString();
        return ss.str();
    }
};

struct Controller{
    Contato cont;

    string shell(string line){
        stringstream in(line);
        stringstream out;
        string op;
        in >> op;
        if(op == "help")
            out << "show; init _nome; add _id _fone; end";
        else if(op == "init"){
            string nome;
            in >> nome;
            cont = Contato(nome);
            out << "success";
        }else if(op == "show"){
            out << cont.toString();
        }else if(op == "add"){
            string id, fone;
            in >> id >> fone;
            cont.add(Fone(id, fone));
        }else if(op == "rm"){
            string id;
            in >> id;
            cont.rm(id);
        }
        return out.str();
    }

    void exec(){
        string line;
        while(true){
            getline(cin, line);
            if(line == "end")
                break;
            cout << line << endl;
            cout << "  " << shell(line) << endl;
        }
    }
};

int main(){
    Controller controller;
    controller.exec();
    return 0;
}