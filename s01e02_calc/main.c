#include <stdio.h>
#include <stdbool.h>
#include <string.h>

//calc.h
typedef struct{
    int bateria;
    int limiteBateria;
} Calc;

void charge(Calc * calc, int carga);
float soma(Calc * calc, float a, float b, bool * deu_certo);
float div(Calc * calc, float a, float b);
bool gastarBateria(Calc * calc);

//calc.c

void charge(Calc * calc, int carga){
    calc->bateria += carga;
    if(calc->bateria > calc->limiteBateria)
        calc->bateria = calc->limiteBateria;
}
float soma(Calc * calc, float a, float b, bool * deu_certo){
    if(gastarBateria(calc)){
        *deu_certo = true;
        return a + b;
    }
    *deu_certo = false;
    return 0;
}

float div(Calc *calc, float a, float b){
    if(gastarBateria(calc)){
        if(b == 0){
            puts("fail: nao posso dividir por 0");
            return 0;
        }
        return a/b;
    }
    return 0;
}

int main(){
    char op[10];
    Calc calc = {2, 5};
    while(true){
        scanf("%s", op);
        if(strcmp(op, "help") == 0){
            puts("soma _a _b; div _a _b; show; charge _carga");
        }else if(strcmp(op, "soma") == 0){
            float a, b;
            bool deu_certo;
            scanf("%f %f", &a, &b);
            float resp = soma(&calc, a, b, &deu_certo);
            if(deu_certo)
                printf("  = %f\n", resp);
        }
        else if(strcmp(op, "div") == 0){
            float a, b;
            scanf("%f %f", &a, &b);
            printf("  = %f\n", div(&calc, a, b));
        }else if(strcmp(op, "charge") == 0){
            int a;
            scanf("%d", &a);
            charge(&calc, a);
        }else if(strcmp(op, "show") == 0){
            printf("  bateria = %d\n", calc.bateria);
        }else if(strcmp(op, "fim"))
            break;
    }
    return 0;
}
