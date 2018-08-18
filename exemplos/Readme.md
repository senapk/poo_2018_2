# Introdução ao CPP

1\.  [Compilando](#compilando)  
2\.  [Escopo](#escopo)  
3\.  [Static](#static)  
4\.  [Args](#args)  
5\.  [Memória dinãmica](#memóriadinãmica)  
6\.  [C - Funções](#c-funções)  
7\.  [Referências Dummy](#referênciasdummy)  

<a name="compilando"></a>

## 1\. Compilando
- O seu código deve ter a extensão .cpp.
- Ele pode ser compilado com o g++. 
    - No Windows instale o Mingw.
    - No linux, só instalar o pacote básico de desenvolvimento.
        - Ubuntu: sudo apt-get install build-essential
        - Arch: sudo pacman -S base-devel
- O seguinte Makefile pode ser utilizado para compilar e executar arquivos .cpp

```
CPPFLAGS = -std=c++14 -Wall
%:
	g++ $(CPPFLAGS) $@.cpp -o exe_$@
	@ ./exe_$@
```

- Após isso, se o arquivo se charmar soma.cpp, digite 

        make soma


***
<a name="escopo"></a>

## 2\. Escopo

- Protótipo, argumentos, tipo de retorno
- Escopo Global e Local
- Operador de Resolução de Escopo (::)

```c++
#include <iostream>
#include <cstdio>

int x = 11;
int main () {
    int x = 9;
    std::cout << x << " " << ::x << std::endl;
    printf("%d %d\n", x, ::x);
}
```

***
<a name="static"></a>

## 3\. Static

- Prefixadas pela palavra chave static
- Uma função declarada como estática só é acessı́vel dentro do arquivo onde foi criada.
- Variáveis estáticas são sensı́veis ao contexto.

```c++
#include <cstdio>

static int global_mas_local = 5;

static void fnc () { //funcao local
    static int x = 0; //variavel persistente
    x++;
    printf ("%d ", x);
}

int main () {
    printf("%d ", global_mas_local);
    fnc ();
    fnc ();
    fnc ();
}
```

***
<a name="args"></a>

## 4\. Args

- argc é a quantidade de argumentos
- argv é a lista de argumentos

```c++
# include <iostream>
# include <cstdlib>
int main(int argc , char *argv []) {
    int soma = 0;
    for (int k = 0; k < argc; k++)
        soma += std::atoi(argv[k]);
    std::cout << soma << std::endl;
}
```

***
<a name="memóriadinãmica"></a>

## 5\. Memória dinãmica

- Memória dinâmica é alocada e desalocada com new e delete

```c++
#include <cstdlib>
int main () {
    int *k = new int(4);//heap
    int  ks = 4;//stack
    int *u = new int [20];//heap
    int  us[20];//stack

    for (int i = 0; i < 20; i++)
        u[i] = i * i + 1;
    
    delete k;
    delete [] u; //devolver vetor
}
```

***
<a name="c-funções"></a>

## 6\. C - Funções

- Ponteiros para função do jeito C de ser
 
```c++
#include <iostream>
using namespace std;

int proc(int * vet, int size, int (*fun)(int ,int) ) {
    if(size < 2)
        return 0;
    int acc = vet[0]; //inicia acumulador
    for(int i = 1; i < size; i++)
        acc = fun(acc, vet[i]); //processa todos os elementos
    return acc;
}

int soma(int x, int y) { return x+y; }
int mult(int x, int y) { return x*y; }

int main () {
    int L[] = {1, 2, 3, 4, 5};
    int size = sizeof(L)/sizeof(int);
    cout << "Soma: " << proc(L, size, soma) << endl;
    cout << "Prod: " << proc(L, size, mult) << endl;
}
```

 ***
 ## C++ - Funções

- Jeito c++ de ser de passar funcoes c++11

```c++
#include <iostream>
#include <functional>
using namespace std;

int proc(int * vet, int size, function<int(int, int)> fun) {
    if(size < 2)
        return 0;
    int acc = vet[0]; //inicia acumulador
    for(int i = 1; i < size; i++)
        acc = fun(acc, vet[i]); //processa todos os elementos
    return acc;
}

int main () {
    int L[] = {1, 2, 3, 4, 5};
    int size = sizeof(L)/sizeof(int);
    cout << "Soma: " << proc(L, size, [](int x, int y){return x + y;}) << endl;
    cout << "Prod: " << proc(L, size, [](int x, int y){return x + y;}) << endl;
}
```

***
<a name="referênciasdummy"></a>

## 7\. Referências Dummy

 - Uso de variáveis dummy static para retornar referências

```c++
#include <iostream>

int v[5];

int& get(int k) {
    static int dummy = -1;
    return (k >=0 && k < 5) ? v[k] : dummy ;
}

int main() {
    for (int k = 0; k < 10; k++) 
        get(k) = 2 * k + 1;
    for (int k = 0; k < 10; k++)
        std::cout << get(k) << " ";
    std::cout << std::endl;
}
```
