#include <cstdlib>
int main () {
    int *k = new int(4);//heap
    int  ks = 4;//stack
    int *u = new int [20];//heap
    int  us[20];//stack

    for (int i = 0; i < 20; i++)
        u[i] = i * i + 1;
    
    delete k;
    delete [] u; //devolver vetor
}