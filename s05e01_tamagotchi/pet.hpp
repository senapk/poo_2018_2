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
    
    void setValue(int value, int &target, int limit){
        if(value <= 0){
            this->alive = false;
            target = 0;
        }else if(value > limit){
            target = limit;
        }else
            target = value;
    }


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
        setValue(value, energy, energyMax);        
    }
    
    void setHungry(int value){
        setValue(value, hungry, hungryMax);        
    }

    void setClean(int value){
        setValue(value, clean, cleanMax);        
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

