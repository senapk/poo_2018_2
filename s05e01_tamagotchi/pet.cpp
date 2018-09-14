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

