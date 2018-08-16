#include <iostream>

int main(){
    {
        std::string s = "as"; //atribuicao funciona como esperado
        s = s + " arvores"; //concatenar
        s += " somos nozes";
        std::cout << s << std::endl;
        std::cout << s.size() << std::endl;
    }
    {
        std::string s("as arvores"); //construtor
        //s( "as arveris");//erro, construtor so pode ser utilizado na criacao
        std::cout << s << std::endl;
    }
    {
        std::string s("as arvores");
        s[0] = 'A'; //acesso indexado
        //s( "arvores");//erro, construtor so pode ser utilizado na criacao
        std::cout << s << std::endl;
    }
    {
        std::string s("as arvores somos nozes");
        for(int i = 0; i < (int) s.size(); i++)
            if(s[i] != ' ')
                s[i] += 'A' - 'a'; //mudando pra maiusculo
        std::cout << s << std::endl;
    }
    {
        std::string s("as arvores");
        s = s.substr(3); //de 3 ate o fim
        //s( "arvores");//erro, construtor so pode ser utilizado na criacao
        std::cout << s << std::endl;
    }
    {
        std::string s(10, '#'); //construtor(qtd, char default)
        std::cout << s << std::endl;
    }

    return 0;
}