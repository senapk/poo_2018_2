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
    return 0;
}