#include <iostream>
#include <sstream>
#include <iomanip> //setprecision
using namespace std;

struct Calc{
    int bateria;
    int limiteBateria;

    Calc(){
        this->limiteBateria = 5;
        this->bateria = 0;
    }
    void charge(int carga){
        bateria += carga;
        if(bateria > limiteBateria)
            bateria = limiteBateria;
    }
    void gastarBateria(){
        if(bateria == 0)
            throw "fail: bateria insuficiente";
        this->bateria -= 1;
    }
    int soma(int a, int b){
        gastarBateria();
        return a + b;
    }
    int div(int a, int b){
        gastarBateria();
        if(b == 0)
            throw "fail: divisao por zero";        
        return a/b;
    }
    string toString(){
        return "battery = " + to_string(this->bateria);
    }
};

struct Controller{
    Calc calc;

    void shell(string line){
        stringstream in(line);
        string op;
        in >> op;
        if(op == "help"){
            cout << "sum _a _b; div _a _b; show; charge _carga; end\n";
        }else if(op == "sum"){
            int a, b;
            in >> a >> b;
            cout << calc.soma(a, b) << endl;
        }else if(op == "div"){
            int a, b;
            in >> a >> b;
            cout << calc.div(a, b) << endl;
        }else if(op == "charge"){
            int charge;
            in >> charge;
            calc.charge(charge);
        }else if(op == "show"){
            cout << calc.toString() << endl;
        }else 
            cout << "fail: comando invalido" << endl;
    }

    void exec(){
        string line;
        while(true){
            getline(cin, line);
            cout << "$" << line << endl;
            if(line == "end")
                break;
            try{
                shell(line);
            }catch(const char* e){
                cout << e << endl;
            }
        }
    }
};

int main(){
    Controller c;
    c.exec();
    return 0;
}