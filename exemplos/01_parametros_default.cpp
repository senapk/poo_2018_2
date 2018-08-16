#include <iostream>
#include <sstream>

int f1(int a, int b, int c){
    return a + b + c; 
};


int f2(int a, int b = 2, int c = 4){
    return a + b + c; 
};

int f3(int a, int b, int c = 4){
    return a + b + c;
}

/* 
int f4(int a = 1, int b, int c = 4){ //erro de compilacao
    return a + b + c;
}
 */

//imprime o texto tabulado com uma quantidade de espacos
std::string tabular(std::string texto, int espacos = 0){
    //std::string delta = std::string(espacos, ' ');
    std::string delta = std::string(espacos, ' ');
    std::stringstream ss;
    ss << delta;
    for(const char& c : texto)
        if(c == '\n')
            ss << '\n' << delta;
        else
            ss << c;
    return ss.str();
}

int main(){
    std::string teste = "hoje eu fui comprar\nbro\nco\nlis bro\nbro";
    std::cout << tabular(teste) << std::endl;
    std::cout << tabular(teste, 4) << std::endl;
    return 0;
}