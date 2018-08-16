# include <iostream>
# include <cstdlib>
int main(int argc , char *argv []) {
    int soma = 0;
    for (int k = 0; k < argc; k++)
        soma += std::atoi(argv[k]);
    std::cout << soma << std::endl;
}