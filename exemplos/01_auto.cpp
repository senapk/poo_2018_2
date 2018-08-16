#include <cstdio>
#include <iostream>

int soma(int a, int b){
    return a + b;
}

int main(){
    auto x = 5; //sera inteiro
    auto b = x; //sera inteiro
    auto &c = x; //será uma referencia para x;
    const auto& d = x; //uma referencia constante para x
    auto res = soma(x, 3); //res sera inteiro

    c = 1; //x, c e d serao 1
    //d = 2; //erro de compilacao, d é const

    decltype(x) g; //g terá o mesmo tipo de x
    g = 3;

    auto y = "ovo";//y sera const char *
    auto z = std::string("cozido");//z sera string

    std::cout << x << b << c << d << res << g << y << z << std::endl;

    return 0;
}