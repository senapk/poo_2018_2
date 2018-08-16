#include <iostream>
using namespace std;

int main(){
    int i;
    char c;
    float f;
    string s;
    string line;
    cout << "Digite um int, um char, um float e uma palavra" << endl;
    cin >> i >> c >> f >> s;
    cin.ignore();
    cout << "Digite uma frase" << endl;
    getline(cin, line, '\n');

    cout << i << "-" << c << "-" << f << "-" << s << "-" << line << endl;
    return 0;
}