#include <iostream>

//significado
// esquerda(lvalue)   = direita(rvalue)
// lugar              = valor

// significado de &
// & no lvalue significa referencia de
// & no rvalue significa endereco de

// significado de *
// * na declaração: ponteiro para
// * no uso : dereferência

//recebe x por cópia
//o elemento precisa ser copiável
//nao há alteração no elemento original
void fcopia(int x){
    x = 0;
}

//recebe x por referencia
//o elemento precisa ser uma variável, nao apenas um valor
//o elemento precisa ser alterável, não uma constante
void fref(int &x){
    x = 0;
}

//recebe x por referencia constante
//o mais restritivo, qualquer coisa pode ser passada dessa forma
void frefconst(const int &x){
    int y = x + 2;
    (void) y;
    //x = 0; //erro de compilacao
}

//recebe x por endereco
//vetores e char * são passado assim
void fend(int *x){
    *x = 0;
}

//raro, mas existe
//O primeiro const informa que o ponteiro é constante, 
//    ou seja, não pode referenciar outros lugares da memória.
//O segundo const informa que valor apontado é constante, 
//    ou seja, não pode ser alterado.
void fendconst(const int * const x){
    // x = nullptr; //erro de compilacao, x não pode referenciar outra posicao
    //*x = 4; //erro de compilacao, o elemento apontado por x não pode mudar de valor
    int y = *x + 3;
    (void) y;
}

int main(){
    const int i = 5; //i nao pode ser modificado
    // i = 7; erro de compilacao
    (void) i;

    int a = 5;
    int &b = a; //b é uma referencia para a (mesmo endereço)
    //int &c = 5; //preciso de um lugar

    b = 7; //a também se torna 7, ja que ambos sao a mesma variável
    
    int* c = &b; //c é um ponteiro que recebeu o endereço de b

    *c = 1; //todas as a e b são 1, pois o elemento que c apontava recebe 1
    
    c = nullptr;

    fcopia(1);
    //fref(2); //erro, 2 não é um lvalue
    fref(b);
    frefconst(1);
    frefconst(2);
    fend(&a);
    //fend(5);//erro, 5 não é um lvalue
    fendconst(&a);

    //modo gambi
    fref((int){5}); //criando memoria temporaria
    fend(&(int){5}); //passando memoria temporaria
    return 0;
}