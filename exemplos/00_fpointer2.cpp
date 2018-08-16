#include <iostream>
#include <functional>
using namespace std;

int proc(int * vet, int size, function<int(int, int)> fun) {
    if(size < 2)
        return 0;
    int acc = vet[0]; //inicia acumulador
    for(int i = 1; i < size; i++)
        acc = fun(acc, vet[i]); //processa todos os elementos
    return acc;
}

int main () {
    int L[] = {1, 2, 3, 4, 5};
    int size = sizeof(L)/sizeof(int);
    cout << "Soma: " << proc(L, size, [](int x, int y){return x + y;}) << endl;
    cout << "Prod: " << proc(L, size, [](int x, int y){return x + y;}) << endl;
}