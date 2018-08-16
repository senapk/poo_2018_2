#include <iostream>

using namespace std;

struct Cat {
    string name;
    int * x;
    Cat(string name){
        x = new int(0);
        this->name = name;
        cout << name << " " << *x << " nasceu\n";
    }
    ~Cat(){
        delete x;
        cout << name << " morreu" << endl;
    }
};

int main(){
    Cat * elvis;
    Cat flock("flock");
    {
        Cat quemia("quemia");
        elvis = new Cat("elvis");
    }
    delete elvis;
    Cat meke("meketrefe");
    return 0;
}













