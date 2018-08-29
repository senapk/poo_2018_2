#include <iostream>
#include <vector>

using namespace std;

struct Cat {
    string name;
    int * idade;
    Cat(string name = "Fulano", int idade = 0){
        this->idade = new int(idade);
        this->name = name;
        cout << name << " " << *this->idade << " nasceu\n";
    }
/*     Cat(const Cat &other){
        name = other.name;
        idade = new int(*other.idade);
    } */
    ~Cat(){
        cout << name << " " << idade << " morreu" << endl;
        delete idade;
        
    }
};

int main(){
/*     Cat * elvis;
    Cat flock("flock");
    {
        Cat quemia("quemia");
        elvis = new Cat("elvis");
    }
    delete elvis;
    Cat meke("meketrefe"); */
    Cat * elvis = new Cat("Elvis Presley");
    {
        Cat chana("Chana");
    }
    delete elvis;
    elvis = nullptr;
    //cout << elvis->name << " nao morrerei " << endl;
    Cat guida("Margarida");
    Cat cehsar("Cehsar");

    Cat um("um");

    vector<Cat> vet;
    vet.push_back(um);
    vet.push_back(um);
    vet.push_back(um);
    vet.pop_back();
    vet.pop_back();

    return 0;
}













