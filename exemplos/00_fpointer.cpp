#include <iostream>
using namespace std;

int proc(int * vet, int size, int (*fun)(int ,int) ) {
    if(size < 2)
        return 0;
    int acc = vet[0]; //inicia acumulador
    for(int i = 1; i < size; i++)
        acc = fun(acc, vet[i]); //processa todos os elementos
    return acc;
}

int soma(int x, int y) { return x+y; }
int mult(int x, int y) { return x*y; }

int main () {
    int L[] = {1, 2, 3, 4, 5};
    int size = sizeof(L)/sizeof(int);
    cout << "Soma: " << proc(L, size, soma) << endl;
    cout << "Prod: " << proc(L, size, mult) << endl;
    return 0;
}