#include <iostream>
using namespace std;

//pos.h
class Pos{
public:
    int x, y;
    Pos(int x = 0, int y = 0):
        x(x), y(y){
    }
};
//Criatura.h
//#include "posicao.h"
struct Criatura{
    Pos posicao;
};

//main.cpp
//#include "criatura.h"
//#include "posicao.h"
int main(){
    Pos * pos_criatura;
    {
        Criatura jose;
        jose.posicao = Pos(4, 5);
        pos_criatura = &jose.posicao;
    }
    cout << pos_criatura->x << " " << pos_criatura->y << endl;
}