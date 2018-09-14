#ifndef PET_H
#define PET_H

#include <iostream>
#include <sstream>
using namespace std;

class Pet{
private:
    string nome;
    int energyMax, hungryMax, cleanMax; 
    int energy, hungry, clean;   
    int age; // {0};
    int diamond; // {0};
    bool alive {true};


public:
    Pet(string nome = "pet", int energyMax = 0, int hungryMax = 0, int cleanMax = 0);
    
    string getNome();  //declaracao
    void setNome(string nome){
        this->nome = nome;
    }
    int getEnergyMax(){
        return energyMax;
    }
    int getHungryMax(){
        return hungryMax;
    }
    int getCleanMax(){
        return cleanMax;
    }
    int getAge();

    string toString(){
        stringstream ss;
        ss << "N:" << nome << ", " 
           << "E:" << energy << "/" << energyMax << ", "
           << "H:" << hungry << "/" << hungryMax << ", "
           << "C:" << clean  << "/" << cleanMax  << ", "
           << "D:" << diamond << ", A:" << age;
        return ss.str();
    }

    void setEnergy(int value){
        if(value <= 0){
            this->alive = false;
            value = 0;
        }else if(value > energyMax){
            value = energyMax;
        }else
            energy = value;
    }

    bool testAlive(){
        if(alive)
            return true;
        cout << "fail: pet esta morto" << endl;
        return false;
    }

    void play(){
        if(!testAlive())
            return;
        setEnergy(energy - 2);
       /*  H - 1
        C - 3
        A + 1
        D + 1 */
    }

/*     eat(){
        E - 1
        H + 4
        C - 2
        A + 1
    }

    sleep(){
        if dif > 5
        E - max
        H - 1
        A + turno
    }

    clean(){
        E - 3
        H - 1
        A - 2
        C - max
    }
 */

};



#endif

#include "pet.hpp"
#include <iostream>

Pet::Pet(std::string nome, int energyMax, int hungryMax, int cleanMax):
    nome(nome), 
    energyMax(energyMax), hungryMax(hungryMax), cleanMax(cleanMax),
    energy(energyMax), hungry(hungryMax), clean(cleanMax){
    this->age = 0;
    this->diamond = 0;
}

string Pet::getNome(){
    return nome;
}

int Pet::getAge(){
    return age;
}

#include <iostream>

#include "pet.hpp"


using namespace std;

int main(){
    Pet p("Bixanuh", 15, 10, 300);
    p.play();
    cout << p.toString() << endl;
    p.play();
    cout << p.toString() << endl;
    p.play();
    cout << p.toString() << endl;
    p.play();
    p.play();
    p.play();
    p.play();
    p.play();

    return 0;
}