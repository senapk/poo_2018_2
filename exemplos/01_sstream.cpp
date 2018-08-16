#include <iostream>
#include <sstream>

using namespace std;

int main(){
    string produto = "refrigerante de uva; 4 5.60 frios U";

    string nome;
    int qtd;
    float preco;
    string setor;
    char tipo;

    //lendo de stream
    stringstream ss(produto);

    getline(ss, nome, ';');
    ss >> qtd >> preco >> setor >> tipo;
    

    //escrevendo em stream
    stringstream sout;
    sout << nome << "-" << qtd << "-" << preco << "-" << setor << "-" << tipo << endl;
    cout << sout.str();
    
    return 0;
}