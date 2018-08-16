#include <vector>
#include <iostream>
#include <cstdio>

void show(std::vector<int> vet){
    printf("[ ");
    for(int i = 0; i < (int) vet.size(); i++)
        printf("%d ", vet[i]);
    puts("]");
}

int main(){
    {
        std::vector<int> vet;
        vet.push_back(1);
        vet.push_back(3);
        vet.push_back(5);
        show(vet);
        vet.pop_back();//removeu o 5
        vet.pop_back();//removeu o 3
        show(vet);
    }
    {
        std::vector<int> vet({7, 3, 5}); //construtor com valores
        show(vet);
    }
    {
        std::vector<int> vet(10, 5); //construtor (qtd, valor_default)
        show(vet);
    }
    {
        std::vector<int> vet(5, 6);
        std::vector<int> copia(vet);//construtor de copia 
        show(copia);
    }
    {
        std::vector<int> vet({7, 3, 5, 8, 6});
        
        for(int &c : vet) //for range
            c = c - 2;
        show(vet);

        for(auto it = vet.begin(); it != vet.end(); it++) //for interador
            *it = *it + 100;
        show(vet);
    }
    {
        std::vector<int> vet({7, 3, 5, 8, 6});
        printf("%d %d", vet.front(), vet.back());//referencia ao primeiro e ultimo
        
        for(int i = 0; i < (int) vet.size(); i++)
            if(vet[i] == 5){
                vet.erase(vet.begin() + i); //remove o 5, elemento indice 2
                break;
            }
    }
    {
        std::vector<int> vet({4, 2, 4, 3, 4, 4, 6, 7, 4});
        for(int i = (int) vet.size() - 1; i >= 0; i--)
            if(vet[i] == 4)
                vet.erase(vet.begin() + i);
    }



    return 0;
}