#include <iostream>

template <typename T>
T read(stringstream& ss){
    T x;
    ss >> x;
    return x;
}

void comprar(string nome, int qtd, float preco){

}

int main(){
    int i = 0;
    int a = i++ + --i;
    strinstream ss("banana 15 5.6");
    string nome = read<string>(ss);
    int qtd = read<int>(ss);
    float preco = read<float>(ss);
    comprar(read<string>(ss), read<int>(ss), read<float>(ss));



}