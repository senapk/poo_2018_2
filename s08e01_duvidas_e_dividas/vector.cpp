#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cctype>

using namespace std;

int compara_string(string one, string two){
    reverse(one.begin(), one.end());
    reverse(two.begin(), two.end());
    return one < two;
}

int main(){
    vector<string> frutas = {"banana", "uva", "urubu", "pera", "pessego", "maca", "ovo"};

    //for indexado - acesso aleatório
    for(size_t i = 0; i < frutas.size(); i++){
        //frutas[i][0] -= 'a' - 'A';
        frutas[i][0] = toupper(frutas[i][0]);
        frutas[i].front() = toupper(*frutas[i].begin());
    }

    //for range 
    for(auto& elem : frutas)
        cout << elem << " ";
    cout << endl;
/*
    frutas.begin() //iterador para o comeco
    frutas.end() //iterator para o final(abismo)
    frutas.front() //referencia para o primeiro elemento
    frutas.back() //referencia para o ultimo elemento
*/

    for(auto it = frutas.begin(); it != frutas.end(); it++)
        it->back() = toupper(it->back());
    
    for(auto& elem : frutas)
        cout << elem << " ";
    cout << endl;
/*
    for(size_t i = frutas.size() - 1; i >= 0; i--){
        if(frutas[i].front() == 'U'){
            frutas.erase(frutas.begin() + i);
        }
    }
*/
    for(auto it = frutas.begin(); it != frutas.end();){
        if(it->front() == 'A'){
            it = frutas.erase(it);
        }else{
            it++;
        }
    }

    auto it = std::find(frutas.begin(), frutas.end(), "MacA");
    if(it != frutas.end())
        *it = "maca mordida";

    std::sort(frutas.begin(), frutas.end(), compara_string);


    for(auto elem : frutas)
        cout << elem << " ";
    cout << endl;
    return 0;
}