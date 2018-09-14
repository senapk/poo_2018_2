#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

class Item{
public:
    string nome;
    int peso;
    Item(string nome, int peso):
        nome(nome), peso(peso){
    }
    string toString(){
        return "[" + nome + ":" + to_string(peso) + "]";
    }
};

struct Jumento{
    int energia;
    int energiaMax;
    int km;
    vector<Item> lombo;
    int peso_total;
   
    Jumento(int enM = 0):
        energia(enM), energiaMax(enM), km(0){
    }

    void carregar(Item item){
        lombo.push_back(item);
        peso_total += item.peso;
    }

    void andar(int dist){
        //distancia maxima que pode andar
        int dist_max = energia/peso_total;
        if(dist_max > dist){
            energia -= dist/peso_total;
            return;
        }
        energia = 0;
        cout << "fail: o jumento andou " << dist_max << " e parou " << endl;
    }

    void alimentar(){
        energia += 1000;
    }

    string toString(){
        string saida = "energy:" + to_string(this->energia) 
                     + " km:" + to_string(km) ;
        for(auto item : lombo)
            saida += " " + item.toString();
        return saida;
    }
};

struct Controller{
    Jumento jumento;

    void shell(string line){
        stringstream in(line);
        string op;
        in >> op;
        if(op == "help")
            cout << "show, andar _dist, alimentar, carregar _nome _peso" << endl;
        else if(op == "init"){
            int energia;
            in >> energia;
            jumento = Jumento(energia);
        }
        else if(op == "alimentar")
            jumento.alimentar();
        else if(op == "andar"){
            int dist;
            in >> dist;
            jumento.andar(dist);
        }
        else if(op == "carregar"){
            string nome;
            int peso;
            in >> nome >> peso;
            jumento.carregar(Item(nome, peso));
        }
        else if(op == "show"){
            cout << jumento.toString() << endl;
        }
    }

    void exec(){
        string line;
        while(true){
            getline(cin, line);
            if(line == "end")
                break;
            shell(line);
        }
    }
};

int main(){
    Controller controller;
    controller.exec();
    return 0;
}
