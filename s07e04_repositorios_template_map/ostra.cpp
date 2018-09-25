#include <iostream>
using namespace std;


template<typename T>
struct Ostra{
    T value;
    Ostra(T value = 0){
        this->value = value;
    }
    T getValue(){
        return value;
    }
};

int main(){
    Ostra<int> ostrai(5);
    cout << ostrai.getValue() << endl;
    return 0;
}