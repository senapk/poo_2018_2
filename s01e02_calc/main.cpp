#include <stdio.h>

#include <iostream>
using namespace std;

struct Calc{
    int bateria;
    int limiteBateria;

    void charge(int carga){
        bateria += carga;
        if(bateria > limiteBateria)
            bateria = limiteBateria;
    }
    float soma(float a, float b, bool * deu_certo){
        *deu_certo = false;
        if(!gastarBateria())
            return 0;
        *deu_certo = true;
        return a + b;
    }
    float div(float a, float b, bool * deu_certo){
        *deu_certo = false;
        if(!gastarBateria())
            return 0;
        if(b == 0){
            puts("  fail: nao posso dividir por 0");
            return 0;
        }
        *deu_certo = true;
        return a/b;
    }
    bool gastarBateria(){
        if(bateria > 0){
            this->bateria -= 1;
            return true;
        }
        puts("  fail: bateria insuficiente");
        return false;
    }
};

int main(){
    string op;
    Calc calc = {2, 5};
    while(true){
        cin >> op;
        if(op == "help"){
            puts("soma _a _b; div _a _b; show; charge _carga");
        }else if(op == "soma"){
            float a, b;
            bool deu_certo;
            scanf("%f %f", &a, &b);
            float c = calc.soma(a, b, &deu_certo);
            if(deu_certo)
                printf("  = %f\n", c);
        }
        else if(op == "div"){
            float a, b;
            bool deu_certo;
            scanf("%f %f", &a, &b);
            float c = calc.div(a, b, &deu_certo);
            if(deu_certo)
                printf("  = %f\n", c);
        }else if(op == "charge"){
            int a;
            scanf("%d", &a);
            calc.charge(a);
        }else if(op == "show"){
            printf("  bateria = %d\n", calc.bateria);
        }else if(op == "fim")
            break;
    }
    return 0;
}