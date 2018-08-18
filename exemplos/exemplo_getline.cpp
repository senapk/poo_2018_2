#include <iostream>
#include <sstream>

using namespace std;
int main(){
    string minha_vida;
    cout << "Conte suas dores gafanhoto, como chegaste ate aqui, termine com #\n";
    getline(cin, minha_vida, '#');
    cout << "muito bem, voce digitou " << minha_vida << endl;
    return 0;
}
