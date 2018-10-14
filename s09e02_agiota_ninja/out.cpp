#include <iostream>
#include <sstream>
using namespace std;

int main(){
    stringstream ss;
    ss << "amigo " << 4 << " " << 4.5 << endl;
    cout << ss.str();
}