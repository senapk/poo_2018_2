#include <iostream>
#include <cstdio>
#include <clocale>
#include <sstream>

using namespace std;

struct Carro{
    int pssgr; // Passageiros
    int limPssg; // limite de Passageiros
    float tanq; // tanque
    float limTanq; // limite do tanque
    float km; // quantidade de quilometragem

    Carro(int pssgr = 0, int limPssg = 2, float tanq = 0,float limTanq = 10,float km = 0){
        this->pssgr = pssgr; // Passageiros
        this->limPssg = limPssg; // limite de Passageiros
        this->tanq = tanq; // tanque
        this->limTanq = limTanq; // limite do tanque
        this->km = km; // quantidade de quilometragem
    }

    string toString(){
        stringstream saida;
        saida << "pass: " << pssgr << " fuel: " << tanq << " Km: " << km; //nao endl
        return saida.str();
    }

    bool inPsger(){
        if (pssgr < limPssg){
            pssgr += 1;
            return true;
        }
        cout << "  fail: limite de pessoas atingido no carro" << endl;
        return false;
    }

    bool outPsger(){
        if (pssgr > 0){
            pssgr-=1;
            return true;
        }
        cout << "  fail: nao ha ninguem no carro" << endl;
        return false;
    }
    
    void fuel(float qtdGas){
        tanq += qtdGas;
//        tanq = (tanq > limTanq) ? limTanq : tanq;
        if(tanq > limTanq)
            tanq = limTanq;
    }

    bool drive (float km){
        if(this->pssgr == 0){
            puts("  fail: do not have passager in the car");
        }
        else if(this->tanq == 0 ){
            puts("  fail: fuel not to endure the travel");
        }
        else if(this->tanq < (km / 10)){
            puts("  fail: fuel not to endure the travel");
        }else{
            this->tanq = tanq - km / 10;
            this->km = this->km + km;
            return true;
        }
        return false;
    }    
};



int main(){
    setlocale(LC_ALL, "Portuguese");
    
    Carro car;
    string op;

    while(1){
        cin >> op;
        cout << op << endl; 
        if(op == "fim")
            break;
        if(op == "help"){
            cout<<"  in; out; show; fuel; drive;\n";
        }
        else if(op == "in"){
            if(car.inPsger())
                puts("  done");
        }else if(op == "out"){
            if(car.outPsger())
                puts("  done");
        }else if(op == "show"){
            cout << "  " << car.toString() << endl;
        }else if (op == "drive"){
            float km;
            cin >> km;
            if(car.drive(km))
                puts("  done");
        }else if (op == "fuel"){
            float gas;
            cin >> gas;
            car.fuel(gas);
            puts("  done");
        }
    }
    return 0;
}

