#include <iostream>
#include <cstdio>

int x = 11;
int main () {
    int x = 9;
    std::cout << x << " " << ::x << std::endl;
    printf("%d %d\n", x, ::x);
}