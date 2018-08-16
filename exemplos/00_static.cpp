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