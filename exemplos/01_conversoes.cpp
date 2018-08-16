#include <sstream> //stringstream
#include <iostream>
int main(){
    //para string
    int i = 4;
    float f = 56;
    char c = 't';

    //forma 1: usando o to_string do c++11
    std::string saida = "" + std::to_string(i) + "\n"
                           + std::to_string(f) + "\n"
                           + std::to_string(c) + "\n"//converte para 116(asc)
                           + std::string(1, c);

    //forma 2: usando o stringstream <sstream>
    return 0;
}